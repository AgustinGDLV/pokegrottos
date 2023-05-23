#include "global.h"
#include "battle.h"
#include "battle_message.h"
#include "battle_anim.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "battle_scripts.h"
#include "battle_z_move.h"
#include "constants/moves.h"
#include "constants/abilities.h"
#include "item.h"
#include "item_gen.h"
#include "util.h"
#include "pokemon.h"
#include "random.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "text.h"
#include "sound.h"
#include "pokedex.h"
#include "recorded_battle.h"
#include "window.h"
#include "reshow_battle_screen.h"
#include "main.h"
#include "palette.h"
#include "money.h"
#include "map_gen.h"
#include "malloc.h"
#include "bg.h"
#include "string_util.h"
#include "pokemon_icon.h"
#include "m4a.h"
#include "mail.h"
#include "event_data.h"
#include "pokemon_storage_system.h"
#include "task.h"
#include "naming_screen.h"
#include "battle_setup.h"
#include "overworld.h"
#include "wild_encounter.h"
#include "rtc.h"
#include "party_menu.h"
#include "battle_arena.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "field_specials.h"
#include "pokemon_summary_screen.h"
#include "pokenav.h"
#include "menu_specialized.h"
#include "data.h"
#include "constants/abilities.h"
#include "constants/battle_anim.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/item_effects.h"
#include "constants/map_types.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "battle_util.h"
#include "constants/pokemon.h"
#include "config/battle.h"

#define CMD_ARGS(...) const struct __attribute__((packed)) { u8 opcode; MEMBERS(__VA_ARGS__) const u8 nextInstr[0]; } *const cmd  = (const void *)gBattlescriptCurrInstr
#define VARIOUS_ARGS(...) CMD_ARGS(u8 battler, u8 id, ##__VA_ARGS__)
#define NATIVE_ARGS(...) CMD_ARGS(void (*func)(void), ##__VA_ARGS__)

#define MEMBERS(...) VARARG_8(MEMBERS_, __VA_ARGS__)
#define MEMBERS_0()
#define MEMBERS_1(a) a;
#define MEMBERS_2(a, b) a; b;
#define MEMBERS_3(a, b, c) a; b; c;
#define MEMBERS_4(a, b, c, d) a; b; c; d;
#define MEMBERS_5(a, b, c, d, e) a; b; c; d; e;
#define MEMBERS_6(a, b, c, d, e, f) a; b; c; d; e; f;
#define MEMBERS_7(a, b, c, d, e, f, g) a; b; c; d; e; f; g;
#define MEMBERS_8(a, b, c, d, e, f, g, h) a; b; c; d; e; f; g; h;

// Scroll Scripts

// The Icy Scroll unpredictably freezes a battler or sets snow.
void BS_ItemIcyScroll(void)
{
    NATIVE_ARGS();
    u32 effect = GetDynamicItemEffect(ITEM_ICY_SCROLL);
    struct Pokemon *mon;

    gEffectBattler = gBattlerAttacker;
    gBattleCommunication[MULTIUSE_STATE] = 0;
    switch (effect)
    {   
        case 1: // Burn opposite foe, or partner if needed.
            if (IsBattlerAlive(gBattlerAttacker ^ BIT_SIDE))
            {
                gEffectBattler = GetBattlerAtPosition(gBattlerAttacker ^ BIT_SIDE);
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                     && IsBattlerAlive(gBattlerAttacker ^ BIT_SIDE ^ BIT_FLANK))
            {
                gEffectBattler = GetBattlerAtPosition(gBattlerAttacker ^ BIT_SIDE ^ BIT_FLANK);
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            // fall through
        case 0: // Freeze user.
            if (CanBeFrozen(gEffectBattler))
            {
                gActiveBattler = gEffectBattler;
                mon = &GetBattlerParty(gActiveBattler)[gBattlerPartyIndexes[gActiveBattler]];
                gBattleMons[gActiveBattler].status1 = STATUS1_FREEZE;
                BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].status1), &gBattleMons[gActiveBattler].status1);
                MarkBattlerForControllerExec(gActiveBattler);
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            break;
        case 2: // Set snow.
            if (TryChangeBattleWeather(gBattlerAttacker, ENUM_WEATHER_SNOW, FALSE))
            {
                gWishFutureKnock.weatherDuration = 8;
                gBattleCommunication[MULTIUSE_STATE] = 1; // Do snow animation.
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            break;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// The Fiery Scroll unpredictably burns a battler or sets sun.
void BS_ItemFieryScroll(void)
{
    NATIVE_ARGS();
    u32 effect = GetDynamicItemEffect(ITEM_FIERY_SCROLL);
    struct Pokemon *mon;

    gEffectBattler = gBattlerAttacker;
    gBattleCommunication[MULTIUSE_STATE] = 0;
    switch (effect)
    {   
        case 1: // Burn available foe.
            if (IsBattlerAlive(gBattlerAttacker ^ BIT_SIDE))
            {
                gEffectBattler = GetBattlerAtPosition(gBattlerAttacker ^ BIT_SIDE);
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                     && IsBattlerAlive(gBattlerAttacker ^ BIT_SIDE ^ BIT_FLANK))
            {
                gEffectBattler = GetBattlerAtPosition(gBattlerAttacker ^ BIT_SIDE ^ BIT_FLANK);
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            // fall through
        case 0: // Burn user.
            if (CanBeBurned(gEffectBattler))
            {
                gActiveBattler = gEffectBattler;
                mon = &GetBattlerParty(gActiveBattler)[gBattlerPartyIndexes[gActiveBattler]];
                gBattleMons[gActiveBattler].status1 = STATUS1_BURN;
                BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].status1), &gBattleMons[gActiveBattler].status1);
                MarkBattlerForControllerExec(gActiveBattler);
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            break;
        case 2: // Set sun.
            if (TryChangeBattleWeather(gBattlerAttacker, ENUM_WEATHER_SUN, FALSE))
            {
                gWishFutureKnock.weatherDuration = 8;
                gBattleCommunication[MULTIUSE_STATE] = 1; // Do sun animation.
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            break;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// The Watery Scroll unpredictably burns a battler or sets sun.
void BS_ItemWateryScroll(void)
{
    NATIVE_ARGS();
    u32 effect = GetDynamicItemEffect(ITEM_WATERY_SCROLL);
    struct Pokemon *mon;

    gBattlerTarget = gBattlerAttacker;
    gBattleCommunication[MULTIUSE_STATE] = 0;
    switch (effect)
    {   
        case 1: // Soak available foe.
            if (IsBattlerAlive(gBattlerAttacker ^ BIT_SIDE))
            {
                gBattlerTarget = GetBattlerAtPosition(gBattlerAttacker ^ BIT_SIDE);
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                     && IsBattlerAlive(gBattlerAttacker ^ BIT_SIDE ^ BIT_FLANK))
            {
                gBattlerTarget = GetBattlerAtPosition(gBattlerAttacker ^ BIT_SIDE ^ BIT_FLANK);
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            // fall through
        case 0: // Soak user.
            if (gBattleMons[gBattlerTarget].type1 == TYPE_WATER
                && gBattleMons[gBattlerTarget].type2 == TYPE_WATER)
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            else
            {
                SET_BATTLER_TYPE(gBattlerTarget, TYPE_WATER);
                PREPARE_TYPE_BUFFER(gBattleTextBuff1, TYPE_WATER);
            }
            break;
        case 2: // Set rain.
            if (TryChangeBattleWeather(gBattlerAttacker, ENUM_WEATHER_RAIN, FALSE))
            {
                gWishFutureKnock.weatherDuration = 8;
                gBattleCommunication[MULTIUSE_STATE] = 1; // Do rain animation.
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            break;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// The Grassy Scroll unpredictably burns a battler or sets sun.
void BS_ItemGrassyScroll(void)
{
    NATIVE_ARGS();
    u32 effect = GetDynamicItemEffect(ITEM_GRASSY_SCROLL);
    struct Pokemon *mon;

    gEffectBattler = gBattlerAttacker;
    gBattleCommunication[MULTIUSE_STATE] = 0;
    switch (effect)
    {   
        case 1: // Sleep available foe.
            if (IsBattlerAlive(gBattlerAttacker ^ BIT_SIDE))
            {
                gEffectBattler = GetBattlerAtPosition(gBattlerAttacker ^ BIT_SIDE);
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                     && IsBattlerAlive(gBattlerAttacker ^ BIT_SIDE ^ BIT_FLANK))
            {
                gEffectBattler = GetBattlerAtPosition(gBattlerAttacker ^ BIT_SIDE ^ BIT_FLANK);
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            // fall through
        case 0: // Sleep user.
            if (CanSleep(gEffectBattler))
            {
                gActiveBattler = gEffectBattler;
                mon = &GetBattlerParty(gActiveBattler)[gBattlerPartyIndexes[gActiveBattler]];
                gBattleMons[gActiveBattler].status1 = STATUS1_SLEEP_TURN(2);
                BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].status1), &gBattleMons[gActiveBattler].status1);
                MarkBattlerForControllerExec(gActiveBattler);
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            break;
        case 2: // Set grassy terrain.
            if (gFieldStatuses & STATUS_FIELD_GRASSY_TERRAIN)
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            else
            {
                gFieldStatuses &= ~STATUS_FIELD_TERRAIN_ANY;
                gFieldStatuses |= STATUS_FIELD_GRASSY_TERRAIN;
                gFieldTimers.terrainTimer = 8;
                gBattleCommunication[MULTIUSE_STATE] = 1; // Do terrain animation.
            }
            break;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// The Electric Scroll unpredictably burns a battler or sets sun.
void BS_ItemElectricScroll(void)
{
    NATIVE_ARGS();
    u32 effect = GetDynamicItemEffect(ITEM_ELECTRIC_SCROLL);
    struct Pokemon *mon;

    gEffectBattler = gBattlerAttacker;
    gBattleCommunication[MULTIUSE_STATE] = 0;
    switch (effect)
    {   
        case 1: // Paralyze available foe.
            if (IsBattlerAlive(gBattlerAttacker ^ BIT_SIDE))
            {
                gEffectBattler = GetBattlerAtPosition(gBattlerAttacker ^ BIT_SIDE);
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                     && IsBattlerAlive(gBattlerAttacker ^ BIT_SIDE ^ BIT_FLANK))
            {
                gEffectBattler = GetBattlerAtPosition(gBattlerAttacker ^ BIT_SIDE ^ BIT_FLANK);
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            // fall through
        case 0: // Paralyze user.
            if (CanBeParalyzed(gEffectBattler))
            {
                gActiveBattler = gEffectBattler;
                mon = &GetBattlerParty(gActiveBattler)[gBattlerPartyIndexes[gActiveBattler]];
                gBattleMons[gActiveBattler].status1 = STATUS1_PARALYSIS;
                BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gActiveBattler].status1), &gBattleMons[gActiveBattler].status1);
                MarkBattlerForControllerExec(gActiveBattler);
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            break;
        case 2: // Set electric terrain.
            if (gFieldStatuses & STATUS_FIELD_ELECTRIC_TERRAIN)
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            else
            {
                gFieldStatuses &= ~STATUS_FIELD_TERRAIN_ANY;
                gFieldStatuses |= STATUS_FIELD_ELECTRIC_TERRAIN;
                gFieldTimers.terrainTimer = 8;
                gBattleCommunication[MULTIUSE_STATE] = 1; // Do terrain animation.
            }
            break;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}

// Treasure Effects
bool32 TrinketBattleEffects(u32 caseID, u32 battlerId, bool32 moveTurn)
{
    u32 i;
    u32 effect = 0;

    switch (caseID)
    {
        // Effects that apply with each hit of a move.
        case ITEMEFFECT_KINGSROCK:
            // Relic Crown effect
            if (IsTrinketEffectActive(ITEM_RELIC_CROWN_TRINKET)
                && gBattleMoveDamage != 0  // Need to have done damage
                && !(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                && TARGET_TURN_DAMAGED
                && RandomPercentage(RNG_FLINCH_RELIC_CROWN, 10 + 10*(GetBattlerAbility(gBattlerAttacker) == ABILITY_SERENE_GRACE))
                && gBattleMoves[gCurrentMove].flags & FLAG_KINGS_ROCK_AFFECTED
                && gBattleMons[gBattlerTarget].hp)
            {
                gBattleScripting.moveEffect = MOVE_EFFECT_FLINCH;
                BattleScriptPushCursor();
                SetMoveEffect(FALSE, 0);
                BattleScriptPop();
                effect = TRUE;
            }
            break;
    }

    return effect;
}

void BS_GiveDroppedItems(void)
{
    NATIVE_ARGS();
    u32 i;
    u32 battlers[] = { GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), 
                        GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT) };
    
    // Drop held items.
    for (i = 0; i < 1 + IsDoubleBattle(); ++i)
    {
        gLastUsedItem = gBattleResources->battleHistory->heldItems[battlers[i]];
        gBattleResources->battleHistory->heldItems[battlers[i]] = ITEM_NONE;
        if (gLastUsedItem && !(gBattleTypeFlags & (BATTLE_TYPE_TRAINER | BATTLE_TYPE_FIRST_BATTLE | BATTLE_TYPE_WALLY_TUTORIAL)))
        {
            if(AddBagItem(gLastUsedItem, 1))
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ITEM_DROPPED;
            else
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_BAG_IS_FULL;
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_ItemDropped;
            return;
        }
    }

    // Try giving medicine.
    if (Random() % 2)
    {
        gLastUsedItem = ChooseElementFromPool(GetItemPool(TYPE_MEDICINE, ITEM_TIER_1));
        if(AddBagItem(gLastUsedItem, 1))
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ITEM_DROPPED;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_BAG_IS_FULL;
        BattleScriptPush(cmd->nextInstr);
        gBattlescriptCurrInstr = BattleScript_ItemDropped;
        return;
    }

    gBattlescriptCurrInstr = cmd->nextInstr;
}
