/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

static bool startup_animation_running = true;
static uint32_t startup_animation_timer = 0;
#define STARTUP_ANIMATION_DURATION 5000 // 5 seconds in milliseconds


//clang-format off
enum custom_keycodes {
    L0_LIGHT_TOGGLE = SAFE_RANGE, // Existing custom keycode
    TAB_TOGGLE, // light toggle
    KC_GRV_MACRO, // grave ``` macro
    TG_L1,
    TG_L2,
    KC_TASK_MANAGER,
    // Other custom keycodes...
};


#define SEMI_COLON LT(2, KC_SCLN) // Layer 2 is a placeholder
#define BRACKET_OPEN LT(2, KC_LBRC)
#define BRACKET_CLOSE LT(2, KC_RBRC)
#define COMMA LT(2, KC_COMM)
#define PERIOD LT(2, KC_DOT)
#define W LT(0, KC_W) // 0 is a placeholder layer, KC_W is the tap keycode
#define Q LT(0, KC_Q) // 0 is a placeholder layer, KC_W is the tap keycode
#define T LT(0, KC_T)
#define F LT(0, KC_F)
#define V LT(0, KC_V)
#define myC LT(0, KC_C)
#define TAB LT(0, KC_TAB)
#define GRV LT(0, KC_GRV)




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,             KC_MUTE,
        GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        TAB,   Q,     W,     KC_E,     KC_R,     T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     myC,     V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(3),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [1] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_PAST,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_PSLS,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(3),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [2] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,             KC_MUTE,
        GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     BRACKET_OPEN,  BRACKET_CLOSE,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     SEMI_COLON,  KC_QUOT,            KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     COMMA,  PERIOD,   KC_SLSH,            KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(3),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [3] = LAYOUT_ansi_82(
        KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK_MANAGER,  KC_FILE,  RGB_SAD,  RGB_SAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,            RGB_TOG,
        TG_L2,  BT_HST1,  BT_HST2,  BT_HST3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS,
        L0_LIGHT_TOGGLE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BAT_LVL,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,   KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                TG_L1,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS)

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [2] = {ENCODER_CCW_CW(C(KC_MS_WH_DOWN), C(KC_MS_WH_UP))},
    [3] = {ENCODER_CCW_CW(C(KC_MS_WH_DOWN), C(KC_MS_WH_UP))}
    };
#endif // ENCODER_MAP_ENABLE

#define HSV_CWHITE 0, 0, 255          // Max saturation for white
#define HSV_SOFT_ORANGE 25, 255, 180  // Full saturation, softer brightness for a warm orange
#define HSV_OCEAN_BLUE 180, 255, 255  // Full saturation for a vivid ocean blue
#define HSV_PASTEL_GREEN 85, 180, 255 // Lower saturation for a softer, pastel green

static bool layer0_light_enabled = false; // By default, the light is off

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 0:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            if (layer0_light_enabled) {
                rgb_matrix_sethsv_noeeprom(HSV_CWHITE); // White light if enabled
            } else {
                rgb_matrix_sethsv_noeeprom(0, 0, 0); // Turn off lights if disabled
            }
            break;
        case 1:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_OCEAN_BLUE); // Ocean Blue for layer 1
            break;
        case 2:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_SOFT_ORANGE); // Soft Orange for layer 2
            break;
        case 3:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgb_matrix_sethsv_noeeprom(HSV_PASTEL_GREEN); // Pastel Green for layer 3
            break;
        default:
            break;
    }
    return state;
}

static bool process_tap_or_long_press_key(keyrecord_t* record, uint16_t long_press_keycode) {
    if (record->tap.count == 0) {  // Key is being held.
        if (record->event.pressed) {
            switch (long_press_keycode) {
                case TAB_TOGGLE:
                    // Custom action for long press: Toggle lights
                    layer0_light_enabled = !layer0_light_enabled;
                    layer_state_set_user(layer_state);
                    break;
                case KC_GRV_MACRO:
                    // Custom action for long press: Send triple grave accent
                    SEND_STRING("```");
                    break;
                // Other cases...
                default:
                    tap_code16(long_press_keycode); // Default action for other keys
                    break;
            }
        }
        return false;  // Skip default handling.
    }
    return true;  // Continue default handling for taps.
}



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool caps_lock_held = false;

    switch (keycode) {
        case KC_TASK_MANAGER:
            if (record->event.pressed) {
                // Key pressed
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code(KC_ESC);       // Ctrl + Shift + Esc opens Task Manager
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false; // Skip further processing of this key
        case TG_L1:
            if (record->event.pressed) {
                if (layer_state_is(1)) {
                    layer_off(1); // Turn off Layer 1 if it's already active
                } else {
                    layer_clear(); // Clear all active layers
                    layer_on(0);   // Activate Layer 0
                    layer_on(1);   // Activate Layer 1
                }
            }
            return false;

        case TG_L2:
            if (record->event.pressed) {
                if (layer_state_is(2)) {
                    layer_off(2); // Turn off Layer 2 if it's already active
                } else {
                    layer_clear(); // Clear all active layers
                    layer_on(0);   // Activate Layer 0
                    layer_on(2);   // Activate Layer 2
                }
            }
            return false;

        // ... handle other keycodes ...
    }

    // Handling for the KC_GRV_MACRO on Layer 0 and Layer 2
    if (layer_state_is(0) || layer_state_is(2)) {
        switch (keycode) {
            case GRV:
                return process_tap_or_long_press_key(record, KC_GRV_MACRO);
        }
    }

    // Special handling when Layer 0 is active
    if (layer_state_is(0)) {
        switch (keycode) {
            case W:
                return process_tap_or_long_press_key(record, KC_WWW_HOME);
            case Q:
                return process_tap_or_long_press_key(record, A(KC_F4));
            case T:
                return process_tap_or_long_press_key(record, G(KC_1));
            case F:
                return process_tap_or_long_press_key(record, G(KC_E));
            case V:
                return process_tap_or_long_press_key(record, G(KC_2));
            case myC:
                return process_tap_or_long_press_key(record, KC_CALC);
            case TAB:
                return process_tap_or_long_press_key(record, TAB_TOGGLE);
        }
    }

    // Special handling when Layer 2 is active
    if (layer_state_is(2)) {
        switch (keycode) {
            case SEMI_COLON: // ';' when tapped, ':' when held
                return process_tap_or_long_press_key(record, KC_COLON);
            case BRACKET_OPEN: // '[' when tapped, '{' when held
                return process_tap_or_long_press_key(record, KC_LCBR);
            case BRACKET_CLOSE: // ']' when tapped, '}' when held
                return process_tap_or_long_press_key(record, KC_RCBR);
            case COMMA: // ',' when tapped, '<' when held
                return process_tap_or_long_press_key(record, KC_LT);
            case PERIOD: // '.' when tapped, '>' when held
                return process_tap_or_long_press_key(record, KC_GT);
            case KC_CAPS:
                if (record->event.pressed) {
                    caps_lock_held = true;
                } else {
                    caps_lock_held = false;
                }
                return false; // Disable Caps Lock functionality on Layer 2

            case KC_SPC:
                if (record->event.pressed && caps_lock_held) {
                    SEND_STRING(SS_LCTL(SS_TAP(X_RGHT) SS_LSFT(SS_TAP(X_LEFT))));
                    return false;
                }
                break;

            case KC_HOME:
                if (record->event.pressed && caps_lock_held) {
                    SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
                    return false;
                }
                break;

            case KC_ENT:
                if (record->event.pressed && caps_lock_held) {
                    // Web Search Macro
                    SEND_STRING(SS_LCTL("c") SS_DELAY(100));
                    SEND_STRING(SS_TAP(X_WWW_HOME) SS_DELAY(500));
                    SEND_STRING(SS_LCTL("v") SS_DELAY(100));
                    SEND_STRING(SS_TAP(X_ENTER));
                    return false;
                }
                break;

            case KC_DEL:
                if (record->event.pressed && caps_lock_held) {
                    // Join Lines Macro
                    SEND_STRING(SS_TAP(X_END) SS_TAP(X_DEL) SS_TAP(X_SPC)
                                SS_LCTL(SS_TAP(X_RGHT) SS_TAP(X_LEFT))
                                SS_LSFT(SS_TAP(X_LEFT) SS_TAP(X_RGHT))
                                SS_TAP(X_SPC));
                    return false;
                }
                break;

            case KC_BSPC:
                if (record->event.pressed && caps_lock_held) {
                    // Delete Word Macro
                    SEND_STRING(SS_LCTL(SS_TAP(X_RGHT) SS_LSFT(SS_TAP(X_LEFT))) SS_TAP(X_BSPC));
                    return false;
                }
                break;

            // Add any additional Layer 2 specific key handling here
        }
    }

    // Handle other layers or global keycodes here

    return true;
}

void run_startup_animation(void) {
    if (startup_animation_running) {
        if (timer_elapsed(startup_animation_timer) > STARTUP_ANIMATION_DURATION) {
            // Stop the animation after the duration has passed
            startup_animation_running = false;
            rgb_matrix_sethsv_noeeprom(0, 0, 0); // Turn off RGB lighting
        } else {
            // Smooth hue transition
            uint8_t hue = (timer_elapsed(startup_animation_timer) * 255) / STARTUP_ANIMATION_DURATION;
            rgb_matrix_sethsv_noeeprom(hue, 255, 255); // Full saturation and brightness
        }
    }
}



void keyboard_post_init_user(void) {
    // Initialize any other keyboard settings here

    // Start the startup animation
    startup_animation_timer = timer_read();
    startup_animation_running = true;

    // Set initial RGB state
    layer0_light_enabled = false; // Set the flag to indicate that layer 0 lighting is off
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(0, 0, 0); // Turn off RGB lighting
}

void matrix_scan_user(void) {
    run_startup_animation();
    // Other code...
}


