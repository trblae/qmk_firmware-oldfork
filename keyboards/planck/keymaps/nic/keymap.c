#include "planck.h"

#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif

#define QWERTY_LAYER 0
#define LOWER_LAYER 1
#define UPPER_LAYER 2
#define SPACEFN_LAYER 3
#define TENKEY_LAYER 4
#define GAME_LAYER 5
#define COLEMAK_LAYER 6
#define UNDERGLOW_LAYER 7

#define PREVENT_STUCK_MODIFIERS

// Tap Dance
enum {
  SFT_CAPS = 0,
  LBRC_LCBR = 1,
  RBRC_RCBR = 2,
  TD_UNDERGLOW = 3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY_LAYER] = {
  {KC_TAB,        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC},
  {CTL_T(KC_ESC), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT},
  {TD(SFT_CAPS), KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT},
  {TD(TD_UNDERGLOW), KC_MEH,  KC_LALT,  KC_LGUI,  FUNC(1),  FUNC(3),  FUNC(3),  FUNC(2),  KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT}
},

[UPPER_LAYER] = {
  {KC_GRV,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,      KC_8,    KC_9,     KC_0,     KC_DELETE},
  {KC_TRNS,     KC_4,    KC_5,    KC_6,    KC_DOT,    KC_TRNS,    KC_TRNS,    KC_MINS,  KC_EQL,   TD(LBRC_LCBR),  TD(RBRC_RCBR),  KC_BSLS},
  {KC_TRNS,     KC_7,    KC_8,    KC_9,    KC_0,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_MUTE,  KC_TRNS,  KC_TRNS},
  {FUNC(6),     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPLY,  KC_VOLD,  KC_VOLU,  KC_MFFD}
},

[LOWER_LAYER] = {
  {KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DELETE},
  {KC_TRNS,  KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE},
  {KC_TRNS,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS},
  {FUNC(4),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END}
},

[SPACEFN_LAYER] = {
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(LSFT(KC_4)), LGUI(LCTL(LSFT(KC_4))), KC_TRNS, KC_HOME, KC_UP,   KC_END,   KC_TRNS, KC_DELETE},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, LGUI(LSFT(KC_M)), KC_TRNS, KC_TRNS,  KC_TRNS, RESET},
  {FUNC(5), FUNC(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS}
},

[TENKEY_LAYER] = {
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, KC_BSPC},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_NLCK},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, KC_ENT},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC,  KC_SPC,  KC_KP_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},

[GAME_LAYER] = {
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_UP, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLSH, KC_LEFT,  KC_DOWN, KC_RIGHT}
},

[COLEMAK_LAYER] = {
  {KC_TRNS,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TRNS},
  {KC_TRNS,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,     KC_QUOT},
  {KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_TRNS, KC_ENT},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS}
},

[UNDERGLOW_LAYER] = {
  {KC_TRNS,  KC_PGUP,  KC_UP,    KC_PGDN,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_DEL},
  {KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_TRNS,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_END,   KC_TRNS},
  {KC_TRNS,  RGB_TOG,  RGB_MOD,  RGB_HUD,  RGB_HUI,  RGB_SAD,  RGB_SAI,  RGB_VAD,  RGB_VAI,  KC_TRNS,  KC_TRNS,  KC_TRNS},
  {KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS}
}
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_DEFAULT_LAYER_SET(QWERTY_LAYER),

    // Tap for backspace, hold for LOWER
    [1] = ACTION_LAYER_TAP_KEY(LOWER_LAYER, KC_BSPC),

    // Tap for enter, hold for RAISE
    [2] = ACTION_LAYER_TAP_KEY(UPPER_LAYER, KC_ENT),

    // Tap for space, hold for SpaceFN
    [3] = ACTION_LAYER_TAP_KEY(SPACEFN_LAYER, KC_SPC),

    [4] = ACTION_LAYER_TOGGLE(GAME_LAYER),
    [5] = ACTION_LAYER_TOGGLE(TENKEY_LAYER),
    [6] = ACTION_LAYER_TOGGLE(COLEMAK_LAYER),
};

void underglow_tapdance (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    layer_invert(UNDERGLOW_LAYER);
    return;
  }

  if (state->pressed) {
    layer_on(UNDERGLOW_LAYER);
  } else {
    layer_off(UNDERGLOW_LAYER);
  }
}

void underglow_tapdance_reset (qk_tap_dance_state_t *state, void *user_datae) {
  if (state->count == 1) {
    layer_off(UNDERGLOW_LAYER);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [SFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
  [LBRC_LCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [RBRC_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),

  [TD_UNDERGLOW] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, underglow_tapdance, underglow_tapdance_reset)
};
