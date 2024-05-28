#include "graphics/mugshots.h"

static const u8 sFlanneryName[] = _("Flannery");
static const u8 sFlanneryDesc[] = _("Specializes in Fire types\nand sunny weather");

static const u8 sWallaceName[] = _("Wallace");
static const u8 sWallaceDesc[] = _("Specializes in Water types\nand rainy weather");

const struct CharacterInfo gCharacterInfos[CHARACTERS_COUNT] = {
    [CHAR_FLANNERY] = {
        .name = sFlanneryName,
        .desc = sFlanneryDesc,
        .item = ITEM_SUN_STONE,
        .starters = {SPECIES_NUMEL, SPECIES_SLUGMA, SPECIES_TORKOAL},
        .color = RGB(24, 3, 3),
        .graphicsId = OBJ_EVENT_GFX_FLANNERY,
        .mugshotTemplate = &sSpriteTemplate_Flannery,
        .mugshotSheet = {gMugshotGfx_Flannery, 0x2800, TAG_MUGSHOT_FLANNERY},
        .mugshotPal = {gMugshotPal_Flannery, TAG_MUGSHOT_FLANNERY},
    },
    [CHAR_WALLACE] = {
        .name = sWallaceName,
        .desc = sWallaceDesc,
        .item = ITEM_WATER_STONE,
        .starters = {SPECIES_SPHEAL, SPECIES_WAILMER, SPECIES_BARBOACH},
        .color = RGB(6, 10, 24),
        .graphicsId = OBJ_EVENT_GFX_WALLACE,
        .mugshotTemplate = &sSpriteTemplate_Wallace,
        .mugshotSheet = {gMugshotGfx_Wallace, 0x2800, TAG_MUGSHOT_WALLACE},
        .mugshotPal = {gMugshotPal_Wallace, TAG_MUGSHOT_WALLACE},
    },
};
