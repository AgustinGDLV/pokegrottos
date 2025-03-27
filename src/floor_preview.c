#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "event_object_movement.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "floor_preview.h"
#include "gpu_regs.h"
#include "load_save.h"
#include "main.h"
#include "malloc.h"
#include "map_gen.h"
#include "map_preview.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon_gen.h"
#include "pokemon_icon.h"
#include "random.h"
#include "save.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "string_util.h"
#include "international_string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "util.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/event_objects.h"
#include "constants/songs.h"

EWRAM_DATA static u32 * sMapPreviewTilemapPtr = NULL;
EWRAM_DATA u8 gNumSpeciesInFloor = 0; // num unique species in the current floor
EWRAM_DATA u16 gFloorSpeciesList[MAX_FLOOR_SPECIES] = {0};

enum Windows
{
	WIN_CONTINUE,
    WIN_BUTTONS,
	WINDOW_COUNT,
};

static const struct WindowTemplate sFloorPreviewWinTemplates[WINDOW_COUNT + 1] =
{
	[WIN_CONTINUE] =
	{
		.bg = 1,
		.tilemapLeft = 1,
		.tilemapTop = 17,
		.width = 28,
		.height = 2,
		.paletteNum = 15,
		.baseBlock = 193,
	},
    [WIN_BUTTONS] =
    {
        .bg = 1,
		.tilemapLeft = 0,
		.tilemapTop = 0,
		.width = 30,
		.height = 2,
		.paletteNum = 15,
		.baseBlock = 249,
    },
	DUMMY_WIN_TEMPLATE,
};

static const struct BgTemplate sFloorPreviewBgTemplates[] =
{
	{ // Map Preview
		.bg = 2,
		.charBaseIndex = 0,
		.mapBaseIndex = 31,
		.screenSize = 0,
		.paletteMode = 0,
		.priority = 2,
		.baseTile = 0,
	},
	{ // Text
		.bg = 1,
		.charBaseIndex = 2,
		.mapBaseIndex = 6,
		.screenSize = 0,
		.paletteMode = 0,
		.priority = 1,
		.baseTile = 0,
	},
};

static void MainCB2_FloorPreview(void);
static void VBlankCB_FloorPreview(void);
static void Task_FloorPreviewExitAndWarp(u8 taskId);
static void Task_FloorPreviewWaitForKeypress(u8 taskId);
static void Task_FloorPreviewFadeIn(u8 taskId);
static void Task_FloorPreviewAutosave(u8 taskId);
static void LoadMapPreviewGfx(void);
static void DrawSpeciesIcons(void);
static void DrawText(void);
static void DrawWindows(void);
static void LoadFloorPreviewGfx(void);
static bool32 IsSpeciesAlreadyInList(u16 species);
static void PopulateSpeciesList(void);

// UI functions
static void MainCB2_FloorPreview(void)
{
	RunTasks();
	AnimateSprites();
	BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
	UpdatePaletteFade();
}

static void VBlankCB_FloorPreview(void)
{
	LoadOam();
	ProcessSpriteCopyRequests();
	TransferPlttBuffer();
}

void CB2_FloorPreview(void)
{
    switch (gMain.state) {
        default:
        case 0:
            UpdatePaletteFade();
            if (!gPaletteFade.active)
                gMain.state++;
            break;
        case 1:
            SetVBlankCallback(NULL); 
            ClearVramOamPlttRegs();
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
            gMain.state++;
            break;
        case 2:
            ClearTasksAndGraphicalStructs();
            gMain.state++;
            break;
        case 3:
            sMapPreviewTilemapPtr = AllocZeroed(BG_SCREEN_SIZE);
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sFloorPreviewBgTemplates, ARRAY_COUNT(sFloorPreviewBgTemplates));
            SetBgTilemapBuffer(2, sMapPreviewTilemapPtr);
            gMain.state++;
            break;
        case 4:
            LoadMapPreviewGfx();
            gMain.state++;
            break;
        case 5:
            if (IsDma3ManagerBusyWithBgCopy() != TRUE)
            {
                HideBg(0);
                ShowBg(1);
                ShowBg(2);
                CopyBgTilemapBufferToVram(2);
                gMain.state++;
            }
            break;
        case 6:
            InitWindows(sFloorPreviewWinTemplates);
            DeactivateAllTextPrinters();
            gMain.state++;
            break;
        case 7:
            // dealing with flicker issues :(
            // BlendPalettes(PALETTES_ALL, 16, 0);
            // BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            gMain.state++;
            break;
        case 8:
            SetVBlankCallback(VBlankCB_FloorPreview);
            LoadFloorPreviewGfx();
            CreateTask(Task_FloorPreviewFadeIn, 0);
            SetMainCallback2(MainCB2_FloorPreview);
            break;
	}
}

static void Task_FloorPreviewExitAndWarp(u8 taskId)
{
    TryWarpToRoom(STARTING_ROOM, 0xFF);
    Free(sMapPreviewTilemapPtr);
    sMapPreviewTilemapPtr = NULL;
    FreeAllWindowBuffers();
    ResetSpriteData();
    UnlockPlayerFieldControls();
    UnfreezeObjectEvents();
    DestroyTask(taskId);
}

static void Task_FloorPreviewWaitForKeypress(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON)
	{
        PlaySE(SE_SELECT);
		gTasks[taskId].func = Task_FloorPreviewExitAndWarp;
    }
}

static void Task_FloorPreviewFadeIn(u8 taskId)
{
	if (!gPaletteFade.active)
	{
        if (gSaveBlock1Ptr->currentFloor > 1)
		    gTasks[taskId].func = Task_FloorPreviewAutosave;
        else
            gTasks[taskId].func = Task_FloorPreviewWaitForKeypress;
	}
}

static void LoadMapPreviewGfx(void)
{   
    struct MapPreview data = gMapPreviewData[GetCurrentTemplateRules()->previewId];

    DecompressAndCopyTileDataToVram(2, data.tiles, 0, 0, 0);
	LZDecompressWram(data.map, sMapPreviewTilemapPtr);
	LoadPalette(data.palette, BG_PLTT_ID(13), PLTT_SIZE_4BPP);
	Menu_LoadStdPalAt(BG_PLTT_ID(15));
}

// Draw species icons into preview screen.
static void DrawSpeciesIcons(void)
{
    u32 i, palette, spriteId;

    // Load black palette for shadows.
    palette = RGB(8, 8, 8); // dark gray used in BG top/bottom, kind of jank to have here
    for (i = 0; i < 15; ++i)
        LoadPalette(&palette, OBJ_PLTT_ID(15) + i + 1, PLTT_SIZEOF(1));

    // Draw mon icons.
    PopulateSpeciesList();
    for (i = 0; i < gNumSpeciesInFloor; ++i)
    {
        // Main icon
        LoadMonIconPalette(gFloorSpeciesList[i]);
        CreateMonIconNoPersonality(GetIconSpeciesNoPersonality(gFloorSpeciesList[i]),
                                   SpriteCB_MonIcon, 24+(i%5)*48, 64-(gNumSpeciesInFloor/6)*18 + (i/5)*36, 0);
        // Shadow
        spriteId = CreateMonIconNoPersonality(GetIconSpeciesNoPersonality(gFloorSpeciesList[i]),
                                   SpriteCB_MonIcon, 25+(i%5)*48, 65-(gNumSpeciesInFloor/6)*18 + (i/5)*36, 4);
        gSprites[spriteId].oam.paletteNum = 15;
    }
}

static void DrawWindows(void)
{
    u32 i, windowId;
    for (i = 0; i < WINDOW_COUNT; ++i)
    {
        windowId = AddWindow(&sFloorPreviewWinTemplates[i]);
        PutWindowTilemap(windowId);
        CopyWindowToVram(i, COPYWIN_FULL);
    }
}

static const u8 sTextColor_Info[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};
static const u8 sTextColor_Instructions[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};

static const u8 sText_Floor[] = _("Floor ");
static const u8 sText_Continue[] = _(":  Entering ");
static const u8 sText_PressA[] = _("{A_BUTTON} Continue");

// Draw text.
static void DrawText(void)
{
    u8 *ptr;
    u16 palette;
    palette = RGB(8, 8, 8); // dark gray used in BG top/bottom, kind of jank to have here
    LoadPalette(&palette, BG_PLTT_ID(15) + 11, PLTT_SIZEOF(1));

    // Load text into continue window.
    ptr = StringCopy(gStringVar4, sText_Floor);
    ptr = ConvertIntToDecimalStringN(ptr, gSaveBlock1Ptr->currentFloor, STR_CONV_MODE_LEFT_ALIGN, 1+(gSaveBlock1Ptr->currentFloor/10));
    ptr = StringAppend(ptr, sText_Continue);
    ptr = StringAppend(ptr, gMapPreviewData[GetCurrentTemplateRules()->previewId].name);
    *ptr = CHAR_ELLIPSIS;
    *(++ptr) = EOS;
    AddTextPrinterParameterized3(WIN_CONTINUE, FONT_NORMAL, 2, 2, sTextColor_Instructions, TEXT_SKIP_DRAW, gStringVar4);
    CopyWindowToVram(WIN_CONTINUE, COPYWIN_FULL);

    // Load instructions into button window.
    AddTextPrinterParameterized3(WIN_BUTTONS, FONT_SMALL, 4, 0, sTextColor_Instructions, TEXT_SKIP_DRAW, sText_PressA);
    CopyWindowToVram(WIN_BUTTONS, COPYWIN_FULL);
}

static void LoadFloorPreviewGfx(void)
{
    DrawWindows();
    DrawSpeciesIcons();
    DrawText();
}

// Returns whether or not a species is already in the floor list.
static bool32 IsSpeciesAlreadyInList(u16 species)
{
    u32 i;
    for (i = 0; i < gNumSpeciesInFloor; ++i)
        if (gFloorSpeciesList[i] == species)
            return TRUE;
    return FALSE;
}

// Clears and populates gFloorSpeciesList with all unique species in current floor.
static void PopulateSpeciesList(void)
{
    const struct MapHeader * header;
    u16 species;
    u32 i, x, y;

    // Clear the list beforehand.
    for (i = 0; i < gNumSpeciesInFloor; ++i)
        gFloorSpeciesList[i] = SPECIES_NONE;
    gNumSpeciesInFloor = 0;

    // Traverse through each room and get the species of every object event encounter.
    for (x = 0; x < MAX_LAYOUT_WIDTH; ++x)
    {
        for (y = 0; y < MAX_LAYOUT_HEIGHT; ++y)
        {
            header = GetRoomMapHeader(ROOM_COORD(x, y));
            for (i = 0; i < header->events->objectEventCount; ++i)
            {
                if (header->events->objectEvents[i].graphicsId == OBJ_EVENT_MON)
                {
                    species = GetOverworldSpeciesInRoom(ROOM_COORD(x, y), header->events->objectEvents[i].localId);
                    if (!IsSpeciesAlreadyInList(species) && gNumSpeciesInFloor < MAX_FLOOR_SPECIES)
                    {
                        gFloorSpeciesList[gNumSpeciesInFloor] = species;
                        ++gNumSpeciesInFloor;
                    }
                }
            }
        }
    }
}

static const u8 sText_Saving[] = _("Saving...");

static void Task_FloorPreviewAutosave(u8 taskId)
{
    s16 *state = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        switch (*state)
        {
        case 0:
            AddTextPrinterParameterized3(WIN_BUTTONS, FONT_SMALL, GetStringRightAlignXOffset(FONT_SMALL, sText_Saving, 236), 0, sTextColor_Instructions, TEXT_SKIP_DRAW, sText_Saving);
            CopyWindowToVram(WIN_BUTTONS, COPYWIN_FULL);
            gSoftResetDisabled = TRUE;
            ++(*state);
            break;
        case 1:
            SetContinueGameWarpStatus();
            SetWarpData(&gSaveBlock1Ptr->continueGameWarp, GetCurrentTemplateRules()->mapGroup,
                        gFloorplan.layout[STARTING_ROOM].mapNum, 0, -1, -1);
            gSaveBlock1Ptr->currentRoom = STARTING_ROOM;
            TrySavingData(SAVE_LINK);
            ++(*state);
            break;
        case 2:
            PlaySE(SE_SAVE);
            FillWindowPixelBuffer(WIN_BUTTONS, PIXEL_FILL(0));
            AddTextPrinterParameterized3(WIN_BUTTONS, FONT_SMALL, 4, 0, sTextColor_Instructions, TEXT_SKIP_DRAW, sText_PressA);
            CopyWindowToVram(WIN_BUTTONS, COPYWIN_FULL);
            ++(*state);
            break;
        case 3:
            gTasks[taskId].func = Task_FloorPreviewWaitForKeypress;
            break;
        }
    }
}
