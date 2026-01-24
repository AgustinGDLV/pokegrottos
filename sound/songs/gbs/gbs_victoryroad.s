	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_VictoryRoad
	.align 2

gbs_Music_VictoryRoad:
	channel_count 4
	channel 1, Music_VictoryRoad_Ch1
	channel 2, Music_VictoryRoad_Ch2
	channel 3, Music_VictoryRoad_Ch3
	channel 4, Music_VictoryRoad_Ch4

gbs_Music_VictoryRoad_Ch1:
	gbs_switch 0
Music_VictoryRoad_Ch1:
	tempo 143
	volume 7, 7
	stereo_panning TRUE, TRUE
	duty_cycle 2
	pitch_offset 2
	octave 2
	note_type 12, 4, -7
	note Ds, 8
	note E_, 8
	duty_cycle 1
	volume_envelope 12, 2
	note F_, 4
	rest 4
	note F_, 4
	rest 4
	note F_, 4
	note F_, 4
	note_type 8, 5, 2
	note Ds, 2
	volume_envelope 6, 2
	note Ds, 2
	volume_envelope 7, 2
	note Ds, 2
	volume_envelope 8, 2
	note Ds, 2
	volume_envelope 9, 2
	note Ds, 2
	volume_envelope 10, 2
	note E_, 2
	volume_envelope 12, 2
	note F_, 6
	rest 6
	note F_, 6
	rest 6
	note F_, 6
	note F_, 6
	volume_envelope 9, 2
	note Cs, 1
	note D_, 1
	note Ds, 1
	note E_, 1
	note F_, 1
	note Fs, 1
	note G_, 1
	note Gs, 1
	note A_, 1
	note As, 1
	note B_, 1
	octave 3
	note C_, 1
Music_VictoryRoad_Ch1_loop:
	volume_envelope 9, 4
	note E_, 4
	note Cs, 2
	note Gs, 6
	note Cs, 4
	octave 2
	note Gs, 2
	octave 3
	note E_, 6
	note D_, 4
	note Gs, 2
	note Fs, 6
	octave 2
	note Gs, 6
	octave 3
	note Fs, 6
	volume_envelope 12, 0
	note E_, 9
	volume_envelope 12, 7
	note E_, 15
	volume_envelope 5, 2
	octave 2
	note Gs, 2
	volume_envelope 6, 2
	note Fs, 2
	volume_envelope 7, 2
	note Gs, 2
	volume_envelope 8, 2
	octave 3
	note D_, 2
	volume_envelope 9, 2
	octave 2
	note Gs, 2
	volume_envelope 10, 2
	octave 3
	note D_, 2
	volume_envelope 12, 5
	note D_, 6
	volume_envelope 12, 2
	note Fs, 2
	note D_, 2
	note Fs, 2
	volume_envelope 10, 0
	octave 1
	note Cs, 2
	note D_, 2
	note E_, 2
	note D_, 2
	note Cs, 2
	note C_, 2
	note Cs, 2
	note D_, 2
	note E_, 2
	note Cs, 2
	note D_, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note Fs, 2
	note E_, 2
	note D_, 2
	note Cs, 2
	note D_, 2
	note E_, 2
	note Fs, 2
	note E_, 2
	note D_, 2
	note Cs, 2
	note Cs, 2
	note D_, 2
	note E_, 2
	note D_, 2
	note Cs, 2
	note C_, 2
	note Cs, 2
	note D_, 2
	note E_, 2
	note Cs, 2
	note D_, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note Fs, 2
	note E_, 2
	note D_, 2
	note Cs, 2
	note D_, 2
	note E_, 2
	note Fs, 2
	note Gs, 6
	rest 6
	volume_envelope 12, 3
	octave 3
	note G_, 6
	note Fs, 6
	note Ds, 6
	note E_, 6
	octave 2
	note B_, 6
	octave 3
	note Cs, 6
	note E_, 6
	rest 6
	pitch_offset 1
	volume_envelope 12, 1
	octave 2
	note A_, 2
	octave 3
	note Cs, 2
	note E_, 2
	note Gs, 2
	note E_, 2
	note Cs, 2
	octave 2
	note A_, 2
	octave 3
	note C_, 2
	note Ds, 2
	volume_envelope 12, 4
	octave 4
	note Cs, 6
	octave 3
	note As, 6
	octave 4
	note Cs, 6
	note E_, 6
	note Ds, 6
	octave 3
	note Ds, 6
	note Ds, 12
	volume_envelope 9, 4
	note Cs, 4
	octave 2
	note Gs, 2
	octave 3
	note Cs, 6
	octave 2
	note Gs, 2
	octave 3
	note Cs, 2
	octave 2
	note Gs, 2
	note Cs, 2
	note Gs, 2
	octave 3
	note Cs, 2
	octave 2
	note B_, 4
	note Fs, 2
	note B_, 6
	note Fs, 2
	note B_, 2
	note Fs, 2
	octave 1
	note B_, 2
	octave 2
	note Fs, 2
	note B_, 2
	volume_envelope 12, 4
	octave 3
	note Gs, 4
	note Fs, 2
	note E_, 6
	volume_envelope 10, 4
	note Ds, 6
	note Cs, 6
	duty_cycle 0
	volume_envelope 13, 4
	note A_, 2
	note E_, 2
	note Cs, 2
	octave 2
	note A_, 2
	octave 3
	note Cs, 2
	note A_, 2
	note Fs, 6
	note B_, 6
	duty_cycle 1
	volume_envelope 9, 4
	note Cs, 4
	octave 2
	note Gs, 2
	octave 3
	note Cs, 6
	octave 2
	note Gs, 2
	octave 3
	note Cs, 2
	octave 2
	note Gs, 2
	note Cs, 2
	note Gs, 2
	octave 3
	note Cs, 2
	octave 2
	note B_, 4
	note Fs, 2
	note B_, 6
	note Fs, 2
	note B_, 2
	note Fs, 2
	octave 1
	note B_, 2
	octave 2
	note Fs, 2
	note B_, 2
	volume_envelope 12, 4
	octave 3
	note Cs, 2
	note C_, 2
	note Cs, 8
	note E_, 6
	note Fs, 6
	duty_cycle 0
	volume_envelope 13, 4
	note A_, 2
	note E_, 2
	note Cs, 2
	octave 2
	note A_, 2
	octave 3
	note Cs, 2
	note A_, 2
	note Fs, 6
	octave 4
	note Cs, 6
	duty_cycle 1
	volume_envelope 13, 2
	octave 3
	note Ds, 6
	rest 6
	note Ds, 6
	rest 6
	note Ds, 6
	note Ds, 6
	volume_envelope 5, 2
	note Cs, 2
	volume_envelope 6, 2
	note Cs, 2
	volume_envelope 7, 2
	note Cs, 2
	volume_envelope 8, 2
	note Cs, 2
	volume_envelope 9, 2
	note Cs, 2
	volume_envelope 10, 2
	note D_, 2
	volume_envelope 13, 2
	note Ds, 6
	rest 6
	note Ds, 6
	rest 6
	note Ds, 6
	note Ds, 6
	volume_envelope 9, 2
	octave 2
	note Cs, 1
	note D_, 1
	note Ds, 1
	note E_, 1
	note F_, 1
	note Fs, 1
	note G_, 1
	note Gs, 1
	note A_, 1
	note As, 1
	note B_, 1
	octave 3
	note C_, 1
	sound_loop 0, Music_VictoryRoad_Ch1_loop

gbs_Music_VictoryRoad_Ch2:
	gbs_switch 1
Music_VictoryRoad_Ch2:
	octave 4
	note_type 12, 4, -7
	note Ds, 8
	note E_, 8
	volume_envelope 12, 2
	note F_, 4
	rest 4
	note F_, 4
	rest 4
	note F_, 4
	note F_, 4
	note_type 8, 5, 2
	note Ds, 2
	volume_envelope 6, 2
	note Ds, 2
	volume_envelope 7, 2
	note Ds, 2
	volume_envelope 8, 2
	note Ds, 2
	volume_envelope 9, 2
	note Ds, 2
	volume_envelope 10, 2
	note E_, 2
	volume_envelope 12, 2
	note F_, 6
	rest 6
	note F_, 6
	rest 6
	note F_, 6
	note F_, 6
	volume_envelope 9, 2
	note Gs, 1
	note G_, 1
	note Fs, 1
	note F_, 1
	note E_, 1
	note Ds, 1
	note D_, 1
	note Cs, 1
	note C_, 1
	octave 3
	note B_, 1
	note As, 1
	note A_, 1
Music_VictoryRoad_Ch2_loop:
	volume_envelope 12, 4
	vibrato 8, 2, 4
	note Cs, 10
	note E_, 2
	volume_envelope 12, 5
	note Gs, 12
	volume_envelope 12, 4
	note D_, 10
	note Fs, 2
	volume_envelope 12, 5
	note B_, 4
	volume_envelope 12, 0
	note As, 1
	note B_, 1
	volume_envelope 12, 7
	note A_, 4
	note Fs, 2
	volume_envelope 12, 0
	note Gs, 9
	volume_envelope 12, 7
	note Gs, 15
	volume_envelope 5, 2
	note D_, 2
	volume_envelope 6, 2
	octave 2
	note A_, 2
	volume_envelope 7, 2
	octave 3
	note D_, 2
	volume_envelope 8, 2
	note Fs, 2
	volume_envelope 9, 2
	note D_, 2
	volume_envelope 10, 2
	note Fs, 2
	volume_envelope 12, 2
	note A_, 2
	volume_envelope 12, 1
	note A_, 1
	note A_, 1
	volume_envelope 12, 2
	note A_, 2
	note A_, 2
	note Fs, 2
	octave 4
	note D_, 2
	duty_cycle 1
	volume_envelope 10, 5
	octave 3
	note Gs, 4
	note E_, 2
	octave 4
	note Cs, 6
	octave 3
	note E_, 4
	note Cs, 2
	note Gs, 6
	note A_, 4
	note Fs, 2
	octave 4
	note D_, 4
	note D_, 1
	note Cs, 1
	octave 3
	note A_, 6
	note B_, 2
	octave 4
	note Cs, 2
	note D_, 2
	note E_, 10
	note D_, 1
	note E_, 1
	note Cs, 10
	note E_, 2
	octave 3
	note A_, 10
	note Fs, 1
	note B_, 1
	octave 4
	note E_, 6
	note D_, 6
	volume_envelope 10, 2
	octave 2
	note Cs, 6
	volume_envelope 12, 3
	octave 4
	note E_, 6
	note Ds, 6
	note C_, 6
	note Cs, 6
	octave 3
	note Gs, 6
	note As, 6
	octave 4
	note C_, 6
	octave 2
	note Cs, 6
	volume_envelope 12, 4
	octave 4
	note E_, 2
	note Cs, 2
	octave 3
	note Gs, 2
	octave 4
	note Ds, 2
	note C_, 2
	octave 3
	note Gs, 2
	octave 4
	note D_, 2
	octave 3
	note B_, 2
	note Fs, 2
	octave 4
	note E_, 6
	note Cs, 6
	note E_, 6
	note G_, 6
	note Gs, 6
	octave 3
	note Gs, 6
	note Gs, 2
	volume_envelope 12, 1
	note G_, 1
	note Gs, 1
	volume_envelope 12, 4
	note Gs, 2
	note Gs, 2
	note As, 2
	octave 4
	note C_, 2
	volume_envelope 10, 1
	vibrato 0, 0, 0
	note Cs, 1
	octave 3
	note Gs, 1
	note E_, 1
	note Ds, 1
	note Cs, 1
	note C_, 1
	note Cs, 1
	note Ds, 1
	note E_, 1
	note Gs, 1
	octave 4
	note Cs, 1
	note E_, 1
	note Gs, 1
	note As, 1
	note B_, 1
	note As, 1
	note Gs, 1
	note Fs, 1
	note E_, 1
	note Ds, 1
	note Cs, 1
	octave 3
	note B_, 1
	note As, 1
	note B_, 1
	octave 4
	note Ds, 1
	octave 3
	note B_, 1
	note Fs, 1
	note E_, 1
	note Ds, 1
	note Cs, 1
	octave 2
	note B_, 1
	octave 3
	note Cs, 1
	note Ds, 1
	note Fs, 1
	note Gs, 1
	note As, 1
	note B_, 1
	octave 4
	note Cs, 1
	note Ds, 1
	note E_, 1
	note Fs, 1
	note Gs, 1
	note As, 1
	note B_, 1
	octave 5
	note Cs, 1
	octave 4
	note B_, 1
	note Fs, 1
	note Ds, 1
	octave 3
	note As, 1
	note Gs, 1
	note Fs, 1
	note E_, 1
	note Ds, 1
	note Cs, 1
	note Ds, 1
	note E_, 1
	note Fs, 1
	note Gs, 1
	note As, 1
	note B_, 1
	octave 4
	note Cs, 1
	note Ds, 1
	note F_, 1
	note Fs, 1
	note Gs, 1
	note A_, 1
	note As, 1
	note A_, 1
	note Gs, 1
	note Fs, 1
	note E_, 1
	note Ds, 1
	volume_envelope 12, 4
	note Cs, 4
	octave 3
	note Gs, 2
	octave 4
	note Cs, 6
	note Ds, 6
	note Fs, 6
	volume_envelope 10, 1
	note Cs, 1
	octave 3
	note B_, 1
	note A_, 1
	note Gs, 1
	note Fs, 1
	note E_, 1
	note Ds, 1
	note E_, 1
	note Fs, 1
	note Gs, 1
	note A_, 1
	note B_, 1
	octave 4
	note Cs, 1
	note Ds, 1
	note E_, 1
	note Fs, 1
	note E_, 1
	note Ds, 1
	note Cs, 1
	octave 3
	note B_, 1
	note A_, 1
	note Gs, 1
	note Fs, 1
	note E_, 1
	note B_, 1
	note A_, 1
	note Gs, 1
	note Fs, 1
	note E_, 1
	note Fs, 1
	note Gs, 1
	note A_, 1
	note B_, 1
	octave 4
	note Cs, 1
	note Ds, 1
	note E_, 1
	note Fs, 1
	note Gs, 1
	note A_, 1
	note B_, 1
	note A_, 1
	note Fs, 1
	note E_, 1
	note Ds, 1
	note Cs, 1
	octave 3
	note B_, 1
	note A_, 1
	note Gs, 1
	volume_envelope 9, 4
	octave 2
	note Gs, 4
	note Fs, 2
	note Gs, 6
	note Fs, 2
	note Gs, 2
	note Fs, 2
	note Cs, 2
	note Fs, 2
	note Gs, 2
	duty_cycle 0
	volume_envelope 13, 2
	octave 4
	note Cs, 2
	note C_, 2
	note Cs, 2
	note Cs, 4
	note D_, 2
	note Ds, 2
	note D_, 2
	note Ds, 2
	note Cs, 2
	note Ds, 2
	note Fs, 2
	note Gs, 6
	rest 6
	note Gs, 6
	rest 6
	note Gs, 6
	note Gs, 6
	volume_envelope 5, 2
	note Fs, 2
	volume_envelope 6, 2
	note Fs, 2
	volume_envelope 7, 2
	note Fs, 2
	volume_envelope 8, 2
	note Fs, 2
	volume_envelope 9, 2
	note Fs, 2
	volume_envelope 10, 2
	note G_, 2
	volume_envelope 13, 2
	note Gs, 6
	rest 6
	note Gs, 6
	rest 6
	note Gs, 6
	note Gs, 6
	volume_envelope 9, 2
	note B_, 1
	note As, 1
	note A_, 1
	note Gs, 1
	note G_, 1
	note Fs, 1
	note F_, 1
	note E_, 1
	note Ds, 1
	note D_, 1
	note Cs, 1
	note C_, 1
	octave 3
	sound_loop 0, Music_VictoryRoad_Ch2_loop

gbs_Music_VictoryRoad_Ch3:
	gbs_switch 2
Music_VictoryRoad_Ch3:
	duty_cycle 6
	pitch_offset 1
	octave 2
	note_type 12, 1, 6
	note G_, 8
	note Fs, 8
	note F_, 3
	rest 5
	note F_, 3
	rest 5
	note F_, 3
	rest 1
	note F_, 3
	rest 1
	octave 3
	note_type 8, 1, 6
	note F_, 2
	note C_, 2
	note F_, 2
	note B_, 4
	octave 4
	note C_, 2
	octave 2
	note_type 12, 1, 6
	note F_, 3
	rest 5
	note F_, 3
	rest 5
	note F_, 3
	rest 1
	note F_, 3
	rest 1
	octave 3
	note Gs, 3
	volume_envelope 2, 6
	note Gs, 1
	volume_envelope 3, 6
	note Gs, 1
	volume_envelope 2, 6
	note Gs, 1
	volume_envelope 1, 6
	note Gs, 2
Music_VictoryRoad_Ch3_loop:
	octave 2
	note_type 8, 1, 6
	note Cs, 2
	note D_, 2
	note E_, 2
	note Gs, 6
	note Cs, 2
	note D_, 2
	note E_, 2
	note Cs, 2
	note D_, 2
	note E_, 2
	note D_, 2
	note E_, 2
	note Fs, 2
	note A_, 6
	note D_, 2
	note E_, 2
	note Fs, 2
	note D_, 2
	note E_, 2
	note Fs, 2
	note Cs, 2
	note D_, 2
	note E_, 2
	note Cs, 2
	note D_, 2
	note E_, 2
	note Cs, 2
	note D_, 2
	note E_, 2
	note D_, 2
	note Cs, 2
	octave 1
	note B_, 2
	volume_envelope 2, 6
	octave 2
	note D_, 2
	note E_, 2
	note Fs, 2
	note E_, 2
	note D_, 2
	note Cs, 2
	volume_envelope 1, 6
	note D_, 2
	note E_, 2
	note Fs, 2
	note E_, 2
	note Ds, 2
	note Cs, 2
	vibrato 0, 2, 5
	octave 4
	note Cs, 4
	note E_, 2
	note Gs, 10
	note G_, 1
	note Fs, 1
	note E_, 6
	note D_, 4
	note Fs, 2
	note A_, 4
	note A_, 1
	note Gs, 1
	note Fs, 6
	note B_, 2
	note A_, 2
	note Fs, 2
	note Gs, 10
	note Fs, 1
	note Gs, 1
	note E_, 10
	note Gs, 2
	note Fs, 10
	note D_, 1
	note Fs, 1
	note B_, 6
	note A_, 6
	vibrato 0, 0, 0
	octave 2
	note Cs, 6
	octave 3
	note Cs, 2
	note E_, 2
	note Gs, 2
	octave 4
	note Cs, 2
	octave 3
	note Gs, 2
	note E_, 2
	note Cs, 2
	note E_, 2
	note Gs, 2
	note As, 2
	note G_, 2
	note E_, 2
	note Cs, 2
	note E_, 2
	note Gs, 2
	octave 4
	note Cs, 2
	octave 3
	note As, 1
	note A_, 1
	note As, 2
	note Gs, 2
	note Gs, 2
	note Gs, 2
	octave 2
	note Cs, 6
	octave 3
	note Cs, 2
	note E_, 2
	note Gs, 2
	octave 4
	note Cs, 2
	octave 3
	note Gs, 2
	note E_, 2
	note Cs, 2
	note E_, 2
	note Gs, 2
	note As, 2
	note G_, 2
	note E_, 2
	note Cs, 2
	note E_, 2
	note G_, 2
	note B_, 2
	note G_, 2
	note E_, 2
	note Cs, 2
	note G_, 2
	octave 4
	note Cs, 2
	note Ds, 6
	octave 3
	note Ds, 6
	note Ds, 2
	note Ds, 1
	note D_, 1
	note Ds, 2
	note Ds, 2
	note F_, 2
	note G_, 2
	duty_cycle 2
	volume_envelope 1, 2
	vibrato 8, 2, 4
	octave 5
	note Cs, 10
	note E_, 2
	note Gs, 12
	note Ds, 10
	note Fs, 2
	note B_, 6
	note A_, 4
	note Fs, 2
	note_type 12, 1, 2
	note Gs, 12
	volume_envelope 2, 2
	note Gs, 4
	note_type 8, 1, 2
	note A_, 4
	note E_, 2
	note A_, 6
	note B_, 6
	octave 6
	note Ds, 1
	note Cs, 1
	note C_, 1
	octave 5
	note B_, 1
	note As, 1
	note Gs, 1
	note Cs, 2
	note C_, 2
	note Cs, 2
	note E_, 4
	note Fs, 2
	note Gs, 12
	note Ds, 2
	note D_, 2
	note Ds, 2
	note Fs, 4
	note Gs, 2
	note B_, 6
	note A_, 4
	note Fs, 2
	note Gs, 2
	note G_, 2
	note Gs, 14
	volume_envelope 2, 2
	note Gs, 6
	volume_envelope 1, 2
	note A_, 2
	note Gs, 2
	note A_, 2
	note A_, 4
	note As, 2
	note B_, 2
	note As, 2
	note B_, 2
	octave 6
	note Cs, 2
	note Ds, 2
	note E_, 2
	duty_cycle 6
	octave 2
	note_type 12, 1, 6
	note Gs, 3
	rest 5
	note Gs, 3
	rest 5
	note Gs, 3
	rest 1
	note Gs, 3
	rest 1
	octave 3
	note_type 8, 1, 6
	note Gs, 2
	note Ds, 2
	note Gs, 2
	octave 4
	note D_, 4
	note Ds, 2
	octave 2
	note_type 12, 1, 6
	note Gs, 3
	rest 5
	note Gs, 3
	rest 5
	note Gs, 3
	rest 1
	note Gs, 3
	rest 1
	note B_, 3
	volume_envelope 2, 6
	note B_, 1
	volume_envelope 3, 6
	note B_, 1
	volume_envelope 2, 6
	note B_, 1
	volume_envelope 1, 6
	note B_, 2
	sound_loop 0, Music_VictoryRoad_Ch3_loop

gbs_Music_VictoryRoad_Ch4:
	gbs_switch 3
Music_VictoryRoad_Ch4:
	drum_speed 12
	rest 16
	toggle_noise 3
Music_VictoryRoad_Ch4_loop:
	drum_speed 8
	drum_note 12, 4
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 2
	drum_note 2, 1
	rest 1
	drum_note 2, 2
	drum_note 12, 4
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 2
	drum_note 2, 1
	rest 1
	drum_note 2, 2
	drum_note 12, 4
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 2
	drum_note 2, 1
	rest 1
	drum_note 2, 2
	drum_note 1, 2
	rest 10
	drum_note 12, 4
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 2
	drum_note 2, 1
	rest 1
	drum_note 2, 2
	drum_note 12, 4
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 2
	drum_note 2, 1
	rest 1
	drum_note 2, 2
	drum_note 12, 4
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 2
	drum_note 2, 1
	rest 1
	drum_note 2, 2
	drum_note 1, 2
	rest 4
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 2, 1
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 1, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 4, 5
	rest 15
	drum_note 4, 2
	drum_note 4, 2
	drum_note 12, 5
	rest 16
	rest 3
	drum_note 4, 5
	rest 15
	drum_note 4, 2
	drum_note 4, 2
	drum_note 12, 5
	rest 13
	drum_note 4, 5
	rest 1
	drum_note 4, 5
	rest 1
	drum_note 4, 5
	rest 1
	drum_note 4, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 1, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 3, 2
	drum_note 1, 2
	drum_note 2, 1
	drum_note 2, 1
	drum_note 3, 2
	drum_note 4, 2
	drum_note 4, 2
	drum_note 4, 2
	sound_loop 0, Music_VictoryRoad_Ch4_loop
