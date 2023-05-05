Prefabs_EventScript_TryWarpNorth::
	trywarptoroom DIR_NORTH @ NORTH
	goto_if_eq VAR_RESULT, TRUE, Prefabs_EventScript_End
	applymovement OBJ_EVENT_ID_PLAYER, Prefabs_Movement_WalkDown
	waitmovement 0
	end

Prefabs_EventScript_TryWarpSouth::
	trywarptoroom DIR_SOUTH @ SOUTH
	goto_if_eq VAR_RESULT, TRUE, Prefabs_EventScript_End
	applymovement OBJ_EVENT_ID_PLAYER, Prefabs_Movement_WalkUp
	waitmovement 0
	end

Prefabs_EventScript_TryWarpEast::
	trywarptoroom DIR_EAST @ EAST
	goto_if_eq VAR_RESULT, TRUE, Prefabs_EventScript_End
	applymovement OBJ_EVENT_ID_PLAYER, Prefabs_Movement_WalkLeft
	waitmovement 0
	end

Prefabs_EventScript_TryWarpWest::
	trywarptoroom DIR_WEST @ WEST
	goto_if_eq VAR_RESULT, TRUE, Prefabs_EventScript_End
	applymovement OBJ_EVENT_ID_PLAYER, Prefabs_Movement_WalkRight
	waitmovement 0
	end

Prefabs_EventScript_End:
	end

Prefabs_Movement_WalkUp:
	walk_up
	step_end

Prefabs_Movement_WalkDown:
	walk_down
	step_end

Prefabs_Movement_WalkRight:
	walk_right
	step_end

Prefabs_Movement_WalkLeft:
	walk_left
	step_end
