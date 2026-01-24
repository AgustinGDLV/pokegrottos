	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_CaveOfOrigin
	.align 2

gbs_Music_CaveOfOrigin:
	channel_count 3
	channel 1, Music_CaveOfOrigin_Ch1
	channel 2, Music_CaveOfOrigin_Ch2
	channel 3, Music_CaveOfOrigin_Ch3

gbs_Music_CaveOfOrigin_Ch1:
	gbs_switch 0
Music_CaveOfOrigin_Ch1:
	tempo 190
	volume 7, 7
	vibrato 6, 2, 3
	note_type 8, 9, 2
	rest 6
Music_CaveOfOrigin_Ch1_loop_main:
	volume_envelope 9, 2
	duty_cycle 2
	octave 4
	note Ds, 2
	note G_, 2
	note Gs, 2
	note G_, 2
	note Ds, 2
	octave 3
	note As, 2
	note Ds, 2
	note G_, 2
	note Gs, 2
	note G_, 2
	octave 4
	note G_, 2
	octave 5
	note Ds, 2
	volume_envelope 6, 2
	octave 7
	note Ds, 1
	note D_, 1
	octave 6
	note As, 1
	note G_, 1
	note Ds, 1
	note D_, 1
	octave 5
	note As, 1
	note G_, 1
	note Ds, 1
	note D_, 1
	octave 4
	note As, 1
	note G_, 1
	note Ds, 1
	note G_, 1
	note As, 1
	octave 5
	note D_, 1
	note Ds, 1
	note G_, 1
	note As, 1
	octave 6
	note D_, 1
	note Ds, 1
	note G_, 1
	note As, 1
	octave 7
	note D_, 1
	volume_envelope 9, 2
	octave 4
	note Cs, 2
	note Ds, 2
	note E_, 2
	note Ds, 2
	note Cs, 2
	octave 3
	note A_, 2
	note Cs, 2
	note Ds, 2
	note E_, 2
	note Ds, 2
	octave 4
	note Cs, 2
	octave 5
	note Cs, 2
	volume_envelope 6, 2
	octave 7
	note Ds, 1
	note Cs, 1
	octave 6
	note A_, 1
	note G_, 1
	note Ds, 1
	note Cs, 1
	octave 5
	note A_, 1
	note G_, 1
	note Ds, 1
	note Cs, 1
	octave 4
	note A_, 1
	note G_, 1
	note Ds, 1
	note G_, 1
	note A_, 1
	octave 5
	note Cs, 1
	note Ds, 1
	note G_, 1
	note A_, 1
	octave 6
	note Cs, 1
	note Ds, 1
	note G_, 1
	note A_, 1
	octave 7
	note Cs, 1
	volume_envelope 9, 2
	duty_cycle 0
	octave 3
	note Gs, 2
	note Ds, 2
	octave 2
	note Gs, 2
	octave 3
	note Gs, 2
	note Ds, 2
	octave 2
	note Gs, 2
	octave 3
	note Gs, 2
	note Ds, 2
	octave 2
	note Gs, 2
	octave 3
	note Gs, 2
	note Ds, 2
	octave 2
	note Gs, 2
	volume_envelope 6, 2
	duty_cycle 2
	octave 7
	note Ds, 1
	note C_, 1
	octave 6
	note Gs, 1
	note Fs, 1
	note Ds, 1
	note C_, 1
	octave 5
	note Gs, 1
	note Fs, 1
	note Ds, 1
	note C_, 1
	octave 4
	note Gs, 1
	note Fs, 1
	note Ds, 1
	note Fs, 1
	note Gs, 1
	octave 5
	note C_, 1
	note Ds, 1
	note Fs, 1
	note Gs, 1
	octave 6
	note C_, 1
	note Ds, 1
	note Fs, 1
	note Gs, 1
	octave 7
	note C_, 1
	volume_envelope 9, 2
	octave 3
	note As, 2
	octave 4
	note E_, 2
	note F_, 2
	note E_, 2
	octave 3
	note As, 2
	note E_, 2
	octave 2
	note As, 2
	octave 3
	note E_, 2
	note F_, 2
	note E_, 2
	note As, 2
	octave 4
	note As, 2
	octave 3
	note As, 2
	octave 4
	note E_, 2
	note F_, 2
	note E_, 2
	octave 3
	note As, 2
	note E_, 2
	note Cs, 2
	note E_, 2
	note F_, 2
	note E_, 2
	octave 4
	note E_, 2
	octave 5
	note Cs, 2
	octave 3
	note As, 2
	octave 4
	note E_, 2
	note F_, 2
	note E_, 2
	octave 3
	note As, 2
	note E_, 2
	octave 2
	note As, 2
	octave 3
	note E_, 2
	note F_, 2
	note E_, 2
	note As, 2
	octave 4
	note As, 2
	octave 5
	note Cs, 2
	octave 4
	note As, 2
	note G_, 2
	octave 5
	note Cs, 2
	octave 4
	note As, 2
	note G_, 2
	octave 5
	note Cs, 2
	octave 4
	note As, 2
	note G_, 2
	octave 5
	note Cs, 2
	octave 4
	note As, 2
	note G_, 2
	duty_cycle 3
	volume_envelope 13, 2
	octave 4
	note Ds, 8
	note Ds, 2
	note Ds, 2
	note Ds, 8
	note Ds, 2
	note Ds, 2
	note Ds, 9
	duty_cycle 2
	volume_envelope 6, 2
	octave 5
	note Ds, 2
	note D_, 2
	octave 4
	note G_, 2
	note Ds, 2
	note C_, 2
	note D_, 2
	note Ds, 2
	note D_, 1
	duty_cycle 3
	volume_envelope 13, 2
	note Ds, 8
	note Ds, 2
	note Ds, 2
	note Ds, 8
	note Ds, 2
	note Ds, 2
	note Ds, 9
	duty_cycle 2
	volume_envelope 6, 2
	octave 5
	note Ds, 2
	note D_, 2
	note C_, 2
	octave 4
	note Gs, 2
	note F_, 2
	note G_, 2
	note Gs, 2
	note G_, 1
	duty_cycle 3
	volume_envelope 13, 2
	note D_, 8
	note D_, 2
	note D_, 2
	note D_, 8
	note D_, 2
	note D_, 2
	note Cs, 8
	note Cs, 2
	note Cs, 2
	note Cs, 8
	note Cs, 2
	note Cs, 2
	note C_, 8
	note C_, 2
	note C_, 2
	note C_, 6
	octave 3
	volume_envelope 8, 0
	note Fs, 1
	note A_, 1
	octave 4
	note C_, 1
	note Ds, 1
	note Fs, 1
	note A_, 1
	note As, 16
	volume_envelope 8, 7
	note As, 8
	sound_loop 0, Music_CaveOfOrigin_Ch1_loop_main

gbs_Music_CaveOfOrigin_Ch2:
	gbs_switch 1
Music_CaveOfOrigin_Ch2:
	vibrato 6, 2, 3
	note_type 8, 11, 2
	duty_cycle 3
	octave 3
	note As, 1
	octave 4
	note D_, 1
	note F_, 1
	note Gs, 1
	note As, 1
	octave 5
	note C_, 1
	volume_envelope 11, 0
	note D_, 16
	note D_, 16
	note D_, 4
	volume_envelope 11, 7
	note D_, 12
	volume_envelope 11, 0
	note Cs, 16
	note Cs, 16
	note Cs, 4
	volume_envelope 11, 7
	note Cs, 12
	volume_envelope 11, 2
	octave 4
	note Gs, 6
	note Gs, 6
	note Gs, 8
	note Gs, 2
	note Gs, 2
	note Gs, 6
	note Gs, 6
	note Gs, 12
	volume_envelope 11, 0
	note As, 16
	note As, 16
	note As, 16
	note As, 16
	volume_envelope 11, 7
	note As, 8
	volume_envelope 9, 2
	octave 3
	note E_, 2
	note Cs, 2
	octave 2
	note As, 2
	octave 3
	note E_, 2
	note Cs, 2
	octave 2
	note As, 2
	octave 3
	note E_, 2
	note Cs, 2
	octave 2
	note As, 2
	octave 3
	note E_, 2
	note Cs, 2
	octave 2
	note As, 2
	duty_cycle 2
	volume_envelope 9, 2
	octave 5
	note C_, 2
	octave 4
	note As, 2
	note G_, 2
	note Ds, 2
	note D_, 2
	octave 3
	note G_, 2
	note Ds, 2
	note C_, 2
	note D_, 2
	note Ds, 2
	octave 4
	note Ds, 2
	octave 5
	note G_, 2
	octave 6
	note C_, 2
	octave 5
	note As, 2
	note G_, 2
	note Ds, 2
	note D_, 2
	octave 4
	note G_, 2
	note Ds, 2
	note C_, 2
	note D_, 2
	note Ds, 2
	note D_, 2
	note C_, 2
	octave 5
	note Ds, 2
	note C_, 2
	octave 4
	note Gs, 2
	note F_, 2
	note Ds, 2
	note C_, 2
	octave 3
	note Gs, 2
	note F_, 2
	note G_, 2
	note Gs, 2
	octave 4
	note Gs, 2
	octave 5
	note F_, 2
	note Gs, 2
	note G_, 2
	note F_, 2
	note Ds, 2
	note D_, 2
	note C_, 2
	octave 4
	note Gs, 2
	note F_, 2
	note G_, 2
	note Gs, 2
	note G_, 2
	note F_, 2
	note D_, 2
	note Ds, 2
	note F_, 2
	octave 5
	note D_, 2
	octave 4
	note B_, 2
	octave 5
	note C_, 2
	note D_, 2
	note Ds, 2
	note D_, 2
	octave 4
	note B_, 2
	note Gs, 2
	note F_, 2
	note Cs, 2
	note D_, 2
	note E_, 2
	octave 5
	note Cs, 2
	octave 4
	note As, 2
	note B_, 2
	octave 5
	note Cs, 2
	note D_, 2
	note Cs, 2
	octave 4
	note As, 2
	note G_, 2
	note E_, 2
	note Fs, 2
	note Ds, 2
	note A_, 2
	note Ds, 2
	note Fs, 2
	note A_, 2
	volume_envelope 8, 2
	note Fs, 2
	volume_envelope 7, 2
	note Ds, 2
	volume_envelope 6, 2
	note A_, 2
	volume_envelope 11, 2
	duty_cycle 3
	octave 4
	rest 2
	note C_, 2
	note C_, 2
	volume_envelope 11, 0
	note Ds, 6
	volume_envelope 11, 7
	note Ds, 6
	note D_, 6
	sound_loop 0, Music_CaveOfOrigin_Ch2
	
gbs_Music_CaveOfOrigin_Ch3:
	gbs_switch 2
Music_CaveOfOrigin_Ch3:
	vibrato 22, 1, 5
	note_type 12, 1, 4
	rest 4
Music_CaveOfOrigin_Ch3_loop_main:
	note_type 12, 1, 4
	octave 2
	note Ds, 14
	note As, 2
	note Ds, 8
	note_type 8, 1, 4
	note G_, 4
	note F_, 4
	note G_, 4
	note_type 12, 1, 4
	note A_, 14
	octave 3
	note Cs, 2
	octave 2
	note A_, 7
	rest 1
	note_type 8, 1, 4
	note A_, 4
	note G_, 4
	note A_, 4
	note Gs, 2
	rest 4
	note Gs, 2
	rest 4
	note Gs, 2
	rest 6
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note Gs, 2
	rest 4
	note Gs, 2
	rest 4
	note Gs, 2
	rest 4
	octave 3
	note C_, 6
	note Cs, 16
	note Cs, 12
	volume_envelope 2, 4
	note Cs, 8
	volume_envelope 1, 4
	note Cs, 4
	octave 2
	note B_, 4
	note Gs, 4
	note G_, 16
	volume_envelope 2, 4
	note G_, 8
	volume_envelope 1, 4
	note G_, 2
	rest 4
	note G_, 2
	rest 4
	note G_, 2
	rest 4
	note G_, 2
	rest 4
	octave 3
	note C_, 2
	rest 6
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 2
	rest 6
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	note C_, 2
	rest 16
	rest 6
	octave 2
	note F_, 2
	rest 6
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	note F_, 2
	rest 6
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	note F_, 2
	rest 16
	rest 6
	note B_, 2
	rest 6
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	note B_, 2
	rest 6
	note B_, 1
	rest 1
	note B_, 1
	rest 1
	note As, 2
	rest 6
	note As, 1
	rest 1
	note As, 1
	rest 1
	note As, 2
	rest 6
	note As, 1
	rest 1
	note As, 1
	rest 1
	note A_, 2
	rest 6
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 2
	rest 6
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note As, 11
	rest 1
	note As, 4
	note Gs, 4
	note F_, 4
	sound_loop 0, Music_CaveOfOrigin_Ch3_loop_main
