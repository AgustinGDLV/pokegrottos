#include "constants/songs.h"

@ Doesn't use VAR_LAST_TALKED because it misbehaves with Movement_FacePlayer
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

EventScript_KecleonShop::
	lock
	faceplayer
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	message gText_WelcomeToKecleonShop
	waitmessage
	callfunc CreateKecleonShopMenu
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox gText_LookingForwardToServing, MSGBOX_DEFAULT
	release
	end

EventScript_ItemBall::
	callfunc ChooseOverworldItem
	finditem VAR_0x8000
	end
