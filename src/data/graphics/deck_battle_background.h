// Grass
static const u16 sGrassBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/grass_tiles.gbapal");
static const u32 sGrassBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/grass_tiles.4bpp.lz");
static const u32 sGrassBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/grass_map.bin.lz");

// Underwater
static const u16 sUnderwaterBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/underwater_tiles.gbapal");
static const u32 sUnderwaterBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/underwater_tiles.4bpp.lz");
static const u32 sUnderwaterBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/underwater_map.bin.lz");

// City
static const u16 sCityBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/city_tiles.gbapal");
static const u32 sCityBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/city_tiles.4bpp.lz");
static const u32 sCityBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/city_map.bin.lz");

// Ice Path
static const u16 sIcePathBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/ice_path_tiles.gbapal");
static const u32 sIcePathBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/ice_path_tiles.4bpp.lz");
static const u32 sIcePathBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/ice_path_map.bin.lz");

// Volcano
static const u16 sVolcanoBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/volcano_tiles.gbapal");
static const u32 sVolcanoBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/volcano_tiles.4bpp.lz");
static const u32 sVolcanoBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/volcano_map.bin.lz");

// Cave
static const u16 sCaveBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/cave_tiles.gbapal");
static const u32 sCaveBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/cave_tiles.4bpp.lz");
static const u32 sCaveBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/cave_map.bin.lz");

// Desert
static const u16 sDesertBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/desert_tiles.gbapal");
static const u32 sDesertBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/desert_tiles.4bpp.lz");
static const u32 sDesertBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/desert_map.bin.lz");

static const u16 sDesertEveBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/desert_tiles_eve.gbapal");
static const u32 sDesertEveBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/desert_tiles_eve.4bpp.lz");
static const u32 sDesertEveBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/desert_map_eve.bin.lz");

static const u16 sDesertNightBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/desert_tiles_night.gbapal");
static const u32 sDesertNightBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/desert_tiles_night.4bpp.lz");
static const u32 sDesertNightBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/desert_map_night.bin.lz");

// Forest
static const u16 sForestBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/forest_tiles.gbapal");
static const u32 sForestBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/forest_tiles.4bpp.lz");
static const u32 sForestBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/forest_map.bin.lz");

static const u16 sForestEveBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/forest_tiles_eve.gbapal");
static const u32 sForestEveBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/forest_tiles_eve.4bpp.lz");
static const u32 sForestEveBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/forest_map_eve.bin.lz");

static const u16 sForestNightBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/forest_tiles_night.gbapal");
static const u32 sForestNightBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/forest_tiles_night.4bpp.lz");
static const u32 sForestNightBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/forest_map_night.bin.lz");

const struct DeckBattleBackground gDeckBackgrounds[BG_COUNT] =
{
    // Fields
    [BG_GRASS] =
    {
        .palette = sGrassBackgroundPalette,
        .tiles = sGrassBackgroundTiles,
        .map = sGrassBackgroundMap,
    },
    [BG_GRASS_EVE] =
    {
        .palette = sGrassBackgroundPalette,
        .tiles = sGrassBackgroundTiles,
        .map = sGrassBackgroundMap,
    },
    [BG_GRASS_NIGHT] =
    {
        .palette = sGrassBackgroundPalette,
        .tiles = sGrassBackgroundTiles,
        .map = sGrassBackgroundMap,
    },

    // Underwater
    [BG_UNDERWATER] =
    {
        .palette = sUnderwaterBackgroundPalette,
        .tiles = sUnderwaterBackgroundTiles,
        .map = sUnderwaterBackgroundMap,
    },
    [BG_UNDERWATER_EVE] =
    {
        .palette = sUnderwaterBackgroundPalette,
        .tiles = sUnderwaterBackgroundTiles,
        .map = sUnderwaterBackgroundMap,
    },
    [BG_UNDERWATER_NIGHT] =
    {
        .palette = sUnderwaterBackgroundPalette,
        .tiles = sUnderwaterBackgroundTiles,
        .map = sUnderwaterBackgroundMap,
    },

    // City
    [BG_CITY] =
    {
        .palette = sCityBackgroundPalette,
        .tiles = sCityBackgroundTiles,
        .map = sCityBackgroundMap,
    },
    [BG_CITY_EVE] =
    {
        .palette = sUnderwaterBackgroundPalette,
        .tiles = sUnderwaterBackgroundTiles,
        .map = sUnderwaterBackgroundMap,
    },
    [BG_CITY_NIGHT] =
    {
        .palette = sUnderwaterBackgroundPalette,
        .tiles = sUnderwaterBackgroundTiles,
        .map = sUnderwaterBackgroundMap,
    },

    // Ice Path
    [BG_ICE_PATH] =
    {
        .palette = sIcePathBackgroundPalette,
        .tiles = sIcePathBackgroundTiles,
        .map = sIcePathBackgroundMap,
    },
    [BG_ICE_PATH_EVE] =
    {
        .palette = sIcePathBackgroundPalette,
        .tiles = sIcePathBackgroundTiles,
        .map = sIcePathBackgroundMap,
    },
    [BG_ICE_PATH_NIGHT] =
    {
        .palette = sIcePathBackgroundPalette,
        .tiles = sIcePathBackgroundTiles,
        .map = sIcePathBackgroundMap,
    },

    // Volcano
    [BG_VOLCANO] =
    {
        .palette = sVolcanoBackgroundPalette,
        .tiles = sVolcanoBackgroundTiles,
        .map = sVolcanoBackgroundMap,
    },
    [BG_VOLCANO_EVE] =
    {
        .palette = sVolcanoBackgroundPalette,
        .tiles = sVolcanoBackgroundTiles,
        .map = sVolcanoBackgroundMap,
    },
    [BG_VOLCANO_NIGHT] =
    {
        .palette = sVolcanoBackgroundPalette,
        .tiles = sVolcanoBackgroundTiles,
        .map = sVolcanoBackgroundMap,
    },

    // Cave
    [BG_CAVE] =
    {
        .palette = sCaveBackgroundPalette,
        .tiles = sCaveBackgroundTiles,
        .map = sCaveBackgroundMap,
    },
    [BG_CAVE_EVE] =
    {
        .palette = sCaveBackgroundPalette,
        .tiles = sCaveBackgroundTiles,
        .map = sCaveBackgroundMap,
    },
    [BG_CAVE_NIGHT] =
    {
        .palette = sCaveBackgroundPalette,
        .tiles = sCaveBackgroundTiles,
        .map = sCaveBackgroundMap,
    },

    // Cave
    [BG_DESERT] =
    {
        .palette = sDesertBackgroundPalette,
        .tiles = sDesertBackgroundTiles,
        .map = sDesertBackgroundMap,
    },
    [BG_DESERT_EVE] =
    {
        .palette = sDesertEveBackgroundPalette,
        .tiles = sDesertEveBackgroundTiles,
        .map = sDesertEveBackgroundMap,
    },
    [BG_DESERT_NIGHT] =
    {
        .palette = sDesertNightBackgroundPalette,
        .tiles = sDesertNightBackgroundTiles,
        .map = sDesertNightBackgroundMap,
    },

    // Forest
    [BG_FOREST] =
    {
        .palette = sForestBackgroundPalette,
        .tiles = sForestBackgroundTiles,
        .map = sForestBackgroundMap,
    },
    [BG_FOREST_EVE] =
    {
        .palette = sForestBackgroundPalette,
        .tiles = sForestBackgroundTiles,
        .map = sForestBackgroundMap,
    },
    [BG_FOREST_NIGHT] =
    {
        .palette = sForestBackgroundPalette,
        .tiles = sForestBackgroundTiles,
        .map = sForestBackgroundMap,
    },
};
