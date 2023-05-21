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
u32 GetDynamicItemEffect(u32 itemId);
bool32 DoesItemHaveDynamicEffect(u32 itemId);
const u8* GetDynamicItemDescription(u32 itemId);
bool32 TryIdentifyItem(u32 itemId);

extern const struct ItemPoolTable gDefaultItemPools[ITEM_TIER_COUNT];

// Dynamic Item Descriptions
static const u8 sUnidentifiedDescription[] = _("???");

static const u8 sIcyScrollDescription1[] = _("Freezes the user.");
static const u8 sIcyScrollDescription2[] = _("Freezes the foe.");
static const u8 sIcyScrollDescription3[] = _("Starts a snowstorm.");

static const u8 * const sIdentifiedItemDescriptions[SCROLLS_END - SCROLLS_START][3] = {
    [ITEM_ICY_SCROLL - SCROLLS_START] = {sIcyScrollDescription1, sIcyScrollDescription2, sIcyScrollDescription3},
};

#endif
