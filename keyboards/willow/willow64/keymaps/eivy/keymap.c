/* Copyright 2021 Hanachi
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

extern keymap_config_t keymap_config;

static bool lower_pressed = false;
static bool raise_pressed = false;

enum custom_layers {
    _QWERTY,
    _FN1,
    _FN2,
    _FN3,
    _FFF,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    EISU,
    KANA,
    GUI1,
    GUI2,
    FFF,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QUWERTY Layer */
[_QWERTY] = LAYOUT(
/* |--L1---+--L2---+--L3---+--L4---+--L5---+--L6---+--L7-----| |--R1---+--R2---+--R3---+--R4---+--R5---+--R6---+--R7---+--R8---+---R9--+--R10-- | */
	KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                    KC_6,   KC_7,   KC_8,   KC_9,	KC_0,  KC_MINS, KC_EQL, KC_GRV, KC_PSCR,
	KC_TAB,	   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                    KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,  KC_LBRC, KC_RBRC,KC_BSLS,
	KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                    KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,        KC_EQL,
	KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  KC_ESC,   GUI1,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,                KC_GRV,
                               KC_SPC, EISU,   GUI1,  GUI2,     KC_ENT, SFT_T(KC_SPC), KANA, 	LT(_FN3, KC_UP)
/* |-------+-------+-------+-------+-------+-------+---------| |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------| */
 ),

/*  NUM Pad layer */
[_FN1] = LAYOUT(
/* |--L1---+--L2---+--L3---+--L4---+--L5---+--L6---+--L7-----| |--R1---+--R2---+--R3---+--R4---+--R5---+--R6---+--R7---+--R8---+---R9--+--R10-- | */
	_______, XXXXXXX,XXXXXXX,XXXXXXX,KC_WH_L,KC_WH_R,				    XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,_______,_______,_______,
	_______, XXXXXXX,KC_MS_U,XXXXXXX,KC_WH_D,KC_WH_U,					XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, _______,_______,_______,
	_______, KC_MS_L,KC_MS_D,KC_MS_R,KC_BTN1,KC_BTN2,					XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,	     _______,
	_______, KC_MNXT,KC_MNXT,KC_VOLU,KC_MPLY,XXXXXXX,_______,    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,				 _______,
					         _______,_______,_______,_______,	 _______,_______,_______,_______
/* |-------+-------+-------+-------+-------+-------+---------| |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------| */
),

/* Cursor key layer */
[_FN2] = LAYOUT(
/* |--L1---+--L2---+--L3---+--L4---+--L5---+--L6---+--L7-----| |--R1---+--R2---+--R3---+--R4---+--R5---+--R6---+--R7---+--R8---+---R9--+--R10-- | */
	_______, KC_F1,	 KC_F2,	 KC_F3,	 KC_F4,  KC_F5,					    KC_F6,	KC_F7,	KC_F8,	KC_F9,	 KC_F10,KC_F11,	 KC_F12, KC_INS, _______,
	_______, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,					XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,KC_PSCR,
	_______, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,					KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT, XXXXXXX,XXXXXXX,	     _______,
	_______, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,	XXXXXXX,KC_HOME,KC_PGDN,KC_PGUP,KC_END,  XXXXXXX,				 _______,
							_______, _______,_______,_______,    _______,_______,_______,_______
/* |-------+-------+-------+-------+-------+-------+---------| |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------| */
),

/* System layer */
[_FN3] = LAYOUT(
/* |--L1---+--L2---+--L3---+--L4---+--L5---+--L6---+--L7-----| |--R1---+--R2---+--R3---+--R4---+--R5---+--R6---+--R7---+--R8---+---R9--+--R10-- | */
	RESET,	RGB_TOG,RGB_MOD,RGB_RMOD,XXXXXXX,XXXXXXX,					XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,
	XXXXXXX,XXXXXXX,RGB_VAD,RGB_VAI, XXXXXXX,XXXXXXX,					XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,		XXXXXXX,
	XXXXXXX,XXXXXXX,RGB_SAD,RGB_SAI, XXXXXXX,AG_NORM,				    AG_SWAP,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,				XXXXXXX,
	XXXXXXX,XXXXXXX,RGB_HUD,RGB_HUI, XXXXXXX,XXXXXXX,XXXXXXX,   XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,						XXXXXXX,
							_______,_______,_______,_______,	_______,_______,_______,_______
/* |-------+-------+-------+-------+-------+-------+---------| |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------| */
),
/* FF14 layer */
[_FFF] = LAYOUT(
/* |--L1---+--L2---+--L3---+--L4---+--L5---+--L6---+--L7-----| |--R1---+--R2---+--R3---+--R4---+--R5---+--R6---+--R7---+--R8---+---R9--+--R10-- | */
	XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,					KC_1   ,KC_2    ,KC_3   ,C(KC_1),C(KC_2),C(KC_3),XXXXXXX,XXXXXXX,_______,
	XXXXXXX,XXXXXXX,KC_W   ,XXXXXXX, XXXXXXX,XXXXXXX,					KC_4   ,KC_5    ,KC_6   ,C(KC_4),C(KC_5),C(KC_6),XXXXXXX,		XXXXXXX,
	XXXXXXX,KC_A   ,KC_S   ,KC_D   , XXXXXXX,XXXXXXX,				    KC_7   ,KC_8    ,KC_9   ,C(KC_7),C(KC_8),C(KC_9),				XXXXXXX,
	XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,   XXXXXXX,KC_0   ,KC_MINS ,KC_QUOT,C(KC_0),C(KC_MINS),       				C(KC_QUOT),
							_______,_______,_______,_______,	S(KC_1),S(KC_2),S(KC_3),S(KC_4)
/* |-------+-------+-------+-------+-------+-------+---------| |--------+-------+-------+-------+-------+-------+-------+-------+-------+-------| */
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EISU:
      if(record->event.pressed) {
        lower_pressed = true;
        layer_on(_FN1);
      }else{
        if(lower_pressed) {
          if(keymap_config.swap_lalt_lgui==false){
            tap_code(KC_LANG2);
          }else{
            add_key(26);
            del_key(26);
          }
        }
        layer_off(_FN1);
        lower_pressed = false;
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        raise_pressed = true;
        layer_on(_FN2);
      } else {
        if(raise_pressed) {
          if(keymap_config.swap_lalt_lgui==false){
            tap_code(KC_LANG1);
          }else{
            add_key(22);
            del_key(22);
          }
        }
        layer_off(_FN2);
        raise_pressed = false;
      }
      return false;
      break;
    case GUI1:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LGUI);
        }else{
          register_code(KC_LALT);
        }
      } else {
        if(keymap_config.swap_lalt_lgui==false){
          unregister_code(KC_LGUI);
        }else{
          unregister_code(KC_LALT);
        }
      }
      return false;
      break;
    case GUI2:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LALT);
        }else{
          register_code(KC_LGUI);
        }
      } else {
        if(keymap_config.swap_lalt_lgui==false){
          unregister_code(KC_LALT);
        }else{
          unregister_code(KC_LGUI);
        }
      }
      return false;
      break;
    default:
      lower_pressed = false;
      raise_pressed = false;
      break;
  }
  return true;
}
