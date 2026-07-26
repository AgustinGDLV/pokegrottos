#include "global.h"
#include "battle.h"
#include "bg.h"
#include "title_screen.h"
#include "sprite.h"
#include "gba/m4a_internal.h"
#include "clear_save_data_menu.h"
#include "decompress.h"
#include "deck_battle.h"
#include "deck_battle_interface.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "global.fieldmap.h"
#include "intro.h"
#include "item.h"
#include "m4a.h"
#include "main.h"
#include "main_menu.h"
#include "malloc.h"
#include "map_gen.h"
#include "map_preview.h"
#include "menu.h"
#include "naming_screen.h"
#include "overworld.h"
#include "palette.h"
#include "play_time.h"
#include "pokemon.h"
#include "reset_rtc_screen.h"
#include "berry_fix_program.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "start_screen.h"
#include "string.h"
#include "string_util.h"
#include "task.h"
#include "trail_map.h"
#include "gpu_regs.h"
#include "trig.h"
#include "graphics.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/flags.h"

#define CLEAR_SAVE_BUTTON_COMBO (B_BUTTON | SELECT_BUTTON | DPAD_UP)
#define RESET_RTC_BUTTON_COMBO (B_BUTTON | SELECT_BUTTON | DPAD_LEFT)
#define BERRY_UPDATE_BUTTON_COMBO (B_BUTTON | SELECT_BUTTON)
#define A_B_START_SELECT (A_BUTTON | B_BUTTON | START_BUTTON | SELECT_BUTTON)

// const rom data
static const struct BgTemplate sTrailMapBgTemplates[] =
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
static const u32 sTrailMapGfx[] = INCBIN_U32("graphics/trail_map/map_tiles.4bpp.lz");
static const u32 sTrailMapTilemap[] = INCBIN_U32("graphics/trail_map/map_tiles.bin.lz");
static const u16 sTrailMapPal[] = INCBIN_U16("graphics/trail_map/map_tiles.gbapal");

// ewram data
EWRAM_DATA static u32 *sTrailMapTilemapPtr = NULL;

// forward declarations
static void MainCB2_TrailMap(void);
static void VBlankCB2_TrailMap(void);
static void Task_OpenTrailMap(u8 taskId);
static void Task_TrailMapWaitForKeypress(u8 taskId);
static void Task_FadeOutToGame(u8 taskId);

// UI functions
static void MainCB2_TrailMap(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB2_TrailMap(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void GoToTrailMap(void)
{
    SetMainCallback2(CB2_InitTrailMap);
}

void CB2_InitTrailMap(void)
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
            sTrailMapTilemapPtr = AllocZeroed(BG_SCREEN_SIZE);

            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sTrailMapBgTemplates, ARRAY_COUNT(sTrailMapBgTemplates));

            SetBgTilemapBuffer(3, sTrailMapTilemapPtr);
            gMain.state++;
            break;
        case 4:
            DecompressAndCopyTileDataToVram(3, sTrailMapGfx, 0, 0, 0);
            LZDecompressWram(sTrailMapTilemap, sTrailMapTilemapPtr);
            LoadPalette(sTrailMapPal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);

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
            SetVBlankCallback(VBlankCB2_TrailMap);
            CreateTask(Task_OpenTrailMap, 0);
            SetMainCallback2(MainCB2_TrailMap);
            break;
    }
}

static void Task_OpenTrailMap(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_TrailMapWaitForKeypress;
    }
}

static void Task_TrailMapWaitForKeypress(u8 taskId)
{
    return;
}

static void Task_FadeOutToGame(u8 taskId)
{
    if (!gPaletteFade.active)
	{
        Free(sTrailMapTilemapPtr);
        sTrailMapTilemapPtr = NULL;
		DestroyTask(taskId);
        // SetMainCallback2(CB2_StartNewRun);
	}
}
