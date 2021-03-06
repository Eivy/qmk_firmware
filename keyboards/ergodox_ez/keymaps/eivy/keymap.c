#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define DDWW 2 // media keys
#define MDIA 3 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  | LEFT |           | BSPC |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  \   |           |  [   |   Y  |   U  |   I  |   O  |   P  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  `   |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   \    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |CtlCmd| Prsc |   ¥  | Alt  | LCmd |                                       |Enter | Prsc |   [  |   ]  | L2   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                     ,---------------.          ,-------------.
 *                                     |LShift| Space  |          | RSift|  Alt |
 *                              ,------|------|--------|          |------+------+------.
 *                              |      |      | Home   |          | End  |      |      |
 *                              |Back  |Eis/L2|--------|          |------|Kan/L1|Space/|
 *                              | Space|      |  Del   |          | RCmd |      | Shift|
 *                              `----------------------'          `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,        KC_1,  KC_2,    KC_3,    KC_4,               KC_5,            KC_LEFT,
        KC_TAB,        KC_Q,  KC_W,    KC_E,    KC_R,               KC_T,            KC_BSLS,
        KC_LCTRL,      KC_A,  KC_S,    KC_D,    KC_F,               KC_G,
        KC_LSFT,       KC_Z,  KC_X,    KC_C,    KC_V,               KC_B,            KC_GRV,
        LCTL(KC_LGUI), KC_RO, KC_JYEN, KC_LALT, KC_LGUI,
                                                                    KC_LSFT,         KC_SPC,
                                                                                     KC_HOME,
                                                                    KC_BSPC,         LT(DDWW, KC_LANG2), KC_DELT,
        // right hand
             KC_BSPC, KC_6,            KC_7,              KC_8,       KC_9,    KC_0,     KC_EQL,
             KC_LBRC, KC_Y,            KC_U,              KC_I,       KC_O,    KC_P,     KC_MINS,
                      KC_H,            KC_J,              KC_K,       KC_L,    KC_SCLN,  KC_QUOT,
             KC_RBRC, KC_N,            KC_M,              KC_COMM,    KC_DOT,  KC_SLSH,  KC_BSLS,
                                       KC_ENT,   KC_PSCREEN, KC_LBRC, KC_RBRC,  MO(DDWW),
             KC_RSFT, KC_RALT,
             KC_END,
             KC_RGUI, LT(SYMB,KC_LANG1), SFT_T(KC_SPC)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      | Home | PgDn | PgUp | End  |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |      | Menu |NUMLCK|PAUSE | INS  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |  L3  |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,MO(MDIA),KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,      KC_F9,      KC_F10,  KC_F11,
       KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP,    KC_END,     KC_NO,   KC_F12,
                KC_LEFT, KC_DOWN, KC_UP,      KC_RGHT,    KC_NO,   KC_ENT,
       KC_TRNS, KC_NO,   KC_APP,  KC_NUMLOCK, KC_PAUSE,   KC_INSERT,   KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    =   | F11  | F12  | F13  | F14  | F15  |      |           |      |      |  /   |  *   |      |  =   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    -   |  P   |  O   |  I   |  U   |  Y   |      |           |      |      |  7   |  8   |  9   |  -   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    '   |  ;   |  L   |  K   |  J   |  H   |------|           |------|      |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    \   |  /   |  .   |  ,   |  M   |  N   |      |           |      |      |  1   |  2   |  3   |  \   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  [   |  ]   |      |      |                                       |  0   |  .   |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|  L3  |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[DDWW] = KEYMAP(
       KC_EQL,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_TRNS,
       KC_MINS, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    KC_TRNS,
       KC_QUOT, KC_L,    KC_L,    KC_K,    KC_J,    KC_H,
       KC_BSPC, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    KC_TRNS,
       KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_KP_SLASH, KC_KP_ASTERISK, KC_NO,     KC_NO,   KC_KP_EQUAL, KC_TRNS,
       KC_TRNS,  KC_NO,       KC_KP_7,        KC_KP_8,   KC_KP_9, KC_KP_MINUS, KC_TRNS,
                 KC_NO,       KC_KP_4,        KC_KP_5,   KC_KP_6, KC_KP_PLUS,  KC_TRNS,
       KC_TRNS,  KC_NO,       KC_KP_1,        KC_KP_2,   KC_KP_3, KC_VOLU,     KC_TRNS,
                              KC_KP_0,        KC_KP_DOT, KC_NO,   KC_NO,       KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, MO(MDIA), KC_TRNS
),
/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | ZKHK |      | MsUp |      |      |      |           |      |      |      |      |      | Play |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | PrSc |MsLeft|MsDown|MsRght|      |------|           |------|      |LClick|RClick|      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | Mute |VolDn |VolUp |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,
       KC_TRNS, KC_ZKHK,    KC_NO,   KC_MS_U, KC_NO,   KC_NO, KC_TRNS,
       KC_TRNS, KC_PSCREEN, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,
       KC_TRNS, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPLY, KC_TRNS,
                 KC_ZKHK, KC_BTN1, KC_BTN2, KC_NO,   KC_NO,   KC_TRNS,
       KC_TRNS,  KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,   KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
