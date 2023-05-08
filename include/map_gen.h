#ifndef GUARD_MAP_GEN_H
#define GUARD_MAP_GEN_H

#include "data_util.h"

// Constants
#define LAYOUT_SIZE             90
#define MAX_LAYOUT_WIDTH        9
#define MAX_LAYOUT_HEIGHT       8
#define MIN_ROOMS               7
#define MAX_ROOMS               20
#define STARTING_ROOM           45
#define PREFAB_MAP_GROUP_START  MAP_GROUP(FOREST_PREFABS_BASES)

#define ROOM_COORD(x, y)    ((x+1) + (y+1)*10)  // gFloorplan.layout is not zero-indexed

enum RoomTypes {
    NORMAL_ROOM = 1,
    BOSS_ROOM,
    TREASURE_ROOM,
    SHOP_ROOM,
    CHALLENGE_ROOM,
    NUM_ROOM_TYPES,
};

struct Room {
    enum RoomTypes type:4;      // room type
    u8 visited:4;               // has player visited this room
    u8 mapNum;
};

struct Floorplan {
    u8 numRooms;
    u8 maxRooms;
    struct Room layout[LAYOUT_SIZE];
    struct Queue queue;                 // the queue of rooms to visit during algorithm
    struct Stack endrooms;              // stores the indices of endrooms in order of decr. distance
    u8 occupiedRooms[20];               // stores the indices of occupied rooms
    u8 mapGroup;
    u16 nextFloorSeed;
};

struct PrefabRules {
    s8 offsets[5][2]; // (x, y) entrance cover offsets for each direction
    u8 numNormalRooms;
    const u8* normalRoomIds;
    u8 specialRoomIds[NUM_ROOM_TYPES];
};

extern struct Floorplan gFloorplan;
extern const struct PrefabRules gPrefabRules[MAP_GROUPS_COUNT];

void DebugPrintFloorplan(struct Floorplan* floorplan);
void CreateDebugFloorplan(void);
bool32 DoesRoomExist(u8 i);
bool32 IsRoomAdjacentToVisited(u8 i);
u32 GetRoomInDirection(u32 dir);
void SetWarpDestinationToRoom(u8 i);
void TryWarpToRoom(void);

#endif
