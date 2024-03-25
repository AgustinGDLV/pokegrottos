#include "graphics/mugshots.h"

static const u8 sFlanneryName[] = _("Flannery");

const struct CharacterInfo gCharacterInfos[CHARACTERS_COUNT] = {
    [CHAR_FLANNERY] = {
        .name = sFlanneryName,
        .color = RGB(24, 3, 3),
        .graphicsId = OBJ_EVENT_GFX_FLANNERY,
        .mugshotTemplate = &sSpriteTemplate_Flannery,
        .mugshotSheet = {gMugshotGfx_Flannery, 0x2800, TAG_MUGSHOT_FLANNERY},
        .mugshotPal = {gMugshotPal_Flannery, TAG_MUGSHOT_FLANNERY},
    },
};
