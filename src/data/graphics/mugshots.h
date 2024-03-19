#define TAG_MUGSHOT_FLANNERY    0x2000

const struct OamData sOamData_Mugshot =
{
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1,
};

const u32 gMugshotGfx_Flannery[] = INCBIN_U32("graphics/trainers/mugshots/flannery.4bpp.lz");
const u16 gMugshotPal_Flannery[] = INCBIN_U16("graphics/trainers/mugshots/flannery.gbapal");

const struct SpriteTemplate sSpriteTemplate_Flannery =
{
    .tileTag = TAG_MUGSHOT_FLANNERY,
    .paletteTag = TAG_MUGSHOT_FLANNERY,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
