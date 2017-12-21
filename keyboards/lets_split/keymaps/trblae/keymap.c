#include "lets_split.h"
#include "rekeymap.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define QWERTY_LAYER 0
#define LOWER_LAYER 1
#define UPPER_LAYER 2
#define SPACEFN_LAYER 3
#define TENKEY_LAYER 4
#define GAMEPAD_LAYER 5
#define UNDERGLOW_LAYER 6

// Tap Dance
enum {
  SFT_CAPS = 0,
  MPLY_MUTE,
};

// Macros
enum macro_id {
  M_USERNAME,
  M_RANDDIGIT,
  M_RANDLETTER,
  M_QWERTY_LAYER,
  M_LOWER_LAYER,
  M_UPPER_LAYER,
  M_SPACEFN_LAYER,
  M_TENKEY_LAYER,
  M_GAMEPAD_LAYER,
  M_UNDERGLOW_LAYER,
};

#define M_TO0 M(M_QWERTY_LAYER)

// The '/**/' indicates the split in a Let's Split keyboard.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY_LAYER] = KEYMAP( \
  KC_TAB,        KC_Q,   KC_W,    KC_E,    KC_R,             KC_T, /**/ KC_Y,   KC_U,             KC_I,            KC_O,    KC_P,    KC_BSPC, \
  CTL_T(KC_ESC), KC_A,   KC_S,    KC_D,    KC_F,             KC_G, /**/ KC_H,   KC_J,             KC_K,            KC_L,    KC_SCLN, KC_QUOT, \
  TD(SFT_CAPS),  KC_Z,   KC_X,    KC_C,    KC_V,             KC_B, /**/ KC_N,   KC_M,             KC_COMM,         KC_DOT,  KC_SLSH, RSFT_T(KC_ENT), \
  KC_LCTL,       KC_MEH, KC_LGUI, KC_LALT, M(M_LOWER_LAYER), F(3), /**/ KC_SPC, M(M_UPPER_LAYER), RGUI_T(KC_LEFT), KC_DOWN, KC_UP,   KC_RGHT \
),

[LOWER_LAYER] = KEYMAP( \
  KC_TILD, KC_EXLM,           KC_AT,   KC_HASH, KC_DLR,  KC_PERC, /**/ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  KC_ESC,  KC_F1,             KC_F2,   KC_F3,   KC_F4,   KC_F5,   /**/ KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  KC_LSFT, KC_F7,             KC_F8,   KC_F9,   KC_F10,  KC_F11,  /**/ KC_F12,  KC_F13,  _______, _______, _______, KC_ENT, \
  _______, M(M_TENKEY_LAYER), KC_HYPR, _______, _______, _______, /**/ _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END \
),

[UPPER_LAYER] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    /**/ KC_6,               KC_7,    KC_8,          KC_9,    KC_0,    _______, \
  _______, KC_4,    KC_5,    KC_6,    KC_DOT,  _______, /**/ _______,            KC_MINS, KC_EQL,        KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_LSFT, KC_7,    KC_8,    KC_9,    KC_0,    _______, /**/ KC_PSCR,            KC_SLCK, KC_PAUS,       KC_DOT,  _______, KC_RSFT, \
  _______, KC_HYPR, KC_LGUI, _______, _______, _______, /**/ M(M_GAMEPAD_LAYER), _______, TD(MPLY_MUTE), KC_VOLD, KC_VOLU, KC_RCTL \
),

[SPACEFN_LAYER] = KEYMAP( \
  KC_HYPR, _______,              M(M_USERNAME),   KC_PGUP, LGUI(LSFT(KC_4)),   LGUI(LCTL(LSFT(KC_4))), /**/  KC_PGUP, KC_HOME,          KC_UP,   KC_END,   _______, KC_INS, \
  _______, _______,              M(M_RANDDIGIT),  KC_PGDN, _______,            KC_MENU,                /**/  KC_PGDN, KC_LEFT,          KC_DOWN, KC_RGHT,  _______, KC_DELETE, \
  KC_LSFT, _______,              M(M_RANDLETTER), _______, LGUI(LSFT(KC_SPC)), KC_APP,                 /**/  KC_JYEN, LGUI(LSFT(KC_M)), KC_MUTE, KC_VOLD,  KC_VOLU, _______, \
  _______, M(M_UNDERGLOW_LAYER), _______,         _______, _______,            _______,                /**/  KC_CALC, KC_MSEL,          KC_MPLY, KC_MSTP,  KC_MPRV, KC_MNXT \
),

[TENKEY_LAYER] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, /**/ KC_PSLS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, KC_BSPC, \
  _______, _______, _______, _______, _______, KC_QUOT, /**/ KC_PAST, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______, \
  _______, _______, _______, _______, _______, KC_COMM, /**/ KC_SCLN, KC_KP_1, KC_KP_2, KC_KP_3, _______, KC_ENT, \
  _______, M_TO0,   _______, _______, _______, _______, /**/ KC_NLCK, KC_KP_0, KC_KP_0, KC_PDOT, _______, _______ \
),

[GAMEPAD_LAYER] = KEYMAP( \
  KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC, \
  KC_ESC,  KC_A, KC_S, KC_D, KC_F, KC_G, /**/ KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, /**/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, \
  KC_LCTL, _______, _______, KC_LALT, _______, KC_SPC, /**/ M_TO0, _______, KC_1, KC_2, KC_3, KC_4 \
),

[UNDERGLOW_LAYER] = KEYMAP( \
  _______, RESET,   _______, _______, _______, _______, /**/ _______, _______, _______, _______, RESET,   _______, \
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, \
  _______, RGB_TOG, RGB_MOD, _______, RGB_HUI, RGB_HUD, /**/ RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, \
  _______, M_TO0,   _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______ \
),
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_DEFAULT_LAYER_SET(QWERTY_LAYER),

  // Tap for backspace, hold for LOWER
  [1] = ACTION_LAYER_TAP_KEY(LOWER_LAYER, KC_BSPC),

  // Tap for enter, hold for RAISE
  [2] = ACTION_LAYER_TAP_KEY(UPPER_LAYER, KC_ENT),

  // Tap for space, hold for SpaceFN
  [3] = ACTION_LAYER_TAP_KEY(SPACEFN_LAYER, KC_SPC),
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [MPLY_MUTE] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MUTE),
};

// This bit of logic seeds a wee linear congruential random number generator
// lots of prime numbers everywhere...
static uint16_t random_value = 157;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  uint8_t clockbyte=0;
  clockbyte = TCNT1 % 256;
  uint8_t rval;

  // MACRODOWN only works in this function
  switch(id) {
  case M_USERNAME:
    if (record->event.pressed) {
      SEND_STRING("albert");
    }
    break;

  case M_RANDDIGIT:
    // Generate, based on random number generator, a keystroke for
    // a numeric digit chosen at random
    random_value = ((random_value + randadd) * randmul) % randmod;
    if (record->event.pressed) {
      // Here, we mix the LCRNG with low bits from one of the system
      // clocks via XOR in the theory that this may be more random
      // than either separately
      rval = (random_value ^ clockbyte) % 10;
      // Note that KC_1 thru KC_0 are a contiguous range
      register_code (KC_1 + rval);
      unregister_code (KC_1 + rval);
    }
    break;

  case M_RANDLETTER:
    // Generate, based on random number generator, a keystroke for
    // a letter chosen at random
    // Here, we mix the LCRNG with low bits from one of the system
    // clocks via XOR in the theory that this may be more random
    // than either separately
    random_value = ((random_value + randadd) * randmul) % randmod;
    if (record->event.pressed) {
      rval = (random_value ^ clockbyte) % 26;
      register_code (KC_A + rval);
      unregister_code (KC_A + rval);
    }
    break;

  case M_QWERTY_LAYER:
    if (record->event.pressed) {
      layer_move(QWERTY_LAYER);
    }
    break;

  // this updates eeprom which only has a limited amount of writes per chip
  case M_LOWER_LAYER:
    if (record->event.pressed) {
      // turn underglow to green for lower layer
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0xff,0x00,0x00);
      #endif
      // activates layer
      layer_on(LOWER_LAYER);
    } else {
      // turn underglow to normal color (none)
      //#ifdef RGBLIGHT_ENABLE
      //rgblight_setrgb(0x00,0x00,0x00);
      //#endif
      // revert to normal layer
      layer_off(LOWER_LAYER);
    }
    break;

  case M_UPPER_LAYER:
    if (record->event.pressed) {
      // turn underglow to blue for upper layer
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0x00,0x00,0xff);
      #endif
      layer_on(UPPER_LAYER);
    } else {
      //#ifdef RGBLIGHT_ENABLE
      //rgblight_setrgb(0x00,0x00,0x00);
      //#endif
      layer_off(UPPER_LAYER);
    }
    break;

  // not currently used right now...
  case M_SPACEFN_LAYER:
    if (record->event.pressed) {
      // turn underglow to white for spacefn layer
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0xff,0xff,0xff);
      #endif
      layer_on(SPACEFN_LAYER);
    } else {
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0x00,0x00,0x00);
      #endif
      layer_off(SPACEFN_LAYER);
    }
    break;

  case M_TENKEY_LAYER:
    if (record->event.pressed) {
      // turn underglow to yellow for tenkey layer
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0xff,0xff,0x00);
      #endif
      layer_move(TENKEY_LAYER);
    }
    break;

  case M_GAMEPAD_LAYER:
    if (record->event.pressed) {
      // turn underglow to orange for gamepad layer
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0xff,0x7e,0x00);
      #endif
      layer_move(GAMEPAD_LAYER);
    }
    break;

  case M_UNDERGLOW_LAYER:
    if (record->event.pressed) {
      // turn off color for underglow layer, since it will probably be changed anyway
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0x00,0x00,0x00);
      #endif
      layer_move(UNDERGLOW_LAYER);
    }
    break;
  }

  return MACRO_NONE;
};
