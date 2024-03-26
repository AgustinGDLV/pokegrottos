#include "graphics/mugshots.h"

static const u8 sFlanneryName[] = _("Flannery");
static const u8 sWallaceName[] = _("Wallace");

const struct CharacterInfo gCharacterInfos[CHARACTERS_COUNT] = {
    [CHAR_FLANNERY] = {
        .name = sFlanneryName,
        .color = RGB(24, 3, 3),
        .graphicsId = OBJ_EVENT_GFX_FLANNERY,
        .mugshotTemplate = &sSpriteTemplate_Flannery,
        .mugshotSheet = {gMugshotGfx_Flannery, 0x2800, TAG_MUGSHOT_FLANNERY},
        .mugshotPal = {gMugshotPal_Flannery, TAG_MUGSHOT_FLANNERY},
    },
    [CHAR_WALLACE] = {
        .name = sWallaceName,
        .color = RGB(6, 10, 24),
        .graphicsId = OBJ_EVENT_GFX_WALLACE,
        .mugshotTemplate = &sSpriteTemplate_Wallace,
        .mugshotSheet = {gMugshotGfx_Wallace, 0x2800, TAG_MUGSHOT_WALLACE},
        .mugshotPal = {gMugshotPal_Wallace, TAG_MUGSHOT_WALLACE},
    },
};
