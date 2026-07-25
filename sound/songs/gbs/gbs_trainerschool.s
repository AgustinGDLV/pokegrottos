	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_TrainerSchool
	.align 2

gbs_Music_TrainerSchool:
	channel_count 3
	channel 1, Music_TrainerSchool_Ch1
	channel 2, Music_TrainerSchool_Ch2
	channel 3, Music_TrainerSchool_Ch3

gbs_Music_TrainerSchool_Ch1:
	gbs_switch 0
Music_TrainerSchool_Ch1:
	tempo 80
	duty_cycle 2
	vibrato 18, 1, 5
	pitch_offset 1
	note_type 12, 9, 2
	sound_call Music_TrainerSchool_Ch1_branch_1
	sound_call Music_TrainerSchool_Ch1_branch_1
	sound_call Music_TrainerSchool_Ch1_branch_1
	sound_call Music_TrainerSchool_Ch1_branch_2
	sound_call Music_TrainerSchool_Ch1_branch_1
	sound_call Music_TrainerSchool_Ch1_branch_2
	sound_call Music_TrainerSchool_Ch1_branch_3
	note A_, 4
	octave 3
	note A_, 4
	octave 2
	note E_, 4
	octave 3
	note A_, 4
	octave 2
	note A_, 4
	octave 3
	note A_, 4
	octave 2
	note E_, 4
	octave 3
	note A_, 4
	sound_call Music_TrainerSchool_Ch1_branch_3
	note A_, 8
	note E_, 8
	note A_, 8
	volume_envelope 9, 5
	octave 1
	note A_, 4
	octave 2
	note Cs, 4
	sound_loop 0, Music_TrainerSchool_Ch1
	
Music_TrainerSchool_Ch1_branch_1:
	octave 2
	note D_, 4
	note A_, 4
	octave 1
	note A_, 4
	octave 2
	note A_, 4
	octave 1
	note B_, 4
	octave 2
	note A_, 4
	note Cs, 4
	note A_, 4
	sound_ret
	
Music_TrainerSchool_Ch1_branch_2:
	note E_, 4
	note B_, 4
	octave 1
	note B_, 4
	octave 2
	note B_, 4
	note Cs, 4
	octave 3
	note Cs, 4
	octave 1
	note A_, 4
	octave 3
	note Cs, 4
	octave 1
	note B_, 4
	octave 2
	note B_, 4
	octave 1
	note As, 4
	octave 2
	note B_, 4
	octave 1
	note A_, 4
	octave 2
	note B_, 4
	octave 1
	note Gs, 4
	octave 2
	note B_, 4
	octave 1
	note G_, 4
	octave 2
	note B_, 4
	octave 1
	note G_, 4
	octave 2
	note B_, 4
	octave 1
	note A_, 4
	octave 3
	note Cs, 4
	octave 1
	note A_, 4
	octave 3
	note Cs, 4
	sound_ret
	
Music_TrainerSchool_Ch1_branch_3:
	octave 2
	note G_, 4
	octave 3
	note B_, 4
	octave 2
	note D_, 4
	octave 3
	note B_, 4
	octave 2
	note G_, 4
	octave 3
	note B_, 4
	octave 2
	note D_, 4
	octave 3
	note B_, 4
	octave 2
	note A_, 4
	octave 3
	note E_, 4
	octave 2
	note E_, 4
	octave 3
	note E_, 4
	octave 2
	note A_, 4
	octave 3
	note E_, 4
	octave 2
	note A_, 4
	note Gs, 4
	note G_, 4
	octave 3
	note G_, 4
	octave 2
	note E_, 4
	octave 3
	note G_, 4
	octave 2
	note G_, 4
	note Fs, 4
	note G_, 4
	note Gs, 4
	sound_ret
	
gbs_Music_TrainerSchool_Ch2:
	gbs_switch 1
Music_TrainerSchool_Ch2:
	duty_cycle 2
	vibrato 18, 1, 5
	pitch_offset 1
	note_type 12, 9, 2
	octave 4
	rest 16
	rest 16
	rest 16
	rest 12
	note Fs, 2
	note G_, 2
	note A_, 4
	note A_, 4
	note A_, 2
	note G_, 2
	note Fs, 2
	note G_, 2
	volume_envelope 9, 4
	note A_, 8
	volume_envelope 9, 2
	octave 5
	note D_, 4
	octave 4
	note E_, 2
	note Fs, 2
	note G_, 4
	note G_, 4
	note G_, 2
	note Fs, 2
	note E_, 2
	note Fs, 2
	volume_envelope 9, 4
	note G_, 8
	volume_envelope 9, 2
	octave 5
	note Cs, 4
	octave 4
	note D_, 2
	note E_, 2
	note Fs, 4
	note Fs, 4
	note Fs, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note Fs, 4
	note B_, 4
	octave 5
	note D_, 4
	octave 4
	note B_, 4
	note G_, 8
	octave 3
	note B_, 4
	octave 4
	note D_, 4
	note Cs, 4
	note D_, 4
	note E_, 4
	note Fs, 2
	note G_, 2
	note A_, 4
	note A_, 4
	note A_, 1
	note B_, 1
	note A_, 2
	note Fs, 2
	note G_, 2
	volume_envelope 9, 4
	note A_, 8
	volume_envelope 9, 2
	octave 5
	note D_, 4
	octave 4
	note E_, 2
	note Fs, 2
	note G_, 4
	note G_, 4
	note G_, 1
	note A_, 1
	note G_, 2
	note E_, 2
	note Fs, 2
	volume_envelope 9, 4
	note G_, 8
	volume_envelope 9, 2
	octave 5
	note Cs, 4
	octave 4
	note D_, 2
	note E_, 2
	note Fs, 4
	note Fs, 4
	note Fs, 1
	note G_, 1
	note Fs, 2
	note D_, 2
	note E_, 2
	note Fs, 4
	note B_, 4
	octave 5
	note Cs, 4
	note D_, 4
	note E_, 4
	octave 4
	note B_, 4
	note B_, 2
	octave 5
	note D_, 2
	note Cs, 1
	note D_, 1
	octave 4
	note B_, 2
	octave 5
	note Cs, 4
	note D_, 4
	note E_, 12
	volume_envelope 9, 4
	octave 4
	note B_, 4
	volume_envelope 9, 2
	octave 5
	note Cs, 4
	note D_, 4
	note Cs, 4
	octave 4
	note B_, 4
	note A_, 4
	note Gs, 4
	note A_, 8
	note B_, 4
	note E_, 2
	note B_, 2
	octave 5
	volume_envelope 9, 6
	note Cs, 16
	rest 4
	volume_envelope 9, 4
	octave 4
	note B_, 4
	volume_envelope 9, 2
	octave 5
	note Cs, 4
	note D_, 4
	note E_, 4
	octave 4
	note B_, 4
	octave 5
	note Cs, 4
	note D_, 4
	note Cs, 8
	octave 4
	note B_, 4
	octave 5
	note Cs, 1
	note D_, 1
	octave 4
	note B_, 2
	volume_envelope 9, 6
	note A_, 16
	rest 4
	note B_, 4
	volume_envelope 9, 2
	octave 5
	note Cs, 4
	note D_, 4
	note Cs, 4
	octave 4
	note B_, 1
	octave 5
	note Cs, 1
	octave 4
	note B_, 2
	note A_, 4
	note Gs, 4
	note A_, 2
	note E_, 2
	note A_, 2
	note B_, 2
	octave 5
	note Cs, 2
	octave 4
	note A_, 2
	octave 5
	note Cs, 2
	note D_, 2
	volume_envelope 9, 6
	note E_, 16
	rest 4
	octave 4
	note B_, 4
	volume_envelope 9, 2
	octave 5
	note Cs, 4
	note D_, 4
	note E_, 4
	note D_, 1
	note E_, 1
	note D_, 2
	note Cs, 4
	octave 4
	note B_, 4
	octave 5
	note Cs, 4
	octave 4
	note A_, 4
	note A_, 2
	note Gs, 2
	note A_, 2
	note B_, 2
	octave 5
	note Cs, 2
	octave 4
	note B_, 2
	octave 5
	note Cs, 2
	note D_, 2
	volume_envelope 9, 6
	note E_, 6
	rest 2
	sound_loop 0, Music_TrainerSchool_Ch2
	
gbs_Music_TrainerSchool_Ch3:
	gbs_switch 2
Music_TrainerSchool_Ch3:
	note_type 12, 2, 5
	octave 3
	rest 4
Music_TrainerSchool_Ch3_loop_1:
	note Fs, 2
	rest 6
	sound_loop 12, Music_TrainerSchool_Ch3_loop_1
Music_TrainerSchool_Ch3_loop_2:
	note G_, 2
	rest 6
	sound_loop 4, Music_TrainerSchool_Ch3_loop_2
Music_TrainerSchool_Ch3_loop_3:
	note Fs, 2
	rest 6
	sound_loop 4, Music_TrainerSchool_Ch3_loop_3
	sound_call Music_TrainerSchool_Ch3_branch_1
Music_TrainerSchool_Ch3_loop_4:
	note Fs, 2
	rest 6
	sound_loop 4, Music_TrainerSchool_Ch3_loop_4	
Music_TrainerSchool_Ch3_loop_5:
	note G_, 2
	rest 6
	sound_loop 4, Music_TrainerSchool_Ch3_loop_5
Music_TrainerSchool_Ch3_loop_6:
	note Fs, 2
	rest 6
	sound_loop 4, Music_TrainerSchool_Ch3_loop_6
	sound_call Music_TrainerSchool_Ch3_branch_1
	octave 4
	sound_call Music_TrainerSchool_Ch3_branch_4
	sound_call Music_TrainerSchool_Ch3_branch_3
	sound_call Music_TrainerSchool_Ch3_branch_2
	octave 4
	sound_call Music_TrainerSchool_Ch3_branch_3
	sound_call Music_TrainerSchool_Ch3_branch_4
	sound_call Music_TrainerSchool_Ch3_branch_3
	sound_call Music_TrainerSchool_Ch3_branch_2
	octave 4
	note Cs, 2
	rest 6
	note Cs, 2
	rest 6
	note Cs, 2
	rest 2
	octave 3
	note A_, 6
	rest 2
	sound_loop 0, Music_TrainerSchool_Ch3
	
Music_TrainerSchool_Ch3_branch_1:
	note G_, 2
	rest 6
	note G_, 2
	rest 6
	note A_, 2
	rest 6
	note A_, 2
	rest 6
	sound_ret
	
Music_TrainerSchool_Ch3_branch_2:
	octave 3
	note B_, 2
	rest 6
	note B_, 2
	rest 6
	note B_, 2
	rest 6
	note B_, 2
	rest 6
	sound_ret
	
Music_TrainerSchool_Ch3_branch_3:
	note Cs, 2
	rest 6
	note Cs, 2
	rest 6
	note Cs, 2
	rest 6
	note Cs, 2
	rest 6
	sound_ret
	
Music_TrainerSchool_Ch3_branch_4:
	note D_, 2
	rest 6
	note D_, 2
	rest 6
	note D_, 2
	rest 6
	note D_, 2
	rest 6
	sound_ret
