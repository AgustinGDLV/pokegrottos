	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_LevelUp
	.align 2

gbs_Music_LevelUp:
	channel_count 4
	channel 1, Music_LevelUp_Ch1
	channel 2, Music_LevelUp_Ch2
	channel 3, Music_LevelUp_Ch3
	channel 4, Music_LevelUp_Ch4

gbs_Music_LevelUp_Ch1:
	gbs_switch 0
Music_LevelUp_Ch1:
	tempo 159
	volume 7, 7
	duty_cycle 1
	note_type 12, 10, 7
	volume_envelope 9, 7
	octave 4
	note C_, 1
	octave 3
	note B_, 1
	note As, 1
	note A_, 1
	rest 1
	note G_, 1
	rest 1
	note As, 1
	rest 1
	note A_, 7
	sound_ret


gbs_Music_LevelUp_Ch2:
	gbs_switch 1
Music_LevelUp_Ch2:
	duty_cycle 1
	note_type 12, 10, 7
	volume_envelope 9, 7
	octave 4
	note F_, 1
	note F_, 1
	note F_, 1
	note F_, 1
	rest 1
	note Ds, 1
	rest 1
	note G_, 1
	rest 1
	note F_, 7
	sound_ret

gbs_Music_LevelUp_Ch3:
	gbs_switch 2
Music_LevelUp_Ch3:
	note_type 12, 1, 0
	sound_ret

gbs_Music_LevelUp_Ch4:
	gbs_switch 3
Music_LevelUp_Ch4:
	toggle_noise 1
	drum_speed 12
	sound_ret
