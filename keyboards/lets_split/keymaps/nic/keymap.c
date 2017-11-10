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

#define KC_TO0 TO(QWERTY_LAYER)

// Tap Dance
enum {
  SFT_CAPS = 0,
  MPLY_MUTE,
  GUI_LEFT,
  RSHIFT_ENT,
};

// Macros
enum macro_id {
  M_USERNAME,
  M_RANDDIGIT,
  M_RANDLETTER,
};

// The '/**/' indicates the split in a Let's Split keyboard.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY_LAYER] = KEYMAP( \
  KC_TAB,        KC_Q,   KC_W,    KC_E,    KC_R, KC_T, /**/ KC_Y,   KC_U, KC_I,         KC_O,    KC_P,    KC_BSPC, \
  CTL_T(KC_ESC), KC_A,   KC_S,    KC_D,    KC_F, KC_G, /**/ KC_H,   KC_J, KC_K,         KC_L,    KC_SCLN, KC_QUOT, \
  TD(SFT_CAPS),  KC_Z,   KC_X,    KC_C,    KC_V, KC_B, /**/ KC_N,   KC_M, KC_COMM,      KC_DOT,  KC_SLSH, TD(RSHIFT_ENT), \
  KC_LCTL,       KC_MEH, KC_LALT, KC_LGUI, F(1), F(3), /**/ KC_SPC, F(2), TD(GUI_LEFT), KC_DOWN, KC_UP,   KC_RGHT \
),

[UPPER_LAYER] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    /**/ KC_6,              KC_7,    KC_8,          KC_9,    KC_0,    _______, \
  _______, KC_4,    KC_5,    KC_6,    KC_DOT,  _______, /**/ _______,           KC_MINS, KC_EQL,        KC_LBRC, KC_RBRC, KC_BSLS, \
  KC_MEH,  KC_7,    KC_8,    KC_9,    KC_0,    _______, /**/ KC_PSCR,           KC_SLCK, KC_PAUS,       KC_DOT,  _______, KC_MUTE, \
  _______, KC_HYPR, _______, KC_LGUI, _______, _______, /**/ TG(GAMEPAD_LAYER), _______, TD(MPLY_MUTE), KC_VOLD, KC_VOLU, KC_RCTL \
),

[LOWER_LAYER] = KEYMAP( \
  KC_TILD,          KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, /**/ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /**/ KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  KC_LSFT,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  /**/ KC_F12,  _______, _______, _______, _______, _______, \
  TG(TENKEY_LAYER), KC_HYPR, KC_LALT, _______, _______, _______, /**/ _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END \
),

[SPACEFN_LAYER] = KEYMAP( \
  KC_HYPR,             _______, M(M_USERNAME),   _______, LGUI(LSFT(KC_4)), LGUI(LCTL(LSFT(KC_4))), /**/  KC_PGUP, KC_HOME,          KC_UP,   KC_END,   _______, KC_INS, \
  _______,             _______, M(M_RANDDIGIT),  _______, _______,          _______,                /**/  KC_PGDN, KC_LEFT,          KC_DOWN, KC_RGHT,  _______, KC_DELETE, \
  KC_LSFT,             _______, M(M_RANDLETTER), _______, _______,          _______,                /**/  _______, LGUI(LSFT(KC_M)), _______, _______,  _______, _______, \
  TG(UNDERGLOW_LAYER), _______, KC_LALT,         _______, _______,          _______,                /**/  _______, _______,          KC_MPLY, KC_MSTP,  KC_MPRV, KC_MNXT \
),

[TENKEY_LAYER] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, /**/ KC_PSLS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, KC_BSPC, \
  _______, _______, _______, _______, _______, _______, /**/ KC_PAST, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______, \
  _______, _______, _______, _______, _______, _______, /**/ _______, KC_KP_1, KC_KP_2, KC_KP_3, _______, KC_ENT, \
  _______, _______, KC_LALT, _______, _______, _______, /**/ KC_NLCK, KC_KP_0, KC_KP_0, KC_PDOT, _______, _______ \
),

[GAMEPAD_LAYER] = KEYMAP( \
  KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, \
  KC_ESC,  KC_A, KC_S, KC_D, KC_F, KC_G, /**/ KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, /**/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TD(RSHIFT_ENT), \
  KC_LCTL, _______, KC_LALT, KC_LGUI, _______, KC_SPC, /**/ _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT \
),

[UNDERGLOW_LAYER] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, RESET,   _______, \
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______, \
  _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, /**/ RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______ \
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
  [GUI_LEFT] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_RGUI),
  [RSHIFT_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_RSFT)
};

// This bit of logic seeds a wee linear congruential random number generator
// lots of prime numbers everywhere...
static uint16_t random_value = 157;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
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
  }

  return MACRO_NONE;
};
