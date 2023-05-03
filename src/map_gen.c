#include "global.h"
#include "malloc.h"
#include "map_gen.h"
#include "random.h"
#include "strings.h"
#include "string_util.h"
#include "text.h"

// global floorplan
EWRAM_DATA struct Floorplan gFloorplan = {0};

// Queue helper functions
static void ZeroQueue(struct Queue* queue)
{
    u32 i;
    queue->size = 0;
    queue->front = 0;
    queue->rear = 0;
    for (i = 0; i < MAX_QUEUE_SIZE; ++i)
        queue->arr[i] = 0;
}

static void Enqueue(struct Queue* queue, u8 item)
{
    if (queue->size == MAX_QUEUE_SIZE)
        return;
    queue->arr[queue->rear] = item;
    queue->rear += 1;
    queue->size += 1;
}

static u8 Dequeue(struct Queue* queue)
{
    u8 item;
    u32 i;
    if (queue->size == 0)
        return 0;

    item = queue->arr[queue->front];
    for (i = 0; i < queue->rear - 1; ++i)
    {
        queue->arr[i] = queue->arr[i + 1];
    }
    queue->rear -= 1;
    queue->size -= 1;
    return item;
}

static void DebugPrintQueue(struct Queue* queue)
{
    u32 i;
    DebugPrintf("Queue:");
    for (i = 0; i < queue->size; ++i)
        DebugPrintf("%d: %d", i, queue->arr[queue->front + i]);
    DebugPrintf("\n");
}

// Stack helper functions
static void ZeroStack(struct Stack* stack)
{
    u32 i;
    stack->top = 0;
    for (i = 0; i < MAX_STACK_SIZE; ++i)
        stack->arr[i] = 0;
}

static void Push(struct Stack* stack, u8 item)
{
    if (stack->top >= MAX_STACK_SIZE)
        return;
    stack->arr[stack->top] = item;
    stack->top += 1;
}

static u8 Pop(struct Stack* stack)
{
    u8 item;
    if (stack->top == 0)
        return 0;
    stack->top -= 1;
    item = stack->arr[stack->top];
    return item;
}

// Generation helper functions
static u32 CountNeighbors(struct Floorplan* floorplan, u8 i)
{
    return floorplan->layout[i-10] + floorplan->layout[i-1] + floorplan->layout[i+1] + floorplan->layout[i+10];
}

static bool32 Visit(struct Floorplan* floorplan, u8 i)
{
    if (floorplan->numRooms >= floorplan->maxRooms)
        return FALSE;
    if (floorplan->layout[i])
        return FALSE;
    if (CountNeighbors(floorplan, i) > 1)
        return FALSE;
    if (i != STARTING_ROOM && (Random() % 2))
        return FALSE;

    Enqueue(&floorplan->queue, i);
    floorplan->layout[i] = 1;
    floorplan->numRooms += 1;
    return TRUE;
}

static void ZeroFloorplan(struct Floorplan* floorplan)
{
    u32 i;
    floorplan->numRooms = 0;
    floorplan->maxRooms = 0;
    ZeroQueue(&floorplan->queue);
    ZeroStack(&floorplan->endrooms);
    for (i = 0; i < LAYOUT_SIZE; ++i)
        floorplan->layout[i] = 0;
}

// Populates an empty floorplan.
// TODO: Take into account depth.
static void PopulateFloorplan(struct Floorplan* floorplan)
{
    // Set up floorplan.
    Enqueue(&floorplan->queue, STARTING_ROOM);
    floorplan->numRooms = 1;
    floorplan->layout[STARTING_ROOM] = 1;
    floorplan->maxRooms = 15;
    // Generate rooms.
    while (floorplan->queue.size > 0)
    {
        u32 i, x;
        bool32 createdRoom = FALSE;
        // DebugPrintQueue(&floorplan->queue);
        i = Dequeue(&floorplan->queue);
        x = i % 10;
        if (x > 1)
            createdRoom |= Visit(floorplan, i - 1);
        if (x < 9)
            createdRoom |= Visit(floorplan, i + 1);
        if (i > 20)
            createdRoom |= Visit(floorplan, i - 10);
        if (i < 70)
            createdRoom |= Visit(floorplan, i + 10);
        if (!createdRoom)
            Push(&floorplan->endrooms, i);
    }
}

// TODO: Make this more functional (wow!).
static void AssignSpecialRooms(struct Floorplan* floorplan)
{
    floorplan->layout[Pop(&floorplan->endrooms)] = BOSS_ROOM;
    while (floorplan->endrooms.top > 0)
        floorplan->layout[Pop(&floorplan->endrooms)] = TREASURE_ROOM;
}

// This prints the floor layout backwards.
void DebugPrintFloorplan(struct Floorplan* floorplan)
{
    u32 x, y, row, exponent;
    for (y = 0; y < MAX_LAYOUT_HEIGHT; ++y)
    {
        row = 2000000000;
        exponent = 1;
        for(x = 0; x < MAX_LAYOUT_WIDTH; ++x)
        {
            row += floorplan->layout[ROOM_COORD(x, y)] * exponent;
            exponent *= 10;
        }
        DebugPrintf("%d", row);
    }
}

void CreateDebugFloorplan(void)
{
    do {
        ZeroFloorplan(&gFloorplan);
        PopulateFloorplan(&gFloorplan);
    } while (gFloorplan.numRooms < MIN_ROOMS);
    AssignSpecialRooms(&gFloorplan);
    DebugPrintFloorplan(&gFloorplan);
}
