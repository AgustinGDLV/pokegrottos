#include "map_gen.h"
#include "item_gen.h"

// This file contains all the data for shop, loot, Pokemon, and room pools
// for each template map group. It also contains offsets for exit covers.

// Items use an array of "pool tables." The array contains ITEM_TIER_COUNT
// different pool tables. These tables contain pointers to medicine, battle item
// hold item, upgrade, and treasure pools. If set to {0}, the code will just
// read from the default pools below.

// These item pools are usually used for all templates, but there is
// more variability in holdItems and treasures.
static const struct WeightedItem sDefaultMedicinePools[ITEM_TIER_COUNT][ITEM_POOL_SIZE] =
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

static const struct WeightedItem sDefaultBattleItemPools[ITEM_TIER_COUNT][ITEM_POOL_SIZE] =
{
    [ITEM_TIER_1] = {
        {ITEM_X_SP_DEF,         100},
        {ITEM_X_DEFENSE,        80},
        {ITEM_X_SPEED,          40},
        {ITEM_MAX_MUSHROOMS,    35},
    },
    [ITEM_TIER_2] = {
        {ITEM_X_SP_DEF,         80},
        {ITEM_X_DEFENSE,        80},
        {ITEM_X_SPEED,          50},
        {ITEM_MAX_MUSHROOMS,    45},
    },
    [ITEM_TIER_3] = {
        {ITEM_X_SP_DEF,         40},
        {ITEM_X_DEFENSE,        60},
        {ITEM_X_SPEED,          60},
        {ITEM_MAX_MUSHROOMS,    95},
    },
    [ITEM_TIER_4] = {
        {ITEM_X_SP_DEF,         20},
        {ITEM_X_DEFENSE,        60},
        {ITEM_X_SPEED,          80},
        {ITEM_MAX_MUSHROOMS,    95},
    },
    [ITEM_TIER_5] = {
        {ITEM_X_ATTACK,         60},
        {ITEM_X_SPEED,          100},
        {ITEM_MAX_MUSHROOMS,    95},
    },
};

static const struct WeightedItem sDefaultHoldItemPools[ITEM_TIER_COUNT][ITEM_POOL_SIZE] =
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

static const struct WeightedItem sDefaultUpgradePools[ITEM_TIER_COUNT][ITEM_POOL_SIZE] =
{
    [ITEM_TIER_1] = {
        {ITEM_ABILITY_PATCH,    100},
        {ITEM_ABILITY_CAPSULE,  80},
        {ITEM_PP_MAX,           40},
        {ITEM_FIRE_STONE,       35},
    },
    [ITEM_TIER_2] = {
        {ITEM_ABILITY_PATCH,    80},
        {ITEM_ABILITY_CAPSULE,  80},
        {ITEM_PP_MAX,           50},
        {ITEM_FIRE_STONE,       45},
    },
    [ITEM_TIER_3] = {
        {ITEM_ABILITY_PATCH,    40},
        {ITEM_ABILITY_CAPSULE,  60},
        {ITEM_PP_MAX,           60},
        {ITEM_FIRE_STONE,       95},
    },
    [ITEM_TIER_4] = {
        {ITEM_ABILITY_PATCH,    20},
        {ITEM_ABILITY_CAPSULE,  60},
        {ITEM_PP_MAX,           80},
        {ITEM_FIRE_STONE,       95},
    },
    [ITEM_TIER_5] = {
        {ITEM_ABILITY_CAPSULE,  60},
        {ITEM_PP_MAX,           100},
        {ITEM_FIRE_STONE,       95},
    },
};

static const struct WeightedItem sDefaultTreasurePools[ITEM_TIER_COUNT][ITEM_POOL_SIZE] =
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
    MAP_NUM(CAVE_PREFABS_ROOM1),
    MAP_NUM(CAVE_PREFABS_ROOM2),
    MAP_NUM(CAVE_PREFABS_ROOM3),
    MAP_NUM(CAVE_PREFABS_ROOM4),
    MAP_NUM(CAVE_PREFABS_ROOM5),
    MAP_NUM(CAVE_PREFABS_ROOM7),
};

static const struct ItemPoolTable sCaveKecleonShopPools[ITEM_TIER_COUNT] = 
{
    [ITEM_TIER_1] = {},
    [ITEM_TIER_2] = {},
    [ITEM_TIER_3] = {},
    [ITEM_TIER_4] = {},
    [ITEM_TIER_5] = {},
};

const struct PrefabRules gPrefabRules[MAP_GROUPS_COUNT] = 
{
    [MAP_GROUP(FOREST_PREFABS_BASES)] =
    {
        .offsets = {
            [DIR_NORTH] = {0, -1},
            [DIR_SOUTH] = {0, -1},
            [DIR_EAST] = {-1, 0},
            [DIR_WEST] = {-1, 0},
        },
    },

    [MAP_GROUP(CAVE_PREFABS_BASES)] =
    {
        .offsets = {
            [DIR_NORTH] = {-1, -1},
            [DIR_SOUTH] = {-1, 1},
            [DIR_EAST] = {-1, 0},
            [DIR_WEST] = {-1, 0},
        },
        .numNormalRooms = ARRAY_COUNT(sCaveNormalRooms),
        .normalRoomIds = sCaveNormalRooms,
        .specialRoomIds = {
            [BOSS_ROOM] = MAP_NUM(CAVE_PREFABS_BOSS_ROOM),
            [TREASURE_ROOM] = MAP_NUM(CAVE_PREFABS_TREASURE_ROOM),
            [SHOP_ROOM] = MAP_NUM(CAVE_PREFABS_SHOP_ROOM),
        },
        .kecleonShopPools = sCaveKecleonShopPools,
    },
};

