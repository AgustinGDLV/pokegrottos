enum {
    TAG_MUGSHOT_FIREBREATHER = 0x3000,
    TAG_MUGSHOT_AROMA_LADY,
    TAG_MUGSHOT_SWIMMER,
    TAG_MUGSHOT_HIKER,
    TAG_MUGSHOT_NINJA_BOY,
    TAG_MUGSHOT_BUG_CATCHER,
    TAG_MUGSHOT_BLACK_BELT,
    TAG_MUGSHOT_HEX_MANIAC,
    TAG_MUGSHOT_GUITARIST,
    TAG_MUGSHOT_PUNK,
    TAG_MUGSHOT_BREEDER,
    TAG_MUGSHOT_POKEMON_RANGER,
    TAG_MUGSHOT_FAIRY_TALE_GIRL,
    TAG_MUGSHOT_RICH_BOY,
    TAG_MUGSHOT_ACE_TRAINER,
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
const u32 gMugshotGfx_NinjaBoy[] = INCBIN_U32("graphics/trainers/mugshots/ninja_boy.4bpp.lz");
const u16 gMugshotPal_NinjaBoy[] = INCBIN_U16("graphics/trainers/mugshots/ninja_boy.gbapal");
const u32 gMugshotGfx_BugCatcher[] = INCBIN_U32("graphics/trainers/mugshots/bug_catcher.4bpp.lz");
const u16 gMugshotPal_BugCatcher[] = INCBIN_U16("graphics/trainers/mugshots/bug_catcher.gbapal");
const u32 gMugshotGfx_BlackBelt[] = INCBIN_U32("graphics/trainers/mugshots/black_belt.4bpp.lz");
const u16 gMugshotPal_BlackBelt[] = INCBIN_U16("graphics/trainers/mugshots/black_belt.gbapal");
const u32 gMugshotGfx_Guitarist[] = INCBIN_U32("graphics/trainers/mugshots/guitarist.4bpp.lz");
const u16 gMugshotPal_Guitarist[] = INCBIN_U16("graphics/trainers/mugshots/guitarist.gbapal");
const u32 gMugshotGfx_Punk[] = INCBIN_U32("graphics/trainers/mugshots/punk.4bpp.lz");
const u16 gMugshotPal_Punk[] = INCBIN_U16("graphics/trainers/mugshots/punk.gbapal");
const u32 gMugshotGfx_HexManiac[] = INCBIN_U32("graphics/trainers/mugshots/hex_maniac.4bpp.lz");
const u16 gMugshotPal_HexManiac[] = INCBIN_U16("graphics/trainers/mugshots/hex_maniac.gbapal");
const u32 gMugshotGfx_FairyTaleGirl[] = INCBIN_U32("graphics/trainers/mugshots/fairy_tale_girl.4bpp.lz");
const u16 gMugshotPal_FairyTaleGirl[] = INCBIN_U16("graphics/trainers/mugshots/fairy_tale_girl.gbapal");
const u32 gMugshotGfx_Breeder[] = INCBIN_U32("graphics/trainers/mugshots/breeder.4bpp.lz");
const u16 gMugshotPal_Breeder[] = INCBIN_U16("graphics/trainers/mugshots/breeder.gbapal");
const u32 gMugshotGfx_PokemonRanger[] = INCBIN_U32("graphics/trainers/mugshots/pokemon_ranger.4bpp.lz");
const u16 gMugshotPal_PokemonRanger[] = INCBIN_U16("graphics/trainers/mugshots/pokemon_ranger.gbapal");
const u32 gMugshotGfx_AceTrainer[] = INCBIN_U32("graphics/trainers/mugshots/ace_trainer.4bpp.lz");
const u16 gMugshotPal_AceTrainer[] = INCBIN_U16("graphics/trainers/mugshots/ace_trainer.gbapal");
const u32 gMugshotGfx_RichBoy[] = INCBIN_U32("graphics/trainers/mugshots/rich_boy.4bpp.lz");
const u16 gMugshotPal_RichBoy[] = INCBIN_U16("graphics/trainers/mugshots/rich_boy.gbapal");

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

const struct SpriteTemplate sSpriteTemplate_NinjaBoy =
{
    .tileTag = TAG_MUGSHOT_NINJA_BOY,
    .paletteTag = TAG_MUGSHOT_NINJA_BOY,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate sSpriteTemplate_BugCatcher =
{
    .tileTag = TAG_MUGSHOT_BUG_CATCHER,
    .paletteTag = TAG_MUGSHOT_BUG_CATCHER,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate sSpriteTemplate_BlackBelt =
{
    .tileTag = TAG_MUGSHOT_BLACK_BELT,
    .paletteTag = TAG_MUGSHOT_BLACK_BELT,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate sSpriteTemplate_Guitarist =
{
    .tileTag = TAG_MUGSHOT_GUITARIST,
    .paletteTag = TAG_MUGSHOT_GUITARIST,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate sSpriteTemplate_Punk =
{
    .tileTag = TAG_MUGSHOT_PUNK,
    .paletteTag = TAG_MUGSHOT_PUNK,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate sSpriteTemplate_HexManiac =
{
    .tileTag = TAG_MUGSHOT_HEX_MANIAC,
    .paletteTag = TAG_MUGSHOT_HEX_MANIAC,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate sSpriteTemplate_FairyTaleGirl =
{
    .tileTag = TAG_MUGSHOT_FAIRY_TALE_GIRL,
    .paletteTag = TAG_MUGSHOT_FAIRY_TALE_GIRL,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate sSpriteTemplate_Breeder =
{
    .tileTag = TAG_MUGSHOT_BREEDER,
    .paletteTag = TAG_MUGSHOT_BREEDER,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate sSpriteTemplate_PokemonRanger =
{
    .tileTag = TAG_MUGSHOT_POKEMON_RANGER,
    .paletteTag = TAG_MUGSHOT_POKEMON_RANGER,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate sSpriteTemplate_AceTrainer =
{
    .tileTag = TAG_MUGSHOT_ACE_TRAINER,
    .paletteTag = TAG_MUGSHOT_ACE_TRAINER,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate sSpriteTemplate_RichBoy =
{
    .tileTag = TAG_MUGSHOT_RICH_BOY,
    .paletteTag = TAG_MUGSHOT_RICH_BOY,
    .oam = &sOamData_Mugshot,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
