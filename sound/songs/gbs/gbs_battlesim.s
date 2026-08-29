	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_BattleSim
	.align 2

gbs_Music_BattleSim:
	channel_count 4
	channel 1, Music_BattleSim_Ch1
	channel 2, Music_BattleSim_Ch2
	channel 3, Music_BattleSim_Ch3
	channel 4, Music_BattleSim_Ch4


gbs_Music_BattleSim_Ch1:
	gbs_switch 0
Music_BattleSim_Ch1:
	vibrato 18, 1, 5
	pitch_offset 1
	tempo 128
	note_type 12, 11, 1
	rest 16
	rest 16
Music_BattleSim_Ch1_loop_main:
	duty_cycle 0
	rest 16
	rest 16
	rest 16
	rest 16
Music_BattleSim_Ch1_loop_1:
	octave 4
	note C_, 1
	note C_, 1
	note C_, 1
	note C_, 2
	note C_, 2
	note C_, 2
	note C_, 1
	note C_, 2
	note C_, 1
	note C_, 2
	note C_, 2
	note C_, 2
	note C_, 2
	note E_, 2
	note E_, 2
	note E_, 1
	note E_, 3
	note E_, 1
	note E_, 1
	note E_, 1
	sound_loop 4, Music_BattleSim_Ch1_loop_1
	duty_cycle 1
	volume_envelope 6, 1
Music_BattleSim_Ch1_loop_2:
	octave 5
	note E_, 1
	octave 4
	note E_, 1
	note E_, 1
	octave 5
	note E_, 1
	octave 4
	note E_, 1
	note E_, 1
	octave 5
	note E_, 1
	octave 4
	note E_, 1
	note E_, 1
	octave 5
	note D_, 1
	note E_, 1
	note F_, 1
	note F_, 1
	note G_, 1
	note E_, 1
	note D_, 1
	sound_loop 8, Music_BattleSim_Ch1_loop_2
	octave 4
Music_BattleSim_Ch1_loop_3:
	volume_envelope 4, -7
	vibrato 0, 0, 0
	note C_, 4
	vibrato 0, 4, 2
	volume_envelope 8, -7
	note C_, 4
	vibrato 0, 8, 2
	volume_envelope 11, -7
	note C_, 4
	vibrato 0, 11, 2
	volume_envelope 15, 0
	note C_, 4
	sound_loop 8, Music_BattleSim_Ch1_loop_3
	vibrato 0, 0, 0
	volume_envelope 11, 1
	rest 16
	rest 16
	rest 16
	rest 16
	sound_loop 0, Music_BattleSim_Ch1_loop_main
	
gbs_Music_BattleSim_Ch2:
	gbs_switch 1
Music_BattleSim_Ch2:
	duty_cycle 2
	vibrato 18, 1, 5
	pitch_offset 1
	note_type 12, 8, 2
	rest 16
	rest 16
	octave 1
Music_BattleSim_Ch2_loop_main:
Music_BattleSim_Ch2_loop_1:
	note E_, 2
	sound_loop 32, Music_BattleSim_Ch2_loop_1
	duty_cycle 0
	volume_envelope 13, 1
Music_BattleSim_Ch2_loop_2:
	octave 3
	note A_, 1
	note A_, 1
	note A_, 1
	note A_, 2
	note A_, 2
	note A_, 2
	note A_, 1
	note A_, 2
	note A_, 1
	note A_, 2
	note A_, 2
	note A_, 2
	note A_, 2
	note Gs, 2
	note Gs, 2
	note Gs, 1
	note Gs, 3
	note Gs, 1
	note Gs, 1
	note Gs, 1
	sound_loop 4, Music_BattleSim_Ch2_loop_2
	duty_cycle 2
	volume_envelope 8, 1
Music_BattleSim_Ch2_loop_3:
	octave 6
	note E_, 1
	octave 5
	note E_, 1
	note E_, 1
	octave 6
	note E_, 1
	octave 5
	note E_, 1
	note E_, 1
	octave 6
	note E_, 1
	octave 5
	note E_, 1
	note E_, 1
	octave 6
	note D_, 1
	note E_, 1
	note F_, 1
	note F_, 1
	note G_, 1
	note E_, 1
	note D_, 1
	sound_loop 8, Music_BattleSim_Ch2_loop_3
	duty_cycle 0
	octave 4
	sound_call Music_BattleSim_Ch2_branch_1
	sound_call Music_BattleSim_Ch2_branch_2
	sound_call Music_BattleSim_Ch2_branch_3
	sound_call Music_BattleSim_Ch2_branch_2
	sound_call Music_BattleSim_Ch2_branch_1
	sound_call Music_BattleSim_Ch2_branch_2
	sound_call Music_BattleSim_Ch2_branch_3
	volume_envelope 4, -7
	vibrato 0, 0, 0
	note Fs, 4
	vibrato 0, 4, 2
	volume_envelope 8, -7
	note Fs, 4
	vibrato 0, 8, 2
	volume_envelope 11, -7
	note Fs, 4
	vibrato 0, 11, 2
	volume_envelope 15, 0
	note Fs, 4
	duty_cycle 2
	vibrato 0, 0, 0
	volume_envelope 8, 2
	octave 1
Music_BattleSim_Ch2_loop_4:
	note E_, 2
	sound_loop 32, Music_BattleSim_Ch2_loop_4
	sound_loop 0, Music_BattleSim_Ch2_loop_main
	
Music_BattleSim_Ch2_branch_1:
	volume_envelope 4, -7
	vibrato 0, 0, 0
	note A_, 4
	vibrato 0, 4, 2
	volume_envelope 8, -7
	note A_, 4
	vibrato 0, 8, 2
	volume_envelope 11, -7
	note A_, 4
	vibrato 0, 11, 2
	volume_envelope 15, 0
	note A_, 4
	sound_ret
	
Music_BattleSim_Ch2_branch_2:
	volume_envelope 4, -7
	vibrato 0, 0, 0
	note Gs, 4
	vibrato 0, 4, 2
	volume_envelope 8, -7
	note Gs, 4
	vibrato 0, 8, 2
	volume_envelope 11, -7
	note Gs, 4
	vibrato 0, 11, 2
	volume_envelope 15, 0
	note Gs, 4
	sound_ret
	
Music_BattleSim_Ch2_branch_3:
	volume_envelope 4, -7
	vibrato 0, 0, 0
	note G_, 4
	vibrato 0, 4, 2
	volume_envelope 8, -7
	note G_, 4
	vibrato 0, 8, 2
	volume_envelope 11, -7
	note G_, 4
	vibrato 0, 11, 2
	volume_envelope 15, 0
	note G_, 4
	sound_ret
	
gbs_Music_BattleSim_Ch3:
	gbs_switch 2
Music_BattleSim_Ch3:
	note_type 6, 1, 9
	rest 16
	rest 16
	rest 16
	rest 16
Music_BattleSim_Ch3_loop_main:
	vibrato 0, 0, 0
Music_BattleSim_Ch3_loop_1:
	sound_call Music_BattleSim_Ch3_branch_1
	sound_loop 4, Music_BattleSim_Ch3_loop_1
	note_type 12, 1, 9
Music_BattleSim_Ch3_loop_2:
	sound_call Music_BattleSim_Ch3_branch_2
	note G_, 1
	rest 1
	note A_, 9
	octave 1
	note A_, 1
	rest 1
	note A_, 1
	note A_, 1
	rest 1
	note A_, 3
	sound_call Music_BattleSim_Ch3_branch_2
	note B_, 1
	rest 1
	note A_, 10
	note G_, 3
	note Fs, 4
	sound_loop 2, Music_BattleSim_Ch3_loop_2
	volume_envelope 1, 2
Music_BattleSim_Ch3_loop_3:
	octave 1
	note B_, 2
	octave 2
	note D_, 2
	note E_, 2
	octave 1
	note B_, 2
	octave 2
	note D_, 2
	note E_, 2
	octave 1
	note B_, 2
	octave 2
	note D_, 2
	note E_, 2
	octave 1
	note B_, 2
	octave 2
	note D_, 2
	note E_, 2
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	note E_, 1
	rest 1
	note D_, 2
	sound_loop 4, Music_BattleSim_Ch3_loop_3
	volume_envelope 1, 7
	vibrato 24, 5, 3
	octave 3
	note A_, 6
	octave 4
	note E_, 14
	note A_, 4
	note E_, 4
	note D_, 4
	note E_, 12
	note C_, 4
	note D_, 6
	note E_, 9
	rest 1
	note E_, 12
	note A_, 8
	note B_, 4
	octave 5
	note D_, 4
	note C_, 4
	octave 4
	note B_, 12
	note G_, 4
	note Fs, 16
	note_type 6, 1, 9
	vibrato 0, 0, 0
Music_BattleSim_Ch3_loop_4:
	sound_call Music_BattleSim_Ch3_branch_1
	sound_loop 4, Music_BattleSim_Ch3_loop_4
	sound_loop 0, Music_BattleSim_Ch3_loop_main
	
Music_BattleSim_Ch3_branch_1:
	octave 2
	note E_, 1
	rest 1
	octave 1
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	octave 2
	note E_, 1
	rest 1
	octave 1
	note E_, 1
	rest 1
	note E_, 1
	rest 1
	octave 2
	note E_, 4
	octave 1
	note E_, 1
	rest 1
	octave 2
	note D_, 1
	rest 1
	note E_, 1
	rest 1
	note F_, 1
	rest 1
	note F_, 1
	rest 1
	note G_, 1
	rest 1
	note E_, 1
	rest 1
	octave 1
	note E_, 1
	rest 1
	sound_ret
	
Music_BattleSim_Ch3_branch_2:
	octave 1
	note A_, 1
	rest 1
	note A_, 1
	octave 2
	note A_, 1
	rest 1
	octave 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	note A_, 1
	rest 1
	octave 3
	note C_, 1
	rest 1
	octave 2
	sound_ret
	
gbs_Music_BattleSim_Ch4:
	gbs_switch 3
Music_BattleSim_Ch4:
	toggle_noise 3
	drum_speed 12
Music_BattleSim_Ch4_loop_1:
	drum_note 4, 2
	drum_note 9, 1
	drum_note 9, 1
	sound_loop 8, Music_BattleSim_Ch4_loop_1
Music_BattleSim_Ch4_loop_2:
	drum_note 4, 2
	drum_note 9, 1
	drum_note 9, 1
	drum_note 3, 2
	drum_note 9, 1
	drum_note 9, 1
	sound_loop 7, Music_BattleSim_Ch4_loop_2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 4, 2
	drum_note 1, 1
Music_BattleSim_Ch4_loop_main:
Music_BattleSim_Ch4_loop_3:
	drum_note 4, 3
	drum_note 4, 1
	drum_note 1, 3
	drum_note 4, 2
	drum_note 4, 1
	drum_note 4, 2
	drum_note 1, 3
	drum_note 4, 1
	sound_loop 7, Music_BattleSim_Ch4_loop_3
	drum_note 4, 3
	drum_note 4, 1
	drum_note 1, 3
	drum_note 4, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 4, 2
	drum_note 1, 1
Music_BattleSim_Ch4_loop_4:
	drum_note 11, 2
	drum_note 8, 2
	sound_loop 30, Music_BattleSim_Ch4_loop_4
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 4, 2
	drum_note 1, 1
	sound_loop 0, Music_BattleSim_Ch4_loop_main
