	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_SantaluneForest
	.align 2

gbs_Music_SantaluneForest:
	channel_count 3
	channel 1, Music_SantaluneForest_Ch1
	channel 2, Music_SantaluneForest_Ch2
	channel 3, Music_SantaluneForest_Ch3

gbs_Music_SantaluneForest_Ch1:
	gbs_switch 0
Music_SantaluneForest_Ch1:
	tempo 152
	volume 7, 7
	vibrato 6, 2, 3
	note_type 12, 9, 2
	duty_cycle 0
	octave 3
	rest 2
	note F_, 2
	note G_, 4
	note As, 4
	note F_, 2
	note G_, 4
	note F_, 2
	note G_, 4
	note As, 4
	note F_, 2
	note G_, 4
	note F_, 2
	note G_, 4
	note As, 4
	note F_, 2
	note G_, 4
	octave 4
	note C_, 2
	note C_, 12
	duty_cycle 3
	volume_envelope 7, 7
	octave 5
	note C_, 6
	octave 4
	note G_, 6
	note As, 6
	note F_, 6
	note G_, 4
	note As, 4
	octave 5
	note C_, 6
	octave 4
	note G_, 6
	note As, 6
	note F_, 14
Music_SantaluneForest_Ch1_loop_1:
	duty_cycle 0
	volume_envelope 11, 2
	octave 5
	note C_, 4
	octave 4
	note G_, 4
	note As, 4
	note F_, 2
	note G_, 4
	octave 5
	note C_, 2
	octave 4
	note G_, 4
	note As, 4
	note F_, 2
	note G_, 4
	octave 5
	note C_, 2
	octave 4
	note G_, 4
	note As, 4
	note F_, 2
	note G_, 4
	note Gs, 2
	note Gs, 12
	sound_loop 2, Music_SantaluneForest_Ch1_loop_1
	sound_loop 0, Music_SantaluneForest_Ch1

gbs_Music_SantaluneForest_Ch2:
	gbs_switch 1
Music_SantaluneForest_Ch2:
	vibrato 8, 2, 4
	note_type 12, 11, 2
	duty_cycle 2
	octave 3
	note C_, 2
	note As, 2
	octave 4
	note C_, 2
	octave 3
	note C_, 2
	octave 4
	note Ds, 2
	octave 3
	note C_, 2
	note As, 2
	octave 4
	note C_, 2
	octave 3
	note C_, 2
	note As, 2
	octave 4
	note C_, 2
	octave 3
	note C_, 2
	octave 4
	note Ds, 2
	octave 3
	note C_, 2
	note As, 2
	octave 4
	note C_, 2
	octave 3
	note C_, 2
	note As, 2
	octave 4
	note C_, 2
	octave 3
	note C_, 2
	octave 4
	note Ds, 2
	octave 3
	note C_, 2
	note As, 2
	octave 4
	note C_, 2
	octave 3
	note C_, 2
	octave 4
	note F_, 2
	note F_, 2
	octave 3
	note C_, 4
	note C_, 4
	note C_, 2
	sound_loop 0, Music_SantaluneForest_Ch2
	
gbs_Music_SantaluneForest_Ch3:
	gbs_switch 2
Music_SantaluneForest_Ch3:
	vibrato 22, 1, 5
	note_type 12, 2, 0
	rest 16
Music_SantaluneForest_Ch3_loop_main:
	rest 16
	rest 16
	rest 16
	rest 2
Music_SantaluneForest_Ch3_loop_1:
	octave 4
	note C_, 2
	note Ds, 2
	note G_, 4
	note C_, 2
	note Ds, 2
	note F_, 4
	note C_, 2
	note Ds, 2
	note F_, 4
	octave 3
	note As, 2
	octave 4
	note C_, 2
	note Ds, 4
	sound_loop 6, Music_SantaluneForest_Ch3_loop_1
	note Ds, 6
	volume_envelope 3, 0
	note Ds, 4
	volume_envelope 2, 0
	rest 4
	sound_loop 0, Music_SantaluneForest_Ch3_loop_main
