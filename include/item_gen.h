#ifndef GUARD_ITEM_GEN_H
#define GUARD_ITEM_GEN_H

// Kecleon Shop and Other Item Constants
#define KECLEON_SHOP_ITEM_COUNT     7
#define ITEM_POOL_SIZE              10
#define ITEM_TOTAL_WEIGHT           UINT8_MAX

struct WeightedItem {
    u16 item;
    u8 weight;
};

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
    const struct WeightedItem* medicines;
    const struct WeightedItem* battleItems;
    const struct WeightedItem* holdItems;
    const struct WeightedItem* upgrades;
    const struct WeightedItem* treasures;
};

void GenerateKecleonShopList(void);

extern const struct ItemPoolTable gDefaultItemPools[ITEM_TIER_COUNT];

#endif
