#ifndef GUARD_ITEM_GEN_H
#define GUARD_ITEM_GEN_H

// Kecleon Shop and Other Item Constants
#define KECLEON_SHOP_ITEM_COUNT     7

enum ItemTier {
    ITEM_TIER_1,
    ITEM_TIER_2,
    ITEM_TIER_3,
    ITEM_TIER_4,
    ITEM_TIER_5,
    ITEM_TIER_COUNT,
};

enum ItemType {
    TYPE_MEDICINE,
    TYPE_BATTLE_ITEM,
    TYPE_HOLD_ITEM,
    TYPE_UPGRADE,
    TYPE_TREASURE,
};

struct ItemPoolTable {
    const struct WeightedElement* medicines;
    const struct WeightedElement* battleItems;
    const struct WeightedElement* holdItems;
    const struct WeightedElement* upgrades;
    const struct WeightedElement* treasures;
};

void GenerateKecleonShopList(void);

extern const struct ItemPoolTable gDefaultItemPools[ITEM_TIER_COUNT];

#endif
