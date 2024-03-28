#include "global.h"
#include "battle.h"
#include "bg.h"
#include "continue_screen.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "main_menu.h"
#include "malloc.h"
#include "map_gen.h"
#include "menu.h"
#include "money.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "text_window.h"
#include "title_screen.h"
#include "util.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

// const rom data
#define MAIN_MENU_BORDER_TILE   0x1D5

enum Windows
{
    WIN_MUGSHOT,
    WIN_STATS,
	WIN_CONTINUE,
    WIN_BUTTONS,
	WINDOW_COUNT,
};

struct MapPreview {
    const u16 * palette;
    const u32 * tiles;
    const u32 * map;
};

static const u16 sMtMoonMapPreviewPalette[] = INCBIN_U16("graphics/map_preview/mt_moon/tiles.gbapal");
static const u32 sMtMoonMapPreviewTiles[] = INCBIN_U32("graphics/map_preview/mt_moon/tiles.4bpp.lz");
static const u32 sMtMoonMapPreviewTilemap[] = INCBIN_U32("graphics/map_preview/mt_moon/tilemap.bin.lz");

static const u16 sPowerPlantMapPreviewPalette[] = INCBIN_U16("graphics/map_preview/power_plant/tiles.gbapal");
static const u32 sPowerPlantMapPreviewTiles[] = INCBIN_U32("graphics/map_preview/power_plant/tiles.4bpp.lz");
static const u32 sPowerPlantMapPreviewTilemap[] = INCBIN_U32("graphics/map_preview/power_plant/tilemap.bin.lz");

const struct MapPreview sMapPreviewData[PREVIEW_COUNT] =
{
    [PREVIEW_MT_MOON] = {
        .palette = sMtMoonMapPreviewPalette,
        .tiles = sMtMoonMapPreviewTiles,
        .map = sMtMoonMapPreviewTilemap,
    },
    [PREVIEW_POWER_PLANT] = {
        .palette = sPowerPlantMapPreviewPalette,
        .tiles = sPowerPlantMapPreviewTiles,
        .map = sPowerPlantMapPreviewTilemap,
    },
};

static const struct WindowTemplate sContinueScreenWinTemplates[WINDOW_COUNT + 1] =
{
	[WIN_MUGSHOT] =
	{
		.bg = 1,
		.tilemapLeft = 2,
		.tilemapTop = 6,
		.width = 8,
		.height = 8,
		.paletteNum = 15,
		.baseBlock = 1,
	},
    [WIN_STATS] =
	{
		.bg = 1,
		.tilemapLeft = 12,
		.tilemapTop = 6,
		.width = 16,
		.height = 8,
		.paletteNum = 15,
		.baseBlock = 65,
	},
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

static const struct BgTemplate sContinueScreenBgTemplates[] =
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
	// { // Floor
	// 	.bg = 0,
	// 	.charBaseIndex = 1,
	// 	.mapBaseIndex = 24,
	// 	.screenSize = 0,
	// 	.paletteMode = 0,
	// 	.priority = 0,
	// 	.baseTile = 0,
	// }
};

// functions
static void LoadMapPreviewGfx(void);
static void ClearTasksAndGraphicalStructs(void);
static void ClearVramOamPlttRegs(void);
static void Task_ContinueScreenFadeOutAndExit(u8 taskId);
static void Task_ContinueScreenWaitForKeypress(u8 taskId);
static void Task_ContinueScreenFadeIn(u8 taskId);
static void LoadContinueScreenGfx(void);

EWRAM_DATA static u32 * sMapPreviewTilemapPtr = NULL;
EWRAM_DATA MainCallback sExitCallback = NULL;

// code
static void MainCB2_ContinueScreen(void)
{
	RunTasks();
	AnimateSprites();
	BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
	UpdatePaletteFade();
}

static void VBlankCB_ContinueScreen(void)
{
	LoadOam();
	ProcessSpriteCopyRequests();
	TransferPlttBuffer();
}

void CB2_ContinueScreen(void)
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
            gMain.state++;
            break;
        case 2:
            ClearTasksAndGraphicalStructs();
            gMain.state++;
            break;
        case 3:
            sMapPreviewTilemapPtr = AllocZeroed(BG_SCREEN_SIZE);
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sContinueScreenBgTemplates, ARRAY_COUNT(sContinueScreenBgTemplates));
            SetBgTilemapBuffer(2, sMapPreviewTilemapPtr);
            gMain.state++;
            break;
        case 4:
            InitWindows(sContinueScreenWinTemplates);
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
            DeactivateAllTextPrinters();
            gMain.state++;
            break;
        case 7:
            // BlendPalettes(PALETTES_ALL, 16, 0);
            // BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            gMain.state++;
            break;
        case 8:
            LoadContinueScreenGfx();
            SetVBlankCallback(VBlankCB_ContinueScreen);
            CreateTask(Task_ContinueScreenFadeIn, 0);
            SetMainCallback2(MainCB2_ContinueScreen);
            break;
	}
}

static void Task_ContinueScreenFadeOutAndExit(u8 taskId)
{
	if (!gPaletteFade.active)
	{
        SetMainCallback2(sExitCallback);
		Free(sMapPreviewTilemapPtr);
        sMapPreviewTilemapPtr = NULL;
		FreeAllWindowBuffers();
        ResetSpriteData();
        UnlockPlayerFieldControls();
        UnfreezeObjectEvents();
		DestroyTask(taskId);
	}
}

static void Task_ContinueScreenWaitForKeypress(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON)
	{
        PlaySE(SE_SELECT);
		BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sExitCallback = CB2_ContinueSavedGame;
		gTasks[taskId].func = Task_ContinueScreenFadeOutAndExit;
    }
    if (gMain.newKeys & B_BUTTON)
	{
        PlaySE(SE_SELECT);
        sExitCallback = CB2_InitTitleScreen;
		gTasks[taskId].func = Task_ContinueScreenFadeOutAndExit;
    }
    if (gMain.newKeys & (L_BUTTON | R_BUTTON))
    {
        PlaySE(SE_SELECT);
        sExitCallback = CB2_InitMainMenu;
		gTasks[taskId].func = Task_ContinueScreenFadeOutAndExit;
    }
}

static void Task_ContinueScreenFadeIn(u8 taskId)
{
	if (!gPaletteFade.active)
	{
		gTasks[taskId].func = Task_ContinueScreenWaitForKeypress;
	}
}

// Draw mugshot sprite.
static void DrawMugshot(void)
{
    LoadSpritePalette(&gCharacterInfos[gSaveBlock1Ptr->characterId].mugshotPal);
    LoadCompressedSpriteSheet(&gCharacterInfos[gSaveBlock1Ptr->characterId].mugshotSheet);
    CreateSprite(gCharacterInfos[gSaveBlock1Ptr->characterId].mugshotTemplate, 48, 80, 0);
}

// Draw windows.
static void DrawWindows(void)
{
    u32 i, windowId;
    LoadMessageBoxAndBorderGfx();
    // Load graphics for windows with border graphics and fill.
    for (i = WIN_MUGSHOT; i <= WIN_CONTINUE; ++i)
    {
        windowId = AddWindow(&sContinueScreenWinTemplates[i]);
        FillWindowPixelBuffer(i, PIXEL_FILL(1));
        DrawStdWindowFrame(windowId, FALSE);
        PutWindowTilemap(windowId);
        CopyWindowToVram(i, COPYWIN_FULL);
    }
    // Load remaining windows.
    for (; i < WINDOW_COUNT; ++i)
    {
        windowId = AddWindow(&sContinueScreenWinTemplates[i]);
        PutWindowTilemap(windowId);
        CopyWindowToVram(i, COPYWIN_FULL);
    }
}

static const u8 sTextColor_Name[] = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_1, TEXT_COLOR_LIGHT_GRAY};
static const u8 sTextColor_Stats[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_BLUE, TEXT_COLOR_LIGHT_GRAY};
static const u8 sTextColor_Info[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};
static const u8 sTextColor_Instructions[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};

static const u8 sText_Floor[] = _("Floor");
static const u8 sText_Gold[] = _("Gold");
static const u8 sText_Time[] = _("Time");
static const u8 sText_Continue[] = _("Continue run?");
static const u8 sText_PressA[] = _("{A_BUTTON} Continue");
static const u8 sText_PressLR[] = _("{L_BUTTON}{R_BUTTON} Change Page");

// Draw text.
static void DrawText(void)
{
    u8 * ptr;
    u8 strFloor[0x20] = {0};
    u8 strMoney[0x20] = {0};
    u8 strTime[0x20] = {0};

    // Load dynamic text colors.
    u16 palette = gCharacterInfos[gSaveBlock1Ptr->characterId].color;
    LoadPalette(&palette, BG_PLTT_ID(15) + 10, PLTT_SIZEOF(1));
    palette = RGB(8, 8, 8); // dark gray used in BG top/bottom
    LoadPalette(&palette, BG_PLTT_ID(15) + 11, PLTT_SIZEOF(1));

    // Load text into stats window.
    AddTextPrinterParameterized3(WIN_STATS, FONT_NORMAL, 2, 0, sTextColor_Name, TEXT_SKIP_DRAW, gCharacterInfos[gSaveBlock1Ptr->characterId].name);
    AddTextPrinterParameterized3(WIN_STATS, FONT_NORMAL, 2, 16, sTextColor_Info, TEXT_SKIP_DRAW, sText_Floor);
    AddTextPrinterParameterized3(WIN_STATS, FONT_NORMAL, 2, 32, sTextColor_Info, TEXT_SKIP_DRAW, sText_Gold);
    AddTextPrinterParameterized3(WIN_STATS, FONT_NORMAL, 2, 48, sTextColor_Info, TEXT_SKIP_DRAW, sText_Time);

    ConvertIntToDecimalStringN(strFloor, gSaveBlock1Ptr->currentFloor, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized3(WIN_STATS, FONT_NORMAL, GetStringRightAlignXOffset(FONT_NORMAL, strFloor, 126), 16, sTextColor_Info, TEXT_SKIP_DRAW, strFloor);
    
    ptr = strMoney;
    *ptr = CHAR_CURRENCY;
    ptr = ConvertIntToDecimalStringN(ptr + 1, GetMoney(&gSaveBlock1Ptr->money), STR_CONV_MODE_LEFT_ALIGN, 6);
    AddTextPrinterParameterized3(WIN_STATS, FONT_NORMAL, GetStringRightAlignXOffset(FONT_NORMAL, strMoney, 126), 32, sTextColor_Info, TEXT_SKIP_DRAW, strMoney);
    
    ptr = ConvertIntToDecimalStringN(strTime, gSaveBlock2Ptr->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
    *ptr = CHAR_COLON;
    ConvertIntToDecimalStringN(ptr + 1, gSaveBlock2Ptr->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    AddTextPrinterParameterized3(WIN_STATS, FONT_NORMAL, GetStringRightAlignXOffset(FONT_NORMAL, strTime, 126), 48, sTextColor_Info, TEXT_SKIP_DRAW, strTime);

    CopyWindowToVram(WIN_STATS, COPYWIN_FULL);

    // Load text into continue window.
    AddTextPrinterParameterized3(WIN_CONTINUE, FONT_NORMAL, 2, 0, sTextColor_Info, TEXT_SKIP_DRAW, sText_Continue);
    CopyWindowToVram(WIN_CONTINUE, COPYWIN_FULL);

    // Load instructions into button window.
    AddTextPrinterParameterized3(WIN_BUTTONS, FONT_SMALL, 2, 0, sTextColor_Instructions, TEXT_SKIP_DRAW, sText_PressA);
    AddTextPrinterParameterized3(WIN_BUTTONS, FONT_SMALL, GetStringRightAlignXOffset(FONT_SMALL, sText_PressLR, 238), 0, sTextColor_Instructions, TEXT_SKIP_DRAW, sText_PressLR);
    CopyWindowToVram(WIN_BUTTONS, COPYWIN_FULL);
}

static void LoadContinueScreenGfx(void)
{
    // Draw sprites, windows, and text.
    DrawMugshot();
    DrawWindows();
    DrawText();
}

static void LoadMapPreviewGfx(void)
{   
    struct MapPreview data = sMapPreviewData[GetTemplateRules(gSaveBlock1Ptr->currentTemplateType)->previewId];
    DecompressAndCopyTileDataToVram(2, data.tiles, 0, 0, 0);
	LZDecompressWram(data.map, sMapPreviewTilemapPtr);
	LoadPalette(data.palette, BG_PLTT_ID(13), PLTT_SIZE_4BPP);
	Menu_LoadStdPalAt(BG_PLTT_ID(15));
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
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}
