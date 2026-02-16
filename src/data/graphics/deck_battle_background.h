static const u16 sGrassBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/grass_tiles.gbapal");
static const u32 sGrassBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/grass_tiles.4bpp.lz");
static const u32 sGrassBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/grass_map.bin.lz");

static const u16 sUnderwaterBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/underwater_tiles.gbapal");
static const u32 sUnderwaterBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/underwater_tiles.4bpp.lz");
static const u32 sUnderwaterBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/underwater_map.bin.lz");

static const u16 sCityBackgroundPalette[] = INCBIN_U16("graphics/deck_battle_backgrounds/city_tiles.gbapal");
static const u32 sCityBackgroundTiles[] = INCBIN_U32("graphics/deck_battle_backgrounds/city_tiles.4bpp.lz");
static const u32 sCityBackgroundMap[] = INCBIN_U32("graphics/deck_battle_backgrounds/city_map.bin.lz");

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
};
