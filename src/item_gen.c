#include "global.h"
#include "item_gen.h"
#include "map_gen.h"
#include "random.h"
#include "event_data.h"

// Returns the total weight of all items in an item pool.
static u16 GetItemPoolTotalWeight(const struct WeightedItem *itemPool)
{
    u32 i, weight = 0;
    for (i = 0; i < ITEM_POOL_SIZE; ++i)
    {
        if (itemPool[i].item > ITEM_NONE && itemPool[i].item <= ITEMS_COUNT)
            weight += itemPool[i].weight;
        else
            break;
    }
    return weight;
}

// Returns an item from a weighted item pool.
static u16 ChooseItemFromPool(const struct WeightedItem* itemPool)
{
    u32 i;
    u32 totalWeight = GetItemPoolTotalWeight(itemPool);
    u16 rand;

    // Generates a value within total weight and finds corresponding item.
    rand = RandomF() % totalWeight;
    for (i = 0; i < ITEM_POOL_SIZE; ++i)
    {
        if (rand > itemPool[i].weight)
            rand -= itemPool[i].weight;
        else
            return itemPool[i].item;
    }

    // This shouldn't be reached, but just in case.
    return ITEM_NONE;
}

// Returns the pool of items for a given tier and item type.
static const struct WeightedItem* GetItemPool(enum ItemType type, enum ItemTier tier)
{
    const struct PrefabRules* rules = GetPrefabRules(gFloorplan.prefabType);
    const struct ItemPoolTable* tablePtr;
    const struct WeightedItem* pool;

    // Get the table from the map template rules.
    if (GetRoomType(gSaveBlock1Ptr->currentRoom) == SHOP_ROOM)
        tablePtr = &rules->kecleonShopPools[tier];
    else // TODO: overworld loot pool
        tablePtr = &rules->kecleonShopPools[tier];
    
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
        gSaveBlock1Ptr->shopItems[i] = ChooseItemFromPool(GetItemPool(TYPE_MEDICINE, ITEM_TIER_1));
    }
}

// Chooses an item for an item ball.
void ChooseOverworldItem(void)
{
    u32 i;
    u32 ballId = gObjectEvents[gSelectedObjectEvent].trainerRange_berryTreeId;

    // Advance RNG to a repeatable state based on the ball ID.
    // This is to allow for consistency between saves and seed.
    SetRNGToRoomSeed();
    for (i = 0; i < ballId; ++i)
        RandomF();

    gSpecialVar_0x8000 = ChooseItemFromPool(GetItemPool(TYPE_MEDICINE, ITEM_TIER_1));
}
