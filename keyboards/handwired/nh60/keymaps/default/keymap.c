#include "nh60.h"

#define DEFAULT_LAYER 0
#define EXTRAS_LAYER 1

#define ______ KC_TRNS
#define XXXXXX KC_NO
#define CTL_ESC CTL_T(KC_ESC)
#define HYPR_TAB ALL_T(KC_TAB)
#define SCREENSHOT LGUI(LSFT(KC_4))
#define SCREENSHOT_CLIPBOARD LGUI(LCTL(LSFT(KC_4)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[DEFAULT_LAYER] = KEYMAP(
		KC_GRV, 				KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_DEL,
		HYPR_TAB, 			KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
		CTL_ESC, 				KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		SFT_T(KC_CAPS), KC_Z, 	KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, ______,
								KC_LALT, KC_LGUI, F(0), KC_RGUI, MO(EXTRAS_LAYER)
	),

	[EXTRAS_LAYER] = KEYMAP(
		______, ______, ______, ______, SCREENSHOT, SCREENSHOT_CLIPBOARD, ______,  ______, KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, ______, ______,
		______, ______, ______, ______, RESET, 			______, 							KC_HOME, KC_END, KC_UP, ______, ______, ______, ______, KC_DEL,
		______, ______, ______, ______, ______, 		______, 							KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT, ______, ______, ______,
		______, ______, ______, ______, ______, 		______, 							KC_PGDN, ______, ______, ______, ______, ______, ______,
										______, ______, ______, 		______, 							______
	),

};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_TAP_KEY(EXTRAS_LAYER, KC_SPACE),
};
