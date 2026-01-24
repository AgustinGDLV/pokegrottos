	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_OceanicFriendArea
	.align 2

@ By Monstarules
@ This music is free-use
gbs_Music_OceanicFriendArea:
	channel_count 4
	channel 1, Music_OceanicFriendArea_Ch1
	channel 2, Music_OceanicFriendArea_Ch2
	channel 3, Music_OceanicFriendArea_Ch3
	channel 4, Music_OceanicFriendArea_Ch4

gbs_Music_OceanicFriendArea_Ch1:
	gbs_switch 0
Music_OceanicFriendArea_Ch1:
	tempo 224
	volume 7, 7
	stereo_panning TRUE, TRUE
	duty_cycle 2
	pitch_offset 1
Music_OceanicFriendArea_Ch1_loop:
	octave 5
	note_type 12, 10, 1
	note F_, 1
	volume_envelope 2, 0
	note F_, 1
	volume_envelope 10, 1
	note Cs, 1
	volume_envelope 2, 0
	note Cs, 1
	volume_envelope 10, 1
	octave 4
	note As, 1
	volume_envelope 2, 0
	note As, 1
	volume_envelope 10, 1
	note Fs, 1
	volume_envelope 2, 0
	note Fs, 1
	volume_envelope 10, 1
	octave 5
	note F_, 1
	volume_envelope 2, 0
	note F_, 1
	volume_envelope 10, 1
	note Cs, 1
	volume_envelope 2, 0
	note Cs, 1
	volume_envelope 10, 1
	octave 4
	note As, 1
	volume_envelope 2, 0
	note As, 1
	volume_envelope 10, 1
	note Fs, 1
	volume_envelope 2, 0
	note Fs, 1
	volume_envelope 10, 1
	octave 5
	note Ds, 1
	volume_envelope 2, 0
	note Ds, 1
	volume_envelope 10, 1
	note C_, 1
	volume_envelope 2, 0
	note C_, 1
	volume_envelope 10, 1
	octave 4
	note Gs, 1
	volume_envelope 2, 0
	note Gs, 1
	volume_envelope 10, 1
	note F_, 1
	volume_envelope 2, 0
	note F_, 1
	volume_envelope 10, 1
	octave 5
	note Ds, 1
	volume_envelope 2, 0
	note Ds, 1
	volume_envelope 10, 1
	note C_, 1
	volume_envelope 2, 0
	note C_, 1
	volume_envelope 10, 1
	octave 4
	note Gs, 1
	volume_envelope 2, 0
	note Gs, 1
	volume_envelope 10, 1
	note F_, 1
	volume_envelope 2, 0
	note F_, 1
	sound_loop 0, Music_OceanicFriendArea_Ch1_loop

gbs_Music_OceanicFriendArea_Ch2:
	gbs_switch 1
Music_OceanicFriendArea_Ch2:
	duty_cycle 0
	note_type 12, 10, 1
	rest 16
	rest 16
	rest 16
	rest 16
	rest 4
	octave 4
	note F_, 2
	volume_envelope 6, 1
	note F_, 2
	volume_envelope 10, 1
	note Ds, 2
	volume_envelope 6, 1
	note Ds, 2
	volume_envelope 10, 1
	note As, 2
	volume_envelope 6, 1
	note As, 2
	volume_envelope 10, 1
	note Gs, 2
	volume_envelope 6, 1
	note Gs, 2
	note Gs, 2
	note Gs, 2
	volume_envelope 10, 1
	note F_, 2
	volume_envelope 6, 1
	note F_, 2
	volume_envelope 10, 1
	note Ds, 2
	volume_envelope 6, 1
	note Ds, 2
	rest 4
	volume_envelope 10, 1
	note F_, 2
	volume_envelope 6, 1
	note F_, 2
	volume_envelope 10, 1
	note Ds, 2
	volume_envelope 6, 1
	note Ds, 2
	volume_envelope 10, 1
	note As, 2
	volume_envelope 6, 1
	note As, 2
	volume_envelope 10, 1
	octave 5
	note C_, 2
	volume_envelope 6, 1
	note C_, 2
	note C_, 2
	note C_, 2
	volume_envelope 10, 1
	octave 4
	note Gs, 2
	volume_envelope 6, 1
	note Gs, 2
	note Gs, 2
	note Gs, 2
	rest 4
	volume_envelope 10, 1
	note F_, 2
	volume_envelope 6, 1
	note F_, 2
	volume_envelope 10, 1
	note Ds, 2
	volume_envelope 6, 1
	note Ds, 2
	volume_envelope 10, 1
	note As, 2
	volume_envelope 6, 1
	note As, 2
	volume_envelope 10, 1
	note Gs, 2
	volume_envelope 6, 1
	note Gs, 2
	note Gs, 2
	note Gs, 2
	volume_envelope 10, 1
	note F_, 2
	volume_envelope 6, 1
	note F_, 2
	volume_envelope 10, 1
	note Ds, 2
	volume_envelope 6, 1
	note Ds, 2
	rest 4
	volume_envelope 10, 1
	note F_, 2
	volume_envelope 6, 1
	note F_, 2
	volume_envelope 10, 1
	note Ds, 2
	volume_envelope 6, 1
	note Ds, 2
	volume_envelope 10, 1
	note As, 2
	volume_envelope 6, 1
	note As, 2
	volume_envelope 10, 1
	octave 5
	note C_, 2
	volume_envelope 6, 1
	note C_, 2
	note C_, 2
	note C_, 2
	volume_envelope 10, 1
	octave 4
	note Gs, 2
	volume_envelope 6, 1
	note Gs, 2
	note Gs, 2
	note Gs, 2
	duty_cycle 1
	volume_envelope 12, 1
	note F_, 1
	note Ds, 1
	note Cs, 1
	octave 3
	note As, 1
	note Fs, 1
	rest 1
	duty_cycle 2
	volume_envelope 9, 1
	octave 4
	note F_, 1
	note Ds, 1
	note Cs, 1
	octave 3
	note As, 1
	note Fs, 1
	rest 5
	duty_cycle 1
	volume_envelope 12, 1
	note Ds, 1
	note F_, 1
	note Gs, 1
	octave 4
	note C_, 1
	note Ds, 1
	rest 1
	duty_cycle 2
	volume_envelope 9, 1
	octave 3
	note Ds, 1
	note F_, 1
	note Gs, 1
	octave 4
	note C_, 1
	note Ds, 1
	rest 5
	duty_cycle 1
	volume_envelope 12, 1
	note F_, 1
	note Ds, 1
	note Cs, 1
	octave 3
	note As, 1
	note Fs, 1
	rest 1
	duty_cycle 2
	volume_envelope 9, 1
	octave 4
	note F_, 1
	note Ds, 1
	note Cs, 1
	octave 3
	note As, 1
	note Fs, 1
	rest 5
	duty_cycle 1
	volume_envelope 12, 1
	note Ds, 1
	note F_, 1
	note Gs, 1
	octave 4
	note C_, 1
	note Gs, 1
	rest 1
	duty_cycle 2
	volume_envelope 9, 1
	octave 3
	note Ds, 1
	note F_, 1
	note Gs, 1
	octave 4
	note C_, 1
	note Gs, 1
	rest 5
	note F_, 1
	note Ds, 1
	note Cs, 1
	octave 3
	note As, 1
	note Fs, 1
	rest 1
	duty_cycle 1
	volume_envelope 12, 1
	octave 4
	note F_, 1
	note Ds, 1
	note Cs, 1
	octave 3
	note As, 1
	note Fs, 1
	rest 5
	duty_cycle 2
	volume_envelope 9, 1
	note Ds, 1
	note F_, 1
	note Gs, 1
	octave 4
	note C_, 1
	note Ds, 1
	rest 1
	duty_cycle 1
	volume_envelope 12, 1
	octave 3
	note Ds, 1
	note F_, 1
	note Gs, 1
	octave 4
	note C_, 1
	note Ds, 1
	rest 5
	duty_cycle 2
	volume_envelope 9, 1
	note F_, 1
	note Ds, 1
	note Cs, 1
	octave 3
	note As, 1
	note Fs, 1
	rest 1
	duty_cycle 1
	volume_envelope 12, 1
	octave 4
	note F_, 1
	note Ds, 1
	note Cs, 1
	octave 3
	note As, 1
	note Fs, 1
	rest 5
	duty_cycle 2
	volume_envelope 9, 1
	note Ds, 1
	note F_, 1
	note Gs, 1
	octave 4
	note C_, 1
	note Gs, 1
	rest 1
	duty_cycle 1
	volume_envelope 12, 1
	octave 3
	note Ds, 1
	note F_, 1
	note Gs, 1
	octave 4
	note C_, 1
	note Gs, 1
	rest 5
	sound_loop 0, Music_OceanicFriendArea_Ch2

gbs_Music_OceanicFriendArea_Ch3:
	gbs_switch 2
Music_OceanicFriendArea_Ch3:
	vibrato 0, 2, 4
	octave 1
	note_type 12, 1, 1
	note As, 4
	duty_cycle 4
	volume_envelope 2, 4
	vibrato 4, 2, 4
	octave 3
	note As, 4
	octave 4
	note F_, 4
	note Cs, 4
	note Ds, 16
	octave 1
	note As, 4
	octave 3
	note As, 4
	octave 4
	note F_, 4
	note Cs, 4
	note C_, 16
	sound_loop 0, Music_OceanicFriendArea_Ch3

gbs_Music_OceanicFriendArea_Ch4:
	gbs_switch 3
Music_OceanicFriendArea_Ch4:
	toggle_noise 3
Music_OceanicFriendArea_Ch4_loop:
	drum_speed 12
	drum_note 4, 4
	drum_note 2, 4
	drum_note 3, 4
	rest 4
	sound_loop 0, Music_OceanicFriendArea_Ch4_loop
