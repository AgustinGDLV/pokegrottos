#include "global.h"
#include "data_util.h"
#include "item.h"
#include "item_gen.h"
#include "map_gen.h"
#include "random.h"
#include "util.h"
#include "test_runner.h"
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

// Returns the effect of an unidentified scroll for a given run.
u32 GetDynamicItemEffect(u32 itemId)
{
    return (gSaveBlock1Ptr->unidSeed + 7 * itemId) % ItemId_GetSecondaryId(itemId);
}

// Returns whether an item uses a dynamic description.
bool32 DoesItemHaveDynamicEffect(u32 itemId)
{
    return (itemId > SCROLLS_START && itemId < SCROLLS_END);
}

// Returns whether an unidentified item has had its effect identified.
static bool32 IsItemIdentified(u32 itemId)
{
    u32 i = itemId - SCROLLS_START;
    return gSaveBlock1Ptr->identifiedItems[i / 32] & (1 << i % 32);
}

// Sets an unidentified item as identified.
bool32 TryIdentifyItem(u32 itemId)
{
    if (!DoesItemHaveDynamicEffect(itemId) || IsItemIdentified(itemId))
    {
        return FALSE;
    }
    else
    {
        u32 i = itemId - SCROLLS_START;
        gSaveBlock1Ptr->identifiedItems[i / 32] |= (1 << i % 32);
        return TRUE;
    }
}

// Returns the description of an identified item.
const u8* GetDynamicItemDescription(u32 itemId)
{
    if (IsItemIdentified(itemId))
        return sIdentifiedItemDescriptions[itemId - SCROLLS_START][GetDynamicItemEffect(itemId)];
    else
        return sUnidentifiedScrollDescription;
}

// Returns whether a treasure effect is currently active.
bool32 IsTrinketEffectActive(u32 itemId)
{
    if (gTestRunnerEnabled)
        return TRUE;

    return CheckBagHasItem(itemId, 1);
}
