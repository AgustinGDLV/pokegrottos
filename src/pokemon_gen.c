#include "global.h"
#include "data_util.h"
#include "event_object_movement.h"
#include "map_gen.h"
#include "random.h"

// Returns the species of an overworld obj. event in a room using its local ID.
u16 GetOverworldSpeciesInRoom(u32 index, u32 localId)
{
    u32 i;
    // Advance RNG to a repeatable state based on the local ID.
    // This is to allow for consistency between saves and seed.
    SeedFloorRng(GetRoomSeed(index));
    for (i = 0; i < localId; ++i)
        RandomF();

    return ChooseElementFromPool(GetCurrentTemplateRules()->encounterPool);
}
