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

// Underwater Template Pools
static const u8 sUnderwaterNormalRooms[] =
{
    MAP_NUM(UNDERWATER_TEMPLATES_ROOM1),
    MAP_NUM(UNDERWATER_TEMPLATES_ROOM2),
    MAP_NUM(UNDERWATER_TEMPLATES_ROOM3),
    MAP_NUM(UNDERWATER_TEMPLATES_ROOM4),
    MAP_NUM(UNDERWATER_TEMPLATES_ROOM5),
};

// City Template Pools
static const u8 sCityNormalRooms[] =
{
    MAP_NUM(CITY_TEMPLATES_ROOM1),
    MAP_NUM(CITY_TEMPLATES_ROOM2),
    MAP_NUM(CITY_TEMPLATES_ROOM3),
    MAP_NUM(CITY_TEMPLATES_ROOM4),
    MAP_NUM(CITY_TEMPLATES_ROOM5),
};

const struct TemplateRules gTemplateRules[TEMPLATE_TYPES_COUNT] = 
{
    [TEMPLATES_UNDERWATER] =
    {
        .name = COMPOUND_STRING("Reefs"),
        .mapGroup = MAP_GROUP(UNDERWATER_TEMPLATES_ROOM1),
        .bgm = MUS_UNDERWATER,
        .background = BG_UNDERWATER,
        .connectionType = CONNECTION_TYPE_WARP,
        .offsets = {
            [DIR_NORTH] = {0, -1, 1, 1},
            [DIR_SOUTH] = {0, 1, 1, 1},
            [DIR_EAST] = {0, 0, 2, 1},
            [DIR_WEST] = {-1, 0, 2, 1},
        },
        .numNormalRooms = ARRAY_COUNT(sUnderwaterNormalRooms),
        .normalRoomIds = sUnderwaterNormalRooms,
        .specialRoomIds = {
            [BOSS_ROOM] = MAP_NUM(UNDERWATER_TEMPLATES_BOSS_ROOM),
            [TREASURE_ROOM] = MAP_NUM(UNDERWATER_TEMPLATES_TREASURE_ROOM),
            [SHOP_ROOM] = MAP_NUM(UNDERWATER_TEMPLATES_SHOP_ROOM),
        },
        .itemPools = gDefaultItemPools,
        .encounterPool = {
            {SPECIES_KRABBY, 100},
            {SPECIES_SLOWPOKE, 100},
        }
    },

    [TEMPLATES_CITY] =
    {
        .name = COMPOUND_STRING("City"),
        .mapGroup = MAP_GROUP(CITY_TEMPLATES_CONNECTIONS),
        .bgm = MUS_RG_CELADON,
        .background = BG_CITY,
        .connectionType = CONNECTION_TYPE_SEAMLESS,
        .offsets = {
            [DIR_NORTH] = {-1, -5, 4, 5},
            [DIR_SOUTH] = {-1, 1, 4, 2},
            [DIR_EAST] = {1, -3, 2, 6},
            [DIR_WEST] = {-2, -3, 2, 6},
        },
        .numNormalRooms = ARRAY_COUNT(sCityNormalRooms),
        .normalRoomIds = sCityNormalRooms,
        .specialRoomIds = {
            [BOSS_ROOM] = MAP_NUM(CITY_TEMPLATES_BOSS_ROOM),
            [TREASURE_ROOM] = MAP_NUM(CITY_TEMPLATES_TREASURE_ROOM),
            [SHOP_ROOM] = MAP_NUM(CITY_TEMPLATES_SHOP_ROOM),
        },
        .itemPools = gDefaultItemPools,
        .encounterPool = {
            {SPECIES_RATTATA, 100},
            {SPECIES_SPEAROW, 100},
            {SPECIES_POOCHYENA, 100},
        }
    },
};
