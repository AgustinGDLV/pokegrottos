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
const struct WeightedElement* GetItemPool(enum ItemType type, enum ItemTier tier)
{
    const struct TemplateRules* rules = GetTemplateRules(gFloorplan.templateType);
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
        default:
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
        case TYPE_TRINKET:
            pool = tablePtr->treasures;
            if (pool == NULL)
                pool = gDefaultItemPools[tier].treasures;
            break;        
    }
    return pool;
}

// Shuffle an array in place, using the floor seed.
static void ShuffleArrayU16(u16* array, u32 size)
{
    u32 i, j, t;
    // Safety check.
    if (size == 0)
        return;

    // Code from https://stackoverflow.com/questions/6127503/shuffle-array-in-c.
    for (i = 0; i < size - 1; ++i) 
    {
        j = i + RandomF() / (UINT16_MAX / (size - i) + 1);
        t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}

// Generates the list of items to sell in a floor.
void GenerateKecleonShopList(void)
{
    u32 tier = ITEM_TIER_1;
    u32 nextSeed;
    u32 attempts = 0;

    // First item is a Super Evo Stone.
    gSaveBlock1Ptr->shopItems[0] = ITEM_SHINY_STONE;

    // Second item is a trinket.
    nextSeed = RandomF();
    do { // Make sure we're not giving a trinket the player already has, if possible.
        gSaveBlock1Ptr->shopItems[1] = ChooseElementFromPool(GetItemPool(TYPE_TRINKET, tier));
    } while (CheckBagHasItem(gSaveBlock1Ptr->shopItems[3], 1) && ++attempts < 10);
    SeedFloorRng(nextSeed);

    // Third and fourth items are held items.
    gSaveBlock1Ptr->shopItems[2] = ChooseElementFromPool(GetItemPool(TYPE_HOLD_ITEM, tier));
    gSaveBlock1Ptr->shopItems[3] = ChooseElementFromPool(GetItemPool(TYPE_HOLD_ITEM, tier));

    // Fifth and sixth items is a battle item.
    gSaveBlock1Ptr->shopItems[4] = ChooseElementFromPool(GetItemPool(TYPE_BATTLE_ITEM, tier));
    gSaveBlock1Ptr->shopItems[5] = ChooseElementFromPool(GetItemPool(TYPE_BATTLE_ITEM, tier));

    // Seventh and eigth items are upgrades.
    gSaveBlock1Ptr->shopItems[6] = ChooseElementFromPool(GetItemPool(TYPE_UPGRADE, tier));
    gSaveBlock1Ptr->shopItems[7] = ChooseElementFromPool(GetItemPool(TYPE_UPGRADE, tier));

    // Last three items are medicines.
    gSaveBlock1Ptr->shopItems[8] = ChooseElementFromPool(GetItemPool(TYPE_MEDICINE, tier));
    gSaveBlock1Ptr->shopItems[9] = ChooseElementFromPool(GetItemPool(TYPE_MEDICINE, tier));
    gSaveBlock1Ptr->shopItems[10] = ChooseElementFromPool(GetItemPool(TYPE_MEDICINE, tier));

    // Shuffle array.
    ShuffleArrayU16(gSaveBlock1Ptr->shopItems, KECLEON_SHOP_ITEM_COUNT);
}

// Chooses an item for an item ball. This is called within a script.
void ChooseOverworldItem(void)
{
    u32 i, rand, tier;
    u32 ballId = gObjectEvents[gSelectedObjectEvent].trainerRange_berryTreeId;

    // Advance RNG to a repeatable state based on the ball ID.
    // This is to allow for consistency between saves and seed.
    SetRNGToRoomSeed();
    for (i = 0; i < ballId; ++i)
        RandomF();

    rand = RandomF();
    tier = ITEM_TIER_1;
    // 30% chance of item being a Poke Ball
    if (rand % 100 < 30)
        gSpecialVar_0x8000 = ITEM_POKE_BALL;
    // 30% chance of item being Medicine
    else if (rand % 10 < 60)
        gSpecialVar_0x8000 = ChooseElementFromPool(GetItemPool(TYPE_MEDICINE, tier));
    // 10% chance of item being Battle Item
    else if (rand % 10 < 70)
        gSpecialVar_0x8000 = ChooseElementFromPool(GetItemPool(TYPE_BATTLE_ITEM, tier));
    // 10% chance of item being Hold Item
    else if (rand % 10 < 80)
        gSpecialVar_0x8000 = ChooseElementFromPool(GetItemPool(TYPE_HOLD_ITEM, tier));
    // 20% chance of item being Upgrade
    else
        gSpecialVar_0x8000 = ChooseElementFromPool(GetItemPool(TYPE_UPGRADE, tier));
}
