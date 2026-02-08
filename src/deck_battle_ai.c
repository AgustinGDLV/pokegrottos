#include "global.h"
#include "battle.h"
#include "bg.h"
#include "deck_battle.h"
#include "deck_battle_effects.h"
#include "deck_battle_interface.h"
#include "deck_battle_util.h"
#include "deck_battle_controller.h"
#include "deck_battle_ai.h"
#include "event_object_movement.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "m4a.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/battle.h"
#include "constants/moves.h"

/* deck_battle_ai.c
 *
 * This file holds the handling for all opponent action
 * selection, as well as support for each move target type.
 * This can be extended to support as many custom AI types
 * as needed.
 * 
*/

#define tState  data[0]
#define tTimer  data[1]

void Task_OpponentSelectAction(u8 taskId)
{
    gDeckStruct.selectedPos = GetLeftmostPositionToMove(B_SIDE_OPPONENT);
    if (gDeckStruct.selectedPos != POSITIONS_COUNT)
    {
        gBattlerAttacker = GetDeckBattlerAtPos(B_SIDE_OPPONENT, gDeckStruct.selectedPos);
        QueueAction(ACTION_ATTACK, gBattlerAttacker, MAX_DECK_BATTLERS_COUNT, gDeckSpeciesInfo[gDeckMons[gBattlerAttacker].species].move);
        gDeckMons[gBattlerAttacker].hasMoved = TRUE;
    }
    else
    {
        gTasks[taskId].func = Task_PrepareForActionPhase;
    } 
}

#undef tState
#undef tTimer
