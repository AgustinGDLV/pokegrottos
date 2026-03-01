static const u16 sGrassBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/grass_tiles.gbapal");
static const u32 sGrassBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/grass_tiles.4bpp.lz");
static const u32 sGrassBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/grass_map.bin.lz");

static const u16 sUnderwaterBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/underwater_tiles.gbapal");
static const u32 sUnderwaterBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/underwater_tiles.4bpp.lz");
static const u32 sUnderwaterBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/underwater_map.bin.lz");

static const u16 sCityBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/city_tiles.gbapal");
static const u32 sCityBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/city_tiles.4bpp.lz");
static const u32 sCityBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/city_map.bin.lz");

static const u16 sIcePathBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/ice_path_tiles.gbapal");
static const u32 sIcePathBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/ice_path_tiles.4bpp.lz");
static const u32 sIcePathBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/ice_path_map.bin.lz");

static const u16 sVolcanoBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/volcano_tiles.gbapal");
static const u32 sVolcanoBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/volcano_tiles.4bpp.lz");
static const u32 sVolcanoBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/volcano_map.bin.lz");

static const u16 sCaveBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/cave_tiles.gbapal");
static const u32 sCaveBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/cave_tiles.4bpp.lz");
static const u32 sCaveBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/cave_map.bin.lz");

static const u16 sDesertBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/desert_tiles.gbapal");
static const u32 sDesertBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/desert_tiles.4bpp.lz");
static const u32 sDesertBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/desert_map.bin.lz");

const struct DeckBattleBackground gDeckBackgrounds[BG_COUNT] =
{
    [BG_GRASS] =
    {
        .palette = sGrassBackgroundPalette,
        .tiles = sGrassBackgroundTiles,
        .map = sGrassBackgroundMap,
    },
    [BG_UNDERWATER] =
    {
        .palette = sUnderwaterBackgroundPalette,
        .tiles = sUnderwaterBackgroundTiles,
        .map = sUnderwaterBackgroundMap,
    },
    [BG_CITY] =
    {
        .palette = sCityBackgroundPalette,
        .tiles = sCityBackgroundTiles,
        .map = sCityBackgroundMap,
    },
    [BG_ICE_PATH] =
    {
        .palette = sIcePathBackgroundPalette,
        .tiles = sIcePathBackgroundTiles,
        .map = sIcePathBackgroundMap,
    },
    [BG_VOLCANO] =
    {
        .palette = sVolcanoBackgroundPalette,
        .tiles = sVolcanoBackgroundTiles,
        .map = sVolcanoBackgroundMap,
    },
    [BG_CAVE] =
    {
        .palette = sCaveBackgroundPalette,
        .tiles = sCaveBackgroundTiles,
        .map = sCaveBackgroundMap,
    },
    [BG_DESERT] =
    {
        .palette = sDesertBackgroundPalette,
        .tiles = sDesertBackgroundTiles,
        .map = sDesertBackgroundMap,
    },
};
