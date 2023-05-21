#include "global.h"
#include "bg.h"
#include "sprite.h"
#include "main.h"
#include "battle.h"
#include "decompress.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_effect.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "main_menu.h"
#include "malloc.h"
#include "menu.h"
#include "new_game_sequence.h"
#include "naming_screen.h"
#include "overworld.h"
#include "random.h"
#include "palette.h"
#include "save.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "string_util.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "util.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"

EWRAM_DATA static bool32 sNewSave = 0;
EWRAM_DATA static TaskFunc sSequenceStartTask = {0};

// const rom data
static const u8 sText_ChooseYourCharacter[] = _("Who do you want to play as?");
static const u8 sText_ChooseSaveName[] = _("This is a new save!\nWhat do you want to name it?");
static const u8 sText_AreYouSureSaveName[] = _("{PLAYER}? Are you sure?");
static const u8 sText_HaveFun[] = _("Have fun,\n{PLAYER}!");

static const u8 sText_Brendan[] = _("Brendan");
static const u8 sText_May[] = _("May");
static const struct MenuAction sMenuActions_Characters[] = {
    {sText_Brendan, NULL},
    {sText_May, NULL}
};

static const u16 sNewGameSequenceBgPals[][16] = {
    INCBIN_U16("graphics/birch_speech/bg0.gbapal"),
    INCBIN_U16("graphics/birch_speech/bg1.gbapal")
};

// templates
enum Windows
{
	WIN_MSG,
    WIN_CHARACTERS,
    WIN_UNK,
	WINDOW_COUNT,
};

static const struct WindowTemplate sNewGameSequenceWinTemplates[] =
{
    [WIN_MSG] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1
    },
    [WIN_CHARACTERS] = {
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 6,
        .width = 6,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x6D
    },
    [WIN_UNK] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 2,
        .width = 9,
        .height = 10,
        .paletteNum = 15,
        .baseBlock = 0x85
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sNewGameSequenceBgTemplate = {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
};

// functions
static void CleanWindows(void);
static void CommitWindows(void);
static void ClearTasksAndGraphicalStructs(void);
static void ClearVramOamPlttRegs(void);
static void ClearWindow(u8 windowId);
static void ShowCharacterMenu(void);
static void ShowDialogueWindow(u8 windowId, u8 copyToVram);
static void CB2_NewGameSequence(void);
static void Task_FadeIn(u8 taskId);
static void Task_ChooseCharacter(u8 taskId);
static void Task_WaitToShowCharacterMenu(u8 taskId);
static void Task_SlideOutOldCharacterSprite(u8 taskId);
static void Task_SlideInNewCharacterSprite(u8 taskId);
static void Task_ChooseCharacterInput(u8 taskId);
static void Task_ChooseSaveName(u8 taskId);
static void Task_WaitForChooseSaveNameToPrint(u8 taskId);
static void Task_WaitPressBeforeNameChoice(u8 taskId);
static void Task_StartNamingScreen(u8 taskId);
static void Task_AreYouSureSaveName(u8 taskId);
static void Task_CreateNameYesNo(u8 taskId);
static void Task_ProcessNameYesNoMenu(u8 taskId);
static void Task_HaveFun(u8 taskId);
static void Task_WaitForTextAndExit(u8 taskId);
static void StartFadeInTarget1OutTarget2(u8 taskId, u8 delay);
static void Task_FadeInTarget1OutTarget2(u8 taskId);
static void StartFadeOutTarget1InTarget2(u8 taskId, u8 delay);
static void Task_FadeOutTarget1InTarget2(u8 taskId);


// code
static void MainCB2_NewGameSequence(void)
{
	RunTasks();
	AnimateSprites();
	BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
	UpdatePaletteFade();
}

static void VBlankCB_NewGameSequence(void)
{
	LoadOam();
	ProcessSpriteCopyRequests();
	TransferPlttBuffer();
}

void InitNewGameSequence(u32 state)
{
    SetMainCallback2(CB2_NewGameSequence);
    switch (state)
    {
        case FROM_NAME_SCREEN:
            sSequenceStartTask = Task_AreYouSureSaveName;
            break;
        case NEW_RUN:
            sSequenceStartTask = Task_ChooseCharacter;
            sNewSave = FALSE;
            break;
        default:
        case NEW_SAVE:
            sSequenceStartTask = Task_ChooseCharacter;
            sNewSave = TRUE;
            break;
    }
}

#define tPlayerSpriteId data[2]
#define tIsDoneFadingSprites data[5]
#define tCharacter data[6]
#define tBrendanSpriteId data[10]
#define tMaySpriteId data[11]


static void LoadNewGameSequenceGfx(void)
{
    // Load standard palettes.
    LoadPalette(sNewGameSequenceBgPals[0], BG_PLTT_ID(0), PLTT_SIZE_4BPP);
	ListMenuLoadStdPalAt(0xC0, 1);
	Menu_LoadStdPalAt(0xF0);

    // Load main menu frame tiles.
    LoadBgTiles(0, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, 0xF3);
    LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
}

static void SpriteCB_Null(struct Sprite* sprite) {}
static void LoadCharacterSprites(u8 taskId)
{
    u8 brendanSpriteId;
    u8 maySpriteId;
    brendanSpriteId = CreateTrainerSprite(FacilityClassToPicIndex(FACILITY_CLASS_BRENDAN), 180, 60, 0, &gDecompressionBuffer[0]);
    gSprites[brendanSpriteId].callback = SpriteCB_Null;
    gSprites[brendanSpriteId].invisible = FALSE;
    gSprites[brendanSpriteId].oam.priority = 0;
    gTasks[taskId].tPlayerSpriteId = brendanSpriteId;
    gTasks[taskId].tBrendanSpriteId = brendanSpriteId;
    maySpriteId = CreateTrainerSprite(FacilityClassToPicIndex(FACILITY_CLASS_MAY), 180, 60, 0, &gDecompressionBuffer[0x800]);
    gSprites[maySpriteId].callback = SpriteCB_Null;
    gSprites[maySpriteId].invisible = TRUE;
    gSprites[maySpriteId].oam.priority = 0;
    gTasks[taskId].tMaySpriteId = maySpriteId;
}

static void CB2_NewGameSequence(void)
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
            InitBgFromTemplate(&sNewGameSequenceBgTemplate);
            gMain.state++;
            break;
        case 3:
            // sMapScreenTilemapPtr = AllocZeroed(BG_SCREEN_SIZE);
            ResetBgsAndClearDma3BusyFlags(0);
            // InitBgsFromTemplates(0, sMapScreenBgTemplates, 3);
            InitBgFromTemplate(&sNewGameSequenceBgTemplate);
            // SetBgTilemapBuffer(2, sMapScreenTilemapPtr);
            gMain.state++;
            break;
        case 4:
            LoadNewGameSequenceGfx();
            gMain.state++;
            break;
        case 5:
            if (IsDma3ManagerBusyWithBgCopy() != TRUE)
            {
                ShowBg(0);
                ShowBg(1);
                ShowBg(2);
                // CopyBgTilemapBufferToVram(2);
                gMain.state++;
            }
            break;
        case 6:
            InitWindows(sNewGameSequenceWinTemplates);
            DeactivateAllTextPrinters();
            gMain.state++;
            break;
        case 7:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            gMain.state++;
            break;
        case 8:
            SetVBlankCallback(VBlankCB_NewGameSequence);
            CreateTask(Task_FadeIn, 0);
            SetMainCallback2(MainCB2_NewGameSequence);
            break;
	}
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

static void Task_FadeIn(u8 taskId)
{
	if (!gPaletteFade.active)
	{
        ResetPaletteFade();
        LoadMessageBoxGfx(0, 0xFC, BG_PLTT_ID(15));
        ShowDialogueWindow(WIN_MSG, TRUE);
        ClearWindow(WIN_MSG);
        LoadCharacterSprites(taskId);
        if (!IsBGMPlaying())
            PlayBGM(MUS_DP_GAME_CORNER);
		gTasks[taskId].func = sSequenceStartTask;
	}
}

static void ShowDialogueWindow(u8 windowId, u8 copyToVram)
{
    CallWindowFunction(windowId, CreateDialogueWindowBorder);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void ClearWindow(u8 windowId)
{
    u8 bgColor = GetFontAttribute(FONT_NORMAL, FONTATTR_COLOR_BACKGROUND);
    u8 maxCharWidth = GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_WIDTH);
    u8 maxCharHeight = GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_HEIGHT);
    u8 winWidth = GetWindowAttribute(windowId, WINDOW_WIDTH);
    u8 winHeight = GetWindowAttribute(windowId, WINDOW_HEIGHT);

    FillWindowPixelRect(windowId, bgColor, 0, 0, maxCharWidth * winWidth, maxCharHeight * winHeight);
    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void ShowCharacterMenu(void)
{
    DrawMainMenuWindowBorder(&sNewGameSequenceWinTemplates[WIN_CHARACTERS], 0xF3);
    FillWindowPixelBuffer(WIN_CHARACTERS, PIXEL_FILL(1));
    PrintMenuTable(WIN_CHARACTERS, ARRAY_COUNT(sMenuActions_Characters), sMenuActions_Characters);
    InitMenuInUpperLeftCornerNormal(WIN_CHARACTERS, ARRAY_COUNT(sMenuActions_Characters), 0);
    PutWindowTilemap(WIN_CHARACTERS);
    CopyWindowToVram(WIN_CHARACTERS, COPYWIN_FULL);
}

static void Task_ChooseCharacter(u8 taskId)
{
    ClearWindow(WIN_MSG);
    StringExpandPlaceholders(gStringVar4, sText_ChooseYourCharacter);
    AddTextPrinterForMessage(TRUE);
    gTasks[taskId].func = Task_WaitToShowCharacterMenu;
}

static void Task_WaitToShowCharacterMenu(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        ShowCharacterMenu();
        gTasks[taskId].func = Task_ChooseCharacterInput;
    }
}

static void Task_SlideOutOldCharacterSprite(u8 taskId)
{
    u8 spriteId = gTasks[taskId].tPlayerSpriteId;
    if (gTasks[taskId].tIsDoneFadingSprites == 0)
    {
        gSprites[spriteId].x += 4;
    }
    else
    {
        gSprites[spriteId].invisible = TRUE;
        if (gTasks[taskId].tCharacter != MALE)
            spriteId = gTasks[taskId].tMaySpriteId;
        else
            spriteId = gTasks[taskId].tBrendanSpriteId;
        gSprites[spriteId].x = DISPLAY_WIDTH;
        gSprites[spriteId].y = 60;
        gSprites[spriteId].invisible = FALSE;
        gTasks[taskId].tPlayerSpriteId = spriteId;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        StartFadeInTarget1OutTarget2(taskId, 0);
        gTasks[taskId].func = Task_SlideInNewCharacterSprite;
    }
}

static void Task_SlideInNewCharacterSprite(u8 taskId)
{
    u8 spriteId = gTasks[taskId].tPlayerSpriteId;

    if (gSprites[spriteId].x > 180)
    {
        gSprites[spriteId].x -= 4;
    }
    else
    {
        gSprites[spriteId].x = 180;
        if (gTasks[taskId].tIsDoneFadingSprites)
        {
            gSprites[spriteId].oam.objMode = ST_OAM_OBJ_NORMAL;
            gTasks[taskId].func = Task_ChooseCharacterInput;
        }
    }
}

enum {
    BRENDAN,
    MAY,
};

static void ClearCharacterWindowTilemap(u8 bg, u8 x, u8 y, u8 width, u8 height, u8 unused)
{
    FillBgTilemapBufferRect(bg, 0, x + 255, y + 255, width + 2, height + 2, 2);
}

static void ClearCharacterWindow(u8 windowId, bool8 copyToVram)
{
    CallWindowFunction(windowId, ClearCharacterWindowTilemap);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void Task_ChooseCharacterInput(u8 taskId)
{
    int selected = Menu_ProcessInputNoWrap();
    int cursorPos;

    // Check selection.
    switch (selected)
    {
        case BRENDAN:
            PlaySE(SE_SELECT);
            gSaveBlock2Ptr->playerGender = MALE;
            ClearCharacterWindow(WIN_CHARACTERS, TRUE);
            if (sNewSave)
                gTasks[taskId].func = Task_ChooseSaveName;
            else
                gTasks[taskId].func = Task_HaveFun;
            break;
        case MAY:
            PlaySE(SE_SELECT);
            gSaveBlock2Ptr->playerGender = FEMALE;
            ClearCharacterWindow(WIN_CHARACTERS, TRUE);
            if (sNewSave)
                gTasks[taskId].func = Task_ChooseSaveName;
            else
                gTasks[taskId].func = Task_HaveFun;
            break;
    }

    // Check cursor change.
    cursorPos = Menu_GetCursorPos();
    if (cursorPos != gTasks[taskId].tCharacter)
    {
        gTasks[taskId].tCharacter = cursorPos;
        gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        StartFadeOutTarget1InTarget2(taskId, 0);
        gTasks[taskId].func = Task_SlideOutOldCharacterSprite;
    }
}

static void Task_ChooseSaveName(u8 taskId)
{
    ClearWindow(WIN_MSG);
    StringExpandPlaceholders(gStringVar4, sText_ChooseSaveName);
    AddTextPrinterForMessage(TRUE);
    gTasks[taskId].func = Task_WaitForChooseSaveNameToPrint;
}

static void Task_WaitForChooseSaveNameToPrint(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active() && ((JOY_NEW(A_BUTTON)) || (JOY_NEW(B_BUTTON))))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_StartNamingScreen;
    }
}

static void CB2_ReturnFromNamingScreen(void)
{
    InitNewGameSequence(FROM_NAME_SCREEN);
}

static void Task_StartNamingScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        NewGameBirchSpeech_SetDefaultPlayerName(0);
        DestroyTask(taskId);
        DoNamingScreen(NAMING_SCREEN_PLAYER, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnFromNamingScreen);
    }
}

static void Task_AreYouSureSaveName(u8 taskId)
{
    ClearWindow(WIN_MSG);
    StringExpandPlaceholders(gStringVar4, sText_AreYouSureSaveName);
    AddTextPrinterForMessage(TRUE);
    gTasks[taskId].func = Task_CreateNameYesNo;
}

static void Task_CreateNameYesNo(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        CreateYesNoMenuParameterized(2, 3, 0xF3, 0xDF, 2, 15);
        gTasks[taskId].func = Task_ProcessNameYesNoMenu;
    }
}

static void Task_ProcessNameYesNoMenu(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0:
            PlaySE(SE_SELECT);
            gSprites[gTasks[taskId].tPlayerSpriteId].oam.objMode = ST_OAM_OBJ_BLEND;
            StartFadeOutTarget1InTarget2(taskId, 2);
            gTasks[taskId].func = Task_HaveFun;
            break;
        case MENU_B_PRESSED:
        case 1:
            PlaySE(SE_SELECT);
            gTasks[taskId].func = Task_ChooseCharacter;
    }
}

static void Task_HaveFun(u8 taskId)
{
    ClearWindow(WIN_MSG);
    StringExpandPlaceholders(gStringVar4, sText_HaveFun);
    AddTextPrinterForMessage(TRUE);
    gTasks[taskId].func = Task_WaitForTextAndExit;
}

static void Task_WaitForTextAndExit(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active() && ((JOY_NEW(A_BUTTON)) || (JOY_NEW(B_BUTTON))))
    {
        FreeAllWindowBuffers();
        ResetAllPicSprites();
        if (sNewSave)
        {
            SetMainCallback2(CB2_NewGame);
        }
        else
        {
            SetMainCallback2(CB2_ContinueStartNewRun);
        }
        DestroyTask(taskId);
    }
}

#undef tPlayerSpriteId
#undef tCharacter
#undef tBrendanSpriteId
#undef tMaySpriteId

#define tMainTask data[0]
#define tAlphaCoeff1 data[1]
#define tAlphaCoeff2 data[2]
#define tDelay data[3]
#define tDelayTimer data[4]

static void Task_FadeInTarget1OutTarget2(u8 taskId)
{
    int alphaCoeff2;

    if (gTasks[taskId].tAlphaCoeff1 == 16)
    {
        gTasks[gTasks[taskId].tMainTask].tIsDoneFadingSprites = TRUE;
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tAlphaCoeff1++;
        gTasks[taskId].tAlphaCoeff2--;
        alphaCoeff2 = gTasks[taskId].tAlphaCoeff2 << 8;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskId].tAlphaCoeff1 + alphaCoeff2);
    }
}

static void StartFadeInTarget1OutTarget2(u8 taskId, u8 delay)
{
    u8 taskId2;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tIsDoneFadingSprites = 0;
    taskId2 = CreateTask(Task_FadeInTarget1OutTarget2, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tAlphaCoeff1 = 0;
    gTasks[taskId2].tAlphaCoeff2 = 16;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

static void Task_FadeOutTarget1InTarget2(u8 taskId)
{
    int alphaCoeff2;

    if (gTasks[taskId].tAlphaCoeff1 == 0)
    {
        gTasks[gTasks[taskId].tMainTask].tIsDoneFadingSprites = TRUE;
        DestroyTask(taskId);
    }
    else if (gTasks[taskId].tDelayTimer)
    {
        gTasks[taskId].tDelayTimer--;
    }
    else
    {
        gTasks[taskId].tDelayTimer = gTasks[taskId].tDelay;
        gTasks[taskId].tAlphaCoeff1--;
        gTasks[taskId].tAlphaCoeff2++;
        alphaCoeff2 = gTasks[taskId].tAlphaCoeff2 << 8;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskId].tAlphaCoeff1 + alphaCoeff2);
    }
}

static void StartFadeOutTarget1InTarget2(u8 taskId, u8 delay)
{
    u8 taskId2;

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_OBJ);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].tIsDoneFadingSprites = 0;
    taskId2 = CreateTask(Task_FadeOutTarget1InTarget2, 0);
    gTasks[taskId2].tMainTask = taskId;
    gTasks[taskId2].tAlphaCoeff1 = 16;
    gTasks[taskId2].tAlphaCoeff2 = 0;
    gTasks[taskId2].tDelay = delay;
    gTasks[taskId2].tDelayTimer = delay;
}

#undef tMainTask
#undef tAlphaCoeff1
#undef tAlphaCoeff2
#undef tDelay
#undef tDelayTimer

#undef tIsDoneFadingSprites
