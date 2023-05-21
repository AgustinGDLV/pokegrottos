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
        case 1: // Freeze available foe.
            if (IsBattlerAlive(B_POSITION_OPPONENT_LEFT))
            {
                gEffectBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE
                     && IsBattlerAlive(B_POSITION_OPPONENT_RIGHT))
            {
                gEffectBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            // fall through
        case 0: // Freeze user.
            if (CanBeFrozen(gEffectBattler))
            {
                mon = &GetBattlerParty(gEffectBattler)[gBattlerPartyIndexes[gEffectBattler]];
                gActiveBattler = gEffectBattler;
                gBattleMons[gActiveBattler].status1 = STATUS1_FREEZE;
                BtlController_EmitSetMonData(BUFFER_A, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[gEffectBattler].status1), &gBattleMons[gEffectBattler].status1);
                MarkBattlerForControllerExec(gActiveBattler);
            }
            else
            {
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            }
            break;
        case 2: // Set snow.
            if (TryChangeBattleWeather(gBattlerAttacker, ENUM_WEATHER_SNOW, FALSE))
                gBattleCommunication[MULTIUSE_STATE] = 1; // Do snow animation.
            else
                gBattleCommunication[MULTIUSE_STATE] = 2; // But it failed!
            break;
    }
    gBattlescriptCurrInstr = cmd->nextInstr;
}
