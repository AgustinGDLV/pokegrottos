#ifndef GUARD_MAP_GEN_H
#define GUARD_MAP_GEN_H

// Sizes
#define MAX_QUEUE_SIZE      20
#define MAX_STACK_SIZE      10
#define LAYOUT_SIZE         90
#define MAX_LAYOUT_WIDTH    9
#define MAX_LAYOUT_HEIGHT   8

// Misc. Constants
#define MIN_ROOMS       7
#define STARTING_ROOM   45

#define ROOM_COORD(x, y)    ((x+1) + (y+1)*10)  // gFloorplan.layout is not zero-indexed

struct Queue {
    u8 front;
    u8 rear;
    u8 size;
    u8 arr[MAX_QUEUE_SIZE];
};

struct Stack {
    u8 top;
    u8 arr[MAX_STACK_SIZE];
};


enum RoomTypes {
    NORMAL_ROOM = 1,
    BOSS_ROOM,
    TREASURE_ROOM,
    SHOP_ROOM,
};

struct Room {
    enum RoomTypes type:4;      // room type
    u8 visited:4;               // has player visited this room
    u8 mapGroup;
    u8 mapNum;
};

struct Floorplan {
    u8 numRooms;
    u8 maxRooms;
    struct Room layout[LAYOUT_SIZE];
    struct Queue queue;
    struct Stack endrooms;
};

extern struct Floorplan gFloorplan;

void DebugPrintFloorplan(struct Floorplan* floorplan);
void CreateDebugFloorplan(void);
bool32 DoesRoomExist(u8 i);
bool32 IsRoomAdjacentToVisited(u8 i);
bool32 IsRoomMapIdValid(u8 i);
void SetWarpDestinationToRoom(u8 i);

#endif
