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

#ifdef ANALOG_JOYSTICK_ENABLE
static uint8_t precision_val = 70;
static uint8_t axesFlags = 0;
enum axes {
    Precision = 1,
    Axis1High = 2,
    Axis1Low = 4,
    Axis2High = 8,
    Axis2Low = 16
};
#endif

#define JOYSTICK_BUTTON_COUNT 16
#define JOYSTICK_AXES_COUNT 2
#define JOYSTICK_AXES_RESOLUTION 8

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
#ifdef ANALOG_JOYSTICK_ENABLE
        // virtual joystick
#    if JOYSTICK_AXES_COUNT > 1
        case KC_P8:
            if (record->event.pressed) {
                axesFlags |= Axis2Low;
            } else {
                axesFlags &= ~Axis2Low;
            }
            joystick_status.status |= JS_UPDATED;
            break;
        case KC_P2:
            if (record->event.pressed) {
                axesFlags |= Axis2High;
            } else {
                axesFlags &= ~Axis2High;
            }
            joystick_status.status |= JS_UPDATED;
            break;
#    endif
        case KC_P4:
            if (record->event.pressed) {
                axesFlags |= Axis1Low;
            } else {
                axesFlags &= ~Axis1Low;
            }
            joystick_status.status |= JS_UPDATED;
            break;
        case KC_P6:
            if (record->event.pressed) {
                axesFlags |= Axis1High;
            } else {
                axesFlags &= ~Axis1High;
            }
            joystick_status.status |= JS_UPDATED;
            break;
        /*case KC_P5:
            if (record->event.pressed) {
                axesFlags |= Precision;
            } else {
                axesFlags &= ~Precision;
            }
            joystick_status.status |= JS_UPDATED;
            break;*/
#endif
    }
    return true;
}