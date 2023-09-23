#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;
/*
  Run `qmk compile -kb keebio/quefrency/rev4 -km culns` to get hex file
*/
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _ML 1
#define _NL 2
#define _WL 3
#define _SL 4


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

enum macro_keycodes {
  PLACEHOLDER = SAFE_RANGE,
  WHOAMI,
  SECRET,
};

/*
  [_XL] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_65_with_macro(
    KC_MPLY, KC_GESC, KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_BSPC, KC_DEL,
    KC_F1,   KC_F2,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, MO(4),
    KC_F3,   KC_F4,   KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  TO(3),
    KC_F5,   KC_F6,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   TO(0),
    KC_F7,   KC_F8,  KC_LCTL, LT(2,KC_GRV), KC_LALT, KC_LGUI, KC_BSPC,            _______, KC_SPC,   KC_RALT, LT(1,KC_RCTL), _______, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_ML] = LAYOUT_65_with_macro(
    _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL,  _______,
    _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_BRID, KC_BRIU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_HYPR, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NL] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, _______, _______, _______, _______, _______,
    _______, _______, _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, KC_KP_0, KC_DOT, _______, _______, _______, _______, _______
  ),

  [_WL] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, XXXXXXX, KC_SPC,          _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_SL] = LAYOUT_65_with_macro(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, WHOAMI,  SECRET,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
  // Right encoder
    if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    // Left encoder
    else if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

const uint16_t PROGMEM fn_actions[] = {};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch (id) {
  case 0:
    if (record->event.pressed) {
      register_code(KC_RSFT);
    }
    else {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode) {
  case WHOAMI:
    if (record->event.pressed) {
      SEND_STRING("Property of Stephen Luc (@stephenluc)");
    }

    return false;
  case SECRET:
    if (record->event.pressed) {
      SEND_STRING("secret");
    }

    return false;
  }

  return true;
}
