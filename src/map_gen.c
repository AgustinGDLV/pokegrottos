#include "global.h"
#include "data_util.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "main.h"
#include "malloc.h"
#include "map_gen.h"
#include "overworld.h"
#include "random.h"
#include "sound.h"
#include "script.h"
#include "strings.h"
#include "string_util.h"
#include "text.h"
#include "constants/songs.h"

// global floorplan
EWRAM_DATA struct Floorplan gFloorplan = {0};

#include "data/prefab_rules.h"

// Generation helper functions
static u32 CountNeighbors(struct Floorplan* floorplan, u8 i)
{
    return (floorplan->layout[i-10].type >= NORMAL_ROOM) + (floorplan->layout[i-1].type >= NORMAL_ROOM) \
    + (floorplan->layout[i+1].type >= NORMAL_ROOM) + (floorplan->layout[i+10].type >= NORMAL_ROOM);
}

static bool32 Visit(struct Floorplan* floorplan, u8 i)
{
    if (floorplan->numRooms >= floorplan->maxRooms)
        return FALSE;
    if (floorplan->layout[i].type >= NORMAL_ROOM)
        return FALSE;
    if (CountNeighbors(floorplan, i) > 1)
        return FALSE;
    if (i != STARTING_ROOM && (Random() % 2))
        return FALSE;

    Enqueue(&floorplan->queue, i);
    floorplan->layout[i].type = 1;
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
    floorplan->mapGroup = 35;
    for (i = 0; i < LAYOUT_SIZE; ++i)
    {
        floorplan->layout[i].type = 0;
        floorplan->layout[i].visited = FALSE;
        floorplan->layout[i].mapNum = 1;
    }
}

// TODO: Take into account depth.
static u8 GetMaxRooms(void)
{
    return 15;
}

// Populates an empty floorplan.
static void PopulateFloorplan(struct Floorplan* floorplan)
{
    // Set up floorplan.
    ZeroFloorplan(floorplan);
    Enqueue(&floorplan->queue, STARTING_ROOM);
    floorplan->numRooms = 1;
    floorplan->layout[STARTING_ROOM].type = NORMAL_ROOM;
    floorplan->layout[STARTING_ROOM].visited = TRUE;
    floorplan->maxRooms = GetMaxRooms();

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
    floorplan->layout[Pop(&floorplan->endrooms)].type = BOSS_ROOM;
    while (floorplan->endrooms.top > 0)
        floorplan->layout[Pop(&floorplan->endrooms)].type = TREASURE_ROOM;
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
            row += floorplan->layout[ROOM_COORD(x, y)].type * exponent;
            exponent *= 10;
        }
        DebugPrintf("%d", row);
    }
}

void CreateDebugFloorplan(void)
{
    u32 attempts = 0;
    gSaveBlock1Ptr->currentRoom = STARTING_ROOM;
    do {
        PopulateFloorplan(&gFloorplan);
    } while (gFloorplan.numRooms < MIN_ROOMS && ++attempts < 10);
    AssignSpecialRooms(&gFloorplan);
    DebugPrintFloorplan(&gFloorplan);
}

bool32 DoesRoomExist(u8 i)
{
    return gFloorplan.layout[i].type >= NORMAL_ROOM;
}

bool32 IsRoomAdjacentToVisited(u8 i)
{
    if (gFloorplan.layout[i - 10].visited)
        return TRUE;
    if (gFloorplan.layout[i + 10].visited)
        return TRUE;
    if (gFloorplan.layout[i - 1].visited)
        return TRUE;
    if (gFloorplan.layout[i + 1].visited)
        return TRUE;
    return FALSE;
}

bool32 IsRoomMapIdValid(u8 i)
{
    return TRUE; //!(gFloorplan.layout[i].mapNum == 0 && gFloorplan.layout[i].mapGroup == 0);
}

u32 GetRoomInDirection(u32 dir)
{
    u32 target = 0;
    switch (dir)
    {
        case DIR_NORTH:
            target = gSaveBlock1Ptr->currentRoom - 10;
            break;
        case DIR_SOUTH:
            target = gSaveBlock1Ptr->currentRoom + 10;
            break;
        case DIR_EAST:
            target = gSaveBlock1Ptr->currentRoom + 1;
            break;
        case DIR_WEST:
            target = gSaveBlock1Ptr->currentRoom - 1;
            break;
    }
    return target;
}

void SetWarpDestinationToRoom(u8 i)
{
    SetWarpDestination(gFloorplan.mapGroup, gFloorplan.layout[i].mapNum, gSpecialVar_0x8000, -1, -1);
}

void TryWarpToRoom(void)
{
    u32 target = GetRoomInDirection(gSpecialVar_0x8000);
    gSpecialVar_Result = FALSE;

    // Don't warp if invalid room.
    if (!DoesRoomExist(target) || !IsRoomMapIdValid(target))
        return;

    // Set appropriate variables and flags.
    gSpecialVar_Result = TRUE;
    gSaveBlock1Ptr->currentRoom = target;
    gFloorplan.layout[target].visited = TRUE;

    // Do warp.
    StoreInitialPlayerAvatarState();
    LockPlayerFieldControls();
    TryFadeOutOldMapMusic();
    WarpFadeOutScreen();
    PlayRainStoppingSoundEffect();
    PlaySE(SE_EXIT);
    SetWarpDestinationToRoom(target);
    WarpIntoMap();
    SetMainCallback2(CB2_LoadMap);
}

struct MapChunk {
    u16 width;
    u16 height;
    u16 *map;
};

// Copies a rectangular area of a map layout and stores it in a MapChunk struct.
static void CopyMapChunk(u32 mapGroup, u32 mapNum, u32 x, u32 y, u32 width, u32 height, struct MapChunk *dest)
{
    s32 i, j;
    const struct MapLayout* src;

    dest->width = width;
    dest->height = height;
    dest->map = Alloc(sizeof(u16) * width * height);
    src = Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->mapLayout;

    for (i = 0; i < height; ++i)
    {
        for (j = 0; j < width; ++j)
        {
            dest->map[j + width * i] = src->map[src->width * (y + i) + x + j];
        }
    }
}

// Pastes a rectangular area of a map layout over gBackupMapLayout at
// the given (x, y) and frees the map stored in the MapChunk.
static void PasteMapChunk(u16 x, u16 y, struct MapChunk *chunk)
{
    u16 *src, *dest;
    int i;
    src = chunk->map;
    dest = gBackupMapLayout.map;
    dest += gBackupMapLayout.width * (7 + y) + x + MAP_OFFSET;
    for (i = 0; i < chunk->height; ++i)
    {
        CpuCopy16(src, dest, chunk->width * 2);
        dest += gBackupMapLayout.width;
        src += chunk->width;
    }
    Free(chunk->map);
    chunk->map = NULL;
}

static s32 GetCoverXOffset(u32 dir)
{
    u32 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    return sPrefabRules[mapGroup].offsets[dir][0];
}

static s32 GetCoverYOffset(u32 dir)
{
    u32 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    return sPrefabRules[mapGroup].offsets[dir][1];
}

static void CoverExitInDirection(u32 dir)
{
    u32 mapGroup, chunkWidth, chunkHeight;
    struct MapChunk chunk;
    const struct WarpEvent* warp;
    const struct MapLayout* layout;

    mapGroup = gSaveBlock1Ptr->location.mapGroup;
    warp = &gMapHeader.events->warps[GetOppositeDirection(dir)];
    layout = Overworld_GetMapHeaderByGroupAndId(mapGroup, 0)->mapLayout;

    chunkWidth = layout->width;
    chunkHeight = layout->height/4;
    CopyMapChunk(mapGroup, 0, 0, (dir - 1) * chunkHeight, chunkWidth, chunkHeight, &chunk);
    PasteMapChunk(warp->x + GetCoverXOffset(dir), warp->y + GetCoverYOffset(dir), &chunk);
}

void CoverInvalidRoomExits(void)
{
    u32 i, target;
    for (i = DIR_SOUTH; i <= DIR_EAST; ++i)
    {
        target = GetRoomInDirection(i);
        if (!DoesRoomExist(target) || !IsRoomMapIdValid(target))
            CoverExitInDirection(i);
    }
}
