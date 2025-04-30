#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SUGAR_RUSH) == EFFECT_SUGAR_RUSH);
}

SINGLE_BATTLE_TEST("Sugar Rush cannot be used if the user doesn't hold Honey")
{
    u16 item = 0;
    PARAMETRIZE { item = ITEM_NONE; }
    PARAMETRIZE { item = ITEM_HONEY; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (item == ITEM_NONE)
            TURN { MOVE(player, MOVE_SUGAR_RUSH, allowed: FALSE); MOVE(player, MOVE_CELEBRATE); }
        else
            TURN { MOVE(player, MOVE_SUGAR_RUSH); }
    } SCENE {
        if (item == ITEM_NONE)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, player);
        else
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SUGAR_RUSH, player);
    }
}

SINGLE_BATTLE_TEST("Sugar Rush forces Struggle if it's the only move is blocked")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_SUGAR_RUSH); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUGAR_RUSH, allowed: FALSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    }
}

SINGLE_BATTLE_TEST("Sugar Rush consumes Honey and raises Attack, Sp. Attack, and Speed by 2 stages")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_HONEY); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUGAR_RUSH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUGAR_RUSH, player);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPATK], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 2);
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}
