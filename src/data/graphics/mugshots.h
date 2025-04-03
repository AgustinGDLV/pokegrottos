enum {
    TAG_MUGSHOT_FIREBREATHER = 0x2000,
    TAG_MUGSHOT_AROMA_LADY,
    TAG_MUGSHOT_SWIMMER,
    TAG_MUGSHOT_HIKER,
};

const struct OamData sOamData_Mugshot =
{
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1,
};

const u32 gMugshotGfx_Firebreather[] = INCBIN_U32("graphics/trainers/mugshots/firebreather.4bpp.lz");
const u16 gMugshotPal_Firebreather[] = INCBIN_U16("graphics/trainers/mugshots/firebreather.gbapal");
const u32 gMugshotGfx_AromaLady[] = INCBIN_U32("graphics/trainers/mugshots/aroma_lady.4bpp.lz");
const u16 gMugshotPal_AromaLady[] = INCBIN_U16("graphics/trainers/mugshots/aroma_lady.gbapal");
const u32 gMugshotGfx_Swimmer[] = INCBIN_U32("graphics/trainers/mugshots/swimmer.4bpp.lz");
const u16 gMugshotPal_Swimmer[] = INCBIN_U16("graphics/trainers/mugshots/swimmer.gbapal");
const u32 gMugshotGfx_Hiker[] = INCBIN_U32("graphics/trainers/mugshots/hiker.4bpp.lz");
const u16 gMugshotPal_Hiker[] = INCBIN_U16("graphics/trainers/mugshots/hiker.gbapal");

const struct SpriteTemplate sSpriteTemplate_Firebreather =
{
    .tileTag = TAG_MUGSHOT_FIREBREATHER,
    .paletteTag = TAG_MUGSHOT_FIREBREATHER,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate sSpriteTemplate_AromaLady =
{
    .tileTag = TAG_MUGSHOT_AROMA_LADY,
    .paletteTag = TAG_MUGSHOT_AROMA_LADY,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate sSpriteTemplate_Swimmer =
{
    .tileTag = TAG_MUGSHOT_SWIMMER,
    .paletteTag = TAG_MUGSHOT_SWIMMER,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate sSpriteTemplate_Hiker =
{
    .tileTag = TAG_MUGSHOT_HIKER,
    .paletteTag = TAG_MUGSHOT_HIKER,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
