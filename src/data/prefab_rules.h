struct PrefabRules {
    s8 offsets[5][2]; // (x, y) entrance cover offsets for each direction
};

static const struct PrefabRules sPrefabRules[MAP_GROUPS_COUNT] = 
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
    },
};
