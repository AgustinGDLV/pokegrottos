#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "bg.h"
#include "start_screen.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "map_preview.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "main.h"
#include "main_menu.h"
#include "malloc.h"
#include "map_gen.h"
#include "menu.h"
#include "money.h"
#include "overworld.h"
#include "palette.h"
#include "play_time.h"
#include "pokemon_icon.h"
#include "pokemon_animation.h"
#include "random.h"
#include "rtc.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "text_window.h"
#include "title_screen.h"
#include "trainer_pokemon_sprites.h"
#include "util.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

// const rom data
#define MAIN_MENU_BORDER_TILE   0x1D5

enum ScreenType
{
    SCREEN_CONTINUE,
    SCREEN_CHARACTER_SELECT,
    SCREEN_STARTER_SELECT,
    SCREEN_COUNT,
};

enum Windows
{
    WIN_BUTTONS_RIGHT,
    WIN_MUGSHOT,
    WIN_INFO,
	WIN_MAIN_TEXT,
    WIN_BUTTONS_LEFT,
	WINDOW_COUNT,
};

static const struct WindowTemplate sStartScreenWinTemplates[WINDOW_COUNT + 1] =
{
    [WIN_BUTTONS_RIGHT] =
    {
        .bg = 1,
		.tilemapLeft = 16,
		.tilemapTop = 0,
		.width = 14,
		.height = 2,
		.paletteNum = 15,
		.baseBlock = 281,
    },
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
    [WIN_INFO] =
	{
		.bg = 1,
		.tilemapLeft = 12,
		.tilemapTop = 6,
		.width = 16,
		.height = 8,
		.paletteNum = 15,
		.baseBlock = 65,
	},
	[WIN_MAIN_TEXT] =
	{
		.bg = 1,
		.tilemapLeft = 1,
		.tilemapTop = 17,
		.width = 28,
		.height = 2,
		.paletteNum = 15,
		.baseBlock = 193,
	},
    [WIN_BUTTONS_LEFT] =
    {
        .bg = 1,
		.tilemapLeft = 0,
		.tilemapTop = 0,
		.width = 16,
		.height = 2,
		.paletteNum = 15,
		.baseBlock = 249,
    },
	DUMMY_WIN_TEMPLATE,
};

static const struct BgTemplate sStartScreenBgTemplates[] =
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

// functions
static void LoadMapPreviewGfx(void);
static void LoadScreenGfx(enum ScreenType prevScreen);
static void Task_StartScreenFadeIn(u8 taskId);
static void Task_StartScreenFadeOutAndExit(u8 taskId);
static void Task_ContinueScreenWaitForKeypress(u8 taskId);
static void Task_CharacterSelectWaitForKeypress(u8 taskId);
static void Task_StarterSelectWaitForKeypress(u8 taskId);
static void DrawMugshot(u32 characterId);
static void DrawCharacterSelectInfoText(void);
static void DrawCharacterSelectItem(void);
static void UpdateStarterPics(void);
static void FreeStarterPics(void);
static void CB2_StartNewRun(void);

EWRAM_DATA static u32 * sMapPreviewTilemapPtr = NULL;
EWRAM_DATA static MainCallback sExitCallback = NULL;
EWRAM_DATA static enum ScreenType sCurrentScreen = 0;
EWRAM_DATA static bool8 sLRButtonWindowDrawn = FALSE;
EWRAM_DATA static enum Character sChosenCharacterId = 0;
EWRAM_DATA static u8 sChosenStarter = 0;
EWRAM_DATA static u16 sMugshotSpriteId = 0;
EWRAM_DATA static u16 sCharacterItemSpriteId = 0;
EWRAM_DATA static u16 sStarterSpriteIds[3] = {0};
EWRAM_DATA static u16 sStarterShadowSpriteIds[3] = {0};

// code
static void MainCB2_StartScreen(void)
{
	RunTasks();
	AnimateSprites();
	BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
	UpdatePaletteFade();
}

static void VBlankCB_StartScreen(void)
{
	LoadOam();
	ProcessSpriteCopyRequests();
	TransferPlttBuffer();
}

void CB2_StartScreen(void)
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
            InitBgsFromTemplates(0, sStartScreenBgTemplates, ARRAY_COUNT(sStartScreenBgTemplates));
            SetBgTilemapBuffer(2, sMapPreviewTilemapPtr);
            gMain.state++;
            break;
        case 4:
            InitWindows(sStartScreenWinTemplates);
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
            sLRButtonWindowDrawn = FALSE;
            LoadMessageBoxAndBorderGfx();
            if (gSaveBlock1Ptr->currentFloor == 0)
                sCurrentScreen = SCREEN_CHARACTER_SELECT;
            else
                sCurrentScreen = SCREEN_CONTINUE;
            LoadScreenGfx(sCurrentScreen);
            gMain.state++;
            break;
        case 8:
            SetVBlankCallback(VBlankCB_StartScreen);
            CreateTask(Task_StartScreenFadeIn, 0);
            SetMainCallback2(MainCB2_StartScreen);
            break;
	}
}

static void ClearWindows(void)
{
    u32 i;
    for (i = 0; i < WINDOW_COUNT; ++i)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
        ClearWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_GFX);
        RemoveWindow(i);
    }
}

static void Task_StartScreenFadeOutAndExit(u8 taskId)
{
	if (!gPaletteFade.active)
	{
        SetMainCallback2(sExitCallback);
		Free(sMapPreviewTilemapPtr);
        sMapPreviewTilemapPtr = NULL;
        ClearWindows();
		FreeAllWindowBuffers();
		DestroyTask(taskId);
	}
}

static void Task_StartScreenFadeIn(u8 taskId)
{
	if (!gPaletteFade.active)
	{
        switch (sCurrentScreen)
        {
            case SCREEN_CONTINUE:
                gTasks[taskId].func = Task_ContinueScreenWaitForKeypress;
                break;
            default:
            case SCREEN_CHARACTER_SELECT:
                sCurrentScreen = SCREEN_CHARACTER_SELECT;
                gTasks[taskId].func = Task_CharacterSelectWaitForKeypress;
                break;
        }
	}
}

static void Task_ContinueScreenWaitForKeypress(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON)
	{
        PlaySE(SE_SELECT);
		BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sExitCallback = CB2_ContinueSavedGame;
		gTasks[taskId].func = Task_StartScreenFadeOutAndExit;
    }
    if (gMain.newKeys & B_BUTTON)
	{
        PlaySE(SE_SELECT);
        sExitCallback = CB2_InitTitleScreen;
		gTasks[taskId].func = Task_StartScreenFadeOutAndExit;
    }
    if (gMain.newKeys & (L_BUTTON | R_BUTTON))
    {
        PlaySE(SE_SELECT);
        LoadScreenGfx(SCREEN_CHARACTER_SELECT);
        gTasks[taskId].func = Task_CharacterSelectWaitForKeypress;
    }
}

static void Task_CharacterSelectWaitForKeypress(u8 taskId)
{
    if ((gMain.newKeys & (L_BUTTON | R_BUTTON)) && gSaveBlock1Ptr->currentFloor != 0)
    {
        PlaySE(SE_SELECT);
        LoadScreenGfx(SCREEN_CONTINUE);
        gTasks[taskId].func = Task_ContinueScreenWaitForKeypress;
    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        PlaySE(SE_SELECT);
        if (sChosenCharacterId == 0)
            sChosenCharacterId = CHARACTERS_COUNT - 1;
        else
            --sChosenCharacterId;
        DrawMugshot(sChosenCharacterId);
        DrawCharacterSelectInfoText();
        DrawCharacterSelectItem();
    }
    if (gMain.newKeys & DPAD_RIGHT)
    {
        PlaySE(SE_SELECT);
        ++sChosenCharacterId;
        if (sChosenCharacterId == CHARACTERS_COUNT)
            sChosenCharacterId = 0;
        DrawMugshot(sChosenCharacterId);
        DrawCharacterSelectInfoText();
        DrawCharacterSelectItem();
    }
    if (gMain.newKeys & A_BUTTON)
	{
        PlaySE(SE_SELECT);
        LoadScreenGfx(SCREEN_STARTER_SELECT);
        gTasks[taskId].func = Task_StarterSelectWaitForKeypress;
    }
    if (gMain.newKeys & B_BUTTON)
	{
        PlaySE(SE_SELECT);
        sExitCallback = CB2_InitTitleScreen;
		gTasks[taskId].func = Task_StartScreenFadeOutAndExit;
    }
}

static void Task_StarterSelectWaitForKeypress(u8 taskId)
{
    if (gMain.newKeys & DPAD_LEFT)
    {
        PlaySE(SE_SELECT);
        if (sChosenStarter == 0)
            sChosenStarter = 2;
        else
            --sChosenStarter;
        UpdateStarterPics();
    }
    if (gMain.newKeys & DPAD_RIGHT)
    {
        PlaySE(SE_SELECT);
        ++sChosenStarter;
        if (sChosenStarter > 2)
            sChosenStarter = 0;
        UpdateStarterPics();
    }
    if (gMain.newKeys & A_BUTTON)
	{
        PlaySE(SE_SELECT);
        sExitCallback = CB2_StartNewRun;
		gTasks[taskId].func = Task_StartScreenFadeOutAndExit;
    }
    if (gMain.newKeys & B_BUTTON)
	{
        PlaySE(SE_SELECT);
        FreeStarterPics();
        LoadScreenGfx(SCREEN_CHARACTER_SELECT);
        gTasks[taskId].func = Task_CharacterSelectWaitForKeypress;
    }

    // for (i = 0; i < 3; ++i) // clean up sprites after anim
    // {
    //     if (gSprites[sStarterSpriteIds[i]].callback == SpriteCallbackDummy)
    //     {
    //         StartSpriteAnim(&gSprites[sStarterSpriteIds[i]], 0);
    //         ResetSpriteAfterAnim(&gSprites[sStarterSpriteIds[i]]);
    //         FreeOamMatrix(gSprites[sStarterSpriteIds[i]].oam.matrixNum);
    //         gSprites[sStarterSpriteIds[i]].oam.matrixNum |= (gSprites[sStarterSpriteIds[i]].hFlip << 3);
    //         gSprites[sStarterSpriteIds[i]].oam.affineMode = ST_OAM_AFFINE_OFF;
    //         ResetSpriteAfterAnim(&gSprites[sStarterShadowSpriteIds[i]]);
    //         FreeOamMatrix(gSprites[sStarterShadowSpriteIds[i]].oam.matrixNum);
    //         gSprites[sStarterShadowSpriteIds[i]].oam.matrixNum |= (gSprites[sStarterShadowSpriteIds[i]].hFlip << 3);
    //         gSprites[sStarterShadowSpriteIds[i]].oam.affineMode = ST_OAM_AFFINE_OFF;
    //     }
    // }
}

static void LoadMapPreviewGfx(void)
{   
    struct MapPreview data = gMapPreviewData[GetCurrentTemplateRules()->previewId];
    DecompressAndCopyTileDataToVram(2, data.tiles, 0, 0, 0);
	LZDecompressWram(data.map, sMapPreviewTilemapPtr);
	LoadPalette(data.palette, BG_PLTT_ID(13), PLTT_SIZE_4BPP);
	Menu_LoadStdPalAt(BG_PLTT_ID(15));
}

// Draw windows for continue and character select screen.
static void DrawContinueAndSelectWindows(void)
{
    u32 i;

    // Load graphics for windows with border graphics and fill.
    for (i = WIN_MUGSHOT; i < WIN_MAIN_TEXT; ++i)
    {
        AddWindow(&sStartScreenWinTemplates[i]);
        FillWindowPixelBuffer(i, PIXEL_FILL(1));
        DrawStdWindowFrame(i, FALSE);
        PutWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_FULL);
    }
    // Load remaining windows.
    for (; i < WINDOW_COUNT; ++i)
    {
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
        AddWindow(&sStartScreenWinTemplates[i]);
        PutWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_FULL);
    }
}

static void DrawStarterSelectWindows(void)
{
    u32 i;

    // Load remaining windows.
    for (i = WIN_BUTTONS_RIGHT; i < WINDOW_COUNT; ++i)
    {
        ClearStdWindowAndFrame(i, TRUE);
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
        AddWindow(&sStartScreenWinTemplates[i]);
        PutWindowTilemap(i);
        CopyWindowToVram(i, COPYWIN_FULL);
    }
    sLRButtonWindowDrawn = FALSE;
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

static void DrawLRButtonWindow(void)
{
    u16 palette = RGB(8, 8, 8); // dark gray used in BG top/bottom
    AddWindow(&sStartScreenWinTemplates[WIN_BUTTONS_RIGHT]);
    FillWindowPixelBuffer(WIN_BUTTONS_RIGHT, PIXEL_FILL(0));
    PutWindowTilemap(WIN_BUTTONS_RIGHT);
    LoadPalette(&palette, BG_PLTT_ID(15) + 11, PLTT_SIZEOF(1));
    AddTextPrinterParameterized3(WIN_BUTTONS_RIGHT, FONT_SMALL, GetStringRightAlignXOffset(FONT_SMALL, sText_PressLR, 110), 0, sTextColor_Instructions, TEXT_SKIP_DRAW, sText_PressLR);
    CopyWindowToVram(WIN_BUTTONS_RIGHT, COPYWIN_FULL);
    sLRButtonWindowDrawn = TRUE;
}

static void DrawContinueScreenText(void)
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
    AddTextPrinterParameterized3(WIN_INFO, FONT_NORMAL, 2, 0, sTextColor_Name, TEXT_SKIP_DRAW, gCharacterInfos[gSaveBlock1Ptr->characterId].name);
    AddTextPrinterParameterized3(WIN_INFO, FONT_NORMAL, 2, 16, sTextColor_Info, TEXT_SKIP_DRAW, sText_Floor);
    AddTextPrinterParameterized3(WIN_INFO, FONT_NORMAL, 2, 32, sTextColor_Info, TEXT_SKIP_DRAW, sText_Gold);
    AddTextPrinterParameterized3(WIN_INFO, FONT_NORMAL, 2, 48, sTextColor_Info, TEXT_SKIP_DRAW, sText_Time);

    ConvertIntToDecimalStringN(strFloor, gSaveBlock1Ptr->currentFloor, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized3(WIN_INFO, FONT_NORMAL, GetStringRightAlignXOffset(FONT_NORMAL, strFloor, 126), 16, sTextColor_Info, TEXT_SKIP_DRAW, strFloor);
    
    ptr = strMoney;
    *ptr = CHAR_CURRENCY;
    ptr = ConvertIntToDecimalStringN(ptr + 1, GetMoney(&gSaveBlock1Ptr->money), STR_CONV_MODE_LEFT_ALIGN, 6);
    AddTextPrinterParameterized3(WIN_INFO, FONT_NORMAL, GetStringRightAlignXOffset(FONT_NORMAL, strMoney, 126), 32, sTextColor_Info, TEXT_SKIP_DRAW, strMoney);
    
    ptr = ConvertIntToDecimalStringN(strTime, gSaveBlock2Ptr->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
    *ptr = CHAR_COLON;
    ConvertIntToDecimalStringN(ptr + 1, gSaveBlock2Ptr->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    AddTextPrinterParameterized3(WIN_INFO, FONT_NORMAL, GetStringRightAlignXOffset(FONT_NORMAL, strTime, 126), 48, sTextColor_Info, TEXT_SKIP_DRAW, strTime);

    CopyWindowToVram(WIN_INFO, COPYWIN_FULL);

    // Load text into main window.
    AddTextPrinterParameterized3(WIN_MAIN_TEXT, FONT_NORMAL, 2, 2, sTextColor_Instructions, TEXT_SKIP_DRAW, sText_Continue);
    CopyWindowToVram(WIN_MAIN_TEXT, COPYWIN_FULL);

    // Load instructions into button window.
    AddTextPrinterParameterized3(WIN_BUTTONS_LEFT, FONT_SMALL, 2, 0, sTextColor_Instructions, TEXT_SKIP_DRAW, sText_PressA);
    CopyWindowToVram(WIN_BUTTONS_LEFT, COPYWIN_FULL);
}

static const u8 sText_StartNewRun[] = _("Start a new run?");
static const u8 sText_CharSelectPressA[] = _("{A_BUTTON} Select {DPAD_LEFTRIGHT} Change");

static void DrawCharacterSelectInfoText(void)
{
    u16 palette = gCharacterInfos[sChosenCharacterId].color;
    LoadPalette(&palette, BG_PLTT_ID(15) + 10, PLTT_SIZEOF(1));
    FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(1));
    AddTextPrinterParameterized3(WIN_INFO, FONT_NORMAL, 2, 0, sTextColor_Name, TEXT_SKIP_DRAW, gCharacterInfos[sChosenCharacterId].name);
    AddTextPrinterParameterized3(WIN_INFO, FONT_SMALL, 2, 14, sTextColor_Info, TEXT_SKIP_DRAW, gCharacterInfos[sChosenCharacterId].desc);
    CopyWindowToVram(WIN_INFO, COPYWIN_FULL);
}

static void DrawCharacterSelectText(void)
{
    // Load dynamic text colors.
    u16 palette = RGB(8, 8, 8); // dark gray used in BG top/bottom
    LoadPalette(&palette, BG_PLTT_ID(15) + 11, PLTT_SIZEOF(1));

    // Load text into stats window.
    DrawCharacterSelectInfoText();

    // Load text into main window.
    AddTextPrinterParameterized3(WIN_MAIN_TEXT, FONT_NORMAL, 2, 2, sTextColor_Instructions, TEXT_SKIP_DRAW, sText_StartNewRun);
    CopyWindowToVram(WIN_MAIN_TEXT, COPYWIN_FULL);

    // Load instructions into button window.
    AddTextPrinterParameterized3(WIN_BUTTONS_LEFT, FONT_SMALL, 2, 0, sTextColor_Instructions, TEXT_SKIP_DRAW, sText_CharSelectPressA);
    CopyWindowToVram(WIN_BUTTONS_LEFT, COPYWIN_FULL);
}

static const u8 sText_ChooseStarter[] = _("Choose your starter!");
static const u8 sText_StarterSelectPressA[] = _("{A_BUTTON} Select {DPAD_LEFTRIGHT} Change {B_BUTTON} Back");

static void DrawStarterSelectText(void)
{
    u16 palette = RGB(8, 8, 8); // dark gray used in BG top/bottom
    LoadPalette(&palette, BG_PLTT_ID(15) + 11, PLTT_SIZEOF(1));

    // Load text into main window.
    AddTextPrinterParameterized3(WIN_MAIN_TEXT, FONT_NORMAL, 2, 2, sTextColor_Instructions, TEXT_SKIP_DRAW, sText_ChooseStarter);
    CopyWindowToVram(WIN_MAIN_TEXT, COPYWIN_FULL);

    // Load instructions into button window.
    AddTextPrinterParameterized3(WIN_BUTTONS_LEFT, FONT_SMALL, 2, 0, sTextColor_Instructions, TEXT_SKIP_DRAW, sText_StarterSelectPressA);
    CopyWindowToVram(WIN_BUTTONS_LEFT, COPYWIN_FULL);
}

#define TAG_ITEM_ICON   0x300

static void DrawMugshot(u32 characterId)
{
    // Free data if there is already a mugshot drawn.
    if (sMugshotSpriteId != 0xFF)
    {
        DestroySprite(&gSprites[sMugshotSpriteId]);
        FreeSpriteTilesByTag(gSprites[sMugshotSpriteId].template->tileTag);
        FreeSpritePaletteByTag(gCharacterInfos[characterId].mugshotPal.tag);
    }
    // Draw the new mugshot.
    LoadSpritePalette(&gCharacterInfos[characterId].mugshotPal);
    LoadCompressedSpriteSheet(&gCharacterInfos[characterId].mugshotSheet);
    sMugshotSpriteId = CreateSprite(gCharacterInfos[characterId].mugshotTemplate, 48, 80, 0);
}

static void DrawCharacterSelectItem(void)
{
    // Free data if there is already an item drawn.
    if (sCharacterItemSpriteId != 0xFF)
        DestroySprite(&gSprites[sCharacterItemSpriteId]);
    FreeSpriteTilesByTag(TAG_ITEM_ICON);
    FreeSpritePaletteByTag(TAG_ITEM_ICON);

    sCharacterItemSpriteId = AddItemIconSprite(TAG_ITEM_ICON, TAG_ITEM_ICON, gCharacterInfos[sChosenCharacterId].item);
    gSprites[sCharacterItemSpriteId].x2 = 216;
    gSprites[sCharacterItemSpriteId].y2 = 104;
}

static void DrawStarterPics(void)
{
    u32 i, palette;

    // Load black palette for shadows.
    palette = RGB(8, 8, 8); // dark gray used in BG top/bottom, kind of jank to have here
    for (i = 0; i < 15; ++i)
        LoadPalette(&palette, OBJ_PLTT_ID(12) + i + 1, PLTT_SIZEOF(1));

    for (i = 0; i < 3; ++i)
    {
        // Draw sprite.
        sStarterSpriteIds[i] = CreateMonPicSprite(gCharacterInfos[sChosenCharacterId].starters[i], FALSE, 0xFE, TRUE,
                                                  56 + 64*i, 80, 13 + i, TAG_NONE);
        
        // Draw shadow.
        sStarterShadowSpriteIds[i] = CreateCopySpriteAt(&gSprites[sStarterSpriteIds[i]], 57 + 64*i, 81, 0xFF);
        gSprites[sStarterShadowSpriteIds[i]].oam.paletteNum = 12;
    }
}

// Refreshes palettes and animation data for starter pic sprites.
static void UpdateStarterPics(void)
{
    u32 i;
    for (i = 0; i < 3; ++i)
        SetGrayscaleOrOriginalPalette(16 + 13 + i, i == sChosenStarter);
    PlayCry_Normal(gCharacterInfos[sChosenCharacterId].starters[sChosenStarter], 0);
    // DoMonFrontSpriteAnimation(&gSprites[sStarterSpriteIds[sChosenStarter]], gCharacterInfos[sChosenCharacterId].starters[sChosenStarter], FALSE, 0);
    // DoMonFrontSpriteAnimation(&gSprites[sStarterShadowSpriteIds[sChosenStarter]], gCharacterInfos[sChosenCharacterId].starters[sChosenStarter], FALSE, 0);
}

static void FreeStarterPics(void)
{
    u32 i;
    for (i = 0; i < 3; ++i)
        FreeAndDestroyMonPicSprite(sStarterSpriteIds[i]);
}

static void LoadScreenGfx(enum ScreenType screenType)
{
    // Clear graphics data
    sMugshotSpriteId = 0xFF;
    sCharacterItemSpriteId = 0xFF;
    ResetSpriteData();
    FreeAllSpritePalettes();

    if (!sLRButtonWindowDrawn)
        DrawLRButtonWindow();

    sCurrentScreen = screenType;
    switch (screenType)
    {
        case SCREEN_CONTINUE:
            DrawMugshot(gSaveBlock1Ptr->characterId);
            DrawContinueAndSelectWindows();
            DrawContinueScreenText();
            break;
        default:
        case SCREEN_CHARACTER_SELECT:
            DrawMugshot(sChosenCharacterId);
            DrawContinueAndSelectWindows();
            DrawCharacterSelectText();
            DrawCharacterSelectItem();
            break;
        case SCREEN_STARTER_SELECT:
            DrawStarterPics();
            UpdateStarterPics();
            DrawStarterSelectWindows();
            DrawStarterSelectText();
            break;
    }
}

// Set the starting seed for a new run (from SeedRNGWithRTC, but custom seeds may be implemented)
static void SeedNewRunRNG(void)
{
    #define BCD8(x) ((((x) >> 4) & 0xF) * 10 + ((x) & 0xF))
    u32 seconds;
    struct SiiRtcInfo rtc;
    RtcGetInfo(&rtc);
    seconds =
        ((HOURS_PER_DAY * RtcGetDayCount(&rtc) + BCD8(rtc.hour))
        * MINUTES_PER_HOUR + BCD8(rtc.minute))
        * SECONDS_PER_MINUTE + BCD8(rtc.second);
    gFloorplan.nextFloorSeed = seconds;
    #undef BCD8
}

// Clears run-specific save data to start a new run or end a run.
void ResetRunSaveData(void)
{
    gSaveBlock1Ptr->characterId = 0;
    gSaveBlock1Ptr->currentFloor = 0;
    gSaveBlock1Ptr->currentRoom = STARTING_ROOM;
    gSaveBlock1Ptr->currentTemplateType = 0;
}

// Sets flags for an entirely new save.
static void NewSaveInitData(void)
{
    FlagSet(FLAG_SYS_POKEMON_GET);
    FlagSet(FLAG_SYS_POKEDEX_GET);
    FlagSet(FLAG_RECEIVED_POKEDEX_FROM_BIRCH);
    FlagSet(FLAG_RECEIVED_RUNNING_SHOES);
    FlagSet(FLAG_SYS_B_DASH);
    EnableNationalPokedex();
}

static void NewRunInitData(void)
{
    ZeroPlayerPartyMons();
    ZeroEnemyPartyMons();
    gPlayerPartyCount = 0;
    SetMoney(&gSaveBlock1Ptr->money, 3000);
    ClearBag();
    PlayTimeCounter_Reset();

    gSaveBlock1Ptr->characterId = sChosenCharacterId;
    StringCopy(gSaveBlock2Ptr->playerName, gCharacterInfos[sChosenCharacterId].name);
    CreateMon(&gPlayerParty[0], gCharacterInfos[sChosenCharacterId].starters[sChosenStarter], 10, USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);
    AddBagItem(gCharacterInfos[gSaveBlock1Ptr->characterId].item, 1);
}

static void CB2_StartNewRun(void)
{
    StopMapMusic();
    ResetInitialPlayerAvatarState();
    PlayTimeCounter_Start();
    ScriptContext_Init();
    UnlockPlayerFieldControls();

    // TODO: Proper new game check
    if (!FlagGet(FLAG_RECEIVED_RUNNING_SHOES))
        NewSaveInitData();

    SeedNewRunRNG();
    ResetRunSaveData();
    NewRunInitData();
    GoToNextFloor();
}
