#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Colony increases defenses by 10% for every Bug-type party member", s16 damage)
{
    u32 species;
    PARAMETRIZE { species = SPECIES_WOBBUFFET; }
    PARAMETRIZE { species = SPECIES_DURANT; }
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_DURANT].types[0] == TYPE_BUG);
        PLAYER(SPECIES_DURANT) { Ability(ABILITY_COLONY); }
        PLAYER(species);
        PLAYER(species);
        PLAYER(species);
        PLAYER(species);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EMBER); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damage, UQ_4_12(1.36), results[0].damage); // from 1.1x to 1.5x
    }
}
