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
    return GetTemplateRules(gFloorplan.templateType)->offsets[dir][0];
}

static s32 GetCoverYOffset(u32 dir)
{
    return GetTemplateRules(gFloorplan.templateType)->offsets[dir][1];
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
        if (!DoesRoomExist(target))
            CoverExitInDirection(i);
    }
}
