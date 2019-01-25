#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | `      |   1  |   2  |   3  |   4  |   5  | PrtSC|           |  | \ |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  Esc |   Y  |   U  |   I  |   O  |   P  | BackSP |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Ctrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ; + |  Enter |
 * |--------+------+------+------+------+------|PageUP|           |PageDW|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | / ?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  Win | LAlt |      | @    |                                       |  ^ ~ | : *  | [ {  |  ] } | \ _  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.        ,-------------.
 *                                        |      |      |       | Left | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       |  Up  |        |      |
 *                                 | Space|  F2  |------|       |------|  Del   | Ctrl |
 *                                 |      |      | End  |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_PSCREEN,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMB),
        KC_LCTL,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_PGUP,
        KC_LCTL,        KC_LGUI,      KC_LALT,KC_TRNS,KC_LBRC,
                                               KC_TRNS, KC_TRNS,
                                                              KC_HOME,
                                               KC_SPC,KC_F2,    KC_END,
        // right hand
          KC_JYEN,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
          KC_ESC,      KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSPC,
                       KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_ENT,
          KC_PGDN,     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                               KC_EQL, KC_QUOT,KC_RBRC,KC_BSLS,          KC_RO,
          KC_LEFT,        KC_RGHT,
          KC_UP,
          KC_DOWN,KC_DEL, KC_RCTL
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc   |  F1  |  F2  |  F3  |  F4  |  F5  | PtrSC|           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |   Tab   |   !  |   @  |   {  |   }  |   |  |      |           | Esc  |      |      | Home |PageUp| @ / `|   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Ctrl   |   #  |   $  |   (  |   )  |   `  |------|           |------|      |  Del |  End |PageDw|   +  |  Enter |
 * |---------+------+------+------+------+------| Left |           | Right|------+------+------+------+------+--------|
 * |  Shift  |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |      |  Up  |      |   \  | RShift |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl  |  Win |  Alt |      |      |                                       | Left | Down | Right|   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.        ,-------------.
 *                                        |  Up  | Down |       | Left | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       |PageUP|        |      |
 *                                 | Space|  F2  |------|       |------|  Del   | Ctrl |
 *                                 |      |      | End  |       |PageDW|        |      |
 *                                 `--------------------'       `----------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_PSCREEN,
       KC_TAB, KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_LCTL,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_LSFT,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_LEFT,
       KC_LCTL,KC_LGUI,KC_LALT,KC_TRNS,KC_TRNS,
                                               KC_UP, KC_DOWN,
                                                              KC_HOME,
                                               KC_SPC,KC_F2,    KC_END,
       // right hand
       LALT(KC_LSFT), KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_ESC,  KC_TRNS, KC_TRNS,KC_HOME, KC_PGUP, KC_LBRC, KC_F12,
                KC_TRNS, KC_DEL, KC_END,  KC_PGDN, KC_PLUS, KC_ENT,
       KC_RGHT, KC_AMPR, KC_TRNS,KC_UP,   KC_TRNS, KC_JYEN, KC_RSFT,
                 KC_LEFT,KC_DOWN, KC_RGHT, KC_EQL,  KC_TRNS,
          KC_LEFT,        KC_RGHT,
          KC_PGUP,
          KC_PGDN,KC_DEL, KC_RCTL
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                    KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
