#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "deck_battle.h"
#include "deck_battle_interface.h"
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
EWRAM_DATA static u32 * sOverlayTilemapPtr = NULL;
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
	    {   // Interface
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {   // Background
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 21,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

static const union AnimCmd sAnim_Paused[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Idle[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(16, 12),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_Battler[] =
{
    sAnim_Paused,
    sAnim_Idle,
};

static const struct OamData sOamData_Battler =
{
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1,
};

static const u8 sDummyObjectGfx[] = INCBIN_U8("graphics/deck_pokemon/slowpoke/player_idle.4bpp");
static const u16 sOverlayPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/overlay.gbapal");
static const u32 sOverlayTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/overlay.4bpp.lz");
static const u32 sOverlayMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/overlay.bin.lz");

static void MainCB2_FloorPreview(void);
static void VBlankCB_FloorPreview(void);
static void Task_FloorPreviewExitAndWarp(u8 taskId);
static void Task_FloorPreviewWaitForKeypress(u8 taskId);
static void Task_FloorPreviewFadeIn(u8 taskId);
static void Task_FloorPreviewAutosave(u8 taskId);
static void LoadMapPreviewGfx(void);
static void DrawBattlerSprites(void);
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
            sOverlayTilemapPtr = AllocZeroed(BG_SCREEN_SIZE);
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sFloorPreviewBgTemplates, ARRAY_COUNT(sFloorPreviewBgTemplates));
            SetBgTilemapBuffer(2, sMapPreviewTilemapPtr);
            SetBgTilemapBuffer(0, sOverlayTilemapPtr);
            gMain.state++;
            break;
        case 4:
        {
            LoadMapPreviewGfx();
            u16 palette = RGB(0,0,0); // for cleaner fadeout
            LoadPalette(&palette, BG_PLTT_ID(0), PLTT_SIZEOF(1));
            LoadPalette(&palette, BG_PLTT_ID(1), PLTT_SIZEOF(1));
            gMain.state++;
            break;
        }
        case 5: 
            if (IsDma3ManagerBusyWithBgCopy() != TRUE)
            {
                ShowBg(0);
                ShowBg(1);
                ShowBg(2);
                CopyBgTilemapBufferToVram(0);
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
    Free(sOverlayTilemapPtr);
    sOverlayTilemapPtr = NULL;
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
    const struct DeckBattleBackground *bg = GetCurrentDeckBattleBackground();
    DecompressAndCopyTileDataToVram(2, bg->tiles, 0, 0, 0);
	LZDecompressWram(bg->map, sMapPreviewTilemapPtr);
	LoadPalette(bg->palette, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
	Menu_LoadStdPalAt(BG_PLTT_ID(15));

    DecompressAndCopyTileDataToVram(0, sOverlayTiles, 0, 0, 0);
	LZDecompressWram(sOverlayMap, sOverlayTilemapPtr);
	LoadPalette(sOverlayPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
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
    palette = RGB(12, 12, 12); // dark gray used in BG top/bottom, kind of jank to have here
    LoadPalette(&palette, BG_PLTT_ID(15) + 11, PLTT_SIZEOF(1));

    // Load text into continue window.
    ptr = StringCopy(gStringVar4, sText_Floor);
    ptr = ConvertIntToDecimalStringN(ptr, gSaveBlock1Ptr->currentFloor, STR_CONV_MODE_LEFT_ALIGN, 1+(gSaveBlock1Ptr->currentFloor/10));
    ptr = StringAppend(ptr, sText_Continue);
    ptr = StringAppend(ptr, GetCurrentTemplateRules()->name);
    *ptr = CHAR_ELLIPSIS;
    *(++ptr) = EOS;
    AddTextPrinterParameterized3(WIN_CONTINUE, FONT_NORMAL, 2, 2, sTextColor_Instructions, TEXT_SKIP_DRAW, gStringVar4);
    CopyWindowToVram(WIN_CONTINUE, COPYWIN_FULL);

    // Load instructions into button window.
    AddTextPrinterParameterized3(WIN_BUTTONS, FONT_SMALL, 4, 0, sTextColor_Instructions, TEXT_SKIP_DRAW, sText_PressA);
    CopyWindowToVram(WIN_BUTTONS, COPYWIN_FULL);
}

static void DrawBattlerSprites(void);

static void LoadFloorPreviewGfx(void)
{
    DrawWindows();
    
    // Load battler sprites.
    LoadSpritePalette(&gMiscGfxSpritePalette);
    LoadSpriteSheet(&gShadowSpriteSheet);
    DrawBattlerSprites();
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 6));

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

static const u8 sText_Saving[] = _("Saving…");

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

static void DrawBattlerSprites(void)
{
    u32 species, palIndex, spriteId;

    PopulateSpeciesList();
    for (u32 i = 0; i < gNumSpeciesInFloor; ++i)
    {
        species = gFloorSpeciesList[i];
        // Draw battler sprite.
        palIndex = LoadSpritePaletteWithTag(gDeckSpeciesInfo[species].objectPalette, 10000 + i);
        const struct SpriteSheet spriteSheet = {gDeckSpeciesInfo[species].opponentIdle, sizeof(sDummyObjectGfx), 10000 + i};
        const struct SpriteTemplate spriteTemplate =
        {
            .tileTag = 10000+i,
            .paletteTag = 0,
            .oam = &sOamData_Battler,
            .anims = sAnims_Battler,
            .images = NULL,
            .affineAnims = gDummySpriteAffineAnimTable,
            .callback = SpriteCallbackDummy,
        };
        LoadSpriteSheet(&spriteSheet);
        spriteId = CreateSprite(&spriteTemplate, 24+(i%5)*48, 64-(gNumSpeciesInFloor/6)*18 + (i/5)*36 + gDeckSpeciesInfo[species].opponentYOffset, 0);
        gSprites[spriteId].oam.paletteNum = palIndex;
        StartSpriteAnim(&gSprites[spriteId], ANIM_IDLE);

        // Draw shadow.
        spriteId = CreateSprite(&gShadowSpriteTemplate, 24+(i%5)*48, 64-(gNumSpeciesInFloor/6)*18 + (i/5)*36, 16);
        gSprites[spriteId].callback = SpriteCallbackDummy;
    }
}
