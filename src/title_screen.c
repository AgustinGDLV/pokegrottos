#include "global.h"
#include "battle.h"
#include "bg.h"
#include "title_screen.h"
#include "sprite.h"
#include "gba/m4a_internal.h"
#include "clear_save_data_menu.h"
#include "decompress.h"
#include "event_data.h"
#include "intro.h"
#include "m4a.h"
#include "main.h"
#include "main_menu.h"
#include "malloc.h"
#include "menu.h"
#include "palette.h"
#include "reset_rtc_screen.h"
#include "berry_fix_program.h"
#include "sound.h"
#include "sprite.h"
#include "start_screen.h"
#include "task.h"
#include "scanline_effect.h"
#include "gpu_regs.h"
#include "trig.h"
#include "graphics.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define CLEAR_SAVE_BUTTON_COMBO (B_BUTTON | SELECT_BUTTON | DPAD_UP)
#define RESET_RTC_BUTTON_COMBO (B_BUTTON | SELECT_BUTTON | DPAD_LEFT)
#define BERRY_UPDATE_BUTTON_COMBO (B_BUTTON | SELECT_BUTTON)
#define A_B_START_SELECT (A_BUTTON | B_BUTTON | START_BUTTON | SELECT_BUTTON)

// const rom data
static const struct BgTemplate sTitleScreenBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    { // Logo
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 14,
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
    { // Environment
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 21,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

// graphics data
static const u32 sTitleForestGfx[] = INCBIN_U32("graphics/title_screen/title_bg.4bpp.lz");
static const u32 sTitleForestTilemap[] = INCBIN_U32("graphics/title_screen/title_bg.bin.lz");
static const u16 sTitleForestPal[] = INCBIN_U16("graphics/title_screen/title_bg.gbapal");

static const u32 sTitleLogoGfx[] = INCBIN_U32("graphics/title_screen/title_logo.4bpp.lz");
static const u32 sTitleLogoTilemap[] = INCBIN_U32("graphics/title_screen/title_logo.bin.lz");
static const u16 sTitleLogoPal[] = INCBIN_U16("graphics/title_screen/title_logo.gbapal");

static const u32 sTitleContinueGfx[] = INCBIN_U32("graphics/title_screen/title_continue.4bpp.lz");
static const u32 sTitleContinueTilemap[] = INCBIN_U32("graphics/title_screen/title_continue.bin.lz");

// ewram data
EWRAM_DATA static u32 *sTitleForestTilemapPtr = NULL;
EWRAM_DATA static u32 *sTitleLogoTilemapPtr = NULL;
EWRAM_DATA static u32 *sTitleContinueTilemapPtr = NULL;

// forward declarations
static void MainCB2_TitleScreen(void);
static void VBlankCB2_TitleScreen(void);
static void Task_OpenTitleScreen(u8 taskId);
static void Task_TitleScreenWaitForKeypress(u8 taskId);
static void CB2_GoToMainMenu(void);
static void CB2_GoToClearSaveDataScreen(void);
static void CB2_GoToResetRtcScreen(void);
static void CB2_GoToBerryFixScreen(void);
static void Task_UpdateContinueText(u8 taskId);

// UI functions
static void MainCB2_TitleScreen(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB2_TitleScreen(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_InitTitleScreen(void)
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
            sTitleForestTilemapPtr = AllocZeroed(BG_SCREEN_SIZE);
            sTitleLogoTilemapPtr = AllocZeroed(BG_SCREEN_SIZE);
            sTitleContinueTilemapPtr = AllocZeroed(BG_SCREEN_SIZE);

            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sTitleScreenBgTemplates, ARRAY_COUNT(sTitleScreenBgTemplates));

            SetBgTilemapBuffer(1, sTitleContinueTilemapPtr);
            SetBgTilemapBuffer(2, sTitleLogoTilemapPtr);
            SetBgTilemapBuffer(3, sTitleForestTilemapPtr);
            gMain.state++;
            break;
        case 4:
            DecompressAndCopyTileDataToVram(1, sTitleContinueGfx, 0, 0, 0);
            LZDecompressWram(sTitleContinueTilemap, sTitleContinueTilemapPtr);
            
            DecompressAndCopyTileDataToVram(2, sTitleLogoGfx, 0, 0, 0);
            LZDecompressWram(sTitleLogoTilemap, sTitleLogoTilemapPtr);
            LoadPalette(sTitleLogoPal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);

            DecompressAndCopyTileDataToVram(3, sTitleForestGfx, 0, 0, 0);
            LZDecompressWram(sTitleForestTilemap, sTitleForestTilemapPtr);
            LoadPalette(sTitleForestPal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);

            Menu_LoadStdPalAt(BG_PLTT_ID(15));
            gMain.state++;
            break;
        case 5:
            if (IsDma3ManagerBusyWithBgCopy() != TRUE)
            {
                HideBg(0);
                ShowBg(1);
                ShowBg(2);
                ShowBg(3);

                CopyBgTilemapBufferToVram(1);
                CopyBgTilemapBufferToVram(2);
                CopyBgTilemapBufferToVram(3);
                gMain.state++;
            }
            break;
        case 6:
            PlayBGM(MUS_TITLE);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            SetVBlankCallback(VBlankCB2_TitleScreen);
            CreateTask(Task_OpenTitleScreen, 0);
            SetMainCallback2(MainCB2_TitleScreen);
            break;
    }
}

static void Task_OpenTitleScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_TitleScreenWaitForKeypress;
        CreateTask(Task_UpdateContinueText, 0);
    }
}

static void Task_TitleScreenWaitForKeypress(u8 taskId)
{
    ChangeBgX(3, 128, BG_COORD_ADD);
    if (JOY_NEW(A_BUTTON) || JOY_NEW(START_BUTTON))
    {
        FadeOutBGM(4);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        SetMainCallback2(CB2_GoToMainMenu);
    }
    else if (JOY_HELD(CLEAR_SAVE_BUTTON_COMBO) == CLEAR_SAVE_BUTTON_COMBO)
    {
        SetMainCallback2(CB2_GoToClearSaveDataScreen);
    }
    else if (JOY_HELD(RESET_RTC_BUTTON_COMBO) == RESET_RTC_BUTTON_COMBO
      && CanResetRTC() == TRUE)
    {
        FadeOutBGM(4);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        SetMainCallback2(CB2_GoToResetRtcScreen);
    }
    else if (JOY_HELD(BERRY_UPDATE_BUTTON_COMBO) == BERRY_UPDATE_BUTTON_COMBO)
    {
        FadeOutBGM(4);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        SetMainCallback2(CB2_GoToBerryFixScreen);
    }
}

static void CB2_GoToMainMenu(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_StartScreen);
}

static void CB2_GoToClearSaveDataScreen(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitClearSaveDataScreen);
}

static void CB2_GoToResetRtcScreen(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitResetRtcScreen);
}

static void CB2_GoToBerryFixScreen(void)
{
    if (!UpdatePaletteFade())
    {
        m4aMPlayAllStop();
        SetMainCallback2(CB2_InitBerryFixProgram);
    }
}

static void Task_UpdateContinueText(u8 taskId)
{
    if (++gTasks[taskId].data[0] < 30)
    {
        ShowBg(1);
    }
    else if (gTasks[taskId].data[0] < 60)
    {
        HideBg(1);
    }
    else
    {
        gTasks[taskId].data[0] = 0;
    }
}
