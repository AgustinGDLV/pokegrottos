	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_Route113
	.align 2

gbs_Music_Route113:
	channel_count 4
	channel 1, Music_Route113_Ch1
	channel 2, Music_Route113_Ch2
	channel 3, Music_Route113_Ch3
	channel 4, Music_Route113_Ch4

gbs_Music_Route113_Ch1:
	gbs_switch 0
Music_Route113_Ch1:
	tempo 144
	duty_cycle 0
	vibrato 18, 1, 5
	pitch_offset 1
	note_type 12, 6, 4
	rest 2
Music_Route113_Ch1_loop_main:
Music_Route113_Ch1_loop_1:
	sound_call Music_Route113_Ch1_branch_1
	sound_call Music_Route113_Ch1_branch_1
	sound_call Music_Route113_Ch1_branch_2
	sound_call Music_Route113_Ch1_branch_2
	sound_loop 2, Music_Route113_Ch1_loop_1
	sound_call Music_Route113_Ch1_branch_3
	octave 4
	volume_envelope 6, 4
	note Cs, 2
	volume_envelope 9, 1
	note Cs, 1
	volume_envelope 6, 1
	note Cs, 1
	volume_envelope 9, 1
	note Cs, 1
	volume_envelope 6, 1
	note Cs, 1
	volume_envelope 6, 4
	note D_, 2
	volume_envelope 9, 1
	note D_, 1
	volume_envelope 6, 1
	note D_, 1
	volume_envelope 6, 4
	note D_, 2
	note Fs, 2
	volume_envelope 9, 1
	note Fs, 1
	volume_envelope 6, 1
	note Fs, 1
	volume_envelope 6, 4
	note Fs, 2
	note Fs, 2
	volume_envelope 9, 1
	note Fs, 1
	volume_envelope 6, 1
	note Fs, 1
	volume_envelope 6, 4
	note Fs, 2
	note G_, 2
	volume_envelope 9, 1
	note G_, 1
	volume_envelope 6, 1
	note G_, 1
	volume_envelope 9, 1
	note G_, 1
	volume_envelope 6, 1
	note G_, 1
	volume_envelope 6, 4
	note G_, 2
	volume_envelope 9, 1
	note G_, 1
	volume_envelope 6, 1
	note G_, 1
	volume_envelope 6, 4
	note G_, 2
	note E_, 2
	volume_envelope 9, 1
	note E_, 1
	volume_envelope 6, 1
	note E_, 1
	volume_envelope 6, 4
	note E_, 2
	note E_, 2
	volume_envelope 9, 1
	note E_, 1
	volume_envelope 6, 1
	note E_, 1
	volume_envelope 6, 4
	note E_, 2
	note Cs, 2
	volume_envelope 9, 1
	note Cs, 1
	volume_envelope 6, 1
	note Cs, 1
	volume_envelope 9, 1
	note Cs, 1
	volume_envelope 6, 1
	note Cs, 1
	volume_envelope 6, 4
	note Fs, 2
	volume_envelope 9, 1
	note Fs, 1
	volume_envelope 6, 1
	note Fs, 1
	volume_envelope 6, 4
	note Fs, 2
	sound_call Music_Route113_Ch1_branch_3
	volume_envelope 6, 4
	octave 5
	note Cs, 2
	volume_envelope 9, 1
	note Cs, 1
	volume_envelope 6, 1
	note Cs, 1
	volume_envelope 9, 1
	note Cs, 1
	volume_envelope 6, 1
	note Cs, 1
	volume_envelope 6, 4
	octave 4
	note B_, 2
	volume_envelope 9, 1
	note B_, 1
	volume_envelope 6, 1
	note B_, 1
	volume_envelope 6, 4
	note B_, 2
	note Fs, 2
	volume_envelope 9, 1
	note Fs, 1
	volume_envelope 6, 1
	note Fs, 1
	volume_envelope 6, 4
	note Fs, 2
	note Fs, 2
	volume_envelope 9, 1
	note Fs, 1
	volume_envelope 6, 1
	note Fs, 1
	volume_envelope 6, 4
	note Fs, 2
	note D_, 2
	volume_envelope 9, 1
	note D_, 1
	volume_envelope 6, 1
	note D_, 1
	volume_envelope 9, 1
	note D_, 1
	volume_envelope 6, 1
	note D_, 1
	volume_envelope 6, 4
	note D_, 2
	volume_envelope 9, 1
	note D_, 1
	volume_envelope 6, 1
	note D_, 1
	volume_envelope 6, 4
	note D_, 2
	note Cs, 2
	volume_envelope 9, 1
	note Cs, 1
	volume_envelope 6, 1
	note Cs, 1
	volume_envelope 6, 4
	note Cs, 2
	note Cs, 2
	volume_envelope 9, 1
	note Cs, 1
	volume_envelope 6, 1
	note Cs, 1
	volume_envelope 6, 4
	note Cs, 2
	note E_, 2
	volume_envelope 9, 1
	note E_, 1
	volume_envelope 6, 1
	note E_, 1
	volume_envelope 9, 1
	note E_, 1
	volume_envelope 6, 1
	note E_, 1
	volume_envelope 6, 4
	note G_, 2
	volume_envelope 9, 1
	note G_, 1
	volume_envelope 6, 1
	note G_, 1
	volume_envelope 6, 4
	note G_, 2
Music_Route113_Ch1_loop_2:
	sound_call Music_Route113_Ch1_branch_1
	sound_call Music_Route113_Ch1_branch_1
	sound_call Music_Route113_Ch1_branch_2
	sound_call Music_Route113_Ch1_branch_2
	sound_loop 2, Music_Route113_Ch1_loop_2
	sound_loop 0, Music_Route113_Ch1_loop_main
	
Music_Route113_Ch1_branch_1:
	volume_envelope 6, 4
	octave 3
	note B_, 2
	volume_envelope 9, 1
	note B_, 1
	volume_envelope 6, 1
	note B_, 1
	volume_envelope 6, 4
	note B_, 2
	note B_, 2
	volume_envelope 9, 1
	note B_, 1
	volume_envelope 6, 1
	note B_, 1
	volume_envelope 6, 4
	note B_, 2
	note B_, 2
	volume_envelope 9, 1
	note B_, 1
	volume_envelope 6, 1
	note B_, 1
	volume_envelope 9, 1
	note B_, 1
	volume_envelope 6, 1
	note B_, 1
	volume_envelope 6, 4
	note B_, 2
	volume_envelope 9, 1
	note B_, 1
	volume_envelope 6, 1
	note B_, 1
	volume_envelope 6, 4
	note B_, 2
	sound_ret
	
Music_Route113_Ch1_branch_2:
	volume_envelope 6, 4
	note Fs, 2
	volume_envelope 9, 1
	note Fs, 1
	volume_envelope 6, 1
	note Fs, 1
	volume_envelope 6, 4
	note Fs, 2
	note Fs, 2
	volume_envelope 9, 1
	note Fs, 1
	volume_envelope 6, 1
	note Fs, 1
	volume_envelope 6, 4
	note Fs, 2
	note Fs, 2
	volume_envelope 9, 1
	note Fs, 1
	volume_envelope 6, 1
	note Fs, 1
	volume_envelope 9, 1
	note Fs, 1
	volume_envelope 6, 1
	note Fs, 1
	volume_envelope 6, 4
	note Fs, 2
	volume_envelope 9, 1
	note Fs, 1
	volume_envelope 6, 1
	note Fs, 1
	volume_envelope 6, 4
	note Fs, 2
	sound_ret
	
Music_Route113_Ch1_branch_3:
	volume_envelope 6, 4
	note A_, 2
	volume_envelope 9, 1
	note A_, 1
	volume_envelope 6, 1
	note A_, 1
	volume_envelope 6, 4
	note A_, 2
	note A_, 2
	volume_envelope 9, 1
	note A_, 1
	volume_envelope 6, 1
	note A_, 1
	volume_envelope 6, 4
	note A_, 2
	volume_envelope 6, 1
	note As, 2
	volume_envelope 9, 1
	note As, 1
	volume_envelope 6, 1
	note As, 1
	volume_envelope 9, 1
	note As, 1
	volume_envelope 6, 1
	note As, 1
	volume_envelope 6, 4
	note As, 2
	volume_envelope 9, 1
	note As, 1
	volume_envelope 6, 1
	note As, 1
	volume_envelope 6, 4
	note As, 2
	note B_, 2
	volume_envelope 9, 1
	note B_, 1
	volume_envelope 6, 1
	note B_, 1
	volume_envelope 6, 4
	note B_, 2
	note B_, 2
	volume_envelope 9, 1
	note B_, 1
	volume_envelope 6, 1
	note B_, 1
	volume_envelope 6, 4
	note B_, 2
	sound_ret
	
gbs_Music_Route113_Ch2:
	gbs_switch 1
Music_Route113_Ch2:
	vibrato 0, 2, 2
	pitch_offset 1
	note_type 12, 9, 7
	duty_cycle 1
	octave 3
	note Fs, 1
	note B_, 1
	octave 4
	note D_, 6
	note Cs, 4
	octave 3
	note A_, 2
	note B_, 4
	note D_, 2
	note G_, 6
	octave 4
	note D_, 2
	note Cs, 2
	octave 3
	note A_, 2
	note B_, 4
	note D_, 2
	volume_envelope 9, 0
	note G_, 2
	volume_envelope 9, 7
	note G_, 8
	note B_, 1
	octave 4
	note Cs, 1
	volume_envelope 9, 0
	octave 3
	note A_, 6
	volume_envelope 9, 7
	vibrato 0, 3, 2
	note A_, 16
	vibrato 0, 2, 2
	duty_cycle 0
	volume_envelope 11, 3
	note D_, 2
	volume_envelope 11, 0
	note A_, 10
	vibrato 0, 4, 3
	volume_envelope 11, 7
	note A_, 12
	vibrato 0, 2, 2
	duty_cycle 1
	volume_envelope 9, 7
	octave 4
	note E_, 1
	note Ds, 1
	note D_, 6
	note Cs, 4
	octave 3
	note A_, 2
	octave 4
	note G_, 4
	octave 3
	note D_, 2
	note G_, 4
	octave 4
	note G_, 1
	note Fs, 1
	note D_, 2
	note Cs, 2
	octave 3
	note A_, 2
	octave 4
	note Cs, 4
	octave 3
	note D_, 2
	octave 4
	note G_, 2
	note D_, 2
	octave 3
	note G_, 2
	note B_, 2
	note D_, 2
	note B_, 1
	octave 4
	note Cs, 1
	volume_envelope 9, 0
	octave 3
	note A_, 6
	volume_envelope 9, 7
	vibrato 0, 3, 2
	note A_, 16
	vibrato 0, 2, 2
	duty_cycle 0
	volume_envelope 11, 3
	note D_, 2
	volume_envelope 11, 0
	note A_, 8
	vibrato 0, 4, 3
	volume_envelope 11, 7
	note A_, 14
	vibrato 0, 2, 2
	duty_cycle 1
	volume_envelope 9, 7
	note A_, 1
	note As, 1
	note B_, 4
	volume_envelope 9, 2
	octave 4
	note Cs, 2
	volume_envelope 10, 7
	note D_, 4
	volume_envelope 10, 4
	octave 3
	note B_, 2
	volume_envelope 10, 7
	octave 4
	note Cs, 4
	volume_envelope 10, 2
	note D_, 2
	volume_envelope 10, 7
	note E_, 4
	volume_envelope 10, 4
	note Cs, 2
	note D_, 2
	note E_, 2
	volume_envelope 10, 2
	note Fs, 2
	note_type 6, 10, 7
	note G_, 1
	note Fs, 3
	note_type 12, 10, 2
	note F_, 2
	note Fs, 2
	volume_envelope 13, 4
	note B_, 2
	volume_envelope 10, 2
	note Fs, 2
	note E_, 2
	volume_envelope 10, 5
	note D_, 4
	note Cs, 2
	note D_, 4
	volume_envelope 10, 3
	octave 3
	note B_, 2
	volume_envelope 10, 6
	octave 4
	note Cs, 4
	volume_envelope 10, 2
	note D_, 2
	note_type 6, 11, 7
	note F_, 1
	note E_, 7
	note_type 12, 10, 7
	note Cs, 2
	note D_, 4
	note E_, 2
	volume_envelope 11, 3
	note Fs, 2
	note_type 6, 11, 4
	note G_, 1
	note Fs, 3
	note_type 12, 11, 4
	note F_, 2
	note Fs, 2
	note F_, 2
	note Fs, 2
	volume_envelope 13, 5
	note As, 2
	volume_envelope 11, 2
	note Fs, 2
	note E_, 2
	volume_envelope 11, 5
	note Fs, 2
	vibrato 0, 3, 4
	duty_cycle 0
	volume_envelope 12, 7
	note D_, 2
	note Cs, 1
	note C_, 1
	octave 3
	note B_, 4
	volume_envelope 12, 2
	octave 4
	note Cs, 2
	note_type 6, 12, 7
	note Ds, 1
	note D_, 7
	note_type 12, 12, 3
	octave 3
	note B_, 2
	volume_envelope 12, 5
	octave 4
	note Cs, 4
	volume_envelope 12, 2
	note D_, 2
	volume_envelope 12, 5
	note E_, 4
	volume_envelope 12, 3
	note Cs, 2
	note D_, 2
	note E_, 2
	note Fs, 2
	note_type 6, 12, 5
	note Fs, 1
	note Fs, 3
	note_type 12, 12, 3
	note F_, 2
	note Fs, 2
	note_type 6, 13, 7
	note A_, 1
	note Gs, 3
	note_type 12, 12, 2
	note Fs, 2
	volume_envelope 12, 5
	note E_, 2
	octave 3
	note B_, 3
	octave 4
	note Cs, 1
	note D_, 1
	note E_, 1
	volume_envelope 13, 5
	note G_, 4
	volume_envelope 12, 2
	note A_, 2
	volume_envelope 13, 4
	note G_, 4
	volume_envelope 13, 2
	note Fs, 2
	volume_envelope 13, 5
	note E_, 4
	volume_envelope 13, 2
	octave 3
	note B_, 2
	volume_envelope 13, 4
	octave 4
	note Cs, 4
	volume_envelope 12, 2
	note D_, 2
	note_type 6, 12, 3
	note F_, 1
	note E_, 3
	note_type 12, 12, 5
	note E_, 2
	volume_envelope 12, 2
	note Ds, 2
	note E_, 2
	note Ds, 2
	note E_, 2
	note_type 6, 12, 6
	note Fs, 1
	note G_, 7
	note_type 12, 11, 2
	note Fs, 2
	volume_envelope 11, 5
	note E_, 4
	vibrato 0, 2, 2
	volume_envelope 10, 7
	duty_cycle 2
	octave 3
	note Fs, 1
	note B_, 1
	octave 4
	note_type 6, 10, 7
	note Ds, 1
	note D_, 11
	note_type 12, 10, 7
	note Cs, 4
	octave 3
	note A_, 2
	note B_, 4
	note D_, 2
	note G_, 6
	octave 4
	note_type 6, 10, 7
	note Ds, 1
	note D_, 3
	note_type 12, 10, 7
	note Cs, 2
	octave 3
	note A_, 2
	note B_, 4
	note D_, 2
	note G_, 10
	note B_, 1
	octave 4
	note Cs, 1
	volume_envelope 10, 0
	octave 3
	note A_, 8
	vibrato 0, 3, 3
	volume_envelope 10, 7
	note A_, 14
	vibrato 0, 2, 3
	duty_cycle 0
	volume_envelope 11, 3
	note D_, 2
	volume_envelope 11, 0
	note A_, 2
	volume_envelope 11, 3
	note D_, 2
	volume_envelope 11, 0
	note A_, 8
	vibrato 0, 4, 3
	volume_envelope 11, 7
	note A_, 10
	vibrato 0, 2, 2
	duty_cycle 2
	octave 4
	note E_, 1
	note Ds, 1
	note_type 6, 10, 7
	note Cs, 1
	note D_, 11
	note_type 12, 10, 7
	note Cs, 4
	octave 3
	note A_, 2
	note_type 6, 10, 7
	octave 4
	note Gs, 1
	note G_, 7
	note_type 12, 10, 7
	octave 3
	note D_, 2
	note G_, 4
	octave 4
	note G_, 1
	note Fs, 1
	note_type 6, 10, 7
	note Cs, 1
	note D_, 3
	note_type 12, 10, 7
	note Cs, 2
	octave 3
	note A_, 2
	octave 4
	note Cs, 4
	octave 3
	note D_, 2
	octave 4
	note_type 6, 10, 7
	note Gs, 1
	note G_, 3
	note_type 12, 10, 7
	note D_, 2
	octave 3
	note G_, 2
	note B_, 2
	note D_, 2
	note B_, 1
	octave 4
	note Cs, 1
	octave 3
	note_type 6, 10, 0	
	note As, 1
	note A_, 15
	note_type 12, 10, 7
	note A_, 14
	vibrato 0, 4, 3
	duty_cycle 0
	volume_envelope 11, 3
	note D_, 2
	volume_envelope 11, 0
	note A_, 4
	volume_envelope 11, 5
	note A_, 6
	volume_envelope 11, 3
	note D_, 2
	volume_envelope 11, 0
	note A_, 4
	volume_envelope 11, 5
	note A_, 6
	sound_loop 0, Music_Route113_Ch2
	
gbs_Music_Route113_Ch3:
	gbs_switch 2
Music_Route113_Ch3:
	note_type 8, 1, 0
	pitch_offset 1
	vibrato 12, 3, 2
	rest 3
Music_Route113_Ch3_loop_main:
Music_Route113_Ch3_loop_1:
	sound_call Music_Route113_Ch3_branch_1
	sound_call Music_Route113_Ch3_branch_1
	sound_call Music_Route113_Ch3_branch_2
	sound_call Music_Route113_Ch3_branch_3
	sound_loop 2, Music_Route113_Ch3_loop_1
	note_type 12, 1, 0
	sound_call Music_Route113_Ch3_branch_4
	note B_, 1
	octave 3
	note D_, 1
	note G_, 1
	note B_, 1
	note G_, 1
	note D_, 1
	octave 2
	note B_, 1
	note G_, 1
	note B_, 1
	octave 3
	note D_, 1
	note G_, 1
	note A_, 1
	note E_, 1
	note Cs, 1
	octave 2
	note A_, 1
	note E_, 1
	note A_, 1
	octave 3
	note Cs, 1
	note E_, 1
	note A_, 1
	note E_, 1
	note Cs, 1
	octave 2
	note A_, 1
	note Fs, 1
	note As, 1
	octave 3
	note Cs, 1
	note E_, 1
	note Fs, 1
	note E_, 1
	note Cs, 1
	octave 2
	note As, 1
	note Fs, 1
	note As, 1
	octave 3
	note Cs, 1
	note E_, 1
	note As, 1
	note Fs, 1
	note E_, 1
	note Cs, 1
	octave 2
	note As, 1
	octave 3
	note Cs, 1
	note E_, 1
	note Fs, 1
	note As, 1
	note Fs, 1
	note E_, 1
	note Cs, 1
	sound_call Music_Route113_Ch3_branch_4
	octave 3
	note D_, 1
	note Fs, 1
	note B_, 1
	octave 4
	note D_, 1
	octave 3
	note B_, 1
	note Fs, 1
	note D_, 1
	octave 2
	note G_, 1
	octave 3
	note D_, 1
	note Fs, 1
	note B_, 1
	octave 4
	note D_, 1
	octave 3
	note Gs, 1
	note Fs, 1
	note D_, 1
	octave 2
	note Gs, 1
	octave 3
	note D_, 1
	note Fs, 1
	note Gs, 1
	note B_, 1
	note Gs, 1
	note Fs, 1
	note D_, 1
	octave 2
	note A_, 1
	octave 3
	note E_, 1
	note A_, 1
	octave 4
	note Cs, 1
	note E_, 1
	note Cs, 1
	octave 3
	note A_, 1
	note E_, 1
	octave 2
	note A_, 1
	octave 3
	note E_, 1
	note A_, 1
	octave 4
	note Cs, 1
	octave 2
	note A_, 1
	octave 3
	note E_, 1
	note A_, 1
	octave 4
	note Cs, 1
	note E_, 1
	note Cs, 1
	octave 3
	note A_, 1
	note E_, 1
	octave 2
	note A_, 1
	octave 3
	note E_, 1
	note A_, 1
	octave 4
	note Cs, 1
	note_type 8, 1, 0
	sound_call Music_Route113_Ch3_branch_1
	sound_call Music_Route113_Ch3_branch_1
	sound_call Music_Route113_Ch3_branch_2
	volume_envelope 2, 6
	octave 2
	note G_, 2
	volume_envelope 3, 6
	note G_, 1
	volume_envelope 2, 6
	octave 3
	note E_, 2
	volume_envelope 3, 6
	note E_, 1
	volume_envelope 2, 6
	octave 2
	note G_, 2
	volume_envelope 3, 6
	note G_, 1
	volume_envelope 2, 6
	octave 3
	note E_, 16
	note E_, 8
	volume_envelope 3, 6
	note E_, 6
	sound_call Music_Route113_Ch3_branch_1
	sound_call Music_Route113_Ch3_branch_1
	sound_call Music_Route113_Ch3_branch_2
	volume_envelope 2, 6
	octave 2
	note G_, 2
	volume_envelope 3, 6
	note G_, 1
	volume_envelope 2, 6
	octave 3
	note E_, 12
	volume_envelope 3, 6
	note E_, 3
	volume_envelope 2, 6
	octave 2
	note G_, 2
	volume_envelope 3, 6
	note G_, 1
	volume_envelope 2, 6
	octave 3
	note E_, 12
	volume_envelope 3, 6
	note E_, 6
	sound_loop 0, Music_Route113_Ch3_loop_main
	
Music_Route113_Ch3_branch_1:
	octave 2
	volume_envelope 1, 0
	note G_, 2
	volume_envelope 3, 0
	note G_, 1
	volume_envelope 1, 0
	note B_, 2
	volume_envelope 3, 0
	note B_, 1
	octave 3
	volume_envelope 1, 0
	note Fs, 2
	volume_envelope 3, 0
	note Fs, 1
	volume_envelope 1, 0
	note G_, 2
	volume_envelope 3, 0
	note G_, 1
	volume_envelope 1, 0
	note B_, 2
	volume_envelope 3, 0
	note B_, 1
	octave 4
	volume_envelope 1, 0
	note Fs, 2
	volume_envelope 3, 0
	note Fs, 1
	volume_envelope 1, 0
	note A_, 1
	note B_, 1
	note G_, 1
	note Fs, 1
	note G_, 1
	note D_, 1
	note Cs, 1
	note D_, 1
	octave 3
	note B_, 1
	note A_, 1
	note B_, 1
	note G_, 1
	note Fs, 1
	note G_, 1
	note D_, 1
	note Cs, 1
	note D_, 1
	octave 2
	note B_, 1
	sound_ret
	
Music_Route113_Ch3_branch_2:
	volume_envelope 1, 0
	octave 2
	note D_, 2
	volume_envelope 3, 0
	note D_, 1
	volume_envelope 1, 0
	note Fs, 2
	volume_envelope 3, 0
	note Fs, 1
	volume_envelope 1, 0
	octave 3
	note Cs, 2
	volume_envelope 3, 0
	note Cs, 1
	volume_envelope 1, 0
	note D_, 2
	volume_envelope 3, 0
	note D_, 1
	volume_envelope 1, 0
	note Fs, 2
	volume_envelope 3, 0
	note Fs, 1
	volume_envelope 1, 0
	octave 4
	note Cs, 2
	volume_envelope 3, 0
	note Cs, 1
	volume_envelope 1, 0
	note E_, 1
	note Fs, 1
	note D_, 1
	note Cs, 1
	note D_, 1
	octave 3
	note A_, 1
	note Gs, 1
	note A_, 1
	note Fs, 1
	note E_, 1
	note Fs, 1
	note D_, 1
	note Cs, 1
	note D_, 1
	octave 2
	note A_, 1
	sound_ret
	
Music_Route113_Ch3_branch_3:
	volume_envelope 2, 6
	octave 2
	note G_, 2
	volume_envelope 3, 6
	note G_, 1
	volume_envelope 2, 6
	octave 3
	note E_, 16
	note E_, 8
	volume_envelope 3, 6
	note E_, 12
	sound_ret
	
Music_Route113_Ch3_branch_4:
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	note Fs, 1
	note B_, 1
	octave 4
	note D_, 1
	octave 3
	note B_, 1
	note Fs, 1
	note D_, 1
	octave 2
	note B_, 1
	octave 3
	note D_, 1
	note Fs, 1
	note B_, 1
	octave 4
	note D_, 1
	octave 3
	note As, 1
	note Fs, 1
	note D_, 1
	octave 2
	note As, 1
	octave 3
	note D_, 1
	note Fs, 1
	note As, 1
	octave 4
	note D_, 1
	octave 3
	note As, 1
	note Fs, 1
	note D_, 1
	octave 2
	note A_, 1
	octave 3
	note D_, 1
	note Fs, 1
	note A_, 1
	octave 4
	note D_, 1
	octave 3
	note A_, 1
	note Fs, 1
	note D_, 1
	octave 2
	note A_, 1
	octave 3
	note D_, 1
	note Fs, 1
	note A_, 1
	octave 4
	note D_, 1
	octave 3
	note Gs, 1
	note Fs, 1
	note D_, 1
	octave 2
	note Gs, 1
	octave 3
	note D_, 1
	note Fs, 1
	note Gs, 1
	octave 4
	note D_, 1
	octave 3
	note Gs, 1
	note Fs, 1
	note D_, 1
	octave 2
	note G_, 1
	sound_ret
	
gbs_Music_Route113_Ch4:
	gbs_switch 3
Music_Route113_Ch4:
	toggle_noise 2
	drum_speed 12
	drum_note 8, 1
	drum_note 8, 1
Music_Route113_Ch4_loop_main:
Music_Route113_Ch4_loop_1:
	sound_call Music_Route113_Ch4_branch_1
	sound_loop 5, Music_Route113_Ch4_loop_1
	sound_call Music_Route113_Ch4_branch_2
	sound_call Music_Route113_Ch4_branch_3
	sound_call Music_Route113_Ch4_branch_1
Music_Route113_Ch4_loop_2:
	sound_call Music_Route113_Ch4_branch_1
	sound_loop 5, Music_Route113_Ch4_loop_2
	sound_call Music_Route113_Ch4_branch_2
	sound_call Music_Route113_Ch4_branch_3
	sound_call Music_Route113_Ch4_branch_4
Music_Route113_Ch4_loop_3:
	sound_call Music_Route113_Ch4_branch_1
	sound_loop 16, Music_Route113_Ch4_loop_3
	sound_call Music_Route113_Ch4_branch_4
	sound_call Music_Route113_Ch4_branch_5
	sound_call Music_Route113_Ch4_branch_4
	sound_call Music_Route113_Ch4_branch_1
	sound_call Music_Route113_Ch4_branch_1
	drum_note 2, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 8, 1
	sound_call Music_Route113_Ch4_branch_6
	drum_note 2, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 8, 1
	sound_call Music_Route113_Ch4_branch_4
	sound_call Music_Route113_Ch4_branch_5
	sound_call Music_Route113_Ch4_branch_4
	sound_call Music_Route113_Ch4_branch_1
	sound_call Music_Route113_Ch4_branch_1
	sound_call Music_Route113_Ch4_branch_6
	sound_call Music_Route113_Ch4_branch_1
	sound_call Music_Route113_Ch4_branch_4
	sound_loop 0, Music_Route113_Ch4_loop_main

Music_Route113_Ch4_branch_1:
	drum_note 2, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	sound_ret
	
Music_Route113_Ch4_branch_2:
	drum_note 2, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 8, 1
	sound_ret
	
Music_Route113_Ch4_branch_3:
	drum_note 1, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 8, 1
	sound_ret
	
Music_Route113_Ch4_branch_4:
	drum_note 2, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 8, 1
	sound_ret
	
Music_Route113_Ch4_branch_5:
	drum_note 2, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	sound_ret
	
Music_Route113_Ch4_branch_6:
	drum_note 2, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 1, 1
	drum_note 8, 1
	sound_ret
