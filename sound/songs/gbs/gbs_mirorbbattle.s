	.include "asm/macros.inc"
	.section .rodata
	.global gbs_Music_MirorBBattle
	.align 2

@Coverted using MIDI2ASM
@Coded by TriteHexagon.
@Version 1.1. (3-Aug-2019)
@https://github.com/TriteHexagon/Midi2ASM-Converter

@ ============================================================================================================

gbs_Music_MirorBBattle:
	channel_count 4
	channel 1, Music_MirorBBattle_Ch1
	channel 2, Music_MirorBBattle_Ch2
	channel 3, Music_MirorBBattle_Ch3
	channel 4, Music_MirorBBattle_Ch4

gbs_Music_MirorBBattle_Ch1:
	gbs_switch 0
Music_MirorBBattle_Ch1:
	volume 7, 7
	duty_cycle 2
	note_type 12, 10, 6
	vibrato 4, 10, 8
	pitch_offset 2
	tempo 163
@Bar 1
	octave 1
	sound_call Music_MirorBBattle_Ch1_bass1
@Bar 5
	transpose 0, 5
	sound_call Music_MirorBBattle_Ch1_oscillate_octave
	transpose 0, 7
	sound_call Music_MirorBBattle_Ch1_oscillate_octave
@Bar 6
	transpose 0, 8
	sound_call Music_MirorBBattle_Ch1_oscillate_octave
	transpose 0, 10
	sound_call Music_MirorBBattle_Ch1_oscillate_octave
@Bar 7
	transpose 0, 5
	sound_call Music_MirorBBattle_Ch1_oscillate_octave
	transpose 0, 7
	sound_call Music_MirorBBattle_Ch1_oscillate_octave
@Bar 6
	transpose 0, 8
	sound_call Music_MirorBBattle_Ch1_oscillate_octave
	transpose 0, 10
	sound_call Music_MirorBBattle_Ch1_oscillate_octave
@Bar 9
	transpose 0, 0
	sound_call Music_MirorBBattle_Ch1_Bar9
@Bar 13
	transpose 0, 5
	sound_call Music_MirorBBattle_Ch1_oscillate_octave
	transpose 0, 7
	sound_call Music_MirorBBattle_Ch1_oscillate_octave
	transpose 0, 8
	sound_call Music_MirorBBattle_Ch1_oscillate_octave
	transpose 0, 10
	sound_call Music_MirorBBattle_Ch1_oscillate_octave
@Bar 15
	transpose 0, 0
	sound_call Music_MirorBBattle_Ch1_bass2
@Bar 19
	octave 2
	sound_call Music_MirorBBattle_Ch1_bass3
@Bar 23
Music_MirorBBattle_Ch1_Gs:
	note G_, 2
	sound_loop 16, Music_MirorBBattle_Ch1_Gs

	sound_loop 0, Music_MirorBBattle_Ch1

Music_MirorBBattle_Ch1_bass1:
@Bar 1
	note F_, 2
	note G_, 2
	rest 2
	note G_, 1
	note G_, 1
	note F_, 2
	note G_, 2
	rest 2
	note G_, 2
@Bar 2
	note As, 2
	rest 2
	note F_, 2
	note G_, 8
	note D_, 2
	sound_loop 2, Music_MirorBBattle_Ch1_bass1
	sound_ret

Music_MirorBBattle_Ch1_bass2:
	duty_cycle 3
	note As, 2
	octave 3
	note C_, 2
	rest 2
	note C_, 1
	note C_, 1
	octave 2
	note As, 2
	octave 3
	note C_, 2
	rest 2
	note C_, 2
@Bar 16
	note Ds, 2
	rest 2
	octave 2
	note As, 2
	octave 3
	note C_, 6
	rest 2
	octave 2
	note G_, 2
	sound_loop 2, Music_MirorBBattle_Ch1_bass2
	sound_ret

Music_MirorBBattle_Ch1_bass3:
	note Ds, 2
	note F_, 2
	rest 2
	note F_, 1
	note F_, 1
	note Ds, 2
	note F_, 2
	rest 2
	note F_, 2
@Bar 20
	note Gs, 2
	rest 2
	note Ds, 2
	note F_, 6
	rest 2
	note C_, 2
	sound_loop 2, Music_MirorBBattle_Ch1_bass3
	sound_ret

Music_MirorBBattle_Ch1_oscillate_octave:
	octave 1
	note C_, 2
	octave 2
	note C_, 2
	sound_loop 2, Music_MirorBBattle_Ch1_oscillate_octave
	sound_ret

Music_MirorBBattle_Ch1_Bar9:
	note C_, 3
	note C_, 2
	octave 3
	note C_, 3
	octave 2
	note C_, 1
	note C_, 1
	rest 2
	note G_, 1
	octave 3
	note C_, 1
	octave 2
	note G_, 1
	note C_, 1
@Bar 10
	note C_, 2
	note C_, 1
	rest 2
	octave 3
	note C_, 2
	octave 2
	note C_, 1
	note C_, 1
	rest 3
	note Cs, 4
	sound_loop 2, Music_MirorBBattle_Ch1_Bar9
	sound_ret

@ ============================================================================================================

gbs_Music_MirorBBattle_Ch2:
	gbs_switch 1
Music_MirorBBattle_Ch2:
	note_type 12, 12, 7
	@vibrato $08, $24
	pitch_offset 1
@Bar 1
	rest 16
	rest 16
Music_MirorBBattle_Ch2_loop:
	duty_cycle 1
	rest 16
	rest 16
@Bar 5
	octave 3
Music_MirorBBattle_Ch2_Bar5:
	note Ds, 1
	note F_, 2
	note Gs, 2
	note F_, 3
	note Ds, 1
	note F_, 2
	note Gs, 5
	sound_loop 4, Music_MirorBBattle_Ch2_Bar5
@Bar 9
	sound_call Music_MirorBBattle_Ch2_Bar9
	note Ds, 5
@Bar 10
	sound_call Music_MirorBBattle_Ch2_Bar9
	note Ds, 5
@Bar 11
	sound_call Music_MirorBBattle_Ch2_Bar9
	note Ds, 5
@Bar 12
	sound_call Music_MirorBBattle_Ch2_Bar9
	rest 5
@Bar 13
	duty_cycle 0
	volume_envelope 12, 8
	octave 4
	note F_, 2
	rest 2
	note Ds, 2
	rest 2
	note D_, 2
	rest 2
	octave 3
	note As, 2
	rest 2
@Bar 14
	octave 4
	note C_, 2
	note C_, 2
	note Ds, 2
	note Ds, 1
	note F_, 8
	rest 16
	rest 16
	rest 1
@Bar 17
	volume_envelope 5, 8
	note G_, 4
	volume_envelope 5, -7
	note G_, 10
	volume_envelope 12, 7
@Bar 18
	note G_, 6
	volume_envelope 12, 8
	note F_, 2
	rest 2
	note Ds, 2
	rest 2
	note C_, 2
	rest 2
@Bar 19
	volume_envelope 5, 8
	note C_, 4
	volume_envelope 5, -7
	note C_, 10
	volume_envelope 12, 7
@Bar 20
	note C_, 6
	volume_envelope 12, 8
	note Ds, 2
	rest 2
	note F_, 2
	rest 2
	note Ds, 2
	rest 2
@Bar 21
	volume_envelope 5, 8
	note C_, 4
	volume_envelope 5, -7
	note C_, 10
	volume_envelope 12, 7
	note C_, 6
@Bar 22
	volume_envelope 12, 8
	note Ds, 2
	rest 2
	note F_, 2
	rest 2
	note Ds, 2
	rest 2
@Bar 23
	volume_envelope 6, 8
	note G_, 4
	volume_envelope 6, -7
	note G_, 10
	volume_envelope 12, 7
	note G_, 6
@Bar 24
	volume_envelope 12, 8
	note G_, 2
	rest 2
	note As, 2
	rest 2
	note G_, 2
	rest 2
@Bar 25
	duty_cycle 0
	volume_envelope 5, 8
	note C_, 8
	volume_envelope 5, -7
	note C_, 6
	volume_envelope 10, 7
	note C_, 16
	rest 2
	volume_envelope 12, 7
	sound_loop 0, Music_MirorBBattle_Ch2_loop

Music_MirorBBattle_Ch2_Bar9:
	octave 2
	note As, 1
	octave 3
	note C_, 2
	note Ds, 2
	note C_, 3
	octave 2
	note As, 1
	octave 3
	note C_, 2
	sound_ret

@ ============================================================================================================

gbs_Music_MirorBBattle_Ch3:
	gbs_switch 2
Music_MirorBBattle_Ch3:
	note_type 12, 1, 6
	vibrato 0, 0, 0
@Bar 1
Music_MirorBBattle_Ch3_Silence:
	rest 16
	sound_loop 6, Music_MirorBBattle_Ch3_Silence
	rest 2
@Bar 7
	octave 5
	note G_, 2
	note F_, 2
	note D_, 2
	note C_, 2
	note C_, 2
	note C_, 1
	note D_, 3
@Bar 8
	note Ds, 4
	note F_, 4
	note G_, 4
	note Gs, 4
@Bar 9
	rest 16
	rest 16
@Bar 11
	volume_envelope 1, 5
	note G_, 16
	note G_, 1
@Bar 12
	note F_, 1
	note D_, 1
	note C_, 1
	octave 4
	note As, 1
	octave 5
	note D_, 1
	note C_, 1
	octave 4
	note As, 1
	note G_, 1
	octave 5
	note C_, 1
	octave 4
	note As, 1
	note G_, 1
	note F_, 1
	note As, 1
	note G_, 1
	note F_, 1
@Bar 13
	note Ds, 1
	note C_, 1
	note Ds, 1
	note F_, 2
	note Ds, 1
	note F_, 1
	note G_, 2
	note G_, 1
	note As, 1
	octave 5
	note C_, 2
	octave 4
	note As, 1
	note G_, 1
	note F_, 1
@Bar 14
	note G_, 1
	note As, 1
	octave 5
	note C_, 1
	octave 4
	note G_, 1
	note As, 1
	octave 5
	note C_, 1
	note D_, 1
	note Ds, 1
	note F_, 8
@Bar 15
	octave 4
	note As, 2
	octave 5
	note C_, 2
	rest 2
	note C_, 1
	note C_, 1
	octave 4
	note As, 2
	octave 5
	note C_, 2
	rest 2
	note C_, 2
@Bar 16
	note Ds, 2
	rest 2
	octave 4
	note As, 2
	octave 5
	note C_, 6
	rest 2
	octave 4
	note G_, 2
@Bar 17
	note As, 2
	octave 5
	note C_, 2
	rest 2
	note C_, 1
	note C_, 1
	octave 4
	note As, 2
	octave 5
	note C_, 2
	rest 2
	note C_, 2
@Bar 18
	note Ds, 2
	rest 2
	octave 4
	note As, 2
	octave 5
	note C_, 6
	rest 2
	note C_, 2
@Bar 19
	octave 4
	note Ds, 2
	note F_, 2
	rest 2
	note F_, 1
	note F_, 1
	note Ds, 2
	note F_, 2
	rest 2
	note F_, 2
@Bar 20
	note Gs, 2
	rest 2
	note Ds, 2
	note F_, 6
	rest 2
	note C_, 2
@Bar 21
	note Ds, 2
	note F_, 2
	rest 2
	note F_, 1
	note F_, 1
	note Ds, 2
	note F_, 2
	rest 2
	note F_, 2
@Bar 22
	note Gs, 2
	rest 2
	note Ds, 2
	note F_, 6
	rest 2
	note F_, 2
@Bar 23
	octave 5
	note C_, 1
	octave 4
	note G_, 1
	note As, 1
	note G_, 6
	note G_, 1
	note F_, 1
	note G_, 9
@Bar 24
	note G_, 4
	note As, 4
	note G_, 4
@Bar 25
	sound_loop 0, Music_MirorBBattle_Ch3

@ ============================================================================================================

gbs_Music_MirorBBattle_Ch4:
	gbs_switch 3
Music_MirorBBattle_Ch4:
	toggle_noise 2

Music_MirorBBattle_Ch4_loop:
	drum_speed 12
@Bar 1
	drum_note 5, 1
	drum_note 4, 1
	drum_note 4, 2
	drum_note 5, 2
	drum_note 4, 2
	drum_note 5, 1
	drum_note 4, 1
	drum_note 4, 2
	drum_note 5, 2
	drum_note 4, 2
@Bar 2
	drum_note 5, 2
	drum_note 4, 2
	drum_note 5, 2
	drum_note 4, 1
	drum_note 4, 1
	drum_note 5, 1
	drum_note 4, 1
	drum_note 4, 2
	drum_note 11, 2
	drum_note 4, 2
@Bar 3
	drum_note 5, 1
	drum_note 4, 1
	drum_note 4, 2
	drum_note 1, 2
	drum_note 4, 2
	drum_note 5, 1
	drum_note 4, 1
	drum_note 4, 2
	drum_note 1, 2
	drum_note 4, 2
@Bar 4
	sound_call Music_MirorBBattle_Ch4_Bar4
@Bar 5
	sound_call Music_MirorBBattle_Ch4_Bar5
@Bar 7
	sound_call Music_MirorBBattle_Ch4_Bar5
@Bar 9
	sound_call Music_MirorBBattle_Ch4_Bar5
@Bar 11
	sound_call Music_MirorBBattle_Ch4_Bar5
@Bar 13
	sound_call Music_MirorBBattle_Ch4_Bar5
@Bar 15
	drum_note 5, 1
	drum_note 4, 1
	drum_note 4, 2
	drum_note 11, 2
	drum_note 4, 2
	drum_note 5, 1
	drum_note 4, 1
	drum_note 4, 2
	drum_note 1, 2
	drum_note 4, 2
@Bar 16
	sound_call Music_MirorBBattle_Ch4_Bar16
@Bar 18
	sound_call Music_MirorBBattle_Ch4_Bar16
@Bar 20
	sound_call Music_MirorBBattle_Ch4_Bar16
@Bar 22
	sound_call Music_MirorBBattle_Ch4_Bar4
@Bar 23
	drum_note 9, 2
	drum_note 9, 2
	drum_note 1, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 1, 2
	drum_note 9, 2
@Bar 24
	drum_note 9, 2
	drum_note 9, 2
	drum_note 1, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 9, 2
	drum_note 11, 2
	drum_note 9, 2
	sound_loop 0, Music_MirorBBattle_Ch4_loop

Music_MirorBBattle_Ch4_Bar5:
	drum_note 5, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 1, 1
	drum_note 4, 1
	drum_note 5, 1
	drum_note 5, 1
	drum_note 5, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 1, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 4, 1
@Bar 6
	drum_note 5, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 1, 2
	drum_note 5, 1
	drum_note 5, 1
	drum_note 5, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 4, 1
	drum_note 11, 1
	drum_note 4, 1
	drum_note 5, 1
	drum_note 4, 1
	sound_ret

Music_MirorBBattle_Ch4_Bar16:
	drum_note 5, 2
	drum_note 4, 2
	drum_note 1, 2
	drum_note 4, 1
	drum_note 4, 1
	drum_note 5, 1
	drum_note 4, 1
	drum_note 4, 2
	drum_note 11, 2
	drum_note 4, 2
@Bar 17
	drum_note 5, 1
	drum_note 4, 1
	drum_note 4, 2
	drum_note 1, 2
	drum_note 4, 2
	drum_note 5, 1
	drum_note 4, 1
	drum_note 4, 2
	drum_note 1, 2
	drum_note 4, 2
	sound_ret

Music_MirorBBattle_Ch4_Bar4:
	drum_note 5, 2
	drum_note 4, 2
	drum_note 1, 2
	drum_note 4, 1
	drum_note 4, 1
	drum_note 5, 1
	drum_note 4, 1
	drum_note 4, 2
	drum_note 11, 2
	drum_note 5, 1
	drum_note 5, 1
	sound_ret

@ ============================================================================================================
