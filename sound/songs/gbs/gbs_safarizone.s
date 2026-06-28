	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_SafariZone
	.align 2

gbs_Music_SafariZone:
	channel_count 4
	channel 1, Music_SafariZone_Ch1
	channel 2, Music_SafariZone_Ch2
	channel 3, Music_SafariZone_Ch3
	channel 4, Music_SafariZone_Ch4

gbs_Music_SafariZone_Ch1:
	gbs_switch 0
Music_SafariZone_Ch1:
	tempo 208
	volume 7, 7
	duty_cycle 0
	vibrato 8, 1, 5
	note_type 12, 8, 2
	rest 14
	octave 2
Music_SafariZone_Ch1_loop:
	note C_, 3
	note C_, 3
	note C_, 3
	note C_, 3
	note C_, 1
	duty_cycle 2
	volume_envelope 7, 2
	octave 4
	note Ds, 2
	note Gs, 1
	octave 5
	note C_, 3
	octave 4
	note C_, 2
	note Ds, 1
	note F_, 3
	note F_, 2
	note Gs, 1
	octave 5
	note Cs, 3
	octave 4
	note F_, 3
	note G_, 3
	note Ds, 2
	note G_, 1
	note As, 3
	note Ds, 2
	octave 5
	note Cs, 1
	note C_, 1
	note C_, 1
	octave 4
	note B_, 1
	octave 5
	note C_, 2
	octave 4
	note Gs, 1
	note Ds, 2
	note Gs, 1
	note C_, 1
	note Cs, 1
	note Ds, 1
	duty_cycle 0
	note F_, 2
	note F_, 1
	note Cs, 1
	note F_, 1
	note Gs, 1
	volume_envelope 7, 5
	octave 5
	note Cs, 3
	octave 4
	note F_, 3
	volume_envelope 7, 2
	note Ds, 2
	note Ds, 1
	note C_, 1
	note Ds, 1
	note Gs, 1
	volume_envelope 7, 5
	octave 5
	note C_, 3
	octave 4
	note Ds, 3
	duty_cycle 2
	note D_, 3
	note D_, 3
	octave 3
	note As, 3
	octave 4
	note F_, 3
	duty_cycle 0
	volume_envelope 7, 2
	note Ds, 1
	note Ds, 1
	note F_, 1
	note Ds, 1
	note G_, 1
	note As, 1
	octave 5
	note Ds, 2
	note Ds, 1
	octave 4
	volume_envelope 9, 4
	note Ds, 3
	duty_cycle 2
	sound_call Music_SafariZone_Ch1_branch_1
	duty_cycle 3
	note Cs, 3
	octave 3
	note F_, 1
	note Gs, 1
	octave 4
	note Cs, 1
	note Ds, 3
	octave 3
	note Gs, 1
	octave 4
	note Cs, 1
	note Ds, 1
	note F_, 3
	octave 6
	duty_cycle 2
	volume_envelope 7, 3
	note Cs, 3
	octave 5
	note F_, 2
	note F_, 1
	note Gs, 3
	octave 4
	volume_envelope 9, 4
	duty_cycle 3
	note G_, 5
	note Gs, 1
	note G_, 3
	note F_, 3
	note Ds, 3
	note Cs, 3
	note C_, 3
	octave 3
	note As, 3
	note Gs, 3
	note Gs, 2
	note G_, 1
	note Gs, 1
	rest 2
	note As, 1
	rest 2
	note G_, 3
	octave 5
	duty_cycle 2
	volume_envelope 9, 3
	note Ds, 2
	note F_, 1
	note Ds, 3
	note Cs, 3
	volume_envelope 9, 4
	sound_call Music_SafariZone_Ch1_branch_1
	duty_cycle 3
	note Cs, 3
	octave 3
	note F_, 1
	note Gs, 1
	octave 4
	note Cs, 1
	note F_, 3
	octave 3
	note F_, 1
	note Gs, 1
	octave 4
	note Cs, 1
	note Gs, 3
	duty_cycle 2
	octave 3
	note F_, 3
	note Ds, 3
	note D_, 3
	volume_envelope 7, 4
	octave 4
	note Ds, 2
	note Ds, 1
	octave 5
	note Ds, 3
	octave 4
	note Ds, 2
	note Ds, 1
	octave 5
	note Ds, 3
	octave 4
	note Ds, 2
	note Ds, 1
	octave 5
	note Ds, 3
	octave 4
	note Ds, 2
	note Ds, 1
	octave 5
	note Ds, 3
	duty_cycle 0
	octave 3
	note F_, 3
	octave 2
	note Gs, 1
	octave 3
	note Cs, 1
	note F_, 1
	note Gs, 1
	rest 2
	octave 4
	duty_cycle 3
	volume_envelope 10, 4
	note F_, 3

	volume_envelope 7, 4
	duty_cycle 0
	octave 3
	note F_, 3
	note D_, 1
	note F_, 1
	note Gs, 1
	octave 4
	note D_, 1
	rest 2
	duty_cycle 3
	volume_envelope 10, 4
	note F_, 3 
	duty_cycle 2
	volume_envelope 10, 2
	note Gs, 3
	note B_, 3
	octave 5
	note C_, 3
	octave 4
	note Gs, 3
	note G_, 3
	octave 3
	note G_, 3
	volume_envelope 10, 4
	note Ds, 1
	note G_, 1
	note As, 1
	octave 4
	note Cs, 3
	duty_cycle 0
	volume_envelope 12, 7
	octave 3
	note Gs, 12
	rest 14
	volume_envelope 8, 2
	octave 2
	note C_, 3
	note C_, 3
	note C_, 3
	note C_, 3
	sound_loop 0, Music_SafariZone_Ch1_loop
	
Music_SafariZone_Ch1_branch_1:
	octave 4
	note Gs, 5
	note As, 1
	octave 5
	note C_, 3
	octave 4
	note As, 3
	note Gs, 3
	note G_, 3
	note F_, 3
	note Ds, 3
	sound_ret

gbs_Music_SafariZone_Ch2:
	gbs_switch 1
Music_SafariZone_Ch2:
	duty_cycle 2
	vibrato 18, 2, 5
	pitch_offset 1
	sound_call Music_SafariZone_Ch2_branch_2
	note_type 12, 10, 2
	note Gs, 12
Music_SafariZone_Ch2_loop:
	duty_cycle 1
	octave 3
	volume_envelope 12, 5
	note Ds, 2
	volume_envelope 12, 2
	note D_, 1
	note Ds, 3
	volume_envelope 12, 5
	note Gs, 2
	volume_envelope 12, 2
	note G_, 1
	note Gs, 3
	volume_envelope 12, 5
	note F_, 2
	note E_, 1
	note F_, 2
	note G_, 1
	note Gs, 3
	rest 3
	note As, 2
	volume_envelope 12, 2
	note Gs, 1
	note G_, 3
	volume_envelope 12, 5
	note G_, 2
	volume_envelope 12, 2
	note F_, 1
	note Ds, 3
	note Gs, 1
	note Gs, 1
	note G_, 1
	volume_envelope 12, 5
	note Gs, 2
	note F_, 1
	note Ds, 3
	rest 3
	duty_cycle 2
	note Gs, 2
	note G_, 1
	note Gs, 2
	note As, 1
	note Gs, 3
	rest 3
	note Gs, 2
	note G_, 1
	note Gs, 2
	note As, 1
	note Gs, 3
	rest 3
	duty_cycle 1
	volume_envelope 12, 2
	note G_, 2
	note Gs, 1
	note G_, 2
	note Gs, 1
	note As, 2
	note F_, 1
	note G_, 2
	note Gs, 1
	volume_envelope 12, 5
	note As, 9
	note_type 3, 5, 2
	rest 6
	note Ds, 1
	volume_envelope 6, 2
	note F_, 1
	volume_envelope 7, 2
	note G_, 1
	volume_envelope 8, 2
	note Gs, 1
	volume_envelope 9, 2
	note As, 1
	volume_envelope 10, 2
	note B_, 1
	note_type 12, 12, 7
	sound_call Music_SafariZone_Ch2_branch_1
	note F_, 3
	rest 3
	note G_, 3
	rest 3
	volume_envelope 12, 0
	note Gs, 3
	volume_envelope 12, 5
	note Gs, 9
	duty_cycle 0
	volume_envelope 12, 7
	note As, 5
	octave 4
	note C_, 1
	octave 3
	note As, 3
	note Gs, 3
	note G_, 3
	note F_, 3
	note Ds, 3
	note Cs, 3
	volume_envelope 12, 3
	note C_, 3
	note C_, 2
	octave 2
	note B_, 1
	octave 3
	note C_, 3
	note Cs, 3
	volume_envelope 12, 0
	note Ds, 3
	volume_envelope 12, 5
	note Ds, 9
	volume_envelope 12, 7
	duty_cycle 1
	sound_call Music_SafariZone_Ch2_branch_1
	note Gs, 3
	rest 3
	octave 4
	note Cs, 3
	rest 3
	volume_envelope 12, 3
	note F_, 3
	volume_envelope 9, 2
	duty_cycle 0
	octave 3
	note Gs, 3
	note G_, 3
	note F_, 3
	volume_envelope 12, 7
	duty_cycle 3
	note Ds, 3
	rest 3
	note F_, 3
	rest 3
	note G_, 3
	rest 3
	note Gs, 3
	rest 3
	duty_cycle 2
	note As, 1
	rest 2
	octave 4
	note Cs, 1
	rest 2
	note F_, 1
	rest 2
	octave 3
	note F_, 3
	note G_, 1
	rest 2
	note Gs, 1
	rest 2
	note G_, 1
	rest 2
	note F_, 3
	volume_envelope 12, 2
	duty_cycle 0
	note Ds, 3
	note D_, 3
	note Ds, 3
	note F_, 3
	note Ds, 3
	note Ds, 2
	octave 4
	note Cs, 1
	volume_envelope 12, 5
	note C_, 3
	octave 3
	note G_, 3
	duty_cycle 2
	sound_call Music_SafariZone_Ch2_branch_2
	volume_envelope 10, 2
	octave 4
	note Gs, 4
	octave 5
	note Ds, 2
	note C_, 2
	note Cs, 2
	note Ds, 2
	volume_envelope 10, 5
	note Fs, 4
	note F_, 1
	note E_, 1
	note Ds, 4
	note F_, 1
	note G_, 1
	note_type 12, 10, 2
	note Gs, 12
	rest 12
	sound_loop 0, Music_SafariZone_Ch2_loop

Music_SafariZone_Ch2_branch_1:
	octave 4
	note C_, 5
	note Cs, 1
	note Ds, 3
	note Cs, 3
	note C_, 3
	octave 3
	note As, 3
	note Gs, 3
	note G_, 3
	sound_ret
	
Music_SafariZone_Ch2_branch_2:
	note_type 6, 10, 2
	octave 4
	note C_, 4
	octave 3
	note B_, 2
	octave 4
	note C_, 2
	note Cs, 2
	note Ds, 2
	volume_envelope 10, 5
	note Fs, 4
	note F_, 1
	note E_, 1
	note Ds, 4
	note F_, 1
	note G_, 1
	sound_ret


gbs_Music_SafariZone_Ch3:
	gbs_switch 2
Music_SafariZone_Ch3:
	vibrato 18, 1, 5
	sound_call Music_SafariZone_Ch3_branch_5
Music_SafariZone_Ch3_loop:
	sound_call Music_SafariZone_Ch3_branch_1
	sound_call Music_SafariZone_Ch3_branch_1
	sound_call Music_SafariZone_Ch3_branch_1
	sound_call Music_SafariZone_Ch3_branch_1
	sound_call Music_SafariZone_Ch3_branch_2
	sound_call Music_SafariZone_Ch3_branch_2
	octave 2
	note Ds, 2
	rest 2
	octave 4
	note Cs, 2
	octave 2
	note As, 2
	rest 2
	octave 4
	note Cs, 2
	octave 2
	note Ds, 2
	rest 2
	octave 4
	note Cs, 2
	octave 2
	note As, 2
	rest 2
	octave 3
	note G_, 2
	sound_call Music_SafariZone_Ch3_branch_1
	sound_call Music_SafariZone_Ch3_branch_1
	sound_call Music_SafariZone_Ch3_branch_3
	octave 3
	note Cs, 1
	rest 1
	note F_, 1
	rest 1
	note Gs, 1
	rest 1
	octave 4
	note F_, 2
	rest 4 
	sound_call Music_SafariZone_Ch3_branch_4
	octave 3
	note C_, 1
	rest 1
	note Ds, 1
	rest 1
	note Gs, 1
	rest 1
	octave 4
	note Ds, 2
	rest 4 
	octave 2
	note D_, 2
	rest 2
	octave 3
	note F_, 2
	octave 1
	note As, 2
	rest 2
	octave 3
	note F_, 2
	octave 2
	note C_, 2
	rest 2
	octave 4
	note D_, 2
	octave 2
	note D_, 2
	rest 2
	octave 4
	note D_, 2
	octave 2
	note Ds, 2
	rest 2
	octave 3
	note G_, 2
	octave 2
	note As, 2
	rest 4
	octave 3
	note Ds, 2
	rest 2
	note As, 2
	octave 2
	note Ds, 2
	rest 4
	note Gs, 2
	rest 4
	note Ds, 2
	rest 4
	note Gs, 2
	rest 4
	note Ds, 2
	rest 4
	note Gs, 2
	rest 4
	note Ds, 2
	rest 4
	octave 3
	note C_, 2
	rest 4
	octave 2
	note Ds, 2
	rest 4
	note Cs, 2
	rest 4
	note Gs, 2
	rest 4
	note Cs, 2
	rest 4
	note Gs, 2
	rest 4
	octave 3
	note Cs, 2
	rest 4
	octave 2
	note Gs, 2
	rest 4
	note F_, 2
	rest 4
	note Gs, 2
	rest 4
	note Ds, 2
	rest 4
	note As, 2
	rest 4
	note Ds, 2
	rest 4
	note As, 2
	rest 4
	note Ds, 2
	rest 4
	note Ds, 2
	rest 4
	note F_, 2
	rest 4
	note G_, 2
	rest 4
	note Gs, 2
	rest 4
	octave 3
	note Ds, 2
	rest 4
	octave 2
	note Gs, 2
	rest 4
	octave 3
	note Ds, 2
	rest 4
	octave 2
	note As, 2
	rest 4
	note Ds, 2
	rest 4
	note F_, 2
	rest 4
	note G_, 2
	rest 4
	note Gs, 2
	rest 4
	note Ds, 2
	rest 4
	note Gs, 2
	rest 4
	note Ds, 2
	rest 4
	note Gs, 2
	rest 4
	note Ds, 2
	rest 4
	note Gs, 2
	rest 4
	octave 3
	note C_, 2
	rest 4
	note Cs, 2
	rest 4
	octave 2
	note Gs, 2
	rest 4
	octave 3
	note Cs, 2
	rest 4
	octave 2
	note Gs, 2
	rest 4
	octave 3
	note D_, 2
	rest 4
	octave 2
	note D_, 2
	rest 4
	note Ds, 2
	rest 4
	note F_, 2
	rest 4
	octave 4
	note_type 12, 1, 4
	note C_, 2
	rest 1
	octave 2
	note Ds, 2
	rest 1
	octave 4
	note D_, 2
	rest 1
	octave 2
	note Ds, 2
	rest 1
	octave 4
	note Cs, 2
	rest 1
	octave 2
	note Ds, 2
	rest 1
	octave 4
	note C_, 2
	rest 1
	octave 2
	note Ds, 2
	rest 1
	note Cs, 1
	rest 11
	note D_, 1
	rest 14
	note Ds, 2
	rest 4
	note Ds, 2
	rest 1
	note Ds, 2
	rest 1
	note Ds, 2
	rest 4
	note Ds, 1
	rest 1
	note Ds, 1
	sound_call Music_SafariZone_Ch3_branch_5
	sound_call Music_SafariZone_Ch3_branch_5
	sound_call Music_SafariZone_Ch3_branch_1
	sound_call Music_SafariZone_Ch3_branch_1
	sound_loop 0, Music_SafariZone_Ch3_loop
	
Music_SafariZone_Ch3_branch_1:
	octave 2
	note Gs, 2
	rest 2
	octave 4
	note Ds, 2
	octave 2
	note Ds, 2
	rest 2
	octave 4
	note Ds, 2
	sound_ret
	
Music_SafariZone_Ch3_branch_2:
	octave 2
	note Cs, 2
	rest 2
	octave 4
	note Cs, 2
	octave 2
	note Gs, 2
	rest 2
	octave 4
	note Cs, 2
	sound_ret
	
Music_SafariZone_Ch3_branch_3:
	octave 2
	note Cs, 2
	rest 2
	octave 4
	note Cs, 2
	octave 2
	note Cs, 2
	rest 2
	octave 4
	note Cs, 2
	sound_ret
	
Music_SafariZone_Ch3_branch_4:
	octave 2
	note Gs, 2
	rest 2
	octave 4
	note C_, 2
	octave 2
	note Gs, 2
	rest 2
	octave 4
	note C_, 2
	sound_ret
	
Music_SafariZone_Ch3_branch_5:
	note_type 6, 1, 4
	octave 2
	note Gs, 2
	rest 2
	note Gs, 1
	rest 1
	note Gs, 1
	rest 1
	note G_, 1
	rest 1
	note Gs, 1
	rest 1
	octave 3
	note Ds, 4
	rest 2
	octave 2
	note Ds, 4
	note F_, 1
	note G_, 1
	sound_ret

gbs_Music_SafariZone_Ch4:
	gbs_switch 3
Music_SafariZone_Ch4:
	toggle_noise 3
	drum_speed 12
	rest 12
Music_SafariZone_Ch4_loop:
	sound_call Music_SafariZone_Ch4_branch_5
	sound_call Music_SafariZone_Ch4_branch_1
	sound_call Music_SafariZone_Ch4_branch_1
	sound_call Music_SafariZone_Ch4_branch_2
	sound_call Music_SafariZone_Ch4_branch_2
	sound_call Music_SafariZone_Ch4_branch_5
	sound_call Music_SafariZone_Ch4_branch_2
	sound_call Music_SafariZone_Ch4_branch_3
	sound_call Music_SafariZone_Ch4_branch_5
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	sound_call Music_SafariZone_Ch4_branch_5
	sound_call Music_SafariZone_Ch4_branch_3
	sound_call Music_SafariZone_Ch4_branch_4
	sound_call Music_SafariZone_Ch4_branch_5
	sound_call Music_SafariZone_Ch4_branch_4
	sound_call Music_SafariZone_Ch4_branch_3
	sound_call Music_SafariZone_Ch4_branch_4
	sound_call Music_SafariZone_Ch4_branch_5
	sound_call Music_SafariZone_Ch4_branch_4
	drum_note 12, 3
	drum_note 1, 3
	drum_note 12, 3
	drum_note 1, 3
	drum_note 12, 3
	drum_note 1, 3
	drum_note 12, 3
	drum_note 1, 3
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 3
	drum_note 12, 3
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 3
	drum_note 12, 3
	sound_call Music_SafariZone_Ch4_branch_5
	drum_note 1, 3
	drum_note 1, 6
	drum_note 12, 3
	drum_note 12, 12
	rest 12
	sound_call Music_SafariZone_Ch4_branch_5
	sound_loop 0, Music_SafariZone_Ch4_loop
	
Music_SafariZone_Ch4_branch_1:
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 3
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 3
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 3
	sound_ret
	
Music_SafariZone_Ch4_branch_2:
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 12, 6
	sound_ret
	
Music_SafariZone_Ch4_branch_3:
	drum_note 12, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 3
	sound_ret
	
Music_SafariZone_Ch4_branch_4:
	drum_note 1, 3
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	drum_note 1, 1
	sound_ret
	
Music_SafariZone_Ch4_branch_5:
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 3
	drum_note 1, 2
	drum_note 1, 1
	drum_note 1, 3
	sound_ret
