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

// Ice Cave Template Pools
static const u8 sIceCaveNormalRooms[] =
{
    0,
};

const struct TemplateRules gTemplateRules[TEMPLATE_TYPES_COUNT] = 
{
    [TEMPLATES_ICE_CAVE] =
    {
        .mapGroup = 0,
        .bgm = MUS_RG_SEVII_CAVE,
        .battleTerrain = BATTLE_TERRAIN_CAVE,
        .lighting = 12,
        .offsets = {
            [DIR_NORTH] = {-1, -1},
            [DIR_SOUTH] = {-1, 1},
            [DIR_EAST] = {-1, 0},
            [DIR_WEST] = {-1, 0},
        },
        .numNormalRooms = ARRAY_COUNT(sIceCaveNormalRooms),
        .normalRoomIds = sIceCaveNormalRooms,
        .specialRoomIds = {
            [BOSS_ROOM] = 0,
            [TREASURE_ROOM] = 0,
            [SHOP_ROOM] = 0,
        },
        .itemPools = gDefaultItemPools,
        .encounterPool = {
            {SPECIES_SPHEAL, 100},
        }
    },
};
