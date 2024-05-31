#include "map_gen.h"
#include "item_gen.h"
#include "battle.h"

// This file contains all the data for shop, loot, Pokemon, and room pools
// for each template map group. It also contains offsets for exit covers.

// Items use an array of "pool tables." The array contains ITEM_TIER_COUNT
// different pool tables. These tables contain pointers to medicine, battle item
// hold item, upgrade, and treasure pools. If set to {0}, the code will just
// read from the default pools below.

// These item pools are usually used for all templates, but there is
// more variability in holdItems and treasures.
static const struct WeightedElement sDefaultMedicinePools[ITEM_TIER_COUNT][MAX_WEIGHTED_POOL_SIZE] =
{
    [ITEM_TIER_1] = {
        {ITEM_SUPER_POTION,     100},
        {ITEM_SITRUS_BERRY,     80},
        {ITEM_FULL_HEAL,        40},
        {ITEM_FULL_RESTORE,     35},
    },
    [ITEM_TIER_2] = {
        {ITEM_SUPER_POTION,     80},
        {ITEM_SITRUS_BERRY,     80},
        {ITEM_FULL_HEAL,        50},
        {ITEM_FULL_RESTORE,     45},
    },
    [ITEM_TIER_3] = {
        {ITEM_SUPER_POTION,     40},
        {ITEM_SITRUS_BERRY,     60},
        {ITEM_FULL_HEAL,        60},
        {ITEM_FULL_RESTORE,     95},
    },
    [ITEM_TIER_4] = {
        {ITEM_SUPER_POTION,     20},
        {ITEM_SITRUS_BERRY,     60},
        {ITEM_FULL_HEAL,        80},
        {ITEM_FULL_RESTORE,     95},
    },
    [ITEM_TIER_5] = {
        {ITEM_SITRUS_BERRY,     60},
        {ITEM_FULL_HEAL,        100},
        {ITEM_FULL_RESTORE,     95},
    },
};

static const struct WeightedElement sDefaultBattleItemPools[ITEM_TIER_COUNT][MAX_WEIGHTED_POOL_SIZE] =
{
    [ITEM_TIER_1] = {
        {ITEM_MAX_MUSHROOMS,    5},
    },
    [ITEM_TIER_2] = {
        {ITEM_MAX_MUSHROOMS,    5},
    },
    [ITEM_TIER_3] = {
        {ITEM_MAX_MUSHROOMS,    5},
    },
    [ITEM_TIER_4] = {
        {ITEM_MAX_MUSHROOMS,    5},
    },
    [ITEM_TIER_5] = {
        {ITEM_MAX_MUSHROOMS,    5},
    },
};

static const struct WeightedElement sDefaultHoldItemPools[ITEM_TIER_COUNT][MAX_WEIGHTED_POOL_SIZE] =
{
    [ITEM_TIER_1] = {
        {ITEM_LEFTOVERS,        255},
    },
    [ITEM_TIER_2] = {
        {ITEM_LEFTOVERS,        255},
    },
    [ITEM_TIER_3] = {
        {ITEM_LEFTOVERS,        255},
    },
    [ITEM_TIER_4] = {
        {ITEM_LEFTOVERS,        255},
    },
    [ITEM_TIER_5] = {
        {ITEM_LEFTOVERS,        255},
    },
};

static const struct WeightedElement sDefaultUpgradePools[ITEM_TIER_COUNT][MAX_WEIGHTED_POOL_SIZE] =
{
    [ITEM_TIER_1] = {
        {ITEM_ABILITY_PATCH,    100},
        {ITEM_ABILITY_CAPSULE,  80},
        {ITEM_PP_MAX,           40},
        {ITEM_SHINY_STONE,      35},
    },
    [ITEM_TIER_2] = {
        {ITEM_ABILITY_PATCH,    80},
        {ITEM_ABILITY_CAPSULE,  80},
        {ITEM_PP_MAX,           50},
        {ITEM_SHINY_STONE,      45},
    },
    [ITEM_TIER_3] = {
        {ITEM_ABILITY_PATCH,    40},
        {ITEM_ABILITY_CAPSULE,  60},
        {ITEM_PP_MAX,           60},
        {ITEM_SHINY_STONE,      95},
    },
    [ITEM_TIER_4] = {
        {ITEM_ABILITY_PATCH,    20},
        {ITEM_ABILITY_CAPSULE,  60},
        {ITEM_PP_MAX,           80},
        {ITEM_SHINY_STONE,      95},
    },
    [ITEM_TIER_5] = {
        {ITEM_ABILITY_CAPSULE,  60},
        {ITEM_PP_MAX,           100},
        {ITEM_SHINY_STONE,      95},
    },
};

static const struct WeightedElement sDefaultTreasurePools[ITEM_TIER_COUNT][MAX_WEIGHTED_POOL_SIZE] =
{
    [ITEM_TIER_1] = {
        {ITEM_RELIC_CROWN,        1},
    },
    [ITEM_TIER_2] = {
        {ITEM_RELIC_CROWN,        1},
    },
    [ITEM_TIER_3] = {
        {ITEM_RELIC_CROWN,        1},
    },
    [ITEM_TIER_4] = {
        {ITEM_RELIC_CROWN,        1},
    },
    [ITEM_TIER_5] = {
        {ITEM_RELIC_CROWN,        1},
    },
};

const struct ItemPoolTable gDefaultItemPools[ITEM_TIER_COUNT] =
{
    [ITEM_TIER_1] = {
        .medicines = sDefaultMedicinePools[ITEM_TIER_1],
        .battleItems = sDefaultBattleItemPools[ITEM_TIER_1],
        .holdItems = sDefaultHoldItemPools[ITEM_TIER_1],
        .upgrades = sDefaultUpgradePools[ITEM_TIER_1],
        .treasures = sDefaultTreasurePools[ITEM_TIER_1],
    },
    [ITEM_TIER_2] = {
        .medicines = sDefaultMedicinePools[ITEM_TIER_2],
        .battleItems = sDefaultBattleItemPools[ITEM_TIER_2],
        .holdItems = sDefaultHoldItemPools[ITEM_TIER_2],
        .upgrades = sDefaultUpgradePools[ITEM_TIER_2],
        .treasures = sDefaultTreasurePools[ITEM_TIER_2],
    },
    [ITEM_TIER_3] = {
        .medicines = sDefaultMedicinePools[ITEM_TIER_3],
        .battleItems = sDefaultBattleItemPools[ITEM_TIER_3],
        .holdItems = sDefaultHoldItemPools[ITEM_TIER_3],
        .upgrades = sDefaultUpgradePools[ITEM_TIER_3],
        .treasures = sDefaultTreasurePools[ITEM_TIER_3],
    },
    [ITEM_TIER_4] = {
        .medicines = sDefaultMedicinePools[ITEM_TIER_4],
        .battleItems = sDefaultBattleItemPools[ITEM_TIER_4],
        .holdItems = sDefaultHoldItemPools[ITEM_TIER_4],
        .upgrades = sDefaultUpgradePools[ITEM_TIER_4],
        .treasures = sDefaultTreasurePools[ITEM_TIER_4],
    },
    [ITEM_TIER_5] = {
        .medicines = sDefaultMedicinePools[ITEM_TIER_5],
        .battleItems = sDefaultBattleItemPools[ITEM_TIER_5],
        .holdItems = sDefaultHoldItemPools[ITEM_TIER_5],
        .upgrades = sDefaultUpgradePools[ITEM_TIER_5],
        .treasures = sDefaultTreasurePools[ITEM_TIER_5],
    },
};

// Cave Template Pools
static const u8 sCaveNormalRooms[] =
{
    MAP_NUM(CAVE_TEMPLATES_ROOM1),
};

// Volcano Template Pools
static const u8 sHotCaveNormalRooms[] =
{
    MAP_NUM(ICE_CAVE_TEMPLATES_ROOM1),
};

// Ice Path Template Pools
static const u8 sIceCaveNormalRooms[] =
{
    MAP_NUM(ICE_CAVE_TEMPLATES_ROOM1),
};

// Power Plant Template Pools
static const u8 sPowerPlantNormalRooms[] =
{
    MAP_NUM(POWER_PLANT_TEMPLATES_ROOM1),
};

const struct TemplateRules gTemplateRules[TEMPLATE_TYPES_COUNT] = 
{
    [TEMPLATES_CAVE] =
    {
        .mapGroup = MAP_GROUP(CAVE_TEMPLATES_ROOM1),
        .bgm = MUS_RG_SEVII_CAVE,
        .previewId = PREVIEW_MT_MOON,
        .battleTerrain = BATTLE_TERRAIN_CAVE,
        .connectionType = CONNECTION_TYPE_WARP,
        .offsets = {
            [DIR_NORTH] = {-1, -1},
            [DIR_SOUTH] = {-1, 1},
            [DIR_EAST] = {0, 0},
            [DIR_WEST] = {-2, 0},
        },
        .numNormalRooms = ARRAY_COUNT(sCaveNormalRooms),
        .normalRoomIds = sCaveNormalRooms,
        .specialRoomIds = {
            [BOSS_ROOM] = MAP_NUM(CAVE_TEMPLATES_BOSS_ROOM),
            [TREASURE_ROOM] = MAP_NUM(CAVE_TEMPLATES_TREASURE_ROOM),
            [SHOP_ROOM] = MAP_NUM(CAVE_TEMPLATES_SHOP_ROOM),
        },
        .itemPools = gDefaultItemPools,
        .encounterPool = {
            {SPECIES_WHISMUR, 100},
            {SPECIES_POOCHYENA, 100},
            {SPECIES_GEODUDE, 100},
            {SPECIES_ZUBAT, 100},
            {SPECIES_ONIX, 100},
            {SPECIES_ARON, 100},
            {SPECIES_DIGLETT, 100},
        }
    },

    [TEMPLATES_ICE_PATH] =
    {
        .mapGroup = MAP_GROUP(ICE_CAVE_TEMPLATES_ROOM1),
        .bgm = MUS_HG_ICE_PATH,
        .previewId = PREVIEW_ICE_PATH,
        .battleTerrain = BATTLE_TERRAIN_CAVE,
        .connectionType = CONNECTION_TYPE_WARP,
        .offsets = {
            [DIR_NORTH] = {-1, -1},
            [DIR_SOUTH] = {-1, 1},
            [DIR_EAST] = {0, 0},
            [DIR_WEST] = {-2, 0},
        },
        .numNormalRooms = ARRAY_COUNT(sIceCaveNormalRooms),
        .normalRoomIds = sIceCaveNormalRooms,
        .specialRoomIds = {
            [BOSS_ROOM] = MAP_NUM(ICE_CAVE_TEMPLATES_BOSS_ROOM),
            [TREASURE_ROOM] = MAP_NUM(ICE_CAVE_TEMPLATES_TREASURE_ROOM),
            [SHOP_ROOM] = MAP_NUM(ICE_CAVE_TEMPLATES_SHOP_ROOM),
        },
        .itemPools = gDefaultItemPools,
        .encounterPool = {
            {SPECIES_SNOVER, 100},
            {SPECIES_POOCHYENA, 100},
            {SPECIES_GEODUDE, 100},
            {SPECIES_ZUBAT, 100},
            {SPECIES_SNEASEL, 100},
            {SPECIES_SPHEAL, 100},
            {SPECIES_DIGLETT, 100},
        }
    },

    [TEMPLATES_VOLCANO] =
    {
        .mapGroup = MAP_GROUP(HOT_CAVE_TEMPLATES_ROOM1),
        .bgm = MUS_DP_STARK_MOUNTAIN,
        .previewId = PREVIEW_MT_EMBER,
        .battleTerrain = BATTLE_TERRAIN_CAVE,
        .connectionType = CONNECTION_TYPE_WARP,
        .offsets = {
            [DIR_NORTH] = {-1, -1},
            [DIR_SOUTH] = {-1, 1},
            [DIR_EAST] = {0, 0},
            [DIR_WEST] = {-2, 0},
        },
        .numNormalRooms = ARRAY_COUNT(sHotCaveNormalRooms),
        .normalRoomIds = sHotCaveNormalRooms,
        .specialRoomIds = {
            [BOSS_ROOM] = MAP_NUM(HOT_CAVE_TEMPLATES_BOSS_ROOM),
            [TREASURE_ROOM] = MAP_NUM(HOT_CAVE_TEMPLATES_TREASURE_ROOM),
            [SHOP_ROOM] = MAP_NUM(HOT_CAVE_TEMPLATES_SHOP_ROOM),
        },
        .itemPools = gDefaultItemPools,
        .encounterPool = {
            {SPECIES_SLUGMA, 100},
            {SPECIES_HOUNDOUR, 100},
            {SPECIES_GEODUDE, 100},
            {SPECIES_ZUBAT, 100},
            {SPECIES_MAGBY, 100},
            {SPECIES_DROWZEE, 100},
            {SPECIES_DIGLETT, 100},
        }
    },

    [TEMPLATES_POWER_PLANT] =
    {
        .mapGroup = MAP_GROUP(POWER_PLANT_TEMPLATES_CONNECTIONS),
        .bgm = MUS_RG_POKE_MANSION,
        .previewId = PREVIEW_POWER_PLANT,
        .battleTerrain = BATTLE_TERRAIN_CAVE,
        .connectionType = CONNECTION_TYPE_SEAMLESS,
        .offsets = {
            [DIR_NORTH] = {-2, -1},
            [DIR_SOUTH] = {-2, -5},
            [DIR_EAST] = {-3, -4},
            [DIR_WEST] = {-1, -4},
        },
        .numNormalRooms = ARRAY_COUNT(sPowerPlantNormalRooms),
        .normalRoomIds = sPowerPlantNormalRooms,
        .specialRoomIds = {
            [BOSS_ROOM] = MAP_NUM(POWER_PLANT_TEMPLATES_BOSS_ROOM),
            [TREASURE_ROOM] = MAP_NUM(POWER_PLANT_TEMPLATES_BOSS_ROOM),
            [SHOP_ROOM] = MAP_NUM(POWER_PLANT_TEMPLATES_BOSS_ROOM),
        },
        .itemPools = gDefaultItemPools,
        .encounterPool = {
            {SPECIES_MAGNEMITE, 100},
            {SPECIES_MAGNETON, 100},
            {SPECIES_VOLTORB, 100},
            {SPECIES_PLUSLE, 100},
            {SPECIES_MINUN, 100},
            {SPECIES_ZIGZAGOON, 100},
            {SPECIES_GRIMER, 100},
        }
    },
};
