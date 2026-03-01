	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_MtCoronet
	.align 2

gbs_Music_MtCoronet:
	channel_count 3
	channel 1, Music_MtCoronet_Ch1
	channel 2, Music_MtCoronet_Ch2
	channel 3, Music_MtCoronet_Ch3

gbs_Music_MtCoronet_Ch1:
	gbs_switch 0
Music_MtCoronet_Ch1:
	tempo 124
	volume 7, 7
	duty_cycle 0
	pitch_offset 1
	note_type 12, 8, 7
	octave 3
	note F_, 4
	octave 4
	note D_, 2
Music_MtCoronet_Ch1_loop:
	octave 3
	note G_, 6
	octave 4
	note D_, 4
	octave 3
	note F_, 6
	note G_, 4
	octave 4
	note D_, 4
	octave 3
	note F_, 6
	octave 4
	note D_, 2
	octave 3
	note F_, 6
	octave 4
	note C_, 4
	octave 3
	note Ds, 6
	note F_, 4
	octave 4
	note C_, 4
	octave 3
	note Ds, 6
	octave 4
	note C_, 2
	sound_loop 4, Music_MtCoronet_Ch1_loop
	octave 3
	note G_, 6
	octave 4
	note D_, 4
	octave 3
	note F_, 6
	note G_, 4
	octave 4
	note D_, 4
	octave 3
	note F_, 6
	octave 4
	note D_, 2
	octave 3
	note F_, 6
	octave 4
	note C_, 4
	octave 3
	note Ds, 6
	note F_, 4
	octave 4
	note C_, 4
	octave 3
	note Ds, 2
	octave 5
	note G_, 1
	note Gs, 1
	note G_, 1
	note Ds, 1
	note C_, 2
	octave 4
	note As, 2
Music_MtCoronet_Ch1_branch_2:
	volume_envelope 8, 7
	octave 2
	note G_, 4
	octave 3
	note D_, 4
	octave 2
	note F_, 6
	note G_, 4
	octave 3
	note D_, 4
	octave 2
	note F_, 6
	octave 3
	note D_, 2
	octave 2
	note F_, 6
	octave 3
	note C_, 4
	octave 2
	note Ds, 6
	note F_, 4
	octave 3
	note C_, 4
	octave 2
	note Ds, 6
	octave 3
	note C_, 2
	octave 2
	note G_, 6
	octave 3
	note D_, 4
	octave 2
	note F_, 6
	note G_, 4
	octave 3
	note D_, 4
	octave 2
	note F_, 6
	octave 3
	note D_, 2
	octave 2
	note F_, 6
	octave 3
	note C_, 4
	octave 2
	note Ds, 6
	note F_, 4
	octave 3
	note C_, 4
	octave 2
	note Ds, 2
	octave 5
	volume_envelope 8, 5
	note G_, 1
	note Gs, 1
	note G_, 1
	note Ds, 1
	volume_envelope 10, 5
	note C_, 1
	octave 4
	note As, 1
	note Gs, 1
	note G_, 1
	note C_, 1
	note F_, 1
	octave 5
	note C_, 1
	note F_, 1
	note Gs, 4
	volume_envelope 8, 7
	octave 2
	note F_, 6
	note G_, 4
	octave 3
	note D_, 4
	octave 2
	note F_, 6
	octave 3
	note D_, 2
	octave 2
	note F_, 6
	octave 3
	note C_, 4
	octave 2
	note Ds, 6
	note F_, 4
	octave 3
	note C_, 4
	octave 2
	note Ds, 6
	octave 3
	note C_, 2
	octave 2
	note G_, 6
	octave 3
	note D_, 4
	octave 2
	note F_, 6
	note G_, 4
	octave 3
	note D_, 4
	octave 2
	note F_, 6
	octave 3
	note D_, 4
	note_type 8, 8, 2
	duty_cycle 1
	octave 6
	note C_, 2
	octave 5
	note F_, 2
	note G_, 2
	octave 6
	note C_, 2
	note Cs, 2
	note G_, 2
	note F_, 1
	note E_, 1
	note Cs, 2
	note C_, 2
	octave 5
	note G_, 2
	note F_, 1
	note E_, 1
	note Cs, 2
	note C_, 2
	octave 4
	note G_, 2
	note F_, 2
	octave 5
	note C_, 2
	note D_, 1
	note F_, 1
	note G_, 2
	note F_, 2
	octave 6
	note C_, 2
	note D_, 2
	note C_, 1
	octave 5
	note As, 1
	note G_, 2
	note F_, 2
	octave 6
	note C_, 2
	octave 5
	note F_, 2
	note G_, 1
	note As, 1
	octave 6
	note C_, 2
	note Ds, 2
	note G_, 2
	note F_, 2
	note Ds, 2
	note C_, 1
	octave 5
	note As, 1
	note G_, 2
	note F_, 2
	note Ds, 2
	note C_, 2
	octave 4
	note G_, 2
	note F_, 2
	note As, 2
	octave 5
	note C_, 1
	note D_, 1
	note E_, 2
	note G_, 1
	note A_, 1
	note As, 1
	note B_, 1
	octave 6
	note C_, 1
	note D_, 1
	note E_, 1
	note D_, 1
	note C_, 1
	octave 5
	note As, 1
	note G_, 2
	note_type 12, 8, 4
	octave 4
	note F_, 1
	octave 3
	note F_, 1
	note Gs, 1
	octave 4
	note C_, 1
	note F_, 2
	note C_, 1
	octave 3
	note Gs, 1
	note Fs, 3
	octave 4
	note Cs, 1
	note F_, 3
	note Fs, 1
	note G_, 1
	note As, 1
	note Cs, 1
	note F_, 1
	octave 3
	note As, 1
	octave 4
	note Cs, 1
	octave 3
	note G_, 1
	note As, 1
	note C_, 1
	note Cs, 1
	note Ds, 1
	note Ds, 1
	note C_, 1
	octave 2
	note G_, 1
	octave 3
	note E_, 1
	note G_, 1
	octave 4
	note F_, 1
	octave 5
	note Gs, 1
	octave 4
	note C_, 1
	note F_, 3
	octave 3
	note Gs, 1
	octave 4
	note C_, 1
	octave 3
	note Fs, 1
	note As, 2
	octave 4
	note Cs, 1
	note F_, 3
	note Fs, 1
	note G_, 1
	note As, 1
	note Cs, 1
	note F_, 1
	octave 3
	note As, 1
	octave 4
	note Cs, 1
	octave 3
	note G_, 1
	note As, 1
	note F_, 1
	note G_, 1
	note C_, 1
	note F_, 1
	octave 2
	note As, 1
	octave 3
	note C_, 1
	note F_, 1
	note G_, 1
	volume_envelope 10, 4
	note As, 1
	octave 4
	note Cs, 1
	note E_, 1
	note G_, 1
	note As, 3
	volume_envelope 8, 4
	note As, 3
	volume_envelope 6, 4
	note As, 3
	volume_envelope 4, 4
	note As, 3
	rest 16
	note_type 12, 8, 7
	octave 3
	duty_cycle 0
	note F_, 4
	octave 4
	note D_, 2
	sound_loop 0, Music_MtCoronet_Ch1_loop
@	notetype $6, $84
@	octave 5
@	note G_, 1
@	note F_, 1
@	note E_, 1
@	note C#, 1
@	tempo 168
@	notetype $C, $87
@	note C#, 10
@	notetype $6, $87
@	tempo 172
@	note E_, 1
@	note C#, 1
@	octave 4
@	note A#, 1
@	intensity $80
@	note G_, 1
@	notetype $C, $80
@	note G_, 9
@	tempo 188
@	intensity $87
@	note G_, 6
@	note A#, 1
@	note G_, 1
@	note E_, 1
@	note C#, 1
@	octave 3
@	tempo 198
@	intensity $80
@	note A#, 8
@	intensity $87
@	note A#, 6
	
	
gbs_Music_MtCoronet_Ch2:
	gbs_switch 1
Music_MtCoronet_Ch2:
	pitch_offset 1
	duty_cycle 0
	note_type 12, 4, 5
	rest 4
Music_MtCoronet_Ch2_loop:
	note_type 12, 4, 5
	octave 4
	note C_, 2
	rest 2
	rest 4
	octave 4
	note C_, 6
	volume_envelope 8, 5
	note D_, 8
	volume_envelope 4, 5
	note C_, 10
	note C_, 8
	octave 3
	note As, 6
	octave 4
	volume_envelope 8, 5
	note C_, 8
	octave 3
	volume_envelope 4, 5
	note As, 6
	octave 5
	volume_envelope 8, 5
	note G_, 1
	note Gs, 1
	note G_, 1
	note Ds, 1
	note C_, 2
	octave 4
	note As, 2
	octave 5
	note C_, 10
	octave 4
	note D_, 8
	volume_envelope 4, 5
	note C_, 10
	note C_, 8
	octave 3
	note As, 6
	octave 4
	volume_envelope 8, 5
	note C_, 8
	octave 3
	volume_envelope 4, 5
	note As, 10
	note As, 8
	octave 4
	note C_, 6
	volume_envelope 8, 5
	note D_, 8
	volume_envelope 4, 5
	note C_, 10
	note C_, 8
	octave 3
	note As, 6
	octave 4
	volume_envelope 8, 5
	note C_, 8
	octave 3
	volume_envelope 4, 5
	note As, 2
	octave 5
	volume_envelope 8, 5
	note G_, 1
	note Gs, 1
	note G_, 1
	note F_, 1
	note Ds, 1
	note F_, 1
	note C_, 2
	note C_, 1
	note Ds, 1
	note C_, 1
	octave 4
	note As, 1
	note G_, 1
	note F_, 1
	note As, 1
	note B_, 1
	octave 5
	note C_, 6
	octave 4
	note D_, 8
	volume_envelope 4, 5
	note C_, 10
	note C_, 8
	octave 3
	note As, 6
	octave 4
	volume_envelope 8, 5
	note C_, 8
	octave 3
	volume_envelope 4, 5
	note As, 10
	note As, 8
	octave 4
	note C_, 6
	octave 4
	note D_, 8
	volume_envelope 4, 5
	note C_, 10
	note C_, 8
	octave 3
	note As, 6
	octave 4
	volume_envelope 8, 5
	note C_, 8
	octave 3
	volume_envelope 4, 5
	note As, 10
	note As, 4
Music_MtCoronet_Ch2_branch_2:
	volume_envelope 8, 5
	duty_cycle 1
	octave 2
	note F_, 4
	octave 4
	note C_, 4
	octave 3
	note As, 2
	note F_, 4
	note D_, 4
	note D_, 4
	note D_, 2
	note G_, 1
	note Gs, 1
	note F_, 2
	note D_, 4
	volume_envelope 4, 5
	note D_, 4
	volume_envelope 8, 5
	octave 2
	note Fs, 1
	octave 3
	note C_, 5
	note A_, 1
	note As, 1
	note Ds, 4
	note F_, 2
	note C_, 10
	octave 3
	note E_, 1
	note F_, 3
	octave 3
	note F_, 1
	note G_, 1
	note Ds, 1
	note C_, 1
	octave 2
	note G_, 2
	note F_, 2
	note C_, 8
	rest 2
	octave 3
	@;;; problem section
	note C_, 6
	rest 4
	note C_, 4
	rest 4
	octave 2
	note As, 6
	note As, 8
	note As, 8
	note As, 6
	@;;;
	octave 3
	note F_, 1
	octave 4
	note C_, 1
	note F_, 1
	octave 5
	note C_, 1
	octave 4
	note C_, 4
	octave 3
	note Gs, 2
	note F_, 2
	octave 4
	note C_, 2
	rest 2
	note D_, 2
	note C_, 2
	rest 2
	note Ds, 1
	note E_, 3
	note D_, 2
	octave 3
	volume_envelope 8, 5
	note D_, 4
	rest 4
	note C_, 4
	rest 2
	note C_, 4
	rest 3
	note G_, 1
	note As, 2
	note G_, 2
	note Ds, 2
	note G_, 2
	note Ds, 2
	note C_, 2
	rest 6
	note D_, 6
	note D_, 6
	octave 2
	note As, 2
	octave 3
	note D_, 2
	note C_, 2
	note Ds, 1
	note E_, 3
	note D_, 6
	octave 4
	duty_cycle 3
	volume_envelope 11, 5
	@quarter
	note C_, 4
	note C_, 1
	note C_, 1
	note C_, 1
	note C_, 1
	@triplet
	note_type 8, 11, 5
	note C_, 4
	note C_, 2
	note C_, 2
	note C_, 2
	note C_, 2
	rest 2
	octave 3
	note F_, 2
	note G_, 2
	rest 2
	note As, 2
	octave 4
	note C_, 2
	rest 2
	note C_, 2
	note D_, 2
	rest 6
	@quartet
	note_type 12, 11, 5
	note C_, 1
	note C_, 1
	note C_, 1
	note C_, 1
	@triplet
	note_type 8, 11, 5
	note C_, 4
	note C_, 2
	note C_, 2
	note C_, 2
	note C_, 2
	note C_, 4
	note C_, 2
	@quartet
	note_type 12, 11, 5
	rest 2
	note C_, 1
	note Ds, 1
	note C_, 1
	octave 3
	note As, 1
	note G_, 1
	note E_, 1
	@triplet
	note_type 8, 11, 5
	note As, 2
	note As, 2
	note As, 2
	octave 4
	note C_, 4
	note C_, 2
	note_type 12, 8, 5
	octave 5
	note F_, 1
	octave 4
	note F_, 1
	note Gs, 1
	octave 5
	note C_, 1
	note F_, 2
	note C_, 1
	octave 4
	note Gs, 1
	note Fs, 3
	octave 5
	note Cs, 1
	note F_, 3
	note Fs, 1
	note G_, 1
	note As, 1
	note Cs, 1
	note F_, 1
	octave 4
	note As, 1
	octave 5
	note Cs, 1
	octave 4
	note G_, 1
	note As, 1
	note C_, 1
	note Cs, 1
	note Ds, 1
	note Cs, 1
	note C_, 1
	octave 3
	note G_, 1
	octave 4
	note E_, 1
	note G_, 1
	octave 5
	note F_, 1
	octave 4
	note Gs, 1
	octave 5
	note C_, 1
	note F_, 3
	octave 4
	note Gs, 1
	octave 5
	note C_, 1
	octave 4
	note Fs, 1
	note As, 2
	octave 5
	note Cs, 1
	note F_, 3
	note Fs, 1
	note G_, 1
	note As, 1
	note Cs, 1
	note F_, 1
	octave 4
	note As, 1
	octave 5
	note Cs, 1
	octave 4
	note G_, 1
	note As, 1
	note F_, 1
	note G_, 1
	note C_, 1
	note F_, 1
	octave 3
	note As, 1
	octave 4
	note C_, 1
	note F_, 1
	note G_, 1
	volume_envelope 10, 4
	note As, 1
	octave 5
	note Cs, 1
	note E_, 1
	note G_, 1
	note As, 3
	volume_envelope 8, 4
	note As, 3
	volume_envelope 6, 4
	note As, 3
	volume_envelope 4, 4
	note As, 3
	rest 4
	volume_envelope 1, -7
	duty_cycle 0
	octave 3
	note Gs, 6
	volume_envelope 7, 0
	note Gs, 4
	volume_envelope 7, 7
	note Gs, 6
	sound_loop 0, Music_MtCoronet_Ch2_loop
@	octave 4
@	intensity $80
@	note G_, 6
@	intensity $87
@	note G_, 6
@	note E_, 1
@	note G_, 1
@	note E_, 1
@	intensity $60
@	note C#, 9
@	intensity $67
@	note C#, 6
@	octave 3
@	intensity $80
@	note G_, 6
@	intensity $87
@	note G_, 6
@	note E_, 1
@	note G_, 1
@	note E_, 1
@	intensity $60
@	note C#, 9
@	intensity $67
@	note C#, 6
	
	
	@note __, 4
	@octave 4
	@note C_, 6
	@intensity $85
	@note D_, 8
	@intensity $45
	@note C_, 10
	@note C_, 8
	@octave 3
	@note A#, 6
	@octave 4
	@intensity $85
	@note C_, 8
	@octave 3
	@intensity $45
	@note A#, 10
	@note A#, 4

gbs_Music_MtCoronet_Ch3:
	gbs_switch 2
Music_MtCoronet_Ch3:
	stereo_panning TRUE, TRUE
Music_MtCoronet_Ch3_branch_0:
	note_type 12, 1, 4
	vibrato 22, 2, 3
	rest 6
	rest 16
	rest 16
	rest 16
	rest 16
Music_MtCoronet_Ch3_branch_1:
	rest 12
	octave 2
	note F_, 2
	octave 3
	note C_, 2
	note G_, 2
	note C_, 2
	note F_, 2
	note As, 2
	note Gs, 2
	note G_, 1
	note Gs, 1
	note G_, 2
	note F_, 2
	note E_, 2
	note Ds, 3
	note F_, 3
	note As, 2
	note C_, 3
	note Ds, 3
	note F_, 2
	octave 2
	note As, 3
	octave 3
	note C_, 3
	note Ds, 2
	octave 2
	note Gs, 4
	note As, 4
	note F_, 1
	note Ds, 1
	note C_, 4
	volume_envelope 2, 4
	note C_, 10
	note C_, 6
	rest 2
	volume_envelope 2, 5
	octave 4
	note C_, 5
	rest 1
	note C_, 1
	rest 1
	octave 5
	volume_envelope 1, 5
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	volume_envelope 2, 5
	note C_, 1
	rest 1
	note C_, 1
	rest 1
	volume_envelope 3, 5
	note C_, 1
	rest 1
	note C_, 2
	rest 16
	volume_envelope 1, 4
	octave 3
	note Ds, 2
	note E_, 2
	note F_, 8
	rest 2
	note Gs, 2
	note G_, 2
	note F_, 2
	note Gs, 1
	note G_, 1
	note C_, 2
	note F_, 2
	octave 4
	note C_, 2
	octave 3
	note As, 2
	note Gs, 6
	note As, 2
	note F_, 6
	note As, 2
	note Ds, 6
	note F_, 1
	note Ds, 1
	octave 2
	note As, 6
	octave 3
	note C_, 2
	octave 2
	note Gs, 4
	note G_, 2
	note Fs, 2
	note F_, 4
	note G_, 2
	note D_, 4
	volume_envelope 2, 4
	note D_, 12
	rest 16
	rest 8
	rest 12
	volume_envelope 1, 4
	octave 4
	note C_, 2
	octave 3
	note As, 2
	note F_, 2
	octave 4
	note C_, 2
	note Gs, 4
	rest 2
	octave 2
	note F_, 2
	octave 3
	note C_, 2
	note G_, 2
	note C_, 2
	note F_, 2
	note As, 2
	note Gs, 2
	note G_, 4
	note F_, 4
	note Ds, 3
	note F_, 3
	note As, 2
	note C_, 3
	note Ds, 3
	note Gs, 2
	octave 2
	note As, 3
	octave 3
	note C_, 3
	note Ds, 2
	note G_, 4
	note E_, 1
	note F_, 3
	rest 8
	volume_envelope 2, 5
	note A_, 2
	rest 1
	note F_, 1
	note As, 6
	note Gs, 8
	rest 2
	octave 4
	volume_envelope 1, 5 
	note D_, 1
	note D_, 1
	note D_, 1
	note D_, 1
	note Cs, 2
	note D_, 2
	rest 6
	note C_, 6
	octave 3
	note As, 2
	octave 4
	note C_, 2
	rest 8
	volume_envelope 1, 4
	octave 4
	note C_, 2
	octave 3
	note As, 2
	note F_, 2
	octave 4
	note C_, 2
	note Gs, 4
	rest 2
	octave 3
	note F_, 2
	octave 4
	note C_, 2
	note G_, 2
	note C_, 2
	note F_, 2
	note As, 2
	note Gs, 2
	octave 5
	note C_, 2
	octave 4
	note B_, 1
	note As, 1
	note Gs, 3
	rest 1
	note G_, 6
	note Fs, 1
	note F_, 1
	note Ds, 4
	note F_, 2
	note G_, 4
	note As, 2
	rest 2
	octave 5
	note Ds, 2
	octave 4
	note As, 4
	octave 5
	note C_, 2
	note Cs, 2
	octave 4
	note As, 2
	octave 5
	note C_, 6
	volume_envelope 2, 4
	note C_, 2
	rest 6
	volume_envelope 1, 1
	octave 2
	note F_, 2
	rest 1
	note F_, 2
	rest 1
	octave 3
	note E_, 1
	note F_, 1
	rest 1
	octave 2
	note F_, 2
	rest 1
	octave 3
	note Ds, 1
	note F_, 1
	octave 2
	note As, 1
	octave 3
	note C_, 1
	volume_envelope 1, 4
	note Cs, 16
	note D_, 16
	note Ds, 16
	note E_, 16
	rest 2
	octave 2
	note Gs, 1
	octave 3
	note C_, 1
	note F_, 4
	note F_, 12
	octave 2
	note G_, 1
	octave 3
	note C_, 1
	note F_, 1
	note G_, 1
	note As, 4
	octave 4
	note C_, 4
	rest 2
	octave 2
	note Gs, 1
	octave 3
	note C_, 1
	note F_, 4
	note F_, 12
	octave 2
	note G_, 1
	octave 3
	note C_, 1
	note F_, 1
	note G_, 1
	note As, 4
	octave 4
	note C_, 4
	note Cs, 4
	rest 12
	rest 16
	sound_loop 0, Music_MtCoronet_Ch3_branch_0
