#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_COCOON_CARE) == EFFECT_COCOON_CARE);
}

SINGLE_BATTLE_TEST("Cocoon Care fully revives a chosen fainted party member for the player")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_COCOON_CARE, partyIndex:2); }
        TURN { SKIP_TURN(player); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SWITCH(player, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COCOON_CARE, player);
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
    }
}

SINGLE_BATTLE_TEST("Cocoon Care activates instantly when selecting a Bug-type target")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_CATERPIE].types[0] == TYPE_BUG);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { HP(0); }
        PLAYER(SPECIES_CATERPIE) { HP(0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_COCOON_CARE, partyIndex:2); }
        TURN { SWITCH(player, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COCOON_CARE, player);
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
    }
}
