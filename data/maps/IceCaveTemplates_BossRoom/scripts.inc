.set LOCALID_BOSS, 1

IceCaveTemplates_BossRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, IceCaveTemplates_BossRoom_SetTile
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IceCaveTemplates_BossRoom_OnFrame
	.byte 0

IceCaveTemplates_BossRoom_OnFrame:
	map_script_2 VAR_TEMP_0, 0, IceCaveTemplates_BossRoom_BossStart
	.2byte 0

IceCaveTemplates_BossRoom_Null:
	end

IceCaveTemplates_BossRoom_SetTile:
	goto_if_unset FLAG_BOSS_ENCOUNTER, IceCaveTemplates_BossRoom_Null
	setmetatile 6, 5, METATILE_IceCave_METATILE_IceCaveTemplates_Hole, TRUE
	end

IceCaveTemplates_BossRoom_BossStart::
	setvar VAR_TEMP_0, 1
	goto_if_set FLAG_BOSS_ENCOUNTER, IceCaveTemplates_BossRoom_Null
	lock
	delay 10
    playse SE_PIN
	applymovement LOCALID_BOSS, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BOSS, Common_Movement_FacePlayer
	waitmovement 0
	delay 40
	specialvar VAR_RESULT, GetPlayerFacingDirection
	switch VAR_RESULT
	case DIR_SOUTH, IceCaveTemplates_BossRoom_WalkNorth
	case DIR_NORTH, IceCaveTemplates_BossRoom_WalkSouth
	case DIR_EAST, IceCaveTemplates_BossRoom_WalkWest
	case DIR_WEST, IceCaveTemplates_BossRoom_WalkEast

IceCaveTemplates_BossRoom_Text:
	.string "The path forward opens.\p$"

IceCaveTemplates_BossRoom_BossContinue:
    playmoncry SPECIES_ABOMASNOW, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
    setwildbattle SPECIES_ABOMASNOW, 10
    dowildbattle
	removeobject LOCALID_BOSS
	setmetatile 6, 5, METATILE_IceCave_METATILE_IceCaveTemplates_Hole, TRUE
	playse SE_M_EXPLOSION
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	message IceCaveTemplates_BossRoom_Text
	waitmessage
	releaseall
    end

IceCaveTemplates_BossRoom_Movement_WalkSouth:
	walk_down
	step_end

IceCaveTemplates_BossRoom_Movement_WalkNorth:
	walk_up
	step_end

IceCaveTemplates_BossRoom_Movement_WalkEast:
	walk_right
	step_end

IceCaveTemplates_BossRoom_Movement_WalkWest:
	walk_left
	step_end

IceCaveTemplates_BossRoom_WalkSouth:
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 2  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	playse SE_M_STRENGTH
	applymovement LOCALID_BOSS, IceCaveTemplates_BossRoom_Movement_WalkSouth
	special ShakeCamera
	waitmovement 0
	playse SE_M_STRENGTH
	applymovement LOCALID_BOSS, IceCaveTemplates_BossRoom_Movement_WalkSouth
	special ShakeCamera
	waitmovement 0
	playse SE_M_STRENGTH
	applymovement LOCALID_BOSS, IceCaveTemplates_BossRoom_Movement_WalkSouth
	special ShakeCamera
	waitmovement 0
	goto IceCaveTemplates_BossRoom_BossContinue

IceCaveTemplates_BossRoom_WalkNorth:
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 2  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	playse SE_M_STRENGTH
	applymovement LOCALID_BOSS, IceCaveTemplates_BossRoom_Movement_WalkNorth
	special ShakeCamera
	waitmovement 0
	playse SE_M_STRENGTH
	applymovement LOCALID_BOSS, IceCaveTemplates_BossRoom_Movement_WalkNorth
	special ShakeCamera
	waitmovement 0
	playse SE_M_STRENGTH
	applymovement LOCALID_BOSS, IceCaveTemplates_BossRoom_Movement_WalkNorth
	special ShakeCamera
	waitmovement 0
	goto IceCaveTemplates_BossRoom_BossContinue

IceCaveTemplates_BossRoom_WalkEast:
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 2  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	playse SE_M_STRENGTH
	applymovement LOCALID_BOSS, IceCaveTemplates_BossRoom_Movement_WalkEast
	special ShakeCamera
	waitmovement 0
	playse SE_M_STRENGTH
	applymovement LOCALID_BOSS, IceCaveTemplates_BossRoom_Movement_WalkEast
	special ShakeCamera
	waitmovement 0
	playse SE_M_STRENGTH
	applymovement LOCALID_BOSS, IceCaveTemplates_BossRoom_Movement_WalkEast
	special ShakeCamera
	waitmovement 0
	goto IceCaveTemplates_BossRoom_BossContinue

IceCaveTemplates_BossRoom_WalkWest:
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 2  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	playse SE_M_STRENGTH
	applymovement LOCALID_BOSS, IceCaveTemplates_BossRoom_Movement_WalkWest
	special ShakeCamera
	waitmovement 0
	playse SE_M_STRENGTH
	applymovement LOCALID_BOSS, IceCaveTemplates_BossRoom_Movement_WalkWest
	special ShakeCamera
	waitmovement 0
	playse SE_M_STRENGTH
	applymovement LOCALID_BOSS, IceCaveTemplates_BossRoom_Movement_WalkWest
	special ShakeCamera
	waitmovement 0
	goto IceCaveTemplates_BossRoom_BossContinue
