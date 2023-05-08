static const u8 sCavePrefabsNormalRooms[] =
{
    MAP_NUM(CAVE_PREFABS_ROOM1),
    MAP_NUM(CAVE_PREFABS_ROOM2),
    MAP_NUM(CAVE_PREFABS_ROOM3),
    MAP_NUM(CAVE_PREFABS_ROOM4),
    MAP_NUM(CAVE_PREFABS_ROOM5),
    MAP_NUM(CAVE_PREFABS_ROOM7),
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
            [DIR_SOUTH] = {-1, -1},
            [DIR_EAST] = {-1, -1},
            [DIR_WEST] = {-1, -1},
        },
        .numNormalRooms = ARRAY_COUNT(sCavePrefabsNormalRooms),
        .normalRoomIds = sCavePrefabsNormalRooms,
        .specialRoomIds = {
            [BOSS_ROOM] = MAP_NUM(CAVE_PREFABS_BOSS_ROOM),
            [TREASURE_ROOM] = MAP_NUM(CAVE_PREFABS_TREASURE_ROOM),
            [SHOP_ROOM] = MAP_NUM(CAVE_PREFABS_SHOP_ROOM),
        },
    },
};
