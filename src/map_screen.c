#include "global.h"
#include "bg.h"
#include "sprite.h"
#include "main.h"
#include "battle.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "sound.h"
#include "map_gen.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "random.h"
#include "palette.h"
#include "save.h"
#include "scanline_effect.h"
#include "script.h"
#include "sprite.h"
#include "string_util.h"
#include "trig.h"
#include "util.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

// sprite tags
enum {
    TAG_BOSS_ROOM = 10000,
    TAG_TREASURE_ROOM,
};

// credit to Sbird for dynamic BG code
#define POS_TO_SCR_ADDR(x,y) (32*(y) + (x))
#define SCR_MAP_ENTRY(tile, pal, hflip, vflip) ((tile) | (hflip ? (1<<10) : 0) | (vflip ? (1 << 11) : 0) | (pal << 12))

enum Windows
{
	WIN_FLOOR,
    // WIN_YESNO,
	WINDOW_COUNT,
};

// const rom data
static const u32 sMapScreenBgGfx[]      = INCBIN_U32("graphics/interface/map_screen.4bpp.lz");
static const u32 sMapScreenBgPal[]      = INCBIN_U32("graphics/interface/map_screen.gbapal.lz");
static const u32 sMapScreenBgMap[]      = INCBIN_U32("graphics/interface/map_screen.bin.lz");
static const u8 sBossRoomGfx[]          = INCBIN_U8("graphics/interface/boss_room.4bpp");
static const u16 sBossRoomPal[]         = INCBIN_U16("graphics/interface/boss_room.gbapal");
static const u8 sTreasureRoomGfx[]          = INCBIN_U8("graphics/interface/treasure_room.4bpp");
static const u16 sTreasureRoomPal[]         = INCBIN_U16("graphics/interface/treasure_room.gbapal");

static const struct WindowTemplate sMapScreenWinTemplates[WINDOW_COUNT + 1] =
{
	[WIN_FLOOR] =
	{
		.bg = 1,
		.tilemapLeft = 0,
		.tilemapTop = 0,
		.width = 8,
		.height = 2,
		.paletteNum = 15,
		.baseBlock = 1,
	},
    // [WIN_YESNO] =
    // {
    //     .bg = 1,
    //     .tilemapLeft = 24,
    //     .tilemapTop = 13,
    //     .width = 5,
    //     .height = 4,
    //     .paletteNum = 15,
    //     .baseBlock = 2,
    // },
	DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sMapScreenBgTemplates[] =
{
	{ // Map Background
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
	{ // Floor
		.bg = 0,
		.charBaseIndex = 1,
		.mapBaseIndex = 24,
		.screenSize = 0,
		.paletteMode = 0,
		.priority = 0,
		.baseTile = 0,
	}
};

// Boss Room sprite data
static const struct OamData sBossRoomOAM =
{
	.affineMode = ST_OAM_AFFINE_OFF,
	.objMode = ST_OAM_OBJ_NORMAL,
	.shape = SPRITE_SHAPE(16x16),
	.size = SPRITE_SIZE(16x16),
	.priority = 2, // On BG 2
};

static void SpriteCB_Dummy(struct Sprite *sprite) {}
static const struct SpriteTemplate sBossRoomSpriteTemplate =
{
	.tileTag = TAG_BOSS_ROOM,
	.paletteTag = TAG_BOSS_ROOM,
	.oam = &sBossRoomOAM,
	.anims = gDummySpriteAnimTable,
	.images = NULL,
	.affineAnims = gDummySpriteAffineAnimTable,
	.callback = SpriteCB_Dummy,
};

static const struct SpriteSheet sBossRoomSpriteSheet = {
    sBossRoomGfx, sizeof(sBossRoomGfx), TAG_BOSS_ROOM
};
static const struct SpritePalette sBossRoomSpritePalette = {
    sBossRoomPal, TAG_BOSS_ROOM
};

// Treasure Room sprite data
static const struct OamData sTreasureRoomOAM =
{
	.affineMode = ST_OAM_AFFINE_OFF,
	.objMode = ST_OAM_OBJ_NORMAL,
	.shape = SPRITE_SHAPE(16x16),
	.size = SPRITE_SIZE(16x16),
	.priority = 2, // On BG 2
};

static void SpriteCB_TreasureRoom(struct Sprite *sprite);
static const struct SpriteTemplate sTreasureRoomSpriteTemplate =
{
	.tileTag = TAG_TREASURE_ROOM,
	.paletteTag = TAG_TREASURE_ROOM,
	.oam = &sTreasureRoomOAM,
	.anims = gDummySpriteAnimTable,
	.images = NULL,
	.affineAnims = gDummySpriteAffineAnimTable,
	.callback = SpriteCB_Dummy,
};

static const struct SpriteSheet sTreasureRoomSpriteSheet = {
    sTreasureRoomGfx, sizeof(sTreasureRoomGfx), TAG_TREASURE_ROOM
};
static const struct SpritePalette sTreasureRoomSpritePalette = {
    sTreasureRoomPal, TAG_TREASURE_ROOM
};

// functions
static void PrintFloorText(void);
static void CleanWindows(void);
static void CommitWindows(void);
static void LoadMapScreenGfx(void);
static void ClearTasksAndGraphicalStructs(void);
static void ClearVramOamPlttRegs(void);
static void Task_MapScreenFadeOutAndExit(u8 taskId);
static void Task_MapScreenWaitForKeypress(u8 taskId);
static void Task_MapScreenFadeIn(u8 taskId);
static void Task_MapScreenWarpYesNo(u8 taskId);
static void Task_HandleMapScreenWarpYesNoInput(u8 taskId);
static void InitMapScreen(void);
static void ShowRooms(void);

EWRAM_DATA static u32 sRoomBuffer = 0;
EWRAM_DATA static u32* sMapScreenTilemapPtr = NULL;

// code
static void MainCB2_MapScreen(void)
{
	RunTasks();
	AnimateSprites();
	BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
	UpdatePaletteFade();
}

static void VBlankCB_MapScreen(void)
{
	LoadOam();
	ProcessSpriteCopyRequests();
	TransferPlttBuffer();
}

void CB2_MapScreen(void)
{
    switch (gMain.state) {
        default:
        case 0:
            SetVBlankCallback(NULL); 
            ClearVramOamPlttRegs();
            gMain.state++;
            break;
        case 1:
            ClearTasksAndGraphicalStructs();
            gMain.state++;
            break;
        case 2:
            sMapScreenTilemapPtr = AllocZeroed(BG_SCREEN_SIZE);
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sMapScreenBgTemplates, 3);
            SetBgTilemapBuffer(2, sMapScreenTilemapPtr);
            gMain.state++;
            break;
        case 3:
            LoadMapScreenGfx();
            gMain.state++;
            break;
        case 4:
            if (IsDma3ManagerBusyWithBgCopy() != TRUE)
            {
                ShowBg(0);
                ShowBg(1);
                ShowBg(2);
                CopyBgTilemapBufferToVram(2);
                gMain.state++;
            }
            break;
        case 5:
            InitWindows(sMapScreenWinTemplates);
            DeactivateAllTextPrinters();
            gMain.state++;
            break;
        case 6:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            gMain.state++;
            break;
        case 7:
            SetVBlankCallback(VBlankCB_MapScreen);
            InitMapScreen();
            CreateTask(Task_MapScreenFadeIn, 0);
            SetMainCallback2(MainCB2_MapScreen);
            break;
	}
}

static void Task_MapScreenFadeOutAndExit(u8 taskId)
{
	if (!gPaletteFade.active)
	{
        SetMainCallback2(CB2_ReturnToFieldContinueScript);
		Free(sMapScreenTilemapPtr);
        sMapScreenTilemapPtr = NULL;
		FreeAllWindowBuffers();
        ResetSpriteData();
		DestroyTask(taskId);
	}
}

static void Task_MapScreenFadeOutAndWarp(u8 taskId)
{
    if (!gPaletteFade.active)
	{
        PlaySE(SE_WARP_IN);
        SetWarpDestinationToRoom(gSaveBlock1Ptr->currentRoom);
        WarpIntoMap();
        SetMainCallback2(CB2_LoadMap);
		Free(sMapScreenTilemapPtr);
        sMapScreenTilemapPtr = NULL;
		FreeAllWindowBuffers();
        ResetSpriteData();
		DestroyTask(taskId);
	}
}

static void Task_MapScreenWaitForKeypress(u8 taskId)
{
    // Check if player is selecting a new room.
    u32 target = gSaveBlock1Ptr->currentRoom;
    if (gMain.newKeys & DPAD_UP)
        target = gSaveBlock1Ptr->currentRoom - 10;
    if (gMain.newKeys & DPAD_DOWN)
        target = gSaveBlock1Ptr->currentRoom + 10;
    if (gMain.newKeys & DPAD_RIGHT)
        target = gSaveBlock1Ptr->currentRoom + 1;
    if (gMain.newKeys & DPAD_LEFT)
        target = gSaveBlock1Ptr->currentRoom - 1;

    #ifdef NDEBUG
    if (target != gSaveBlock1Ptr->currentRoom && DoesRoomExist(target) && gFloorplan.layout[target].visited
        && IsRoomMapIdValid(target))
    {
        PlaySE(SE_SELECT);
        gSaveBlock1Ptr->currentRoom = target;
        ShowRooms();
    }
    #else
    // In Debug mode, you can reveal the map by navigating in this screen.
    if (target != gSaveBlock1Ptr->currentRoom && DoesRoomExist(target) && IsRoomMapIdValid(target))
    {
        PlaySE(SE_SELECT);
        gFloorplan.layout[target].visited = TRUE;
        gSaveBlock1Ptr->currentRoom = target;
        ShowRooms();
    }
    #endif

    // Try to warp to new room.
    if (gMain.newKeys & A_BUTTON && gSaveBlock1Ptr->currentRoom != sRoomBuffer)
	{
		PlaySE(SE_SELECT);
		BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
		gTasks[taskId].func = Task_MapScreenFadeOutAndWarp;
    }

    // Exit map menu.
    if (gMain.newKeys & B_BUTTON)
	{
		PlaySE(SE_RG_CARD_FLIP);
        gSaveBlock1Ptr->currentRoom = sRoomBuffer;
		BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
		gTasks[taskId].func = Task_MapScreenFadeOutAndExit;
    }
}

static void Task_MapScreenFadeIn(u8 taskId)
{
	if (!gPaletteFade.active)
	{
		gTasks[taskId].func = Task_MapScreenWaitForKeypress;
	}
}

static const u8 sText_Floor[] = _("Floor ");
static void PrintFloorText(void)
{
	const u8 colour[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};
	StringCopy(gStringVar1, sText_Floor);
	ConvertIntToDecimalStringN(gStringVar2, 1, STR_CONV_MODE_LEFT_ALIGN, 3);
	StringAppend(gStringVar1, gStringVar2);
	AddTextPrinterParameterized3(WIN_FLOOR, 0, 4, 0, colour, 0, gStringVar1);
}

static void DrawRoomOnBg(u32 x, u32 y)
{
    u16 *tilemapPtr = GetBgTilemapBuffer(2);
    u32 tileId, bgX, bgY;

    if (ROOM_COORD(x, y) == gSaveBlock1Ptr->currentRoom)
        tileId = 0x09;
    else if (gFloorplan.layout[ROOM_COORD(x, y)].visited)
        tileId = 0x05;
    else if (IsRoomAdjacentToVisited(ROOM_COORD(x, y)))
        tileId = 0x01;
    else
        return;
    
    bgX = 5 + x*2;
    bgY = 2 + y*2;

    tilemapPtr[POS_TO_SCR_ADDR(bgX, bgY)] = SCR_MAP_ENTRY(tileId, 0, FALSE, FALSE);
    tilemapPtr[POS_TO_SCR_ADDR(bgX + 1, bgY)] = SCR_MAP_ENTRY(tileId + 1, 0, FALSE, FALSE);
    tilemapPtr[POS_TO_SCR_ADDR(bgX, bgY + 1)] = SCR_MAP_ENTRY(tileId + 2, 0, FALSE, FALSE);
    tilemapPtr[POS_TO_SCR_ADDR(bgX + 1, bgY + 1)] = SCR_MAP_ENTRY(tileId + 3, 0, FALSE, FALSE);
}

static void DrawRoomIcon(u32 x, u32 y)
{
    if (!gFloorplan.layout[ROOM_COORD(x, y)].visited && !IsRoomAdjacentToVisited(ROOM_COORD(x, y)))
        return;

    switch (gFloorplan.layout[ROOM_COORD(x, y)].type)
    {
        case BOSS_ROOM:
            LoadSpritePalette(&sBossRoomSpritePalette);
            LoadSpriteSheet(&sBossRoomSpriteSheet);
            CreateSprite(&sBossRoomSpriteTemplate, 8*(5 + x*2) + 9, 8*(2 + y*2) + 8, 0);
            break;
        case TREASURE_ROOM:
            LoadSpritePalette(&sTreasureRoomSpritePalette);
            LoadSpriteSheet(&sTreasureRoomSpriteSheet);
            CreateSprite(&sTreasureRoomSpriteTemplate, 8*(5 + x*2) + 9, 8*(2 + y*2) + 8, 0);
            break;
    }
}

static void ShowRooms(void)
{
    u32 x, y;
	for (x = 0; x < MAX_LAYOUT_WIDTH; ++x)
    {
        for (y = 0; y < MAX_LAYOUT_HEIGHT; ++y)
        {
            if (DoesRoomExist(ROOM_COORD(x, y)))
            {
                DrawRoomOnBg(x, y);
                DrawRoomIcon(x, y);
            }
        }
    }
    ScheduleBgCopyTilemapToVram(2);
}

// Cleans the windows
static void CleanWindows(void)
{
    u32 i;
	for (i = 0; i < WINDOW_COUNT; ++i)
    {
		FillWindowPixelBuffer(i, PIXEL_FILL(0));
    }
}

// Display commited windows
static void CommitWindows(void)
{
    u32 i;
	for (i = 0; i < WINDOW_COUNT; ++i)
	{
		CopyWindowToVram(i, 3);
		PutWindowTilemap(i);
	}
}

static void InitMapScreen(void)
{
    // Clean windows.
	CleanWindows();
	CommitWindows();

    ShowRooms();
    PrintFloorText();
    
	// Display newly commited windows.
	CommitWindows();
}

static void LoadMapScreenGfx(void)
{	
    DecompressAndCopyTileDataToVram(2, &sMapScreenBgGfx, 0, 0, 0);
	LZDecompressWram(sMapScreenBgMap, sMapScreenTilemapPtr);
	LoadCompressedPalette(sMapScreenBgPal, 0, 0x20);
	ListMenuLoadStdPalAt(0xC0, 1);
	Menu_LoadStdPalAt(0xF0);
}

static void ClearTasksAndGraphicalStructs(void)
{
	ScanlineEffect_Stop();
	ResetTasks();
	ResetSpriteData();
	ResetTempTileDataBuffers();
	ResetPaletteFade();
	FreeAllSpritePalettes();
}

static void ClearVramOamPlttRegs(void)
{
	DmaFill16(3, 0, VRAM, VRAM_SIZE);
	DmaFill32(3, 0, OAM, OAM_SIZE);
	DmaFill16(3, 0, PLTT, PLTT_SIZE);
	SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
	SetGpuReg(REG_OFFSET_BG3CNT, DISPCNT_MODE_0);
	SetGpuReg(REG_OFFSET_BG2CNT, DISPCNT_MODE_0);
	SetGpuReg(REG_OFFSET_BG1CNT, DISPCNT_MODE_0);
	SetGpuReg(REG_OFFSET_BG0CNT, DISPCNT_MODE_0);
	SetGpuReg(REG_OFFSET_BG3HOFS, DISPCNT_MODE_0);
	SetGpuReg(REG_OFFSET_BG3VOFS, DISPCNT_MODE_0);
	SetGpuReg(REG_OFFSET_BG2HOFS, DISPCNT_MODE_0);
	SetGpuReg(REG_OFFSET_BG2VOFS, DISPCNT_MODE_0);
	SetGpuReg(REG_OFFSET_BG1HOFS, DISPCNT_MODE_0);
	SetGpuReg(REG_OFFSET_BG1VOFS, DISPCNT_MODE_0);
	SetGpuReg(REG_OFFSET_BG0HOFS, DISPCNT_MODE_0);
	SetGpuReg(REG_OFFSET_BG0VOFS, DISPCNT_MODE_0);
}

void ShowMapScreen(void)
{
    if (gFloorplan.numRooms != 0 && !gPaletteFade.active)
	{
        DebugPrintFloorplan(&gFloorplan);
        sRoomBuffer = gSaveBlock1Ptr->currentRoom;
        PlaySE(SE_RG_CARD_FLIPPING);
        PlayRainStoppingSoundEffect();
		SetMainCallback2(CB2_MapScreen);
	}
    else if (!gPaletteFade.active) // safety check, looks awful
    {
		BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        SetMainCallback2(CB2_ReturnToFieldContinueScript);
    }
}

// static void Task_MapScreenWarpYesNo(u8 taskId)
// {
//     CreateYesNoMenu(&sMapScreenWinTemplates[WIN_YESNO], 0x4F, 13, 0);
//     gTasks[taskId].func = Task_HandleMapScreenWarpYesNoInput;
// }

// static void Task_HandleMapScreenWarpYesNoInput(u8 taskId)
// {
//     switch (Menu_ProcessInputNoWrapClearOnChoose())
//     {
//         case 0: // Yes
//             BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
//             gTasks[taskId].func = Task_MapScreenFadeOutAndExit;
//             break;
//         case MENU_B_PRESSED:
//             PlaySE(SE_SELECT);
//         case 1: // No
//             ClearStdWindowAndFrameToTransparent(WIN_YESNO, FALSE);
//             ClearWindowTilemap(WIN_YESNO);
//             if (MenuHelpers_IsLinkActive() == TRUE)
//             {
//                 gTasks[taskId].func = Task_MapScreenWaitForKeypress;
//             }
//             break;
//     }
// }
