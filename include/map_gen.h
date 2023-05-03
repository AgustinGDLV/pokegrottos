#ifndef GUARD_MAP_GEN_H
#define GUARD_MAP_GEN_H

#define MAX_QUEUE_SIZE      20
#define MAX_STACK_SIZE      10
#define LAYOUT_SIZE         100
#define MAX_LAYOUT_WIDTH    9
#define MAX_LAYOUT_HEIGHT   8

#define MIN_ROOMS       7

#define STARTING_ROOM   45

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

struct Floorplan {
    u8 numRooms;
    u8 maxRooms;
    u8 layout[LAYOUT_SIZE];
    struct Queue queue;
    struct Stack endrooms;
};

void DebugPrintFloorplan(struct Floorplan* floorplan);
void CreateDebugFloorplan(void);

#endif