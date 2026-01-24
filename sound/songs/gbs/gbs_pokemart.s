	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_PokemonMart
	.align 2

gbs_Music_PokemonMart:
	channel_count 4
	channel 1, Music_PokemonMart_Ch1
	channel 2, Music_PokemonMart_Ch2
	channel 3, Music_PokemonMart_Ch3
	channel 4, Music_PokemonMart_Ch4


gbs_Music_PokemonMart_Ch1:
	gbs_switch 0
Music_PokemonMart_Ch1:
	duty_cycle 2
	vibrato 18, 1, 5
	tempo 228
	note_type 8, 12, 1
	octave 2
Music_PokemonMart_Ch1_loop_1:	
	rest 3
	pitch_sweep 6, -3
	note B_, 1 
	rest 2
	sound_loop 6, Music_PokemonMart_Ch1_loop_1
	note_type 3, 8, 2
	octave 6
	note Ds, 4
	octave 5
	note B_, 1
	sound_call Music_PokemonMart_Ch1_branch_1
	note E_, 1
	note D_, 1
	note C_, 1
	octave 2
	note B_, 7
Music_PokemonMart_Ch1_loop_main:
	note_type 4, 6, 0
	duty_cycle 1
	rest 12
Music_PokemonMart_Ch1_loop_2:
	octave 5
	note Ds, 2
	rest 2
	note Ds, 2
	octave 4
	note Ds, 2
	octave 5
	note Ds, 2
	octave 4
	note Ds, 2
	rest 12
	rest 12
	rest 12
	sound_loop 2, Music_PokemonMart_Ch1_loop_2
	octave 5
	note E_, 2
	rest 2
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note Ds, 2
	note Cs, 2
	octave 4
	note B_, 12
	note As, 6
	note Gs, 6
	note Fs, 10
	note Gs, 1
	note A_, 1
	note Gs, 12
	note As, 2
	note B_, 2
	octave 5
	note Cs, 2
	note Ds, 2
	note E_, 2
	note Fs, 2
	rest 12
	rest 12
Music_PokemonMart_Ch1_loop_3:
	octave 5
	note B_, 2
	rest 2
	note B_, 2
	octave 4
	note B_, 2
	octave 5
	note B_, 2
	octave 4
	note B_, 2
	rest 12
	rest 12
	rest 12
	sound_loop 2, Music_PokemonMart_Ch1_loop_3
	octave 5
	note E_, 2
	rest 2
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	note Ds, 2
	note Cs, 2
	octave 4
	note Gs, 12
	note B_, 6
	note Gs, 6
	note As, 10
	note B_, 1
	note As, 1
	note Gs, 12
	note As, 2
	rest 2
	note B_, 2
	octave 5
	note Cs, 2
	rest 2
	note Ds, 2
	note E_, 2
	rest 10
@;;;;;;;;;;;;;;;;;;;;;;;
	duty_cycle 2
	volume_envelope 7, 2
	sound_call Music_PokemonMart_Ch1_branch_2
	note As, 6
	note G_, 6
	note Ds, 6
	note Gs, 4
	note G_, 2
	note Gs, 4
	note As, 2
	note B_, 4
	note As, 2
	note B_, 4
	octave 4
	note Cs, 2
	note Ds, 4
	note D_, 2
	note Ds, 4
	note Gs, 6
	note Ds, 2
	note Cs, 2
	octave 3
	note B_, 2
	note Gs, 2
	sound_call Music_PokemonMart_Ch1_branch_2
	note As, 2
	note A_, 2
	note As, 2
	note B_, 2
	note As, 2
	note B_, 2
	octave 4
	note Cs, 2
	note C_, 2
	note Cs, 2
	volume_envelope 7, 4
	note Cs, 6
	note Ds, 4
	octave 3
	note B_, 6
	note As, 2
	note B_, 4
	octave 4
	note Cs, 8
	note Ds, 4
	octave 3
	note B_, 6
	octave 4
	note E_, 2
	note Ds, 4
	note Cs, 2
	volume_envelope 7, 2
	octave 2
	note B_, 2
	octave 3
	note E_, 2
	note Gs, 2
	note B_, 2
	octave 4
	note E_, 2
	note Gs, 2
	note B_, 2
	octave 5
	note E_, 2
	octave 4
	note B_, 2
	note Gs, 2
	note E_, 2
	octave 3
	note B_, 2
	note Gs, 2
	note F_, 2
	note Gs, 2
	note B_, 2
	octave 4
	note F_, 2
	note Gs, 2
	note B_, 2
	octave 5
	note F_, 2
	octave 4
	note B_, 2
	note Gs, 2
	note E_, 2
	octave 3
	note B_, 2
	note Fs, 2
	note B_, 2
	octave 4
	note Cs, 2
	note Fs, 2
	note B_, 2
	octave 5
	note Cs, 2
	note Fs, 2
	note Cs, 2
	octave 4
	note As, 2
	octave 5
	note Cs, 2
	octave 4
	note As, 2
	note Fs, 8
	duty_cycle 3
	volume_envelope 5, 0
	octave 6
	note E_, 2
	note Cs, 2
	octave 5
	note Gs, 2
	note As, 2
	note Gs, 2
	note Fs, 2
	note E_, 2
	octave 4
	note Gs, 2
	note As, 2
	sound_loop 0, Music_PokemonMart_Ch1_loop_main

Music_PokemonMart_Ch1_branch_1:
	volume_envelope 7, 1
	note A_, 1
	note G_, 1
	note F_, 1
	note E_, 1
	volume_envelope 6, 1
	note D_, 1
	note C_, 1
	octave 4
	note B_, 1
	note A_, 1
	volume_envelope 5, 1
	note G_, 1
	note F_, 1
	note E_, 1
	note D_, 1
	volume_envelope 4, 1
	note C_, 1
	octave 3
	note B_, 1
	note A_, 1
	note G_, 1
	volume_envelope 3, 1
	note F_, 1
	sound_ret
	
Music_PokemonMart_Ch1_branch_2:
	octave 3
	note As, 6 
	note As, 6 
	note As, 4
	note Fs, 2
	note As, 2
	note G_, 2
	octave 4
	note Ds, 8
	octave 3
	sound_ret
	
gbs_Music_PokemonMart_Ch2:
	gbs_switch 1
Music_PokemonMart_Ch2:
	duty_cycle 3
	note_type 3, 8, 2
Music_PokemonMart_Ch2_loop_1:
	rest 16
	sound_loop 6, Music_PokemonMart_Ch2_loop_1
	octave 5
	note B_, 4
	sound_call Music_PokemonMart_Ch1_branch_1
	rest 3
	duty_cycle 0
	note_type 4, 10, 2
	note Fs, 2
	note Gs, 2
	note As, 2
Music_PokemonMart_Ch2_loop_main:
	vibrato 18, 1, 5
	sound_call Music_PokemonMart_Ch2_branch_1
	rest 1
	volume_envelope 10, 0
	note E_, 3
	volume_envelope 8, 0
	note Ds, 1
	volume_envelope 6, 0
	note Cs, 1
	volume_envelope 5, 0
	octave 3
	note As, 1
	volume_envelope 3, 0
	note A_, 1
	volume_envelope 2, 0
	note F_, 1
	volume_envelope 10, 2
	octave 4
	note Ds, 2
	note E_, 2
	note Fs, 2
	sound_call Music_PokemonMart_Ch2_branch_1
	note G_, 1
	volume_envelope 10, 0
	note Gs, 3
	volume_envelope 8, 0
	note G_, 1
	volume_envelope 6, 0
	note F_, 1
	volume_envelope 5, 0
	note D_, 1
	volume_envelope 3, 2
	note C_, 2
	volume_envelope 10, 2
	note E_, 2
	note Ds, 2
	note Cs, 2
@;;;;;;;;;;;;;;;;
	octave 4
	note Ds, 4
	octave 3
	note Gs, 2
	octave 4
	note E_, 4
	volume_envelope 10, 0
	note Cs, 10
	octave 3
	volume_envelope 8, 0
	note B_, 1
	volume_envelope 6, 0
	note As, 1
	volume_envelope 5, 0
	note Fs, 1
	volume_envelope 3, 2
	note E_, 7
	volume_envelope 10, 0
	note Gs, 6
	note As, 6
	note B_, 6
	octave 4
	note Ds, 10
	note E_, 1
	note Ds, 1
	note Cs, 6
	volume_envelope 10, 2
	octave 3
	note B_, 2
	note As, 2
	note B_, 2
	note_type 3, 10, 0
	octave 4
	note Cs, 4
	volume_envelope 7, 0
	note C_, 1
	volume_envelope 5, 0
	octave 3
	note A_, 1
	volume_envelope 3, 0
	note G_, 1
	note E_, 1
	volume_envelope 4, 0
	note Cs, 1
	note Ds, 1
	volume_envelope 5, 0
	note E_, 1
	note Gs, 1
	volume_envelope 6, 0
	note As, 1
	octave 4
	note Cs, 1
	volume_envelope 7, 0
	note Ds, 1
	note Fs, 1
	volume_envelope 8, 0
	note Gs, 1
	duty_cycle 2
	note B_, 1
	volume_envelope 10, 0
	octave 5
	note C_, 1
	octave 4
	note B_, 5
	note_type 4, 10, 2
	note Fs, 2
	note E_, 2
	note Ds, 2
@;;;;;;;;;;;;;;;;;;;;;;;
	note Cs, 5
	note D_, 1
	note Ds, 4
	volume_envelope 10, 5
	octave 3
	note B_, 10
	volume_envelope 10, 2
	note B_, 2
	octave 4
	note Cs, 2
	note Ds, 10
	note E_, 6
	note Ds, 2
	note E_, 4
	note Fs, 2
	note Cs, 4
	octave 3
	note Fs, 2
	octave 4
	note Ds, 4
	volume_envelope 10, 5
	octave 3
	note B_, 10
	volume_envelope 10, 2
	note B_, 2
	octave 4
	note Cs, 2
	note Ds, 9
	note G_, 1
	note Gs, 6
	note Fs, 4
	octave 3
	note B_, 2
	octave 4
	note Cs, 2
@;;;;;;;;;;;;;;;;;;;;
	note Ds, 4
	octave 3
	note Gs, 2
	octave 4
	note E_, 4
	volume_envelope 10, 7
	note Cs, 16
	rest 4
	volume_envelope 10, 4
	octave 3
	note Gs, 2
	note G_, 2
	note Gs, 2
	note As, 2
	note A_, 2
	note As, 2
	note B_, 2
	note As, 2
	note B_, 2
	volume_envelope 10, 6
	octave 4
	note Ds, 10
	note E_, 1
	note Ds, 1
	note Cs, 6
	octave 3
	note B_, 2
	note As, 2
	note B_, 2
	octave 4
	note Cs, 2
	rest 16
	duty_cycle 0
	volume_envelope 10, 2
	octave 2
	note B_, 4
	octave 3
	note Cs, 2
@;;;;;;;;;;;;;;;
	note Ds, 6
	note Ds, 6
	note Ds, 4
	note D_, 2
	note Ds, 2
	note D_, 2
	note As, 8
	note G_, 6
	note Ds, 6
	note Cs, 6
	duty_cycle 2
	volume_envelope 10, 4
	octave 4
	note Cs, 5
	note D_, 1
	note Ds, 4
	octave 3
	note B_, 6
	note As, 2
	note B_, 4
	octave 4
	note Cs, 8
	note Ds, 4
	octave 3
	note B_, 6
	note As, 2
	note B_, 4
	octave 4
	note Cs, 2
@;;;;;;;;;;;;;;;
	duty_cycle 0
	volume_envelope 10, 2
	octave 3
	note Ds, 6
	note Ds, 6
	note Ds, 4
	note D_, 2
	note Ds, 2
	note D_, 2
	note As, 8
	note G_, 2
	note Fs, 2
	note G_, 2
	note Gs, 2
	note G_, 2
	note Gs, 2
	note As, 2
	note A_, 2
	note As, 2
	duty_cycle 2
	volume_envelope 10, 5
	octave 4
	note As, 6
	volume_envelope 10, 3
	note B_, 4
	note Gs, 6
	note G_, 2
	note Gs, 4
	volume_envelope 10, 5
	note As, 8
	volume_envelope 10, 3
	note B_, 4
	note Gs, 6
	octave 5
	note Cs, 2
	octave 4
	note B_, 4
	note A_, 2
	vibrato 18, 2, 4
	duty_cycle 0
	volume_envelope 10, 0
	note B_, 12
	volume_envelope 10, 7
	note B_, 11
	note As, 1
	volume_envelope 10, 0
	note B_, 12
	volume_envelope 10, 7
	note B_, 6
	volume_envelope 10, 2
	note Gs, 2
	note As, 2
	note B_, 2
	volume_envelope 10, 0
	note As, 12
	volume_envelope 10, 7
	note As, 6
	volume_envelope 10, 2
	note Gs, 2
	note As, 2
	note Gs, 2
	volume_envelope 10, 6
	note Fs, 6
	duty_cycle 2
	octave 5
	note E_, 2
	note Cs, 2
	octave 4
	note Gs, 2
	note As, 2
	note Gs, 2
	note Fs, 2
	note E_, 2
	octave 3
	note Gs, 2
	note As, 2
	duty_cycle 0
	volume_envelope 9, 2
	sound_loop 0, Music_PokemonMart_Ch2_loop_main
	
Music_PokemonMart_Ch2_branch_1:
	octave 4
	note Cs, 4
	octave 3
	note Fs, 2
	octave 4
	note Ds, 4
	octave 3
	volume_envelope 9, 5
	note B_, 10
	volume_envelope 9, 2
	note B_, 2
	octave 4
	note Cs, 2
	note Ds, 4
	note D_, 2
	note Ds, 3
	sound_ret
	
gbs_Music_PokemonMart_Ch3:
	gbs_switch 2
Music_PokemonMart_Ch3:
	note_type 4, 2, 2
Music_PokemonMart_Ch3_loop_1:
	rest 16
	sound_loop 6, Music_PokemonMart_Ch3_loop_1
Music_PokemonMart_Ch3_loop_main:
Music_PokemonMart_Ch3_loop_2:
	sound_call Music_PokemonMart_Ch3_branch_1
	sound_call Music_PokemonMart_Ch3_branch_1
	octave 2
	note E_, 4
	rest 2
	octave 4
	note Gs, 4
	octave 3
	note B_, 2
	octave 2
	note E_, 4
	rest 2
	octave 4
	note Gs, 4
	octave 3
	note B_, 2
	octave 2
	note Cs, 4
	rest 2
	octave 4
	note E_, 4
	octave 3
	note B_, 2
	octave 2
	note Cs, 4
	rest 2
	octave 4
	note E_, 4
	rest 2
	octave 2
	note Fs, 4
	rest 2
	octave 4
	note As, 4
	note Fs, 2
	octave 2
	note Fs, 4
	rest 2
	octave 4
	note As, 4
	rest 2
	octave 2
	note Fs, 3
	rest 1
	note Fs, 2
	octave 4
	note As, 2
	note Fs, 2
	note As, 2
	octave 2
	note Fs, 2
	octave 4
	note As, 4
	note B_, 2
	rest 2
	octave 5
	note Cs, 2
	sound_loop 2, Music_PokemonMart_Ch3_loop_2
	octave 2
	note Ds, 4
	rest 2
	note Ds, 4
	rest 2
	octave 1
	note As, 8
	rest 2
	octave 2
	note Ds, 2
	rest 4
	note Ds, 2
	rest 4
	note Ds, 2
	note G_, 4
	note Ds, 2
	note Cs, 4
	octave 1
	note As, 2
	octave 2
	note Gs, 4
	note B_, 2
	octave 3
	note Ds, 2
	rest 2
	octave 2
	note G_, 6
	note B_, 2
	octave 3
	note Ds, 2
	rest 4
	octave 2
	note Fs, 4
	note Gs, 2
	note Fs, 2
	rest 2
	note F_, 8
	note Ds, 2
	rest 2
	note Fs, 2
@;;;;;;;;;;;;;;;;;;
	octave 2
	note G_, 4
	rest 2
	note G_, 4
	rest 2
	note Ds, 4
	octave 1
	note As, 2
	octave 2
	note G_, 2
	rest 2
	note Ds, 2
	rest 4
	note As, 2
	rest 4
	note As, 2
	octave 3
	note Ds, 2
	rest 2
	octave 2
	note As, 2
	note G_, 2
	rest 2
	note Ds, 2
	note Gs, 4
	note B_, 2
	octave 3
	note Ds, 2
	rest 2
	octave 2
	note G_, 4
	rest 2
	note B_, 2
	octave 3
	note Ds, 6
	octave 2
	note Fs, 4
	note Gs, 2
	note Fs, 2
	rest 2
	note F_, 8
	note Ds, 2
	rest 2
	note F_, 2
Music_PokemonMart_Ch3_loop_3:
	octave 2
	note E_, 2
	rest 2
	octave 1
	note B_, 2
	sound_loop 4, Music_PokemonMart_Ch3_loop_3
Music_PokemonMart_Ch3_loop_4:
	octave 2
	note F_, 2
	rest 2
	octave 1
	note B_, 2
	sound_loop 4, Music_PokemonMart_Ch3_loop_4
	octave 2
Music_PokemonMart_Ch3_loop_5:
	note Fs, 2
	rest 2
	note Cs, 2
	sound_loop 4, Music_PokemonMart_Ch3_loop_5
	note Fs, 2
	rest 2
	note Fs, 2
	note E_, 2
	rest 2
	note Cs, 2
	octave 1
	note As, 2
	rest 2
	note Gs, 2
	note Fs, 2
	rest 2
	note As, 2
	sound_loop 0, Music_PokemonMart_Ch3_loop_main
	
Music_PokemonMart_Ch3_branch_1:
	octave 1
	note B_, 4
	rest 2
	octave 4
	note Ds, 4
	octave 3
	note B_, 2
	octave 1
	note B_, 4
	rest 2
	octave 4
	note Ds, 4
	rest 2
	octave 1
	note B_, 3
	rest 1
	note B_, 2
	octave 4
	note Ds, 4
	octave 3
	note B_, 2
	octave 1
	note B_, 4
	rest 2
	octave 4
	note Ds, 4
	rest 2
	sound_ret
	
gbs_Music_PokemonMart_Ch4:
	gbs_switch 3
Music_PokemonMart_Ch4:
	toggle_noise 3
	drum_speed 4
	drum_note 9, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 1, 4
	drum_note 9, 2
	drum_note 9, 4
	drum_note 9, 2
	drum_note 1, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 1, 4
	drum_note 9, 2
	drum_note 9, 4
	drum_note 1, 2
	drum_note 1, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 1, 4
	drum_note 9, 2
	drum_note 9, 4
	drum_note 9, 2
	drum_note 1, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 1, 4
	drum_note 1, 2
	drum_note 9, 4
	drum_note 1, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 1, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 1, 2
Music_PokemonMart_Ch4_loop_main:
	sound_call Music_PokemonMart_Ch4_branch_1
Music_PokemonMart_Ch4_loop_1:
	sound_call Music_PokemonMart_Ch4_branch_2
	sound_loop 5, Music_PokemonMart_Ch4_loop_1
	sound_call Music_PokemonMart_Ch4_branch_3
	sound_call Music_PokemonMart_Ch4_branch_1
Music_PokemonMart_Ch4_loop_2:
	sound_call Music_PokemonMart_Ch4_branch_2
	sound_loop 5, Music_PokemonMart_Ch4_loop_2
	sound_call Music_PokemonMart_Ch4_branch_3
	sound_call Music_PokemonMart_Ch4_branch_4
	sound_call Music_PokemonMart_Ch4_branch_5
	sound_call Music_PokemonMart_Ch4_branch_6
	drum_note 9, 4
	drum_note 9, 2
	drum_note 9, 4
	drum_note 9, 2
	drum_note 9, 4
	drum_note 9, 2
	sound_call Music_PokemonMart_Ch4_branch_4
	drum_note 9, 2
	drum_note 9, 2
	drum_note 9, 2
	sound_call Music_PokemonMart_Ch4_branch_5
	sound_call Music_PokemonMart_Ch4_branch_6
	drum_note 9, 4
	drum_note 9, 2
	drum_note 9, 4
	drum_note 9, 2
	sound_call Music_PokemonMart_Ch4_branch_5
	sound_call Music_PokemonMart_Ch4_branch_5
	sound_call Music_PokemonMart_Ch4_branch_5
	drum_note 9, 4
	drum_note 9, 2
	drum_note 1, 4
	drum_note 9, 2
	drum_note 9, 4
	drum_note 1, 2
	drum_note 9, 4
	drum_note 1, 2
	sound_loop 0, Music_PokemonMart_Ch4_loop_main

Music_PokemonMart_Ch4_branch_1:
	drum_note 12, 6
	drum_note 1, 4
	drum_note 9, 2
	drum_note 9, 4
	drum_note 9, 2
	drum_note 1, 2
	drum_note 9, 2
	drum_note 9, 2
	sound_ret
	
Music_PokemonMart_Ch4_branch_2:
	drum_note 9, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 1, 4
	drum_note 9, 2
	drum_note 9, 4
	drum_note 9, 2
	drum_note 1, 2
	drum_note 9, 2
	drum_note 9, 2
	sound_ret
	
Music_PokemonMart_Ch4_branch_3:
	drum_note 9, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 12, 6
	drum_note 9, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 12, 6
	drum_note 9, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 12, 6
	drum_note 9, 4
	drum_note 9, 2
	drum_note 1, 4
	drum_note 9, 2
	sound_ret
	
Music_PokemonMart_Ch4_branch_4:
	drum_note 1, 4
	drum_note 9, 2
	drum_note 1, 4
	drum_note 9, 2
	drum_note 4, 4
	drum_note 4, 2
	drum_note 2, 6
	drum_note 7, 2
	drum_note 7, 2
	drum_note 7, 2
	drum_note 7, 4
	drum_note 7, 2
	drum_note 12, 6
	drum_note 7, 4
	drum_note 7, 2
	sound_ret
	
Music_PokemonMart_Ch4_branch_5:
	drum_note 9, 4
	drum_note 9, 2
	drum_note 9, 4
	drum_note 9, 2
	drum_note 9, 4
	drum_note 9, 2
	drum_note 9, 4
	drum_note 9, 2
	sound_ret
	
Music_PokemonMart_Ch4_branch_6:
	drum_note 9, 1
	drum_note 9, 1
	drum_note 9, 1
	drum_note 9, 1
	drum_note 9, 1
	drum_note 9, 1
	sound_ret
