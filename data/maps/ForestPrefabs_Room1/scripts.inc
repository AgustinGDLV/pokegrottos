ForestPrefabs_Room1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ForestPrefabs_Room1_OnLoad
	.byte 0

ForestPrefabs_Room1_OnLoad:
	special CoverInvalidRoomExits
	end

ForestPrefabs_Room1_EventScript_TryWarpNorth::
	trywarptoroom DIR_NORTH @ NORTH
	goto_if_eq VAR_RESULT, TRUE, ForestPrefabs_Room1_EventScript_End
	applymovement OBJ_EVENT_ID_PLAYER, ForestPrefabs_Room1_Movement_WalkDown
	waitmovement 0
	end

ForestPrefabs_Room1_EventScript_TryWarpSouth::
	trywarptoroom DIR_SOUTH @ SOUTH
	goto_if_eq VAR_RESULT, TRUE, ForestPrefabs_Room1_EventScript_End
	applymovement OBJ_EVENT_ID_PLAYER, ForestPrefabs_Room1_Movement_WalkUp
	waitmovement 0
	end

ForestPrefabs_Room1_EventScript_TryWarpEast::
	trywarptoroom DIR_EAST @ EAST
	goto_if_eq VAR_RESULT, TRUE, ForestPrefabs_Room1_EventScript_End
	applymovement OBJ_EVENT_ID_PLAYER, ForestPrefabs_Room1_Movement_WalkLeft
	waitmovement 0
	end

ForestPrefabs_Room1_EventScript_TryWarpWest::
	trywarptoroom DIR_WEST @ WEST
	goto_if_eq VAR_RESULT, TRUE, ForestPrefabs_Room1_EventScript_End
	applymovement OBJ_EVENT_ID_PLAYER, ForestPrefabs_Room1_Movement_WalkRight
	waitmovement 0
	end

ForestPrefabs_Room1_EventScript_End:
	end

ForestPrefabs_Room1_Movement_WalkUp:
	walk_up
	step_end

ForestPrefabs_Room1_Movement_WalkDown:
	walk_down
	step_end

ForestPrefabs_Room1_Movement_WalkRight:
	walk_right
	step_end

ForestPrefabs_Room1_Movement_WalkLeft:
	walk_left
	step_end
