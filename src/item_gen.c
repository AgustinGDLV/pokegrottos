#include "global.h"
#include "data_util.h"
#include "item_gen.h"
#include "map_gen.h"
#include "random.h"
#include "event_data.h"

// Returns the pool of items for a given tier and item type.
static const struct WeightedElement* GetItemPool(enum ItemType type, enum ItemTier tier)
{
    const struct PrefabRules* rules = GetPrefabRules(gFloorplan.prefabType);
    const struct ItemPoolTable* tablePtr;
    const struct WeightedElement* pool;

    // Get the table from the map template rules.
    if (GetRoomType(gSaveBlock1Ptr->currentRoom) == SHOP_ROOM)
        tablePtr = &rules->itemPools[tier];
    else // TODO: overworld loot pool
        tablePtr = &rules->itemPools[tier];
    
    // Check to make sure it's a valid table.
    if (tablePtr == NULL)
        tablePtr = &gDefaultItemPools[tier];

    // Get the right item pool type.
    switch (type)
    {
        case TYPE_MEDICINE:
            pool = tablePtr->medicines;
            if (pool == NULL)
                pool = gDefaultItemPools[tier].medicines;
            break;
        case TYPE_BATTLE_ITEM:
            pool = tablePtr->battleItems;
            if (pool == NULL)
                pool = gDefaultItemPools[tier].battleItems;
            break;
        case TYPE_HOLD_ITEM:
            pool = tablePtr->holdItems;
            if (pool == NULL)
                pool = gDefaultItemPools[tier].holdItems;
            break;
        case TYPE_UPGRADE:
            pool = tablePtr->upgrades;
            if (pool == NULL)
                pool = gDefaultItemPools[tier].upgrades;
            break;
        case TYPE_TREASURE:
            pool = tablePtr->treasures;
            if (pool == NULL)
                pool = gDefaultItemPools[tier].treasures;
            break;        
    }
    return pool;
}

// Generates the list of items to sell in a floor.
void GenerateKecleonShopList(void)
{
    u32 i;
    for (i = 0; i < KECLEON_SHOP_ITEM_COUNT; ++i)
    {
        gSaveBlock1Ptr->shopItems[i] = ChooseElementFromPool(GetItemPool(TYPE_MEDICINE, ITEM_TIER_1));
    }
}

// Chooses an item for an item ball. This is called within a script.
void ChooseOverworldItem(void)
{
    u32 i;
    u32 ballId = gObjectEvents[gSelectedObjectEvent].trainerRange_berryTreeId;

    // Advance RNG to a repeatable state based on the ball ID.
    // This is to allow for consistency between saves and seed.
    SetRNGToRoomSeed();
    for (i = 0; i < ballId; ++i)
        RandomF();

    gSpecialVar_0x8000 = ChooseElementFromPool(GetItemPool(TYPE_MEDICINE, ITEM_TIER_1));
}
