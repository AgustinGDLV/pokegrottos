	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_VastPoniCanyon
	.align 2

@Coverted using MIDI2ASM
@Code by TriteHexagon
@Version 5.0.1 (7-Feb-2021)
@Visit github.com/TriteHexagon/Midi2ASM-Converter for up-to-date versions.

@ ============================================================================================================

gbs_Music_VastPoniCanyon:
	channel_count 4
	channel 1, Music_VastPoniCanyon_Ch1
	channel 2, Music_VastPoniCanyon_Ch2
	channel 3, Music_VastPoniCanyon_Ch3
	channel 4, Music_VastPoniCanyon_Ch4

gbs_Music_VastPoniCanyon_Ch1:
	gbs_switch 0
Music_VastPoniCanyon_Ch1:
	volume 7, 7
	duty_cycle 0
	note_type 12, 9, 5
	tempo 159
@Bar 1
	octave 4
	sound_call Music_VastPoniCanyon_Ch1_Bar1
@Bar 2
	sound_call Music_VastPoniCanyon_Ch1_Bar2
@Bar 3
	sound_call Music_VastPoniCanyon_Ch1_Bar1
@Bar 4
	sound_call Music_VastPoniCanyon_Ch1_Bar2
@Bar 5
Music_VastPoniCanyon_Ch1_loop:
	sound_call Music_VastPoniCanyon_Ch1_Bar1
@Bar 6
	sound_call Music_VastPoniCanyon_Ch1_Bar2
@Bar 7
	sound_call Music_VastPoniCanyon_Ch1_Bar1
@Bar 8
	sound_call Music_VastPoniCanyon_Ch1_Bar2
@Bar 9
	sound_call Music_VastPoniCanyon_Ch1_Bar1
@Bar 10
	sound_call Music_VastPoniCanyon_Ch1_Bar2
@Bar 11
	sound_call Music_VastPoniCanyon_Ch1_Bar1
@Bar 12
	sound_call Music_VastPoniCanyon_Ch1_Bar2
@Bar 13
	sound_call Music_VastPoniCanyon_Ch1_Bar1
@Bar 14
	sound_call Music_VastPoniCanyon_Ch1_Bar2
@Bar 15
	sound_call Music_VastPoniCanyon_Ch1_Bar1
@Bar 16
	sound_call Music_VastPoniCanyon_Ch1_Bar2
@Bar 17
	volume_envelope 7, 8
	duty_cycle 1
	note C_, 16
@Bar 18
	rest 16
	rest 4
@Bar 19
	volume_envelope 14, 7
	note E_, 1
	note D_, 1
	note C_, 1
	note D_, 3
	note E_, 2
	rest 4
@Bar 20
	volume_envelope 11, 7
	octave 3
	note G_, 4
	note Fs, 4
	note F_, 4
	note E_, 4
@Bar 21
	rest 1
	note C_, 1
	note D_, 1
	note C_, 1
	note E_, 2
	note E_, 1
	note E_, 1
	rest 1
	note E_, 1
	note G_, 1
	rest 2
	note E_, 1
	rest 3
@Bar 22
	note C_, 1
	note D_, 1
	note C_, 1
	note E_, 2
	note E_, 1
	note E_, 1
	rest 1
	note E_, 1
	note G_, 1
	rest 2
	note E_, 1
	rest 4
@Bar 23
	octave 2
	note A_, 2
	note A_, 1
	note A_, 3
	rest 1
	note B_, 1
	note B_, 1
	note B_, 2
	note G_, 1
	octave 3
	note C_, 1
	note D_, 1
@Bar 24
	note E_, 1
	note F_, 1
	note G_, 1
	octave 4
	note C_, 5
	note C_, 4
	note C_, 3
	rest 3
@Bar 25
	octave 3
	note G_, 1
	rest 1
	octave 4
	note C_, 1
	octave 3
	note G_, 1
	rest 1
	octave 4
	note C_, 2
	note C_, 1
	octave 3
	note G_, 1
	rest 1
	octave 4
	note C_, 1
	note Cs, 1
	note D_, 1
	note E_, 3
@Bar 26
	note F_, 1
	rest 1
	note G_, 1
	note A_, 1
	rest 1
	note G_, 3
	note G_, 1
	note A_, 1
	rest 1
	note A_, 1
	note F_, 1
	note D_, 1
@Bar 27
	octave 3
	note B_, 1
	rest 2
	note B_, 1
	rest 16
	rest 12
@Bar 29
	octave 4
	note B_, 1
	rest 2
	note B_, 1
	rest 16
	rest 12
@Bar 31
	octave 5
	note C_, 2
	rest 4
	octave 4
	note B_, 1
	rest 5
	note A_, 2
	rest 4
@Bar 32
	octave 5
	note C_, 1
	rest 5
	note D_, 1
	note D_, 1
	rest 2
	note D_, 1
	note D_, 1
	rest 2
@Bar 33
	volume_envelope 8, 8
	octave 4
	note C_, 16
@Bar 34
	note D_, 16
	volume_envelope 9, 5
@Bar 35
	duty_cycle 0
	sound_call Music_VastPoniCanyon_Ch1_Bar1
@Bar 36
	sound_call Music_VastPoniCanyon_Ch1_Bar2
@Bar 37
	sound_call Music_VastPoniCanyon_Ch1_Bar1
@Bar 38
	sound_call Music_VastPoniCanyon_Ch1_Bar2
	sound_loop 0, Music_VastPoniCanyon_Ch1_loop

Music_VastPoniCanyon_Ch1_Bar1:
	rest 2
	note G_, 1@
	note A_, 1
	rest 1
	note D_, 1
	note E_, 1
	rest 1
	note G_, 1
	note A_, 1
	octave 5
	note C_, 1
	octave 4
	note B_, 1
	rest 1
	note G_, 1
	note A_, 1
	rest 1
	sound_ret

Music_VastPoniCanyon_Ch1_Bar2:
	note D_, 1@
	note E_, 1
	rest 1
	note G_, 1
	note A_, 1
	octave 5
	note C_, 1
	octave 4
	note B_, 1
	note G_, 1
	rest 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note E_, 1
	rest 2
	sound_ret

@ ============================================================================================================

gbs_Music_VastPoniCanyon_Ch2:
	gbs_switch 1
Music_VastPoniCanyon_Ch2:
	duty_cycle 1
	note_type 12, 6, 8
@Bar 1
	octave 3
	note A_, 16
	note A_, 16
@Bar 3
	note G_, 16
	note G_, 16
@Bar 5
Music_VastPoniCanyon_Ch2_loop:
	vibrato 0, 0, 0
	volume_envelope 6, 8
	note F_, 8
	note Gs, 8
@Bar 6
	note G_, 16
@Bar 7
	note F_, 8
	note Gs, 8
@Bar 8
	note G_, 10
	vibrato 8, 1, 4
	volume_envelope 14, 7
	note C_, 1 
	rest 1
	note D_, 1
	note C_, 1
	note_type 6, 14, 7
	rest 2
	note D_, 1
@Bar 9
	note Ds, 9
	note_type 12, 14, 7
	note D_, 4
	note C_, 1
	octave 2
	note A_, 1
	rest 1
	octave 3
	note D_, 2
	note E_, 1
	rest 1
	note D_, 2
@Bar 10
	note Ds, 1
	note E_, 1
	rest 7
	note C_, 2
	note D_, 1
	note C_, 1
	note_type 6, 14, 7
	rest 2
	note Gs, 1
@Bar 11
	note A_, 9
	note_type 12, 14, 7
	note G_, 4
	note Ds, 1
	note D_, 1
	note C_, 1
	note D_, 2
	note C_, 2
	note D_, 2
@Bar 12
	note C_, 1
	octave 2
	note A_, 1
	rest 7
	note A_, 2
	note G_, 1
	note A_, 1
	octave 3
	note D_, 1
	note C_, 5
@Bar 13
	note_type 6, 14, 7
	note Gs, 1
	note A_, 7
	note_type 12, 14, 7
	note G_, 2
	note F_, 1
	note E_, 1
	rest 1
	note D_, 1
	note C_, 4
@Bar 14
	note_type 6, 14, 7
	note B_, 1
	octave 4
	note C_, 3
	note_type 12, 14, 7
	octave 3
	note B_, 1
	octave 4
	note C_, 1
	rest 1
	octave 3
	note G_, 3
	note A_, 1
	rest 1
	note E_, 1
	note D_, 2
	note C_, 3
@Bar 15
	octave 2
	note G_, 2
	rest 1
	octave 3
	note E_, 1
	note D_, 2
	note C_, 2
	octave 2
	note G_, 2
	rest 2
	octave 3
	note G_, 1
	note F_, 2
@Bar 16
	note E_, 1
	note C_, 4
	note F_, 1
	note E_, 2
	note A_, 1
	note G_, 1
	note F_, 1
	note E_, 1
	note F_, 1
	note G_, 1
	note B_, 1
@Bar 17
	duty_cycle 0
	rest 4
	octave 4
	note G_, 4
	note_type 6, 14, 7
	rest 1
	note B_, 1
	note_type 12, 14, 7
	octave 5
	note C_, 2
	note A_, 1
	rest 2
	note G_, 4
@Bar 18
	note A_, 1
	rest 1
	note C_, 1
	octave 4
	note G_, 1
	rest 1
	octave 5
	note C_, 5
	note Ds, 1
	note D_, 1
	note C_, 1
	note D_, 3
@Bar 19
	note E_, 1
	rest 9
	note_type 6, 14, 7
	note D_, 1
	note Ds, 1
	note_type 12, 14, 7
	note D_, 1
	note C_, 1
	note D_, 3
@Bar 20
	note C_, 1
	rest 1
	note_type 6, 14, 7
	note Gs, 1
	note A_, 3
	note_type 12, 14, 7
	note G_, 2
	note E_, 1
	note F_, 1
	note G_, 1
	note A_, 1
	rest 1
	note C_, 7
@Bar 21
	rest 1
	octave 4
	note G_, 1
	note A_, 1
	octave 5
	note C_, 1
	note E_, 2
	note D_, 1
	note C_, 1
	rest 1
	note D_, 1
	note C_, 6
@Bar 22
	rest 1
	octave 4
	note G_, 1
	note A_, 1
	octave 5
	note C_, 1
	note Ds, 2
	note D_, 1
	note C_, 1
	rest 1
	note D_, 1
	note C_, 1
	rest 1
@Bar 23
	rest 2
	octave 4
	note_type 6, 14, 7
	note B_, 1
	octave 5
	note C_, 1
	note_type 12, 14, 7
	rest 1
	octave 4
	note A_, 1
	note G_, 1
	octave 5
	note_type 6, 14, 7
	rest 2
	note E_, 1
	note F_, 3
	note_type 12, 14, 7
	note E_, 1
	note C_, 1
	octave 4
	note G_, 1
	rest 1
	note A_, 1
	octave 5
	note C_, 1
	note E_, 1
@Bar 24
	note G_, 9
	note_type 6, 14, 7
	rest 7
	note Gs, 1
	note_type 12, 14, 7
	note A_, 2
	octave 6
	volume_envelope 9, 8
	note C_, 8
	vibrato 0, 1, 4
	volume_envelope 9, 7
	note C_, 8
	vibrato 8, 1, 4
	rest 8
@Bar 26
	rest 16
	rest 3
@Bar 27
	volume_envelope 14, 7
	octave 4
	note F_, 1
	note Ds, 1
	note E_, 1
	octave 5
	note D_, 2
	octave 4
	note B_, 2
@Bar 28
	octave 5
	note C_, 1
	octave 4
	note B_, 1
	note G_, 2
	note E_, 1
	note D_, 9
	rest 7
@Bar 29
	octave 5
	note C_, 1
	octave 4
	note A_, 1
	note B_, 2
	octave 5
	note C_, 2
	note D_, 1
	note E_, 2
	octave 4
	note B_, 5
@Bar 30
	octave 5
	note C_, 1
	octave 4
	note B_, 1
	note A_, 1
	note B_, 2
	note G_, 1
	note D_, 6
@Bar 31
	octave 5
	note E_, 1
	note A_, 1
	note G_, 1
	note A_, 1
	rest 2
	note D_, 1
	note C_, 1
	note D_, 1
	note E_, 1
	rest 2
	note C_, 1
	octave 4
	note A_, 1
	note G_, 1
	octave 5
	note C_, 1
@Bar 32
	rest 2
	octave 4
	note A_, 1
	note G_, 1
	note A_, 1
	octave 5
	note C_, 1
	note D_, 1
	note Ds, 1
	note D_, 1
	note C_, 1
	octave 4
	note A_, 1
	note E_, 1
	note G_, 1
	note A_, 3
@Bar 33
	duty_cycle 1
	octave 3
	note C_, 2
	note A_, 1
	note G_, 2
	note F_, 1
	note E_, 4
	note F_, 2
	note G_, 1
	note A_, 2
	rest 1
@Bar 34
	octave 4
	note C_, 4
	octave 3
	note E_, 1
	note D_, 1
	note C_, 1
	note A_, 1
	note A_, 2
	note A_, 1
	note G_, 1
	note B_, 1
	volume_envelope 12, 8
	note A_, 11
@Bar 35
	volume_envelope 12, 7
	note A_, 8
@Bar 36
	rest 16
@Bar 37
	rest 16
@Bar 38
	rest 16
	sound_loop 0, Music_VastPoniCanyon_Ch2_loop
	sound_ret

@ ============================================================================================================

gbs_Music_VastPoniCanyon_Ch3:
	gbs_switch 2
Music_VastPoniCanyon_Ch3:
	note_type 12, 1, 6
@Bar 1
	octave 1
	note A_, 16
	note A_, 16
@Bar 3
	note G_, 16
	note G_, 16
@Bar 5
Music_VastPoniCanyon_Ch3_loop:
	octave 3
	sound_call Music_VastPoniCanyon_Ch3_Bar5
@Bar 6
	sound_call Music_VastPoniCanyon_Ch3_Bar6
	sound_call Music_VastPoniCanyon_Ch3_Bar6_P2
@Bar 7
	sound_call Music_VastPoniCanyon_Ch3_Bar5
@Bar 8
	sound_call Music_VastPoniCanyon_Ch3_Bar6
	sound_call Music_VastPoniCanyon_Ch3_Bar6_P2
@Bar 9
	sound_call Music_VastPoniCanyon_Ch3_Bar5
@Bar 10
	sound_call Music_VastPoniCanyon_Ch3_Bar6
	sound_call Music_VastPoniCanyon_Ch3_Bar6_P2
@Bar 11
	sound_call Music_VastPoniCanyon_Ch3_Bar5
@Bar 12
	sound_call Music_VastPoniCanyon_Ch3_Bar6
	sound_call Music_VastPoniCanyon_Ch3_Bar6_P2
@Bar 13
	sound_call Music_VastPoniCanyon_Ch3_Bar5
@Bar 14
	sound_call Music_VastPoniCanyon_Ch3_Bar6
	rest 1
	octave 3
	note A_, 1
	note G_, 1
	note F_, 1
	note F_, 3
@Bar 15
	note F_, 1
	note F_, 1
	rest 5
	note E_, 3
	note E_, 4
@Bar 16
	note A_, 1
	rest 1
	note G_, 1
	note A_, 1
	rest 1
	note C_, 1
	note D_, 1
	note Ds, 1
	note E_, 1
	note A_, 3
	note G_, 4
@Bar 17
	note D_, 3
	note D_, 1
	rest 2
	octave 2
	note A_, 5
	octave 3
	note D_, 2
	octave 2
	note A_, 1
	octave 3
	note E_, 1
	note F_, 1
@Bar 18
	note E_, 1
	rest 2
	note E_, 2
	note G_, 2
	note E_, 3
	note E_, 2
	note B_, 2
	note G_, 1
	note E_, 1
@Bar 19
	note A_, 3
	note A_, 1
	rest 1
	note E_, 1
	note D_, 1
	octave 2
	note A_, 2
	octave 3
	note A_, 2
	note E_, 2
	note A_, 1
	note E_, 1
	note Gs, 1
@Bar 20
	note A_, 4
	note Gs, 4
	note G_, 4
	note Fs, 4
@Bar 21
	note F_, 3
	note F_, 1
	rest 2
	note F_, 4
	note C_, 3
	note F_, 1
	note A_, 1
	note C_, 1
@Bar 22
	note E_, 3
	note E_, 1
	rest 2
	octave 2
	note E_, 4
	note G_, 3
	octave 3
	note C_, 1
	octave 2
	note G_, 1
	note E_, 1
@Bar 23
	note D_, 2
	octave 3
	note D_, 1
	rest 2
	note D_, 1
	rest 1
	note F_, 1
	octave 2
	note E_, 2
	octave 3
	note E_, 1
	rest 2
	note E_, 1
	rest 1
	note E_, 1
@Bar 24
	note F_, 1
	rest 2
	note F_, 2
	octave 2
	note A_, 1
	octave 3
	note C_, 1
	note E_, 1
	note F_, 3
	note F_, 3
	note C_, 2
@Bar 25
	note G_, 1
	rest 2
	note G_, 3
	note F_, 1
	note E_, 1
	note G_, 8
@Bar 26
	octave 2
	note G_, 1
	octave 3
	note D_, 1
	note C_, 1
	octave 2
	note G_, 4
	octave 3
	note G_, 2
	note A_, 1
	note G_, 3
	octave 2
	note E_, 1
	note G_, 1
	note Gs, 1
@Bar 27
	note A_, 1
	rest 2
	note A_, 1
	rest 16
	rest 9
@Bar 28
	note E_, 3
@Bar 29
	note A_, 1
	rest 2
	note A_, 1
	rest 16
	rest 9
@Bar 30
	note A_, 1
	note G_, 1
	note E_, 1
@Bar 31
	note A_, 2
	rest 4
	note E_, 1
	rest 5
	note D_, 2
	rest 4
@Bar 32
	note D_, 1
	rest 5
	note E_, 1
	note E_, 1
	rest 2
	note E_, 1
	note E_, 1
	note A_, 1
	note G_, 1
@Bar 33
	note D_, 16
@Bar 34
	note E_, 16
@Bar 35
Music_VastPoniCanyon_Ch3_Bar35:
	rest 2
	note G_, 1@
	note A_, 1
	rest 1
	note D_, 1
	note E_, 1
	rest 1
	note G_, 1
	note A_, 1
	octave 3
	note C_, 1
	octave 2
	note B_, 1
	rest 1
	note G_, 1
	note A_, 1
	rest 1
@Bar 36
	note D_, 1@
	note E_, 1
	rest 1
	note G_, 1
	note A_, 1
	octave 3
	note C_, 1
	octave 2
	note B_, 1
	note G_, 1
	rest 1
	note A_, 1
	note G_, 1
	rest 1
	note A_, 1
	note E_, 1
	rest 2
	sound_loop 2, Music_VastPoniCanyon_Ch3_Bar35
	sound_loop 0, Music_VastPoniCanyon_Ch3_loop

Music_VastPoniCanyon_Ch3_Bar5:
	note F_, 2@
	note E_, 1
	note F_, 1
	rest 5
	note E_, 1
	rest 2
	note E_, 2
	rest 2
	sound_ret

Music_VastPoniCanyon_Ch3_Bar6:
	note A_, 1@
	rest 1
	note G_, 1
	note A_, 1
	rest 1
	note C_, 1
	note D_, 1
	note Ds, 1
	note E_, 1
	note A_, 1
	octave 2
	note A_, 1
	sound_ret

Music_VastPoniCanyon_Ch3_Bar6_P2:
	rest 2@
	octave 3
	note A_, 1
	note G_, 1
	rest 1
	sound_ret

@ ============================================================================================================

gbs_Music_VastPoniCanyon_Ch4:
	gbs_switch 3
Music_VastPoniCanyon_Ch4:
	toggle_noise 3
	drum_speed 12
@Bar 1
	rest 16
	rest 16
	rest 16
	rest 10
@Bar 4
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
@Bar 5
Music_VastPoniCanyon_Ch4_loop:
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 6
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 7
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 8
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 9
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 10
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 11
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 12
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 13
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 14
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 15
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 16
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 17
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 18
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 19
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 20
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 21
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 22
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 23
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 24
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 25
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 26
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 27
Music_VastPoniCanyon_Ch4_Bar27_28:
	drum_note 4, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 4, 1
	drum_note 8, 1
	drum_note 4, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 11, 1
	drum_note 11, 1
	drum_note 8, 1
@Bar 28
	drum_note 4, 1
	drum_note 8, 1
	drum_note 12, 4
	drum_note 8, 1
	drum_note 8, 1
	drum_note 4, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 11, 1
	drum_note 11, 1
	drum_note 8, 1
	sound_loop 2, Music_VastPoniCanyon_Ch4_Bar27_28
@Bar 31
	drum_note 7, 2
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 7, 2
	drum_note 4, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 7, 2
@Bar 32
	drum_note 4, 1
	drum_note 8, 1
	drum_note 7, 2
	drum_note 3, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 4, 1
	drum_note 8, 1
	drum_note 7, 2
	drum_note 3, 1
	drum_note 7, 2
	drum_note 8, 1
@Bar 33
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 34
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 35
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 36
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 37
	sound_call Music_VastPoniCanyon_Ch4_Bar2
@Bar 38
	sound_call Music_VastPoniCanyon_Ch4_Bar2
	sound_loop 0, Music_VastPoniCanyon_Ch4_loop

Music_VastPoniCanyon_Ch4_Bar2:
	drum_note 4, 1@
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 4, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 8, 1
	sound_ret

Music_VastPoniCanyon_Ch4_Bar27:
	drum_note 4, 1@
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 8, 1
	drum_note 4, 1
	drum_note 8, 1
	drum_note 4, 1
	drum_note 8, 1
	drum_note 3, 1
	drum_note 11, 1
	drum_note 11, 1
	drum_note 8, 1
	sound_ret
