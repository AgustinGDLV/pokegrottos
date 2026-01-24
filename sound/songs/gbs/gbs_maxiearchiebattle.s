	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_MaxieArchieBattle
	.align 2

gbs_Music_MaxieArchieBattle:
	channel_count 4
	channel 1, Music_MaxieArchieBattle_Ch1
	channel 2, Music_MaxieArchieBattle_Ch2
	channel 3, Music_MaxieArchieBattle_Ch3
	channel 4, Music_MaxieArchieBattle_Ch4

gbs_Music_MaxieArchieBattle_Ch1:
	gbs_switch 0
Music_MaxieArchieBattle_Ch1:
	tempo 205
	duty_cycle 3
	pitch_offset 1
	note_type 12, 10, 4
	vibrato 5, 2, 6
	octave 3
	rest 16
	rest 11
	note_type 6, 11, 0
	rest 1
	note D_, 1
	note_type 12, 11, 0
	note Ds, 6
	volume_envelope 11, 5
	note Ds, 2
	note_type 6, 11, 0
	rest 1
	note D_, 1
	note_type 12, 11, 0
	note Ds, 1
	note Cs, 1
	note Ds, 1
	note Fs, 1
	note E_, 1
	note Ds, 1
	note Cs, 1
	note Ds, 6
	volume_envelope 11, 5
	note Ds, 3
	volume_envelope 11, 0
	note Ds, 1
	note Cs, 1
	note Ds, 1
	note Fs, 1
	note E_, 1
	note Gs, 1
	note E_, 1
	note Ds, 6
	volume_envelope 11, 5
	note Ds, 3
	volume_envelope 11, 0
	note Ds, 1
	note Cs, 1
	note Ds, 1
	note Fs, 1
	note E_, 1
	note Ds, 1
	note Cs, 1
	volume_envelope 11, 0
	note Ds, 8
	volume_envelope 11, 7
	note Ds, 7
@;;;mark
	note_type 6, 13, 0
	rest 1
	note E_, 1
	note_type 12, 13, 0
	note F_, 6
	volume_envelope 13, 5
	note F_, 2
	note_type 6, 13, 0
	rest 1
	note E_, 1
	note_type 12, 13, 0
	note F_, 1
	note Ds, 1
	note F_, 1
	note Gs, 1
	note Fs, 1
	note F_, 1
	note Ds, 1
	note F_, 6
	volume_envelope 13, 5
	note F_, 3
	volume_envelope 13, 0
	note F_, 1
	note Ds, 1
	note F_, 1
	note Gs, 1
	note Fs, 1
	note As, 1
	note Fs, 1
	note F_, 6
	volume_envelope 13, 5
	note F_, 3
	volume_envelope 13, 0
	note F_, 1
	note Ds, 1
	note F_, 1
	note Gs, 1
	note Fs, 1
	note F_, 1
	note Ds, 1
	volume_envelope 13, 0
	note F_, 8
	volume_envelope 13, 7
	note F_, 4
	volume_envelope 14, 0
	note Fs, 4
Music_MaxieArchieBattle_Ch1_loop:
	@;;;mark
	volume_envelope 15, 0
	note G_, 6
	note_type 6, 15, 7
	note G_, 5
	note E_, 1
	note_type 12, 15, 0
	note G_, 1
	note F_, 1
	note G_, 1
	note As, 1
	note Gs, 1
	note G_, 1
	note F_, 1
	note G_, 6
	volume_envelope 15, 5
	note G_, 3
	volume_envelope 15, 0
	note G_, 1
	note F_, 1
	note G_, 1
	note As, 1
	note Gs, 1
	octave 4
	note C_, 1
	octave 3
	note Gs, 1
	note G_, 6
	volume_envelope 15, 5
	note G_, 3
	volume_envelope 15, 0
	note G_, 1
	note F_, 1
	note G_, 1
	note As, 1
	note Gs, 1
	note G_, 1
	note F_, 1
	volume_envelope 15, 0
	note G_, 6
	octave 4
	note D_, 6
	note C_, 4
@;;;mark
	octave 3
	volume_envelope 12, 7
	note B_, 3
	note As, 3
	note Fs, 2
	note A_, 3
	note G_, 3
	note E_, 2
	note Fs, 3
	note G_, 3
	note Fs, 2
	volume_envelope 12, 0
	note Ds, 8
	volume_envelope 12, 7
	note Ds, 8
	volume_envelope 10, 0
	octave 2
	note Ds, 8
	volume_envelope 10, 7
	note Ds, 8
@;;;mark
	rest 16
	rest 1
	volume_envelope 10, 2
	duty_cycle 0
	octave 3
	note C_, 1
	octave 2
	note As, 1
	octave 3
	note C_, 1
	note Ds, 1
	note Cs, 1
	note C_, 1
	octave 2
	note As, 1
	octave 3
	volume_envelope 12, 7
	note C_, 8
	duty_cycle 1
	octave 2
	note F_, 3
	note Fs, 3
	note B_, 2
	note As, 3
	note Fs, 3
	note E_, 2
	note F_, 3
	note Fs, 3
	note B_, 2
	note As, 3
	note B_, 3
	octave 3
	note Cs, 2
@;;;;mark
	note C_, 1
	note C_, 1
	note Cs, 2
	note C_, 1
	note C_, 1
	note Ds, 2
	note C_, 1
	note C_, 1
	note E_, 2
	note F_, 1
	note E_, 1
	note Cs, 1
	note C_, 1
	note C_, 1
	note C_, 1
	note Cs, 2
	note C_, 1
	note C_, 1
	note Ds, 2
	note C_, 1
	note C_, 1
	note E_, 2
	note F_, 2
	note E_, 2
@;;;mark
	octave 4
	duty_cycle 0
	note C_, 1
	note C_, 1
	note Cs, 2
	note C_, 1
	note C_, 1
	note Ds, 2
	note C_, 1
	note C_, 1
	note E_, 2
	note F_, 1
	note E_, 1
	note Cs, 1
	note C_, 1
	note C_, 1
	note C_, 1
	note Cs, 2
	note C_, 1
	note C_, 1
	note Ds, 2
	note C_, 1
	note C_, 1
	note E_, 2
	note F_, 2
	note E_, 2
	volume_envelope 12, 0
	note F_, 16
	note F_, 8
	volume_envelope 12, 7
	note F_, 8
	octave 5
	volume_envelope 12, 0
	note F_, 16
	note F_, 8
	volume_envelope 12, 7
	note F_, 7
	octave 3
	note_type 6, 13, 0
	rest 1
	note E_, 1
	note_type 12, 13, 0
	note F_, 6
	volume_envelope 13, 5
	note F_, 2
	note_type 6, 13, 0
	rest 1
	note E_, 1
	note_type 12, 13, 0
	note F_, 1
	note Ds, 1
	note F_, 1
	note Gs, 1
	note Fs, 1
	note F_, 1
	note Ds, 1
	note F_, 6
	volume_envelope 13, 5
	note F_, 3
	volume_envelope 13, 0
	note F_, 1
	note Ds, 1
	note F_, 1
	note Gs, 1
	note Fs, 1
	note As, 1
	note Fs, 1
	note F_, 6
	volume_envelope 13, 5
	note F_, 3
	volume_envelope 13, 0
	note F_, 1
	note Ds, 1
	note F_, 1
	note Gs, 1
	note Fs, 1
	note F_, 1
	note Ds, 1
	volume_envelope 13, 0
	note F_, 6
	volume_envelope 15, 7
	octave 4
	note C_, 4
	volume_envelope 14, 0
	octave 3
	note F_, 2
	note Fs, 4
	sound_loop 0, Music_MaxieArchieBattle_Ch1_loop

gbs_Music_MaxieArchieBattle_Ch2:
	gbs_switch 1
Music_MaxieArchieBattle_Ch2:
	pitch_offset 1
	duty_cycle 1
	note_type 12, 10, 7
	vibrato 18, 1, 5
	octave 2
	rest 16
	rest 16
	rest 16
	rest 16
	rest 16
	rest 8
	note E_, 4
Music_MaxieArchieBattle_Ch2_loop_main:
	duty_cycle 1
	volume_envelope 11, 7
	octave 2
	note F_, 1
	rest 2
	note C_, 3
	note Ds, 1
	rest 1
	note F_, 1
	rest 2
	note C_, 3
	note E_, 1
	rest 1
	note F_, 1
	rest 2
	note As, 2
	note Gs, 1
	note Fs, 1
	note E_, 1
	note F_, 1
	rest 2
	note C_, 3
	note Fs, 1
	rest 1
	note F_, 1
	rest 2
	note C_, 3
	note E_, 1
	rest 1
	note F_, 1
	rest 2
	note C_, 3
	note E_, 1
	rest 1
	note F_, 1
	rest 2
	note As, 2
	note Gs, 1
	note Fs, 1
	note E_, 1
	note F_, 1
	rest 2
	note C_, 1
	note Fs, 4
@;;;mark
	note G_, 1
	rest 2
	note D_, 3
	note Fs, 1
	rest 1
	note G_, 1
	rest 2
	note D_, 3
	note Fs, 1
	rest 1
	note G_, 1
	rest 2
	octave 3
	note C_, 2
	octave 2
	note As, 1
	note Gs, 1
	note Fs, 1
	note G_, 1
	rest 2
	note D_, 3
	note Gs, 1
	rest 1
	note G_, 1
	rest 2
	note D_, 3
	note Fs, 1
	rest 1
	note G_, 1
	rest 2
	note D_, 3
	note Fs, 1
	rest 1
	note G_, 1
	rest 2
	octave 3
	note C_, 2
	octave 2
	note As, 1
	note Gs, 1
	note Fs, 1
	note G_, 1
	rest 2
	note D_, 1
	octave 3
	note Ds, 4
@;;;mark
	duty_cycle 1
	volume_envelope 12, 7
	note E_, 3
	note Ds, 3
	octave 2
	note B_, 2
	octave 3
	note D_, 3
	note C_, 3
	octave 2
	note A_, 2
	note B_, 3
	octave 3
	note C_, 3
	octave 2
	note B_, 2
	volume_envelope 12, 0
	note Gs, 8
	volume_envelope 12, 7
	note Gs, 8
	volume_envelope 10, 0
	octave 1
	note Gs, 8
	volume_envelope 10, 7
	note Gs, 8
@;;;;mark
	octave 2
	note C_, 3
	note Cs, 3
	note Fs, 2
	note F_, 3
	note Cs, 3
	octave 1
	note B_, 2
	octave 2
	note C_, 3
	note Cs, 3
	note Fs, 2
	note F_, 3
	note Fs, 3
	note Ds, 2
	duty_cycle 2
	note C_, 3
	note Cs, 3
	note Fs, 2
	note F_, 3
	note Cs, 3
	octave 1
	note B_, 2
	octave 2
	note C_, 3
	note Cs, 3
	note Fs, 2
	note F_, 3
	note Fs, 3
	note Gs, 2
@;;;;mark
	note G_, 1
	note G_, 1
	note Gs, 2
	note G_, 1
	note G_, 1
	note As, 2
	note G_, 1
	note G_, 1
	octave 3
	note C_, 2
	note Cs, 1
	note C_, 1
	octave 2
	note As, 1
	note Gs, 1
	note G_, 1
	note G_, 1
	note Gs, 2
	note G_, 1
	note G_, 1
	note As, 2
	note G_, 1
	note G_, 1
	octave 3
	note C_, 2
	note Cs, 2
	note C_, 2
@;;;mark
	octave 3
	duty_cycle 0
	note G_, 1
	note G_, 1
	note Gs, 2
	note G_, 1
	note G_, 1
	note As, 2
	note G_, 1
	note G_, 1
	octave 4
	note C_, 2
	note Cs, 1
	note C_, 1
	octave 3
	note As, 1
	note Gs, 1
	note G_, 1
	note G_, 1
	note Gs, 2
	note G_, 1
	note G_, 1
	note As, 2
	note G_, 1
	note G_, 1
	octave 4
	note C_, 2
	note Cs, 2
	note_type 6, 10, 7
	note C_, 3
	rest 1
	note_type 12, 10, 0
@;;;;mark
	duty_cycle 1
	note C_, 4
	volume_envelope 10, 7
	note C_, 4
	volume_envelope 10, 0
	octave 3
	note Fs, 4
	volume_envelope 10, 7
	note Fs, 4
	volume_envelope 10, 0
	note F_, 4
	volume_envelope 10, 7
	note F_, 4
	volume_envelope 10, 0
	note C_, 4
	volume_envelope 10, 7
	note C_, 4
	volume_envelope 10, 0
	note C_, 4
	volume_envelope 10, 7
	note C_, 4
	volume_envelope 10, 0
	octave 2
	note Fs, 4
	volume_envelope 10, 7
	note Fs, 4
	volume_envelope 10, 0
	note F_, 4
	volume_envelope 10, 7
	note F_, 4
	volume_envelope 10, 0
	note Fs, 4
	volume_envelope 10, 7
	note Fs, 4
	sound_loop 0, Music_MaxieArchieBattle_Ch2_loop_main
	
Music_MaxieArchieBattle_Ch2_branch_1:
	octave 2
	volume_envelope 10, 2
	note B_, 1
	octave 3
	note Ds, 1
	note E_, 1
	note Fs, 1
	note G_, 1
	note A_, 1
	note As, 1
	note B_, 1
	octave 4
	note C_, 1
	octave 3
	note B_, 1
	note As, 1
	note A_, 1
	note G_, 1
	note Fs, 1
	note E_, 1
	note Ds, 1
	note Cs, 1
	note F_, 1
	note Fs, 1
	note Gs, 1
	note A_, 1
	note B_, 1
	octave 4
	note C_, 1
	note Cs, 1
	note D_, 1
	note Cs, 1
	note C_, 1
	octave 3
	note B_, 1
	note A_, 1
	note Gs, 1
	note Fs, 1
	note F_, 1
	note Ds, 1
	note G_, 1
	note Gs, 1
	note As, 1
	note B_, 1
	octave 4
	note Cs, 1
	note D_, 1
	note Ds, 1
	note E_, 1
	note Ds, 1
	note D_, 1
	note Cs, 1
	octave 3
	note B_, 1
	note As, 1
	note Gs, 1
	note G_, 1
	note F_, 1
	note A_, 1
	note As, 1
	octave 4
	note C_, 1
	note Cs, 1
	note Ds, 1
	note E_, 1
	note F_, 1
	note Fs, 1
	note F_, 1
	note E_, 1
	note Ds, 1
	note Cs, 1
	note C_, 1
	octave 3
	note As, 1
	note A_, 1
	sound_ret
	
Music_MaxieArchieBattle_Ch2_branch_2:
	duty_cycle 1
	octave 3
	note G_, 2
	note C_, 2
	note G_, 2
	octave 4
	note C_, 2
	note E_, 2
	note C_, 2
	octave 3
	note G_, 2
	octave 4
	note C_, 2
	sound_ret
	
Music_MaxieArchieBattle_Ch2_branch_3:
	duty_cycle 0
	octave 3
	note Gs, 2
	note Cs, 2
	note Gs, 2
	octave 4
	note Cs, 2
	note Gs, 2
	note Cs, 2
	octave 3
	note Gs, 2
	octave 4
	note Cs, 2
	sound_ret

gbs_Music_MaxieArchieBattle_Ch3:
	gbs_switch 2
Music_MaxieArchieBattle_Ch3:
	stereo_panning TRUE, TRUE
	note_type 12, 2, 5
	octave 2
	note Ds, 2
	note Fs, 2
	note E_, 2
	note Ds, 2
	note Cs, 2
	note E_, 2
	note Ds, 2
	note Cs, 2
	note Ds, 2
	note Fs, 2
	note E_, 2
	note Ds, 2
	note Cs, 2
	octave 1
	note B_, 2
Music_MaxieArchieBattle_Ch3_loop_1:
	sound_call Music_MaxieArchieBattle_Ch3_branch_1
	sound_loop 3, Music_MaxieArchieBattle_Ch3_loop_1
	sound_call Music_MaxieArchieBattle_Ch3_branch_2
	sound_call Music_MaxieArchieBattle_Ch3_branch_1
	note Ds, 1
	note Fs, 1
	note As, 1
	note B_, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_1
	note Ds, 1
	note B_, 1
	note As, 1
	note Gs, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_1
	note Ds, 1
	note As, 1
	note Ds, 1
	note B_, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_1
	sound_call Music_MaxieArchieBattle_Ch3_branch_2
	sound_call Music_MaxieArchieBattle_Ch3_branch_1
	note Ds, 1
	note Fs, 1
	note As, 1
	note B_, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_1
	note Ds, 1
	note As, 1
	note A_, 1
	note As, 1
Music_MaxieArchieBattle_Ch3_loop_main:
	sound_call Music_MaxieArchieBattle_Ch3_branch_3
	sound_call Music_MaxieArchieBattle_Ch3_branch_3
	sound_call Music_MaxieArchieBattle_Ch3_branch_3
	sound_call Music_MaxieArchieBattle_Ch3_branch_4
	sound_call Music_MaxieArchieBattle_Ch3_branch_3
	sound_call Music_MaxieArchieBattle_Ch3_branch_5
	sound_call Music_MaxieArchieBattle_Ch3_branch_3
	octave 2
	note F_, 1
	octave 3
	note Cs, 1
	note C_, 1
	octave 2
	note As, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_3
	octave 2
	note F_, 1
	octave 3
	note C_, 1
	octave 2
	note F_, 1
	octave 3
	note Cs, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_3
	sound_call Music_MaxieArchieBattle_Ch3_branch_4
	sound_call Music_MaxieArchieBattle_Ch3_branch_3
	sound_call Music_MaxieArchieBattle_Ch3_branch_5
	sound_call Music_MaxieArchieBattle_Ch3_branch_3
	octave 2
	note F_, 1
	note Fs, 1
	note G_, 1
	note A_, 1
@;;;mark
	sound_call Music_MaxieArchieBattle_Ch3_branch_7
	sound_call Music_MaxieArchieBattle_Ch3_branch_7
	sound_call Music_MaxieArchieBattle_Ch3_branch_7
	octave 2
	note As, 1
	octave 3
	note C_, 1
	note D_, 1
	note Ds, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_7
	sound_call Music_MaxieArchieBattle_Ch3_branch_6
	sound_call Music_MaxieArchieBattle_Ch3_branch_7
	octave 2
	note G_, 1
	octave 3
	note Ds, 1
	note D_, 1
	note C_, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_7
	octave 2
	note G_, 1
	octave 3
	note D_, 1
	octave 2
	note G_, 1
	octave 3
	note Ds, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_7
	octave 2
	note As, 1
	octave 3
	note C_, 1
	note D_, 1
	note Ds, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_7
	sound_call Music_MaxieArchieBattle_Ch3_branch_6
	sound_call Music_MaxieArchieBattle_Ch3_branch_7
	octave 2
	note G_, 1
	note Gs, 1
	note A_, 1
	note B_, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_7
	sound_call Music_MaxieArchieBattle_Ch3_branch_7
	sound_call Music_MaxieArchieBattle_Ch3_branch_7
	sound_call Music_MaxieArchieBattle_Ch3_branch_7
	sound_call Music_MaxieArchieBattle_Ch3_branch_7
	octave 2
	note G_, 1
	octave 3
	note D_, 1
	note Ds, 1
	note Ds, 1
Music_MaxieArchieBattle_Ch3_loop_2:
	sound_call Music_MaxieArchieBattle_Ch3_branch_8
	sound_loop 8, Music_MaxieArchieBattle_Ch3_loop_2
Music_MaxieArchieBattle_Ch3_loop_3:
	sound_call Music_MaxieArchieBattle_Ch3_branch_3
	sound_call Music_MaxieArchieBattle_Ch3_branch_3
	sound_call Music_MaxieArchieBattle_Ch3_branch_3
	octave 2
	note F_, 1
	octave 3
	note C_, 1
	octave 2
	note B_, 1
	octave 3
	note C_, 1
	sound_loop 3, Music_MaxieArchieBattle_Ch3_loop_3
	sound_call Music_MaxieArchieBattle_Ch3_branch_3
	sound_call Music_MaxieArchieBattle_Ch3_branch_3
	octave 2
	note F_, 1
	octave 3
	note C_, 1
	note F_, 1
	note Fs, 1
	note F_, 1
	note Ds, 1
	note Cs, 1
	note Ds, 1
Music_MaxieArchieBattle_Ch3_loop_4:
	sound_call Music_MaxieArchieBattle_Ch3_branch_9
	octave 2
	note G_, 1
	octave 3
	note C_, 1
	octave 2
	note G_, 1
	octave 3
	note Ds, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_9
	octave 2
	note G_, 1
	octave 3
	note C_, 1
	note Cs, 1
	note C_, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_9
	octave 2
	note G_, 1
	octave 3
	note C_, 1
	octave 2
	note G_, 1
	octave 3
	note Ds, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_9
	octave 2
	note G_, 1
	octave 3
	note C_, 1
	note Cs, 1
	note C_, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_9
	octave 2
	note G_, 1
	octave 3
	note C_, 1
	octave 2
	note As, 1
	note As, 1
	octave 3
	note C_, 1
	note C_, 1
	octave 2
	note G_, 1
	octave 3
	note C_, 1
	note Cs, 1
	note C_, 1
	note Cs, 1
	note C_, 1
	sound_call Music_MaxieArchieBattle_Ch3_branch_9
	octave 2
	note G_, 1
	octave 3
	note C_, 1
	octave 2
	note As, 1
	octave 3
	note Ds, 1
	note C_, 1
	note C_, 1
	octave 2
	note G_, 1
	octave 3
	note C_, 1
	octave 2
	note G_, 1
	octave 3
	note Cs, 1
	note Ds, 1
	note E_, 1
Music_MaxieArchieBattle_Ch3_loop_5:
	sound_call Music_MaxieArchieBattle_Ch3_branch_3
	sound_loop 16, Music_MaxieArchieBattle_Ch3_loop_5
	sound_loop 0, Music_MaxieArchieBattle_Ch3_loop_main
	
Music_MaxieArchieBattle_Ch3_branch_1:
	octave 2
	note Ds, 1
	note As, 1
	note Ds, 1
	note As, 1
	sound_ret
	
Music_MaxieArchieBattle_Ch3_branch_2:
	octave 2
	note Fs, 1
	note Gs, 1
	note As, 1
	note B_, 1
	sound_ret
	
Music_MaxieArchieBattle_Ch3_branch_3:
	octave 2
	note F_, 1
	octave 3
	note C_, 1
	octave 2
	note F_, 1
	octave 3
	note C_, 1
	sound_ret
	
Music_MaxieArchieBattle_Ch3_branch_4:
	octave 2
	note Gs, 1
	note As, 1
	octave 3
	note C_, 1
	note Cs, 1
	sound_ret
	
Music_MaxieArchieBattle_Ch3_branch_5:
	octave 2
	note F_, 1
	note Gs, 1
	octave 3
	note C_, 1
	note Cs, 1
	sound_ret
	
Music_MaxieArchieBattle_Ch3_branch_6:
	octave 2
	note G_, 1
	note As, 1
	octave 3
	note D_, 1
	note Ds, 1
	sound_ret
	
Music_MaxieArchieBattle_Ch3_branch_7:
	octave 2
	note G_, 1
	octave 3
	note D_, 1
	octave 2
	note G_, 1
	octave 3
	note D_, 1
	sound_ret
	
Music_MaxieArchieBattle_Ch3_branch_8:
	octave 2
	note Gs, 1
	octave 3
	note Ds, 1
	octave 2
	note Gs, 1
	octave 3
	note Ds, 1
	sound_ret
	
Music_MaxieArchieBattle_Ch3_branch_9:
	octave 2
	note G_, 1
	octave 3
	note C_, 1
	octave 2
	note G_, 1
	octave 3
	note C_, 1
	sound_ret

gbs_Music_MaxieArchieBattle_Ch4:
	gbs_switch 3
Music_MaxieArchieBattle_Ch4:
	toggle_noise 3
	drum_speed 12
	drum_note 4, 8
	drum_note 4, 4
	drum_note 4, 10
	drum_note 1, 2
	drum_note 1, 2
	drum_note 1, 2
	sound_call Music_MaxieArchieBattle_Ch4_branch_2
	sound_call Music_MaxieArchieBattle_Ch4_branch_3
	sound_call Music_MaxieArchieBattle_Ch4_branch_2
	sound_call Music_MaxieArchieBattle_Ch4_branch_3
	sound_call Music_MaxieArchieBattle_Ch4_branch_2
	sound_call Music_MaxieArchieBattle_Ch4_branch_2
	sound_call Music_MaxieArchieBattle_Ch4_branch_2
	sound_call Music_MaxieArchieBattle_Ch4_branch_4
@;;;;mark
Music_MaxieArchieBattle_Ch4_loop_main:
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_3
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
@;;;;mark
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_3
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_3
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
@;;;;mark
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	rest 2
	drum_note 9, 2
	rest 2
	drum_note 9, 2
	rest 2
	drum_note 9, 2
	rest 2
	drum_note 9, 2
	rest 2
	drum_note 9, 2
	rest 2
	drum_note 9, 2
	rest 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 3, 1
	drum_note 3, 1
@;;;;mark
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	drum_note 1, 1
	drum_note 4, 2
	drum_note 1, 2
	drum_note 1, 2
	drum_note 4, 1
	sound_call Music_MaxieArchieBattle_Ch4_branch_1
	sound_call Music_MaxieArchieBattle_Ch4_branch_1
	sound_call Music_MaxieArchieBattle_Ch4_branch_1
	sound_call Music_MaxieArchieBattle_Ch4_branch_1
	sound_call Music_MaxieArchieBattle_Ch4_branch_1
	sound_call Music_MaxieArchieBattle_Ch4_branch_1
	sound_call Music_MaxieArchieBattle_Ch4_branch_1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 1, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 1, 1
	drum_note 4, 1
	drum_note 1, 1
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	sound_call Music_MaxieArchieBattle_Ch4_branch_5
	drum_note 1, 2
	drum_note 4, 1
	drum_note 1, 2
	drum_note 4, 2
	drum_note 4, 1
	sound_loop 0, Music_MaxieArchieBattle_Ch4_loop_main
	
Music_MaxieArchieBattle_Ch4_branch_1:
	drum_note 4, 1
	drum_note 4, 1
	drum_note 1, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 1, 1
	drum_note 4, 1
	sound_ret
	
Music_MaxieArchieBattle_Ch4_branch_2:
	drum_note 1, 3
	drum_note 1, 3
	drum_note 4, 2
	sound_ret
	
Music_MaxieArchieBattle_Ch4_branch_3:
	drum_note 1, 3
	drum_note 1, 3
	drum_note 4, 1
	drum_speed 6
	drum_note 3, 1
	drum_note 3, 1
	drum_speed 12
	sound_ret

Music_MaxieArchieBattle_Ch4_branch_4:
	drum_note 1, 3
	drum_note 1, 3
	rest 1
	drum_speed 6
	drum_note 3, 1
	drum_note 3, 1
	drum_speed 12
	sound_ret
	
Music_MaxieArchieBattle_Ch4_branch_5:
	drum_note 1, 2
	drum_note 4, 1
	drum_note 1, 3
	drum_note 4, 2
	sound_ret
