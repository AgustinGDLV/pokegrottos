#include "global.h"
#include "test_battle.h"

// Outside tests that fail:
// Schooling, U-turn, Snow, Sturdy, CreateNPCTrainer, Contrary, Hex, Mega Evo

SINGLE_BATTLE_TEST("Relic Crown gives moves a 10\% chance to flinch")
{
    PASSES_RANDOMLY(1, 10, RNG_FLINCH_RELIC_CROWN);
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TACKLE].power > 0);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet used Tackle!");
        MESSAGE("Foe Wobbuffet flinched!");
    }
}

SINGLE_BATTLE_TEST("Relic Crown gives moves a 20\% chance to flinch with Serene Grace")
{
    PASSES_RANDOMLY(1, 5, RNG_FLINCH_RELIC_CROWN);
    GIVEN {
        ASSUME(gBattleMoves[MOVE_TACKLE].power > 0);
        PLAYER(SPECIES_TOGEPI) { Ability(ABILITY_SERENE_GRACE); };
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Togepi used Tackle!");
        MESSAGE("Foe Wobbuffet flinched!");
    }
}
