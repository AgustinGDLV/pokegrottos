#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "event_object_movement.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "item_icon.h"
#include "item_menu.h"
#include "main.h"
#include "malloc.h"
#include "map_gen.h"
#include "map_preview.h"
#include "map_screen.h"
#include "menu.h"
#include "money.h"
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

enum Expressions
{
    KECLEON_NORMAL,
    KECLEON_HAPPY,
    KECLEON_JOYOUS,
    KECLEON_SURPRISED,
    KECLEON_SIGH,
    EXPRESSIONS_COUNT,
};

#define TAG_ITEM_ICON   8999

enum PortraitTags
{
    TAG_KECLEON_NORMAL = 9000,
    TAG_KECLEON_HAPPY,
    TAG_KECLEON_JOYOUS,
    TAG_KECLEON_SURPRISED,
    TAG_KECLEON_SIGH,
};

enum Windows
{
	WIN_MESSAGE,
    WIN_PORTRAIT,
    WIN_ACTIONS,
    WIN_ICON_YESNO,
    WIN_MONEY,
    WIN_ITEMS,
	WINDOW_COUNT,
};

enum IntroActions
{
    INTRO_BUY,
    INTRO_SELL,
    INTRO_EXIT,
};

enum BuyActions
{
    BUY_YES,
    BUY_NO,
};

static const struct WindowTemplate sShopWinTemplates[WINDOW_COUNT + 1] =
{
	[WIN_MESSAGE] =
	{
		.bg = 0,
		.tilemapLeft = 1,
		.tilemapTop = 15,
		.width = 21,
		.height = 4,
		.paletteNum = 15,
		.baseBlock = 1,
	},
    [WIN_PORTRAIT] =
    {
        .bg = 0,
		.tilemapLeft = 1,
		.tilemapTop = 8,
		.width = 5,
		.height = 5,
		.paletteNum = 15,
		.baseBlock = 1 + 21*4,
    },
    [WIN_ACTIONS] =
    {
        .bg = 0,
		.tilemapLeft = 24,
		.tilemapTop = 13,
		.width = 5,
		.height = 6,
		.paletteNum = 15,
		.baseBlock = 1 + 21*4 + 5*5,
    },
    [WIN_ICON_YESNO] =
    {
        .bg = 0,
		.tilemapLeft = 24,
		.tilemapTop = 15,
		.width = 5,
		.height = 4,
		.paletteNum = 15,
		.baseBlock = 1 + 21*4 + 5*5,
    },
    [WIN_MONEY] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1 + 21*4 + 5*5 + 5*4,
    },
    [WIN_ITEMS] =
    {
        .bg = 0,
		.tilemapLeft = 16,
		.tilemapTop = 1,
		.width = 13,
		.height = 12,
		.paletteNum = 15,
		.baseBlock = 1 + 21*4 + 5*5 + 5*4 + 10*2,
    },
	DUMMY_WIN_TEMPLATE,
};

// sprite data
static const u8 sKecleonNormalGfx[]     = INCBIN_U8("graphics/interface/kecleon_portrait_normal.4bpp");
static const u8 sKecleonHappyGfx[]      = INCBIN_U8("graphics/interface/kecleon_portrait_happy.4bpp");
static const u8 sKecleonJoyousGfx[]     = INCBIN_U8("graphics/interface/kecleon_portrait_joyous.4bpp");
static const u8 sKecleonSurprisedGfx[]     = INCBIN_U8("graphics/interface/kecleon_portrait_surprised.4bpp");
static const u8 sKecleonSighGfx[]     = INCBIN_U8("graphics/interface/kecleon_portrait_sigh.4bpp");
static const u16 sKecleonNormalPal[]    = INCBIN_U16("graphics/interface/kecleon_portrait_normal.gbapal");
static const u16 sKecleonJoyousPal[]    = INCBIN_U16("graphics/interface/kecleon_portrait_joyous.gbapal");
static const u16 sKecleonSurprisedPal[]    = INCBIN_U16("graphics/interface/kecleon_portrait_surprised.gbapal");
static const u16 sKecleonSighPal[]    = INCBIN_U16("graphics/interface/kecleon_portrait_sigh.gbapal");

static const struct SpriteSheet sKecleonSpriteSheets[] = 
{
    {sKecleonNormalGfx, sizeof(sKecleonNormalGfx), TAG_KECLEON_NORMAL},
    {sKecleonHappyGfx, sizeof(sKecleonHappyGfx), TAG_KECLEON_HAPPY},
    {sKecleonJoyousGfx, sizeof(sKecleonJoyousGfx), TAG_KECLEON_JOYOUS},
    {sKecleonSurprisedGfx, sizeof(sKecleonSurprisedGfx), TAG_KECLEON_SURPRISED},
    {sKecleonSighGfx, sizeof(sKecleonSighGfx), TAG_KECLEON_SIGH},
};

static const struct SpritePalette sKecleonSpritePalettes[] = 
{
    {sKecleonNormalPal, TAG_KECLEON_NORMAL},
    {sKecleonNormalPal, TAG_KECLEON_HAPPY},
    {sKecleonJoyousPal, TAG_KECLEON_JOYOUS},
    {sKecleonSurprisedPal, TAG_KECLEON_SURPRISED},
    {sKecleonSighPal, TAG_KECLEON_SIGH},
};

static const struct OamData sKecleonOAM =
{
	.affineMode = ST_OAM_AFFINE_OFF,
	.objMode = ST_OAM_OBJ_NORMAL,
	.shape = SPRITE_SHAPE(64x64),
	.size = SPRITE_SIZE(64x64),
	.priority = 0,
};

static void SpriteCB_Dummy(struct Sprite *sprite) {}
static const struct SpriteTemplate sKecleonNormalSpriteTemplate =
{
	.tileTag = TAG_KECLEON_NORMAL,
	.paletteTag = TAG_KECLEON_NORMAL,
	.oam = &sKecleonOAM,
	.anims = gDummySpriteAnimTable,
	.images = NULL,
	.affineAnims = gDummySpriteAffineAnimTable,
	.callback = SpriteCB_Dummy,
};

// happy
static const struct SpriteTemplate sKecleonHappySpriteTemplate =
{
	.tileTag = TAG_KECLEON_HAPPY,
	.paletteTag = TAG_KECLEON_HAPPY,
	.oam = &sKecleonOAM,
	.anims = gDummySpriteAnimTable,
	.images = NULL,
	.affineAnims = gDummySpriteAffineAnimTable,
	.callback = SpriteCB_Dummy,
};

// joyous
static const struct SpriteTemplate sKecleonJoyousSpriteTemplate =
{
	.tileTag = TAG_KECLEON_JOYOUS,
	.paletteTag = TAG_KECLEON_JOYOUS,
	.oam = &sKecleonOAM,
	.anims = gDummySpriteAnimTable,
	.images = NULL,
	.affineAnims = gDummySpriteAffineAnimTable,
	.callback = SpriteCB_Dummy,
};

// surprised
static const struct SpriteTemplate sKecleonSurprisedSpriteTemplate =
{
	.tileTag = TAG_KECLEON_SURPRISED,
	.paletteTag = TAG_KECLEON_SURPRISED,
	.oam = &sKecleonOAM,
	.anims = gDummySpriteAnimTable,
	.images = NULL,
	.affineAnims = gDummySpriteAffineAnimTable,
	.callback = SpriteCB_Dummy,
};

// sigh
static const struct SpriteTemplate sKecleonSighSpriteTemplate =
{
	.tileTag = TAG_KECLEON_SIGH,
	.paletteTag = TAG_KECLEON_SIGH,
	.oam = &sKecleonOAM,
	.anims = gDummySpriteAnimTable,
	.images = NULL,
	.affineAnims = gDummySpriteAffineAnimTable,
	.callback = SpriteCB_Dummy,
};

// table
static const struct SpriteTemplate * const sKecleonSpriteTemplates[] =
{
    &sKecleonNormalSpriteTemplate, &sKecleonHappySpriteTemplate, &sKecleonJoyousSpriteTemplate,
    &sKecleonSurprisedSpriteTemplate, &sKecleonSighSpriteTemplate,
};

// text
static const u8 sTextColor_Normal[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};
static const u8 sText_WelcomeToKecleonShop[] = _("Welcome to the Kecleon Shop! {EMOJI_NOTE}\nHow can I help you? {EMOJI_NOTE}");
static const u8 sText_MayIHelpYouWithAnythingElse[] = _("May I help you with\nanything else?");
static const u8 sText_WhatWouldYouLike[] = _("What would you\nlike to buy? {EMOJI_NOTE}");
static const u8 sText_GoodChoice[] = _("Thank you so much{EMOJI_TILDE}{EMOJI_NOTE}\nA very good choice!");
static const u8 sText_BuyAnythingElse[] = _("Do you wish to purchase\nanything else?");
static const u8 sText_ConfirmItem[] = _("{STR_VAR_1}?\nThat will be ¥{STR_VAR_2}.");
static const u8 sText_VisitAgain[] = _("Please do visit again! {EMOJI_TILDE}{EMOJI_NOTE}{PAUSE 24}");
static const u8 sText_NotEnoughMoney[] = _("Huh? You don't seem\nto have the money…{PAUSE 24}");
static const u8 sText_NoMoreMerchandise[] = _("That's it! No more merchandise!\nI'm completely sold out!{PAUSE 24}");
static const u8 sText_ImSoldOut[] = _("I'm sold out… I will have new\nmerchandise later, I swear!{PAUSE 24}");
static const u8 sText_Buy[]     = _("Buy");
static const u8 sText_Sell[]    = _("Sell");
static const u8 sText_Exit[]    = _("Exit");
static const u8 sText_Yes[]     = _("Yes");
static const u8 sText_No[]      = _("No    "); // fixing visual artifact don't ask
static const u8 sText_Empty[]   = _("");

// list menus
static const struct ListMenuItem sShopIntroListItems[] =
{
    {sText_Buy, INTRO_BUY},
    {sText_Sell, INTRO_SELL},
    {sText_Exit, INTRO_EXIT},
};

static const struct ListMenuItem sShopYesNoListItems[] =
{
    {sText_Yes, BUY_YES},
    {sText_No, BUY_NO},
};

static const struct ListMenuItem sShopItemsListItems[] =
{
    {sText_Empty, 0},
    {sText_Empty, 1},
    {sText_Empty, 2},
    {sText_Empty, 3},
    {sText_Empty, 4},
    {sText_Empty, 5},
    {sText_Empty, 6},
    {sText_Empty, 7},
    {sText_Empty, 8},
    {sText_Empty, 9},
    {sText_Empty, 10},
    {sText_Empty, 11},
};

static const struct ListMenuTemplate sShopIntroListTemplate =
{
    .items = sShopIntroListItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sShopIntroListItems),
    .maxShowed = ARRAY_COUNT(sShopIntroListItems),
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct ListMenuTemplate sShopYesNoListTemplate =
{
    .items = sShopYesNoListItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sShopYesNoListItems),
    .maxShowed = ARRAY_COUNT(sShopYesNoListItems),
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct ListMenuTemplate sShopItemsListTemplate =
{
    .items = sShopItemsListItems, // dynamic
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 12,
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

// EWRAM
EWRAM_DATA static u8 sShopItemsCount = 0;
EWRAM_DATA static void (*sShopExitTask)(u8) = {0};
EWRAM_DATA static u8 sShopWindowIds[WINDOW_COUNT] = {0};
EWRAM_DATA static bool8 sCreateCommonWindows = FALSE;
EWRAM_DATA static u8 sKecleonPortraitSpriteId = 0;
EWRAM_DATA static u8 sItemIconSpriteId = 0;
EWRAM_DATA static const u8 * sKecleonMessageText = NULL;
EWRAM_DATA static enum Expressions sKecleonExpression = 0;
EWRAM_DATA static u32 sStartingMoney = 0;
EWRAM_DATA static u32 sSelectedItem = 0;

// this file's functions
static void KecleonShop_ShowIntroScreen(u8 taskId);
static void KecleonShop_ShowBuyScreenDisplayItems(u8 taskId);
static void KecleonShop_ShowBuyScreenYesNo(u8 taskId);
static void KecleonShop_DestroyIntroScreen(u8 taskId);
static void KecleonShop_ReturnToField(u8 taskId);
static void KecleonShop_IntroScreenHandleInput(u8 taskId);
static void KecleonShop_BuyItemsHandleInput(u8 taskId);
static void KecleonShop_BuyYesNoHandleInput(u8 taskId);
static void KecleonShop_GoToSellMenu(u8 taskId);
static void KecleonShop_GoToBuyMenu(u8 taskId);
static void KecleonShop_ReturnFromSellMenu(u8 taskId);
static void KecleonShop_WaitForTextPrinter(u8 taskId);
static void KecleonShop_SimplePrintFunc(u8 windowId, u32 itemId, u8 y);
static void KecleonShop_ItemPrintFunc(u8 windowId, u32 itemId, u8 y);
static void CalculateKecleonShopItemCount(void);
static void RemoveKecleonShopItem(u32 index);

#define tMenuTaskId   data[0]
#define tWindowId     data[1]
#define tRow          data[2]
#define tScroll       data[3]

// function definitions
void InitKecleonShop(void)
{
    u32 i;
    sCreateCommonWindows = TRUE;
    sKecleonExpression = KECLEON_HAPPY;
    sKecleonPortraitSpriteId = 0xFF;
    sKecleonMessageText = sText_WelcomeToKecleonShop;
    for (i = 0; i < WINDOW_COUNT; ++i)
        sShopWindowIds[i] = 0xFF;
    ScriptContext_Stop();
    FreezeObjectEvents();
    LockPlayerFieldControls();
    CreateTask(KecleonShop_ShowIntroScreen, 3);
}

static void DrawWindow(enum Windows windowId)
{
    sShopWindowIds[windowId] = AddWindow(&sShopWinTemplates[windowId]);
    DrawStdWindowFrame(sShopWindowIds[windowId], FALSE);
    CopyWindowToVram(sShopWindowIds[windowId], COPYWIN_FULL);
}

static void DestroyWindow(enum Windows windowId)
{
    if (sShopWindowIds[windowId] != 0xFF)
    {
        ClearStdWindowAndFrame(sShopWindowIds[windowId], TRUE);
        RemoveWindow(sShopWindowIds[windowId]);
        sShopWindowIds[windowId] = 0xFF;
    }
}

static void DrawTextToMessageWindow(const u8* text)
{
    FillWindowPixelBuffer(sShopWindowIds[WIN_MESSAGE], PIXEL_FILL(1));
    if (text == NULL)
        AddTextPrinterParameterized3(sShopWindowIds[WIN_MESSAGE], FONT_NORMAL, 2, 0, sTextColor_Normal, GetPlayerTextSpeedDelay(), sText_WelcomeToKecleonShop);
    else
        AddTextPrinterParameterized3(sShopWindowIds[WIN_MESSAGE], FONT_NORMAL, 2, 0, sTextColor_Normal, GetPlayerTextSpeedDelay(), text);
    CopyWindowToVram(sShopWindowIds[WIN_MESSAGE], COPYWIN_FULL);
}

static void DrawKecleonPortrait(enum Expressions type)
{
    if (type >= EXPRESSIONS_COUNT)
        type = KECLEON_NORMAL;

    if (sKecleonPortraitSpriteId != 0xFF)
    {
        FreeSpritePalette(&gSprites[sKecleonPortraitSpriteId]);
        FreeSpriteTiles(&gSprites[sKecleonPortraitSpriteId]);
        DestroySprite(&gSprites[sKecleonPortraitSpriteId]);
    }

    LoadSpritePalette(&sKecleonSpritePalettes[type]);
    LoadSpriteSheet(&sKecleonSpriteSheets[type]);
    sKecleonPortraitSpriteId = CreateSprite(sKecleonSpriteTemplates[type], 40, 96, 0);
}

static void KecleonShop_ShowIntroScreen(u8 taskId)
{
    u32 menuTaskId;
    struct ListMenuTemplate menuTemplate;

    // Create windows.
    if (sCreateCommonWindows)
    {
        LoadMessageBoxAndBorderGfx();
        DrawWindow(WIN_MESSAGE);
        DrawWindow(WIN_PORTRAIT);
        sCreateCommonWindows = FALSE;
    }
    DrawWindow(WIN_ACTIONS);

    // Draw portrait.
    DrawKecleonPortrait(sKecleonExpression);

    // Draw text.
    DrawTextToMessageWindow(sKecleonMessageText);        

    // Create list menu.
    menuTemplate = sShopIntroListTemplate;
    menuTemplate.windowId = sShopWindowIds[WIN_ACTIONS];
    menuTemplate.itemPrintFunc = KecleonShop_SimplePrintFunc;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    // Create input handler task.
    gTasks[taskId].func = KecleonShop_IntroScreenHandleInput;
    gTasks[taskId].tMenuTaskId = menuTaskId;
    gTasks[taskId].tWindowId = sShopWindowIds[WIN_ACTIONS];
}

static void DrawItemIcon(u32 itemId)
{
    if (sItemIconSpriteId != 0xFF)
    {
        FreeSpritePalette(&gSprites[sItemIconSpriteId]);
        FreeSpriteTiles(&gSprites[sItemIconSpriteId]);
        DestroySprite(&gSprites[sItemIconSpriteId]);
    }
    sItemIconSpriteId = AddItemIconSprite(TAG_ITEM_ICON, TAG_ITEM_ICON, itemId);
    gSprites[sItemIconSpriteId].oam.priority = 0;
    gSprites[sItemIconSpriteId].x2 = 196 + 20;
    gSprites[sItemIconSpriteId].y2 = 112 + 28;
}

static void KecleonShop_ShowBuyScreenDisplayItems(u8 taskId)
{
    u32 menuTaskId;
    struct ListMenuTemplate menuTemplate;

    // Create windows.
    if (sCreateCommonWindows)
    {
        LoadMessageBoxAndBorderGfx();
        DrawWindow(WIN_MESSAGE);
        DrawWindow(WIN_PORTRAIT);
        sCreateCommonWindows = FALSE;
    }
    DrawWindow(WIN_ICON_YESNO);
    DrawWindow(WIN_ITEMS);

    // Draw money box.
    if (sShopWindowIds[WIN_MONEY] == 0xFF)
    {
        DrawWindow(WIN_MONEY);
        PrintMoneyAmountInMoneyBox(sShopWindowIds[WIN_MONEY], GetMoney(&gSaveBlock1Ptr->money), 0);
        AddMoneyLabelObject(19, 11);
    }

    // Draw portrait.
    DrawKecleonPortrait(sKecleonExpression);

    // Draw text.
    DrawTextToMessageWindow(sKecleonMessageText);       

    // Draw item icon.
    DrawItemIcon(sSelectedItem);

    // Create list menu.
    menuTemplate = sShopItemsListTemplate;
    menuTemplate.totalItems = sShopItemsCount + 1;
    menuTemplate.windowId = sShopWindowIds[WIN_ITEMS];
    menuTemplate.itemPrintFunc = KecleonShop_ItemPrintFunc;
    menuTaskId = ListMenuInit(&menuTemplate, gTasks[taskId].tScroll, gTasks[taskId].tRow);

    // Create input handler task.
    gTasks[taskId].func = KecleonShop_BuyItemsHandleInput;
    gTasks[taskId].tMenuTaskId = menuTaskId;
    gTasks[taskId].tWindowId = sShopWindowIds[WIN_ITEMS];
}

static void KecleonShop_ShowBuyScreenYesNo(u8 taskId)
{
    u32 menuTaskId;
    struct ListMenuTemplate menuTemplate;

    // Draw portrait.
    DrawKecleonPortrait(sKecleonExpression);

    // Draw text.
    FillWindowPixelBuffer(sShopWindowIds[WIN_ITEMS], PIXEL_FILL(1));
    AddTextPrinterParameterized3(sShopWindowIds[WIN_ITEMS], FONT_NORMAL, 0, 0, sTextColor_Normal, TEXT_SKIP_DRAW, ItemId_GetDescription(sSelectedItem));
    CopyWindowToVram(sShopWindowIds[WIN_ITEMS], COPYWIN_FULL);
    StringCopy(gStringVar1, ItemId_GetName(sSelectedItem));
    ConvertIntToDecimalStringN(gStringVar2, ItemId_GetPrice(sSelectedItem) / 10, STR_CONV_MODE_LEFT_ALIGN, 5);
    StringExpandPlaceholders(gStringVar4, sText_ConfirmItem);
    DrawTextToMessageWindow(gStringVar4);

    // Create list menu.
    menuTemplate = sShopYesNoListTemplate;
    menuTemplate.windowId = sShopWindowIds[WIN_ICON_YESNO];
    menuTemplate.itemPrintFunc = KecleonShop_SimplePrintFunc;
    menuTaskId = ListMenuInit(&menuTemplate, 0, 0);

    // Create input handler task.
    gTasks[taskId].func = KecleonShop_BuyYesNoHandleInput;
    gTasks[taskId].tMenuTaskId = menuTaskId;
    gTasks[taskId].tWindowId = sShopWindowIds[WIN_ICON_YESNO];
}

static void KecleonShop_DestroyIntroScreen(u8 taskId)
{
    u32 i;
    for (i = 0; i < WINDOW_COUNT; ++i)
        DestroyWindow(i);
    FreeSpritePalette(&gSprites[sKecleonPortraitSpriteId]);
    FreeSpriteTiles(&gSprites[sKecleonPortraitSpriteId]);
    DestroySprite(&gSprites[sKecleonPortraitSpriteId]);
    DestroyListMenuTask(gTasks[taskId].tMenuTaskId, NULL, NULL);
    gTasks[taskId].func = KecleonShop_ReturnToField;
}

static void KecleonShop_PrintExitMessage(u8 taskId)
{
    DestroyWindow(WIN_ACTIONS);
    DrawTextToMessageWindow(sText_VisitAgain);
    sShopExitTask = KecleonShop_DestroyIntroScreen;
    gTasks[taskId].func = KecleonShop_WaitForTextPrinter;
}

static void KecleonShop_ReturnToField(u8 taskId)
{
    DestroyListMenuTask(gTasks[taskId].tMenuTaskId, 0, 0);
    DestroyTask(taskId);
    ScriptContext_Enable();
    UnfreezeObjectEvents();
    UnlockPlayerFieldControls();
}

static void KecleonShop_IntroScreenHandleInput(u8 taskId)
{
    if (!RunTextPrintersRetIsActive(sShopWindowIds[WIN_MESSAGE]))
    {
        u32 input = ListMenu_ProcessInput(gTasks[taskId].tMenuTaskId);
        if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
        {
            switch (input)
            {
            case INTRO_BUY:
                PlaySE(SE_SELECT);
                CalculateKecleonShopItemCount();
                // Don't go to Buy Menu if sold out.
                if (sShopItemsCount > 0)
                {
                    gTasks[taskId].func = KecleonShop_GoToBuyMenu;
                }
                else
                {
                    DrawKecleonPortrait(KECLEON_SIGH);
                    DrawTextToMessageWindow(sText_ImSoldOut);
                    sShopExitTask = KecleonShop_ShowIntroScreen;
                    gTasks[taskId].func = KecleonShop_WaitForTextPrinter;
                }
                break;
            case INTRO_SELL:
                PlaySE(SE_SELECT);
                FadeScreen(FADE_TO_BLACK, 0);
                gTasks[taskId].func = KecleonShop_GoToSellMenu;
                break;
            case LIST_CANCEL:
            case INTRO_EXIT:
                PlaySE(SE_SELECT);
                sShopExitTask = KecleonShop_ReturnToField;
                gTasks[taskId].func = KecleonShop_PrintExitMessage;
                break;
            }
        }
    }
}

static void KecleonShop_ClearBuyMenuGraphics(u8 taskId)
{
    DestroyListMenuTask(gTasks[taskId].tMenuTaskId, 0, 0);
    DestroyWindow(WIN_ITEMS);
    DestroyWindow(WIN_ICON_YESNO);
    DestroyWindow(WIN_MONEY);
    RemoveMoneyLabelObject();
    FreeSpritePalette(&gSprites[sItemIconSpriteId]);
    FreeSpriteTiles(&gSprites[sItemIconSpriteId]);
    DestroySprite(&gSprites[sItemIconSpriteId]);
    sItemIconSpriteId = 0xFF;
    SetMinimapVisibility(FALSE);
}

static void KecleonShop_BuyItemsHandleInput(u8 taskId)
{
    if (!RunTextPrintersRetIsActive(sShopWindowIds[WIN_MESSAGE]))
    {
        u32 input = ListMenu_ProcessInput(gTasks[taskId].tMenuTaskId);
        struct ListMenu *list = (void *) gTasks[gTasks[taskId].tMenuTaskId].data;
        sSelectedItem = gSaveBlock1Ptr->shopItems[list->scrollOffset + list->selectedRow];

        if (JOY_REPEAT(DPAD_UP) || JOY_REPEAT(DPAD_DOWN))
        {
            u32 price = (ItemId_GetPrice(sSelectedItem) / 10);
            DrawItemIcon(sSelectedItem);
            if (price >= 1000)
                DrawKecleonPortrait(KECLEON_JOYOUS);
            else if (price >= 500)
                DrawKecleonPortrait(KECLEON_HAPPY);
            else
                DrawKecleonPortrait(KECLEON_NORMAL);
        }

        if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
        {
            gTasks[taskId].tRow = list->selectedRow;
            gTasks[taskId].tScroll = list->scrollOffset;
            switch (input)
            {
            default: // try buying selected item
                PlaySE(SE_SELECT);
                if (list->scrollOffset + list->selectedRow >= sShopItemsCount)
                {
                    PlaySE(SE_SELECT);
                    KecleonShop_ClearBuyMenuGraphics(taskId);
                    if (sStartingMoney > GetMoney(&gSaveBlock1Ptr->money))
                        sKecleonExpression = KECLEON_JOYOUS;
                    else
                        sKecleonExpression = KECLEON_NORMAL;
                    sKecleonMessageText = sText_MayIHelpYouWithAnythingElse;
                    gTasks[taskId].func = KecleonShop_ShowIntroScreen;
                }
                else if ((ItemId_GetPrice(sSelectedItem) / 10) <= GetMoney(&gSaveBlock1Ptr->money))
                {
                    DestroyListMenuTask(gTasks[taskId].tMenuTaskId, 0, 0);
                    FreeSpritePalette(&gSprites[sItemIconSpriteId]);
                    FreeSpriteTiles(&gSprites[sItemIconSpriteId]);
                    DestroySprite(&gSprites[sItemIconSpriteId]);
                    sItemIconSpriteId = 0xFF;
                    gTasks[taskId].func = KecleonShop_ShowBuyScreenYesNo;
                }
                else
                {
                    DrawKecleonPortrait(KECLEON_NORMAL);
                    DrawTextToMessageWindow(sText_NotEnoughMoney);
                    sShopExitTask = KecleonShop_ShowBuyScreenDisplayItems;
                    gTasks[taskId].func = KecleonShop_WaitForTextPrinter;
                }
                break;
            case LIST_CANCEL:
                PlaySE(SE_SELECT);
                KecleonShop_ClearBuyMenuGraphics(taskId);
                if (sStartingMoney > GetMoney(&gSaveBlock1Ptr->money))
                    sKecleonExpression = KECLEON_JOYOUS;
                else
                    sKecleonExpression = KECLEON_NORMAL;
                sKecleonMessageText = sText_MayIHelpYouWithAnythingElse;
                gTasks[taskId].func = KecleonShop_ShowIntroScreen;
                break;
            }
        }
    }
}

static void KecleonShop_BuyYesNoHandleInput(u8 taskId)
{
    if (!RunTextPrintersRetIsActive(sShopWindowIds[WIN_MESSAGE]))
    {
        u32 input = ListMenu_ProcessInput(gTasks[taskId].tMenuTaskId);
        if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
        {
            switch (input)
            {
            case BUY_YES:
                PlaySE(SE_SHOP);
                RemoveMoney(&gSaveBlock1Ptr->money, ItemId_GetPrice(sSelectedItem) / 10);
                PrintMoneyAmountInMoneyBox(sShopWindowIds[WIN_MONEY], GetMoney(&gSaveBlock1Ptr->money), 0);
                AddBagItem(sSelectedItem, 1);
                RemoveKecleonShopItem(gTasks[taskId].tRow + gTasks[taskId].tScroll);
                DestroyListMenuTask(gTasks[taskId].tMenuTaskId, 0, 0);
                sKecleonExpression = KECLEON_JOYOUS;
                sKecleonMessageText = sText_BuyAnythingElse;
                // Update list menu scroll to avoid minor visual bugs.
                if ((gTasks[taskId].tRow > 3 || gTasks[taskId].tRow + gTasks[taskId].tScroll >= sShopItemsCount - 3) && sShopItemsCount >= 5)
                    --gTasks[taskId].tScroll;
                else if (gTasks[taskId].tRow > 0 && sShopItemsCount < 5)
                    --gTasks[taskId].tRow;
                // Exit back to intro if sold out.
                if (sShopItemsCount > 0)
                {
                    gTasks[taskId].func = KecleonShop_ShowBuyScreenDisplayItems;
                }
                else
                {
                    sKecleonMessageText = sText_MayIHelpYouWithAnythingElse;
                    DrawTextToMessageWindow(sText_NoMoreMerchandise);
                    DrawKecleonPortrait(KECLEON_SURPRISED);
                    KecleonShop_ClearBuyMenuGraphics(taskId);
                    sShopExitTask = KecleonShop_ShowIntroScreen;
                    gTasks[taskId].func = KecleonShop_WaitForTextPrinter;
                }
                break;
            case BUY_NO:
            case LIST_CANCEL:
                PlaySE(SE_SELECT);
                DestroyListMenuTask(gTasks[taskId].tMenuTaskId, 0, 0);
                gTasks[taskId].func = KecleonShop_ShowBuyScreenDisplayItems;
                break;
            }
        }
    }
}

static void KecleonShop_SimplePrintFunc(u8 windowId, u32 itemId, u8 y)
{
    if (itemId == LIST_CANCEL)
        return;
    else
        AddTextPrinterParameterized4(windowId, FONT_NORMAL, 8, y, 0, 0, sTextColor_Normal, TEXT_SKIP_DRAW, sShopIntroListItems[itemId].name);
}

static void KecleonShop_ItemPrintFunc(u8 windowId, u32 itemId, u8 y)
{
    if (itemId == LIST_CANCEL)
    {
        return;
    }
    else if (itemId < sShopItemsCount)
    {
        AddTextPrinterParameterized4(windowId, GetFontIdToFit(ItemId_GetName(gSaveBlock1Ptr->shopItems[itemId]), FONT_NARROW, 0, 64), 8, y, 0, 0, sTextColor_Normal, TEXT_SKIP_DRAW, ItemId_GetName(gSaveBlock1Ptr->shopItems[itemId]));
        ConvertIntToDecimalStringN(gStringVar1, ItemId_GetPrice(gSaveBlock1Ptr->shopItems[itemId]) / 10, STR_CONV_MODE_LEFT_ALIGN, 5);
        StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
        AddTextPrinterParameterized4(windowId, FONT_SMALL, 8 + GetStringRightAlignXOffset(FONT_SMALL, gStringVar4, 96), y, 0, 0, sTextColor_Normal, TEXT_SKIP_DRAW, gStringVar4);
    }
    else
    {
        AddTextPrinterParameterized4(windowId, FONT_NARROW, 8, y, 0, 0, sTextColor_Normal, TEXT_SKIP_DRAW, sText_Exit);
    }
}

static void KecleonShop_GoToSellMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyListMenuTask(gTasks[taskId].tMenuTaskId, 0, 0);
        DestroyTask(taskId);
        sStartingMoney = GetMoney(&gSaveBlock1Ptr->money);
        SetMainCallback2(CB2_GoToSellMenuFromKecleonShop);
    }
}

static void KecleonShop_ReturnFromSellMenu(u8 taskId)
{
    if (IsWeatherNotFadingIn())
    {
        DestroyTask(taskId);
        FreezeObjectEvents();
        sKecleonMessageText = sText_MayIHelpYouWithAnythingElse;
        sCreateCommonWindows = TRUE;
        if (sStartingMoney < GetMoney(&gSaveBlock1Ptr->money))
            sKecleonExpression = KECLEON_JOYOUS;
        else
            sKecleonExpression = KECLEON_NORMAL;
        CreateTask(KecleonShop_ShowIntroScreen, 3);
    }
}

static void MapPostLoadHook_ReturnToShopMenu(void)
{
    FadeInFromBlack();
    CreateTask(KecleonShop_ReturnFromSellMenu, 8);
}

void CB2_KecleonShopExitSellMenu(void)
{
    gFieldCallback = MapPostLoadHook_ReturnToShopMenu;
    SetMainCallback2(CB2_ReturnToField);
}

static void KecleonShop_GoToBuyMenu(u8 taskId)
{
    DestroyListMenuTask(gTasks[taskId].tMenuTaskId, 0, 0);
    DestroyWindow(WIN_ACTIONS);
    SetMinimapVisibility(TRUE);
    sItemIconSpriteId = 0xFF;
    sSelectedItem = gSaveBlock1Ptr->shopItems[0];
    sKecleonMessageText = sText_WhatWouldYouLike;
    sKecleonExpression = KECLEON_HAPPY;
    sStartingMoney = GetMoney(&gSaveBlock1Ptr->money);
    gTasks[taskId].tRow = 0;
    gTasks[taskId].tScroll = 0;
    gTasks[taskId].func = KecleonShop_ShowBuyScreenDisplayItems;
}

static void KecleonShop_WaitForTextPrinter(u8 taskId)
{
    if (!RunTextPrintersRetIsActive(sShopWindowIds[WIN_MESSAGE]))
    {
        if (sShopExitTask != NULL)
            gTasks[taskId].func = sShopExitTask;
        else
            gTasks[taskId].func = KecleonShop_DestroyIntroScreen;
    }
}

#undef tMenuTaskId
#undef tWindowId
#undef tRow
#undef tScroll

static void CalculateKecleonShopItemCount(void)
{
    u32 i;
    for (i = 0; i < 11; ++i)
        if (gSaveBlock1Ptr->shopItems[i] == ITEM_NONE)
            break;
    sShopItemsCount = i;
}

static void RemoveKecleonShopItem(u32 index)
{
    u32 i;
    for (i = index; i < 11-1; ++i)
        gSaveBlock1Ptr->shopItems[i] = gSaveBlock1Ptr->shopItems[i+1];
    gSaveBlock1Ptr->shopItems[i] = ITEM_NONE;
    --sShopItemsCount;
}
