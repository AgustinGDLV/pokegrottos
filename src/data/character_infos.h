#include "graphics/mugshots.h"

static const u8 sFirebreatherName[] = _("Firebreather");
static const u8 sFirebreatherDesc[] = _("Specializes in Fire types\nand sunny weather");

static const u8 sAromaLadyName[] = _("Aroma Lady");
static const u8 sAromaLadyDesc[] = _("Specializes in Grass types\nand powder");

static const u8 sSwimmerName[] = _("Swimmer");
static const u8 sSwimmerDesc[] = _("Specializes in Water types\nand rainy weather");

static const u8 sHikerName[] = _("Hiker");
static const u8 sHikerDesc[] = _("Specializes in Rock types\nand sandstorms");

const struct CharacterInfo gCharacterInfos[CHARACTERS_COUNT] = {
    [CHAR_FIREBREATHER] = {
        .name = sFirebreatherName,
        .desc = sFirebreatherDesc,
        .item = ITEM_SUN_STONE,
        .starters = {SPECIES_NUMEL, SPECIES_SLUGMA, SPECIES_TORKOAL},
        .color = RGB(24, 3, 3),
        .graphicsId = OBJ_EVENT_GFX_FLANNERY,
        .mugshotTemplate = &sSpriteTemplate_Firebreather,
        .mugshotSheet = {gMugshotGfx_Firebreather, 0x2800, TAG_MUGSHOT_FIREBREATHER},
        .mugshotPal = {gMugshotPal_Firebreather, TAG_MUGSHOT_FIREBREATHER},
    },
    [CHAR_AROMA_LADY] = {
        .name = sAromaLadyName,
        .desc = sAromaLadyDesc,
        .item = ITEM_LEAF_STONE,
        .starters = {SPECIES_SPHEAL, SPECIES_WAILMER, SPECIES_BARBOACH},
        .color = RGB(3, 18, 3),
        .graphicsId = OBJ_EVENT_GFX_WALLACE,
        .mugshotTemplate = &sSpriteTemplate_AromaLady,
        .mugshotSheet = {gMugshotGfx_AromaLady, 0x2800, TAG_MUGSHOT_AROMA_LADY},
        .mugshotPal = {gMugshotPal_AromaLady, TAG_MUGSHOT_AROMA_LADY},
    },
    [CHAR_SWIMMER] = {
        .name = sSwimmerName,
        .desc = sSwimmerDesc,
        .item = ITEM_WATER_STONE,
        .starters = {SPECIES_SPHEAL, SPECIES_WAILMER, SPECIES_BARBOACH},
        .color = RGB(3, 3, 24),
        .graphicsId = OBJ_EVENT_GFX_WALLACE,
        .mugshotTemplate = &sSpriteTemplate_Swimmer,
        .mugshotSheet = {gMugshotGfx_Swimmer, 0x2800, TAG_MUGSHOT_SWIMMER},
        .mugshotPal = {gMugshotPal_Swimmer, TAG_MUGSHOT_SWIMMER},
    },
    [CHAR_HIKER] = {
        .name = sHikerName,
        .desc = sHikerDesc,
        .item = ITEM_SMOOTH_ROCK,
        .starters = {SPECIES_SPHEAL, SPECIES_WAILMER, SPECIES_BARBOACH},
        .color = RGB(14, 12, 7),
        .graphicsId = OBJ_EVENT_GFX_WALLACE,
        .mugshotTemplate = &sSpriteTemplate_Hiker,
        .mugshotSheet = {gMugshotGfx_Hiker, 0x2800, TAG_MUGSHOT_HIKER},
        .mugshotPal = {gMugshotPal_Hiker, TAG_MUGSHOT_HIKER},
    },
};
