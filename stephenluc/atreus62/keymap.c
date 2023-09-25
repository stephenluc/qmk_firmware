/*
  Atreus62 v9.23.2023
*/
#include QMK_KEYBOARD_H

// For readability, these are shortcuts to visiualize certain key codes
#define _______ KC_TRNS
#define _x_x_x_ KC_TRNS
#define xxxxxxx KC_NO
#define RESET   QK_BOOT

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum atreus62_layers {
  _BL, // Base Layer
  _FL, // Function Layer
  _NL, // Numberpad Layer
  _ML, // Mouse Layer
  _SL, // System Layer
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE,
  WHOAMI,
  SECRET,
};

  /* LAYOUT _XL: (X Layer) Some Layer
   * ,-----------------------------------------.                ,-----------------------------------------.
   * |      |      |      |      |      |      |                |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      |      |      |      |      |      |,------.,------.|      |      |      |      |      |      |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |      |      |      |      |      |      ||      ||      ||      |      |      |      |      |      |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |      |      |      |      |      |      |`------'`------'|      |      |      |      |      |      |
   * `-----------------------------------------'                `-----------------------------------------'
   */
/*
  [_XL] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* LAYOUT _BL: (Base Layer) Base Layer
   * http://www.keyboard-layout-editor.com/#/gists/13f44b58c4a269189bdfc3b754037098
   * ,-----------------------------------------.                ,-----------------------------------------.
   * |  =   |   1  |   2  |   3  |   4  |   5  |                |   6  |   7  |   8  |   9  |   0  |  -   |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |,------.,------.|   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |Shift |   Z  |   X  |   C  |   V  |   B  || Esc  ||Enter ||   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |MO(NL)|  `   | Ins  | Alt  | Cmd  | Bksp |`------'`------'|Space |  Up  | Down |  [   |   ]  |MO(FL)|
   * `-----------------------------------------'                `-----------------------------------------'
   */
  [_BL] = LAYOUT(
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    MO(_NL), KC_GRV,  KC_INS,  KC_LALT, KC_LGUI, KC_BSPC, LT(_ML,KC_ESC),
                                                                   KC_ENT,  KC_SPC,  KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(_FL)),

  /* LAYOUT _FL: (Function Layer) Function and Media Controls
   * http://www.keyboard-layout-editor.com/#/gists/6b6020c9a3eb3a56f9c3e565d98d48c1
   * ,-----------------------------------------.                ,-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                |  F6  |  F7  |  F8  |  F9  |  F0  | F11  |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * | Caps | Prev | Play | Next | Stop |      |                |      |      |      |      |      | F12  |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      | Vol- | Vol+ | Mute |      |      |,------.,------.|      |      |      |      |      |      |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |      | Bri- | Bri+ |      |      |      ||Hyper ||      ||      |      |      |  Up  |      |      |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |MO(SL)|      |      |      |      |      |`------'`------'|      |      | Left | Down |Right |_x_x_x|
   * `-----------------------------------------'                `-----------------------------------------'
   */
  [_FL] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    KC_CAPS, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, _______,                   _______, _______, _______, _______, _______, KC_F12,
    _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, KC_BRID, KC_BRIU, _______, _______, _______,                   _______, _______, _______, KC_UP,   _______, _______,
    MO(_SL), _______, _______, _______, _______, _______, KC_HYPR, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _x_x_x_),

  /* LAYOUT _NL: (Numpad Layer) Number Pad Layer
   * http://www.keyboard-layout-editor.com/#/gists/b12ade81c305f652dc549f00cadef062
   * ,-----------------------------------------.                ,-----------------------------------------.
   * |      |      |      |      |      |      |                |      |Num_lk|  /   |  *   |  -   |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                |      |  7   |  8   |  9   |  +   |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      |      |Sleep |      |      |      |,------.,------.|      |  4   |  5   |  6   |  +   |      |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |      |      |      |      |      |      ||  =   ||Enter ||      |  1   |  2   |  3   |  =   |      |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |_x_x_x|      |      |      |      |      |`------'`------'|  0   |  0   |  0   |  .   |  =   |MO(SL)|
   * `-----------------------------------------'                `-----------------------------------------'
   */
  [_NL] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, KC_NUM , KC_PSLS, KC_PAST, KC_PMNS, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
    _______, _______, KC_SLEP, _______, _______, _______,                   _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, _______,
    _x_x_x_, _______, _______, _______, _______, _______, KC_PEQL, KC_PENT, KC_P0,   KC_P0,   KC_P0,   KC_PDOT, KC_PEQL, MO(_SL)),

  /* LAYOUT _ML: (Mouse Layer) Mouse Controls
   * http://www.keyboard-layout-editor.com/#/gists/44c3ff6d3239dce8a599c7557fda43ba
   * ,-----------------------------------------.                ,-----------------------------------------.
   * |      |      |      |      |      |      |                |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                | Whl+ |Whl_lt|Ms_up |Whl_rt |      |      |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * |      |      |      |      |      |      |,------.,------.| Whl- |Ms_lt |Ms_dn |Ms_rt |      |      |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |      |      |      |      |      |      ||_x_x_x||Btn_3 ||      |      |      |      |      |      |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |      |      |      |      |      |      |`------'`------'|Btn_1 |Btn_2 |      |      |      |      |
   * `-----------------------------------------'                `-----------------------------------------'
   */
  [_ML] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _x_x_x_, KC_BTN3, KC_BTN1, KC_BTN2, _______, _______, _______, _______),

  /* LAYOUT _SL: (System Layer) System Commands
   * http://www.keyboard-layout-editor.com/#/gists/fb89ca44fcbec4799596293cbc7d2a79
   * ,-----------------------------------------.                ,-----------------------------------------.
   * | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |                | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * | xxxx | xxxx | xxxx | xxxx |RESET | xxxx |                | xxxx | xxxx | xxxx |WHOAMI|SECRET| xxxx |
   * |------+------+------+------+------+------|                |------+------+------+------+------+------|
   * | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |,------.,------.| xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx || xxxx || xxxx || xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |
   * |------+------+------+------+------+------||      ||      ||------+------+------+------+------+------|
   * |_x_x_x| xxxx | xxxx | xxxx | xxxx | xxxx |`------'`------'| xxxx | xxxx | xxxx | xxxx | xxxx |_x_x_x|
   * `-----------------------------------------'                `-----------------------------------------'
   */
  [_SL] = LAYOUT(
    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                   xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, RESET,   xxxxxxx,                   xxxxxxx, xxxxxxx, xxxxxxx, WHOAMI,  SECRET, xxxxxxx,
    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                   xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                   xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
    _x_x_x_, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _x_x_x_),
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
    default:
    return true;
  }
}
