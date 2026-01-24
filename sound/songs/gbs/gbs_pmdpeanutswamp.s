	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_PeanutSwamp
	.align 2

@ By Monstarules
@ This music is free-use
gbs_Music_PeanutSwamp:
	channel_count 4
	channel 1, Music_PeanutSwamp_Ch1
	channel 2, Music_PeanutSwamp_Ch2
	channel 3, Music_PeanutSwamp_Ch3
	channel 4, Music_PeanutSwamp_Ch4

gbs_Music_PeanutSwamp_Ch1:
	gbs_switch 0
Music_PeanutSwamp_Ch1:
	tempo 198
	volume 7, 7
	stereo_panning TRUE, TRUE
	vibrato 4, 2, 4
	octave 3
	note_type 12, 11, 7
Music_PeanutSwamp_Ch1_SUB1:
	note Gs, 8
	sound_loop 8, Music_PeanutSwamp_Ch1_SUB1
	note_type 8, 10, 2
	duty_cycle 2
	vibrato 0, 0, 0
Music_PeanutSwamp_Ch1_loop:
	pitch_offset 1
	sound_call Music_PeanutSwamp_Ch1_BR1
	sound_call Music_PeanutSwamp_Ch1_BR2
	sound_call Music_PeanutSwamp_Ch1_BR3
	sound_call Music_PeanutSwamp_Ch1_BR1
	sound_call Music_PeanutSwamp_Ch1_BR1
	sound_call Music_PeanutSwamp_Ch1_BR2
	sound_call Music_PeanutSwamp_Ch1_BR3
	duty_cycle 1
	volume_envelope 10, 7
	octave 2
	note B_, 6
	octave 3
	note Ds, 6
	duty_cycle 2
	volume_envelope 10, 2
	sound_call Music_PeanutSwamp_Ch1_BR1
	sound_call Music_PeanutSwamp_Ch1_BR2
	sound_call Music_PeanutSwamp_Ch1_BR3
	sound_call Music_PeanutSwamp_Ch1_BR1
	sound_call Music_PeanutSwamp_Ch1_BR1
	sound_call Music_PeanutSwamp_Ch1_BR2
	sound_call Music_PeanutSwamp_Ch1_BR3
	duty_cycle 1
	volume_envelope 10, 7
	octave 2
	note B_, 6
	octave 3
	note Ds, 6
	pitch_offset 0
	sound_call Music_PeanutSwamp_Ch1_BR4
	note B_, 2
	note Ds, 2
	volume_envelope 10, 3
	note E_, 4
	volume_envelope 10, 2
	note E_, 2
	note Fs, 2
	note Ds, 2
	note Fs, 2
	note Gs, 2
	note Ds, 2
	note Fs, 2
	volume_envelope 10, 3
	note Gs, 4
	note Ds, 2
	duty_cycle 1
	sound_call Music_PeanutSwamp_Ch1_BR4
	note B_, 2
	note Ds, 2
	volume_envelope 10, 3
	note E_, 6
	sound_call Music_PeanutSwamp_Ch1_BR5
	note Gs, 6
	duty_cycle 1
	sound_call Music_PeanutSwamp_Ch1_BR4
	note B_, 2
	note Ds, 2
	volume_envelope 10, 3
	note E_, 4
	note E_, 2
	sound_call Music_PeanutSwamp_Ch1_BR5
	note Gs, 4
	note Ds, 2
	duty_cycle 1
	sound_call Music_PeanutSwamp_Ch1_BR4
	octave 2
	note B_, 2
	octave 3
	note Ds, 2
	duty_cycle 1
	volume_envelope 10, 7
	octave 2
	note B_, 6
	octave 3
	note Cs, 6
	duty_cycle 2
	volume_envelope 10, 2
	note E_, 2
	octave 4
	note Cs, 2
	note Ds, 2
	volume_envelope 10, 3
	note Gs, 6
	volume_envelope 10, 2
	sound_loop 0, Music_PeanutSwamp_Ch1_loop
Music_PeanutSwamp_Ch1_BR1:
	octave 2
	note Gs, 2
	octave 3
	note Ds, 2
	note Gs, 2
	volume_envelope 10, 4
	note B_, 6
	volume_envelope 10, 2
	sound_ret
Music_PeanutSwamp_Ch1_BR2:
	octave 2
	note Fs, 2
	octave 3
	note Cs, 2
	note Fs, 2
	volume_envelope 10, 4
	note As, 6
	volume_envelope 10, 2
	octave 2
	sound_ret
Music_PeanutSwamp_Ch1_BR3:
	note E_, 2
	note B_, 2
	octave 3
	note E_, 2
	octave 2
	note Cs, 2
	note Gs, 2
	octave 3
	note Cs, 2
	sound_ret
Music_PeanutSwamp_Ch1_BR4:
	volume_envelope 10, 4
	note E_, 6
	note Fs, 6
	note Gs, 6
	duty_cycle 2
	volume_envelope 10, 2
	note Gs, 2
	sound_ret
Music_PeanutSwamp_Ch1_BR5:
	volume_envelope 10, 2
	note Fs, 2
	note Ds, 2
	note Fs, 2
	note Gs, 2
	note Ds, 2
	note Fs, 2
	volume_envelope 10, 3
	sound_ret

gbs_Music_PeanutSwamp_Ch2:
	gbs_switch 1
Music_PeanutSwamp_Ch2:
	note_type 8, 10, 2
	rest 4
	duty_cycle 2
	octave 3
	note Fs, 2
	note Gs, 2
	octave 4
	note Cs, 2
	note Ds, 2
	rest 2
	octave 3
	note Gs, 2
	note Fs, 2
	note Gs, 2
	octave 4
	note Cs, 2
	note Ds, 2
	rest 4
	octave 3
	note Fs, 2
	note Gs, 2
	octave 4
	note Cs, 2
	note Ds, 2
	rest 2
	note Cs, 2
	note Ds, 2
	note Fs, 2
	note F_, 2
	note Cs, 2
	rest 4
	octave 3
	note Fs, 2
	note Gs, 2
	octave 4
	note Cs, 2
	note Ds, 2
	rest 2
	octave 3
	note Gs, 2
	note Fs, 2
	note Gs, 2
	octave 4
	note Cs, 2
	note Ds, 2
	rest 4
	octave 3
	note Fs, 2
	note Gs, 2
	octave 4
	note Cs, 2
	note Ds, 2
	rest 2
	octave 3
	note Fs, 2
	note Gs, 2
	note B_, 2
	note As, 2
	note Fs, 2
Music_PeanutSwamp_Ch2_loop:
	duty_cycle 1
	volume_envelope 12, 3
	vibrato 10, 2, 4
	note Gs, 2
	volume_envelope 12, 1
	octave 4
	note Ds, 2
	note Ds, 2
	volume_envelope 12, 3
	note Ds, 2
	note Cs, 2
	octave 3
	note B_, 2
	volume_envelope 12, 4
	octave 4
	note Cs, 4
	volume_envelope 12, 1
	octave 3
	note Fs, 2
	volume_envelope 12, 3
	note Fs, 2
	note Gs, 2
	note As, 2
	volume_envelope 12, 4
	note B_, 4
	volume_envelope 12, 1
	note Gs, 2
	volume_envelope 12, 3
	note Fs, 2
	note Gs, 2
	note As, 2
	volume_envelope 12, 4
	note Gs, 4
	volume_envelope 12, 1
	note Ds, 2
	volume_envelope 12, 4
	note Ds, 4
	volume_envelope 12, 2
	note Ds, 2
	volume_envelope 12, 3
	note Gs, 2
	volume_envelope 12, 1
	octave 4
	note Ds, 2
	note Ds, 2
	volume_envelope 12, 3
	note Ds, 2
	note Cs, 2
	octave 3
	note B_, 2
	volume_envelope 12, 4
	octave 4
	note Cs, 4
	volume_envelope 12, 1
	octave 3
	note Fs, 2
	volume_envelope 12, 3
	note Fs, 2
	note Gs, 2
	note As, 2
	volume_envelope 12, 4
	note B_, 4
	volume_envelope 12, 1
	note Gs, 2
	volume_envelope 12, 3
	note Fs, 2
	note Gs, 2
	note As, 2
	volume_envelope 12, 7
	note Gs, 12
	duty_cycle 0
	volume_envelope 12, 3
	note Gs, 2
	volume_envelope 12, 1
	octave 4
	note Ds, 2
	note Ds, 2
	volume_envelope 12, 3
	note Ds, 2
	note Cs, 2
	octave 3
	note B_, 2
	volume_envelope 12, 4
	octave 4
	note Cs, 4
	volume_envelope 12, 1
	octave 3
	note Fs, 2
	volume_envelope 12, 3
	note Fs, 2
	note Gs, 2
	note As, 2
	volume_envelope 12, 4
	note B_, 4
	volume_envelope 12, 1
	note Gs, 2
	volume_envelope 12, 3
	note Fs, 2
	note Gs, 2
	note As, 2
	volume_envelope 12, 4
	note Gs, 4
	volume_envelope 12, 1
	note Ds, 2
	volume_envelope 12, 4
	note Ds, 4
	volume_envelope 12, 2
	note Ds, 2
	volume_envelope 12, 3
	note Gs, 2
	volume_envelope 12, 1
	octave 4
	note Ds, 2
	note Ds, 2
	volume_envelope 12, 3
	note Ds, 2
	note Cs, 2
	octave 3
	note B_, 2
	volume_envelope 12, 4
	octave 4
	note Cs, 4
	volume_envelope 12, 1
	octave 3
	note Fs, 2
	volume_envelope 12, 3
	note Fs, 2
	note Gs, 2
	note As, 2
	volume_envelope 12, 4
	note B_, 4
	volume_envelope 12, 1
	note Gs, 2
	volume_envelope 12, 3
	note Fs, 2
	note Gs, 2
	note As, 2
	volume_envelope 12, 7
	note Gs, 12
	duty_cycle 1
	volume_envelope 12, 4
	note Gs, 6
	note As, 6
	note B_, 6
	duty_cycle 0
	volume_envelope 12, 1
	octave 4
	note Cs, 2
	octave 3
	note B_, 2
	note As, 2
	volume_envelope 12, 3
	note Gs, 4
	volume_envelope 12, 1
	note B_, 2
	note As, 2
	note Gs, 2
	note Fs, 2
	volume_envelope 12, 3
	note Gs, 4
	volume_envelope 12, 1
	note Ds, 2
	volume_envelope 12, 5
	note Ds, 6
	duty_cycle 1
	volume_envelope 12, 4
	note Gs, 6
	note As, 6
	note B_, 6
	duty_cycle 0
	volume_envelope 12, 1
	octave 4
	note Cs, 2
	octave 3
	note B_, 2
	note As, 2
	volume_envelope 12, 3
	note Gs, 4
	volume_envelope 12, 1
	note B_, 2
	note As, 2
	note Gs, 2
	note Fs, 2
	volume_envelope 12, 7
	note Gs, 12
	duty_cycle 1
	volume_envelope 12, 4
	note Gs, 6
	note As, 6
	note B_, 6
	duty_cycle 0
	volume_envelope 12, 1
	octave 4
	note Cs, 2
	octave 3
	note B_, 2
	note As, 2
	volume_envelope 12, 3
	note Gs, 4
	volume_envelope 12, 1
	note B_, 2
	note As, 2
	note Gs, 2
	note Fs, 2
	volume_envelope 12, 3
	note Gs, 4
	volume_envelope 12, 1
	note Ds, 2
	volume_envelope 12, 5
	note Ds, 6
	duty_cycle 1
	volume_envelope 12, 4
	note Gs, 6
	note As, 6
	note B_, 6
	duty_cycle 0
	volume_envelope 12, 1
	octave 4
	note Cs, 2
	octave 3
	note B_, 2
	note As, 2
	volume_envelope 12, 3
	note Gs, 4
	volume_envelope 12, 1
	note B_, 2
	note As, 2
	note Gs, 2
	note Fs, 2
	duty_cycle 1
	volume_envelope 13, 7
	note Gs, 12
	sound_loop 0, Music_PeanutSwamp_Ch2_loop

gbs_Music_PeanutSwamp_Ch3:
	gbs_switch 2
Music_PeanutSwamp_Ch3:
	duty_cycle 4
	octave 2
	note_type 12, 1, 4
Music_PeanutSwamp_Ch3_SUB1:
	note Gs, 7
	rest 1
	sound_loop 7, Music_PeanutSwamp_Ch3_SUB1
	note Gs, 6
	volume_envelope 2, 4
	note Gs, 2
Music_PeanutSwamp_Ch3_loop:
	volume_envelope 1, 4
Music_PeanutSwamp_Ch3_SUB2:
	sound_call Music_PeanutSwamp_Ch3_BR1_1
	sound_call Music_PeanutSwamp_Ch3_BR1_2
	sound_call Music_PeanutSwamp_Ch3_BR1_1
	sound_call Music_PeanutSwamp_Ch3_BR1_1
	sound_call Music_PeanutSwamp_Ch3_BR1_2
	note Gs, 4
	note B_, 4
	sound_loop 2, Music_PeanutSwamp_Ch3_SUB2
	octave 3
	note E_, 4
	note Fs, 4
	note Gs, 4
	note_type 8, 2, 4
	sound_call Music_PeanutSwamp_Ch3_BR2
	note B_, 4
	octave 3
	note Cs, 2
	octave 2
	note Gs, 6
	octave 3
	note E_, 6
	note Fs, 6
	note Gs, 6
	sound_call Music_PeanutSwamp_Ch3_BR2
	note Gs, 12
	volume_envelope 1, 4
	octave 3
	note E_, 6
	note Fs, 6
	note Gs, 6
	volume_envelope 2, 4
	sound_call Music_PeanutSwamp_Ch3_BR2
	note B_, 4
	octave 3
	note Cs, 2
	octave 2
	note Gs, 6
	volume_envelope 1, 4
	octave 3
	note E_, 6
	note Fs, 6
	note Gs, 6
	volume_envelope 2, 4
	note Ds, 4
	note Fs, 2
	note E_, 4
	note Fs, 2
	note Cs, 4
	octave 2
	note As, 2
	octave 3
	note Cs, 12
	note_type 12, 1, 4
	octave 2
	sound_loop 0, Music_PeanutSwamp_Ch3_loop
Music_PeanutSwamp_Ch3_BR1_1:
	note Gs, 3
	rest 1
	note B_, 3
	rest 1
	sound_ret
Music_PeanutSwamp_Ch3_BR1_2:
	note Fs, 3
	rest 1
	note As, 3
	rest 1
	note Gs, 3
	rest 1
	note Fs, 3
	rest 1
	sound_ret
Music_PeanutSwamp_Ch3_BR2:
	note Ds, 4
	note Fs, 2
	note E_, 4
	note Fs, 2
	note Cs, 4
	note Ds, 2
	octave 2
	sound_ret

gbs_Music_PeanutSwamp_Ch4:
	gbs_switch 3
Music_PeanutSwamp_Ch4:
	toggle_noise 2
	drum_speed 8
	sound_call Music_PeanutSwamp_Ch4_BR1
	drum_note 3, 2
	sound_call Music_PeanutSwamp_Ch4_BR1
	drum_note 3, 2
	sound_call Music_PeanutSwamp_Ch4_BR1
	drum_note 3, 2
	drum_note 3, 2
	drum_note 4, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 9, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 9, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 9, 2
	drum_note 9, 2
Music_PeanutSwamp_Ch4_loop:
Music_PeanutSwamp_Ch4_SUB1:
	sound_call Music_PeanutSwamp_Ch4_BR2
	sound_call Music_PeanutSwamp_Ch4_BR2
	sound_call Music_PeanutSwamp_Ch4_BR2
	sound_call Music_PeanutSwamp_Ch4_BR3
	sound_loop 3, Music_PeanutSwamp_Ch4_SUB1
	sound_call Music_PeanutSwamp_Ch4_BR2
	sound_call Music_PeanutSwamp_Ch4_BR2
	sound_call Music_PeanutSwamp_Ch4_BR2
	drum_note 3, 2
	drum_note 2, 2
	drum_note 9, 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 3, 2
	sound_call Music_PeanutSwamp_Ch4_BR1
	drum_note 9, 2
	sound_call Music_PeanutSwamp_Ch4_BR1
	drum_note 9, 2
	sound_call Music_PeanutSwamp_Ch4_BR1
	drum_note 9, 2
	sound_call Music_PeanutSwamp_Ch4_BR1
	drum_note 9, 2
	sound_call Music_PeanutSwamp_Ch4_BR1
	drum_note 9, 2
	sound_call Music_PeanutSwamp_Ch4_BR1
	drum_note 9, 2
	sound_call Music_PeanutSwamp_Ch4_BR1
	drum_note 9, 2
	sound_call Music_PeanutSwamp_Ch4_BR1
	drum_note 9, 2
	sound_loop 0, Music_PeanutSwamp_Ch4_loop
Music_PeanutSwamp_Ch4_BR1:
	drum_note 3, 2
	rest 2
	drum_note 3, 2
	drum_note 3, 2
	rest 2
	drum_note 3, 2
	drum_note 3, 2
	rest 2
	drum_note 3, 2
	drum_note 3, 2
	drum_note 2, 2
	sound_ret
Music_PeanutSwamp_Ch4_BR2:
	drum_note 3, 2
	rest 2
	drum_note 3, 2
	drum_note 9, 2
	rest 2
	drum_note 8, 2
	sound_ret
Music_PeanutSwamp_Ch4_BR3:
	drum_note 3, 2
	drum_note 8, 2
	drum_note 9, 2
	drum_note 3, 2
	drum_note 8, 2
	drum_note 9, 2
	sound_ret
