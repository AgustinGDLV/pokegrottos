#ifndef GUARD_TRAIL_INTERFACE_H
#define GUARD_TRAIL_INTERFACE_H

void CB2_InitTrailInterface(void);

#define TRAIL_MAP_WIDTH     28
#define TRAIL_MAP_HEIGHT    17

enum Checkpoint
{
    CHECKPOINT_PEONY_TOWN,
    CHECKPOINT_FUNKY_FOREST_NORTH,
    CHECKPOINT_FUNKY_FOREST_EAST,
    CHECKPOINT_FUNKY_FOREST_WEST,
    CHECKPOINT_DEEP_DESERT_WEST,
    CHECKPOINT_DEEP_DESERT_EAST,
    CHECKPOINT_DEEP_DESERT_SOUTH,
    CHECKPOINT_COOL_COAST_NORTH,
    CHECKPOINT_COOL_COAST_EAST,
    CHECKPOINT_TULIP_TOWN,
    CHECKPOINT_MOLTEN_MOUNTAIN_NORTH,
    CHECKPOINT_MOLTEN_MOUNTAIN_SOUTH,
    CHECKPOINT_ORCHID_CITY,
};

struct PlayerPos
{
    u8 facing;
    u8 x;
    u8 y;
};

struct TrailInterface
{
    u8 playerSpriteId;
    u8 arrowSpriteIds[5]; // for each direction
    struct PlayerPos player;
    u16 keyHeldTimer;
    u8 day;
    u8 halfDay;
    u8 hour;
    u8 minute;
};

extern const u8 gTrailMapData[TRAIL_MAP_HEIGHT][TRAIL_MAP_WIDTH];
extern struct TrailInterface gTrailInterface;

#endif
