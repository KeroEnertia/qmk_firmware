#pragma once

//#define GRAVE_ESC_SHIFT_OVERRIDE	//Always send Escape if Shift is pressed
#define GRAVE_ESC_CTRL_OVERRIDE		//Always send Escape if Control is pressed
#define GRAVE_ESC_ALT_OVERRIDE		//Always send Escape if Alt is pressed
#define GRAVE_ESC_GUI_OVERRIDE		//Always send Escape if GUI is pressed

#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(STARTUP_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

//#define TAPPING_TOGGLE 3