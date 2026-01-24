	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_RoadToReversalMountain
	.align 2

gbs_Music_RoadToReversalMountain:
	channel_count 4
	channel 1, Music_RoadToReversalMountain_Ch1
	channel 2, Music_RoadToReversalMountain_Ch2
	channel 3, Music_RoadToReversalMountain_Ch3
	channel 4, Music_RoadToReversalMountain_Ch4

gbs_Music_RoadToReversalMountain_Ch1:
	gbs_switch 0
Music_RoadToReversalMountain_Ch1:
	tempo 140
	volume 7, 7
	duty_cycle 3
	pitch_offset 2
	vibrato 16, 2, 2
	note_type 12, 6, 0
	sound_call Music_RoadToReversalMountain_Ch1_branch_1
	sound_call Music_RoadToReversalMountain_Ch1_branch_1
	octave 3
	note A_, 15
	volume_envelope 6, 7
	note A_, 3
	volume_envelope 6, 0
	note A_, 12
	note As, 6
	sound_call Music_RoadToReversalMountain_Ch1_branch_1
	sound_call Music_RoadToReversalMountain_Ch1_branch_1
	note D_, 15
	volume_envelope 6, 7
	note D_, 3
	rest 16
	rest 16
	rest 16
	rest 6
	sound_loop 0, Music_RoadToReversalMountain_Ch1
	
Music_RoadToReversalMountain_Ch1_branch_1:
	octave 2
	note A_, 12
	note As, 6
	note A_, 12
	note G_, 6
	sound_ret

gbs_Music_RoadToReversalMountain_Ch2:
	gbs_switch 1
Music_RoadToReversalMountain_Ch2:
	duty_cycle 0
	pitch_offset 1
	vibrato 28, 1, 2
	note_type 6, 10, 4
	rest 4
	octave 3
	note D_, 2
	note Cs, 2
	note D_, 4
	note Cs, 1
	note D_, 1
	note Cs, 2
	octave 2
	note A_, 8
	note Gs, 4
	note A_, 4
	note As, 8
	octave 3
	note Cs, 2
	note C_, 2
	note Cs, 4
	note Cs, 1
	note C_, 1
	note Cs, 2
	octave 2
	note A_, 8
	note As, 4
	octave 3
	note C_, 4
	note Cs, 8
	note Ds, 2
	note D_, 2
	note Ds, 4
	note D_, 4
	note Ds, 1
	note D_, 1
	note Cs, 10
	octave 2
	note As, 4
	note A_, 8
	octave 3
	note Ds, 2
	note D_, 2
	note Ds, 4
	note D_, 4
	note C_, 12
	note Cs, 4
	note Ds, 4
	note D_, 1
	note Ds, 1
	note_type 12, 10, 0
	note D_, 6
	volume_envelope 10, 7
	note D_, 11
	duty_cycle 3
	volume_envelope 7, 0
	note C_, 12
	volume_envelope 7, 7
	note C_, 6
	duty_cycle 0
	octave 2
	note_type 6, 10, 4
	note Gs, 4
	note As, 4
	octave 3
	note C_, 4
	note C_, 1
	note Cs, 7
	note C_, 1
	note Cs, 1
	note C_, 2
	octave 2
	note As, 4
	note A_, 4
	note As, 4
	octave 3
	note C_, 4
	note Cs, 4
	note Cs, 1
	note D_, 3
	note Ds, 8
	note D_, 4
	note Cs, 4
	note C_, 4
	note Cs, 4
	note D_, 4
	note Ds, 4
	note D_, 4
	note_type 8, 10, 4
	note Cs, 1
	note D_, 1
	note Cs, 1
	note_type 12, 10, 6
	octave 2
	note A_, 10
	volume_envelope 10, 4
	octave 3
	note C_, 2
	note Cs, 2
	note C_, 2
	note_type 8, 10, 4
	octave 2
	note B_, 1
	octave 3
	note C_, 1
	octave 2
	note B_, 1
	note_type 12, 10, 7
	note Gs, 10
	note A_, 16
	rest 16
	rest 4
	octave 3
	note_type 3, 10, 4
	note A_, 8
	note A_, 4
	note G_, 4
	note A_, 8
	octave 4
	note C_, 8
	note Cs, 1
	note D_, 1
	note Cs, 1
	note D_, 1
	note Cs, 12
	note_type 6, 10, 4
	note Ds, 12
	note D_, 4
	octave 3
	note A_, 2
	note G_, 2
	note A_, 4
	octave 4
	note C_, 4
	note Cs, 8
	note C_, 1
	note Cs, 1
	note C_, 10
	sound_loop 0, Music_RoadToReversalMountain_Ch2

gbs_Music_RoadToReversalMountain_Ch3:
	gbs_switch 2
Music_RoadToReversalMountain_Ch3:
	note_type 12, 2, 5
	octave 2
	sound_call Music_RoadToReversalMountain_Ch3_branch_1
	note D_, 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	sound_call Music_RoadToReversalMountain_Ch3_branch_1
	note C_, 2
	note G_, 1
	rest 1
	note G_, 1
	rest 1
	sound_loop 0, Music_RoadToReversalMountain_Ch3
	
Music_RoadToReversalMountain_Ch3_branch_1:
	note D_, 2
	rest 2
	note A_, 2
	rest 2
	note A_, 2
	rest 2
	sound_ret
	
gbs_Music_RoadToReversalMountain_Ch4:
	gbs_switch 3
Music_RoadToReversalMountain_Ch4:
	stereo_panning FALSE, TRUE
	toggle_noise 3
	drum_speed 12
Music_RoadToReversalMountain_Ch4_loop:
	drum_note 1, 4
	drum_note 4, 2
	drum_note 4, 2
	drum_note 1, 2
	drum_note 4, 1
	drum_note 4, 1
	drum_note 1, 2
	drum_note 1, 2
	drum_note 4, 2
	sound_loop 0, Music_RoadToReversalMountain_Ch4_loop
