#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Convenient macros
#define SHFT_ENT MT(MOD_RSFT, KC_ENT)
#define SHFT_CAP MT(MOD_LSFT, KC_CAPS)
#define CAD      LALT(LCTL(KC_DEL))
#define MO_NAV   LT(3, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[0] = {
  {KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSPC},
  {MO_NAV,   KC_A,     KC_S,     KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT},
  {SHFT_CAP, KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT},
  {KC_LCTL,  KC_LGUI,  KC_LALT,  KC_BTN1,  M(1),    KC_ENT,  KC_SPC,  M(2),    KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R}
},

/* === LOWER === */
[1] = {
  {KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,   KC_8,   KC_9,    KC_0,    KC_BSPC},
  {_______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,   KC_5,   KC_6,    KC_PPLS, KC_PMNS},
  {_______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,   KC_2,   KC_3,    KC_PAST, KC_PSLS},
  {_______,  _______, _______, _______, _______, _______, _______, KC_0,   KC_0,   KC_DOT,  _______, _______}
},


/* === RAISE === */
[2] = {
  {KC_TILD,  KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,   KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {_______,  KC_LBRC,   KC_RBRC,   KC_LPRN,   KC_RPRN,   _______,   _______,   KC_MINS, KC_EQL,  KC_MINS, KC_EQL,  KC_BSLS},
  {_______,  KC_LCBR,   KC_RCBR,   _______,   _______,   _______,   _______,   KC_UNDS, KC_PLUS, KC_UNDS, KC_PLUS, KC_RSFT},
  {_______,  _______,   _______,   _______,   _______,   _______,   _______,   _______, _______, _______, _______, _______}
},


/* === NAVIGATION === */
[3] = {
  {_______, CAD,     _______, _______, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN,  KC_PSCR, _______},
  {_______, M(3),    _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_INS,   KC_DEL},
  {_______, _______, _______, _______, _______, _______, KC_END,  _______, _______, _______,  _______, _______},
  {RESET,   MU_TOG,  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______}
},


};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 1:
      if (record->event.pressed) {
        layer_on(1);
      } else {
        layer_off(1);
      }
      break;
    case 2:
      if (record->event.pressed) {
        layer_on(2);
      } else {
        layer_off(2);
      }
      break;
    case 3:
      if (record->event.pressed) {
	return MACRO(
		      T(HOME),
		      D(LSFT),
		      T(END),
		      U(LSFT),
		      END
		    );
      }
  }
  return MACRO_NONE;
};
