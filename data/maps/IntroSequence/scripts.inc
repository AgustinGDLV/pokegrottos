IntroSequence_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, IntroSequence_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IntroSequence_OnFrame
	.byte 0

IntroSequence_OnWarp:
	map_script_2 VAR_TEMP_1, 0, IntroSequence_HidePlayer
	.2byte 0

IntroSequence_OnFrame:
	map_script_2 VAR_TEMP_0, 0, IntroSequence_Introduction
	.2byte 0

IntroSequence_HidePlayer:
	setvar VAR_TEMP_1, 1
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
	end

IntroSequence_Introduction:
	lockall
	setvar VAR_TEMP_0, 1
	message IntroSequence_IntroductionText
	waitmessage
	dynmultipush IntroSequence_CharacterBugCatcher, 0
	dynmultipush IntroSequence_CharacterBreeder, 1
	dynmultipush IntroSequence_CharacterSwimmer, 2
	dynmultipush IntroSequence_CharacterHiker, 3
	dynmultistack 9, 3, TRUE, 4, FALSE, 0, NULL
	callnative AssignPlayerCharacter
	special SpawnCameraObject
	setobjectxy OBJ_EVENT_ID_PLAYER, 7, 9
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_LITTLEROOT_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, IntroSequence_Movement_WalkUp
	switch VAR_RESULT
	case 0, IntroSequence_ChoseBugCatcher
	case 1, IntroSequence_ChoseBugCatcher
	case 2, IntroSequence_ChoseBugCatcher
	case 3, IntroSequence_ChoseBugCatcher
	end

IntroSequence_ChoseBugCatcher:
	message IntroSequence_ChoseBugCatcherText
	waitmessage
	goto IntroSequence_AskPlayerName
	end

IntroSequence_AskPlayerName:
	callnative AssignPlayerName
	waitstate
	msgbox IntroSequence_ConfirmName, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, IntroSequence_AskPlayerName
	end

IntroSequence_IntroductionText:
	.string "Hello trainer!\p"
	.string "As you are no doubt aware, there\n"
	.string "is rumored to be a mysterious\l"
	.string "POKéMON in Orchid City.\p"
	.string "That is why, out of dozens of\n"
	.string "applicants, I've chosen you, a…\p$"

IntroSequence_ChoseBugCatcherText:
	.string "…fearless bug catcher!\p"
	.string "You might be young, but I\n"
	.string "know you can handle this!\p"
	.string "…\n"
	.string "What was your name again?\p$"

IntroSequence_ConfirmName:
	.string "{PLAYER}, is that right?$"

IntroSequence_CharacterBugCatcher:
	.string "Bug Catcher$"

IntroSequence_CharacterBreeder:
	.string "Breeder$"

IntroSequence_CharacterSwimmer:
	.string "Swimmer$"

IntroSequence_CharacterHiker:
	.string "Hiker$"

IntroSequence_Movement_WalkUp:
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end
