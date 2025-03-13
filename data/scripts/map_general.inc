EventScript_OverworldEncounterStart::
    lock
    playse SE_PIN
	applymovement VAR_0x8001, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8001, Common_Movement_FacePlayer
	waitmovement 0
    playmoncry VAR_0x8000, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
    setwildbattle VAR_0x8000, 10 @ Set based on GraphicsID
    dowildbattle
	removeobject VAR_0x8001
	releaseall
    end

EventScript_ItemBall::
	callnative ChooseOverworldItem
	finditem VAR_0x8000
	end

EventScript_KecleonShop::
    lock
	faceplayer
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	callnative InitKecleonShop
	waitmoncry
	releaseall
	end

EventScript_EnterBossRoom_Text:
	.string "You sense a strong presence ahead...\n"
	.string "Should you enter?$"

EventScript_EnterBossRoom::
	lock
	msgbox EventScript_EnterBossRoom_Text, MSGBOX_YESNO
	waitmessage
	releaseall
	callnative WarpToBossRoomOrTurn 
	end

EventScript_Movement_WalkSouth:
	walk_down
	step_end

EventScript_Movement_WalkNorth:
	walk_up
	step_end

EventScript_Movement_WalkEast:
	walk_right
	step_end

EventScript_Movement_WalkWest:
	walk_left
	step_end

EventScript_WalkSouth:
	applymovement OBJ_EVENT_ID_PLAYER, EventScript_Movement_WalkSouth
	waitmovement 0
	releaseall
	end

EventScript_WalkNorth:
	applymovement OBJ_EVENT_ID_PLAYER, EventScript_Movement_WalkNorth
	waitmovement 0
	releaseall
	end

EventScript_WalkEast:
	applymovement OBJ_EVENT_ID_PLAYER, EventScript_Movement_WalkEast
	waitmovement 0
	releaseall
	end

EventScript_WalkWest:
	applymovement OBJ_EVENT_ID_PLAYER, EventScript_Movement_WalkWest
	waitmovement 0
	releaseall
	end

EventScript_WalkForward:
	specialvar VAR_RESULT, GetPlayerFacingDirection
	switch VAR_RESULT
	case DIR_SOUTH, EventScript_WalkSouth
	case DIR_NORTH, EventScript_WalkNorth
	case DIR_EAST, EventScript_WalkEast
	case DIR_WEST, EventScript_WalkWest

EventScript_WalkOppposite:
	specialvar VAR_RESULT, GetPlayerFacingDirection
	switch VAR_RESULT
	case DIR_SOUTH, EventScript_WalkNorth
	case DIR_NORTH, EventScript_WalkSouth
	case DIR_EAST, EventScript_WalkWest
	case DIR_WEST, EventScript_WalkEast

EventScript_EnterBossRoomFromConnection::
	lock
	playse SE_PIN
	msgbox EventScript_EnterBossRoom_Text, MSGBOX_YESNO
	waitmessage
	releaseall
	switch VAR_RESULT
	case 1, EventScript_WalkForward
	case 0, EventScript_WalkOppposite
