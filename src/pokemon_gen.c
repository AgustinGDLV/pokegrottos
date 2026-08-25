#include "global.h"
#include "data_util.h"
#include "deck_battle.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "map_gen.h"
#include "random.h"

#include "data/encounters.h"

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

void InitEnemyPartyFromEncounter(void) // used by callnative
{
    u32 enemyLevel = 5;
    for (u32 i = 0; i < PARTY_SIZE; ++i)
    {
        CreateMon(&gEnemyParty[i], gEncountersInfo[gSpecialVar_0x8000][i], enemyLevel + (Random() % 2), USE_RANDOM_IVS, 0, 0, OT_ID_PLAYER_ID, 0);
        SetMonData(&gEnemyParty[i], MON_DATA_POSITION, &i);
    }
}
