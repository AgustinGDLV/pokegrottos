#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_HONEY].holdEffect == HOLD_EFFECT_RESTORE_PCT_HP);
    ASSUME(gSpeciesInfo[SPECIES_COMBEE].abilities[0] == ABILITY_HONEY_GATHER);
    ASSUME(gSpeciesInfo[SPECIES_COMBEE].types[0] == TYPE_BUG);
}

SINGLE_BATTLE_TEST("Honey Gather has a 50% chance to grant Honey at the end of a turn")
{
    PASSES_RANDOMLY(1, 2, RNG_HONEY_GATHER);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_COMBEE) { Ability(ABILITY_HONEY_GATHER); }
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_HONEY_GATHER);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_HONEY);
    }
}

SINGLE_BATTLE_TEST("Honey Gather always grants Honey at the end of a turn with 3 Bug-type party members")
{
    PASSES_RANDOMLY(1, 1, RNG_HONEY_GATHER);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_COMBEE) { Ability(ABILITY_HONEY_GATHER); }
        OPPONENT(SPECIES_COMBEE);
        OPPONENT(SPECIES_COMBEE);
    } WHEN {
        TURN { }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_HONEY_GATHER);
    } THEN {
        EXPECT_EQ(opponent->item, ITEM_HONEY);
    }
}
