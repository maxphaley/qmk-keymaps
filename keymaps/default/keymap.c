// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define _BASE 0
#define _NAV  1
#define _NUM  2
#define _SYM  3
#define _FUNC 4
#define _MOUSE 5
#define _MEDIA 6

/* colemak dh
  q w f p b  j l u y ;
  a r s t g  m n e i o '
  z x c d v  k h , . /
*/
/* graphite like
  b l d w z  ' f o u j
  n r t s g  y h a e i
  q x m c v  k p , . /
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_3(
    KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,                               KC_QUOT,    KC_F,    KC_O,    KC_U,    KC_J,
    LCMD_T(KC_N), LALT_T(KC_R), LCTL_T(KC_T), LSFT_T(KC_S), KC_G,        KC_Y, RSFT_T(KC_H), RCTL_T(KC_A), RALT_T(KC_E), RGUI_T(KC_I),
    KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,                               KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH,
     LT(_MOUSE, KC_ESC), LT(_NAV,KC_SPC), LT(_NUM,KC_TAB),        LT(_SYM, KC_ENT), LT(_MEDIA, KC_BSPC),  LT(_FUNC, KC_DEL)
  ),
  [_NAV] = LAYOUT_split_3x5_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_AGIN, KC_PSTE, KC_COPY, KC_CUT , KC_UNDO,
    KC_LCMD, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                            KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, CW_TOGG,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_INS ,
                               XXXXXXX, XXXXXXX, XXXXXXX,           KC_ENT, KC_BSPC, KC_DEL
  ),
  [_NUM] = LAYOUT_split_3x5_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_LBRC, KC_7   , KC_8   , KC_9   , KC_RBRC,
    KC_LCMD, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                            KC_EQL , KC_4   , KC_5   , KC_6   , KC_SCLN,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_BSLS, KC_1   , KC_2   , KC_3   , KC_GRV ,
                               XXXXXXX, XXXXXXX, XXXXXXX,          KC_MINS, KC_0   , KC_DOT
  ),
  [_SYM] = LAYOUT_split_3x5_3(
    KC_LCBR, KC_MINS, KC_GRV , KC_RCBR, KC_EQL ,                            KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,
    KC_LPRN, KC_BSLS, KC_SLSH, KC_RPRN, KC_ASTR,                            KC_PLUS, KC_DLR , KC_PERC, KC_CIRC, KC_COLN,
    KC_LBRC, KC_LABK, KC_RABK, KC_RBRC, KC_PLUS,                            KC_PIPE, KC_EXLM, KC_AT  , KC_HASH, KC_TILD,
                               KC_PEQL, KC_UNDS, KC_PMNS,          XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_FUNC] = LAYOUT_split_3x5_3(
    KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PSCR,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_SCRL,                            XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LCMD,
    KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_PAUS,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               KC_APP , KC_SPC , KC_TAB ,          XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_MOUSE] = LAYOUT_split_3x5_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LCMD, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                            KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX,          KC_BTN2, KC_BTN1, KC_BTN3
  ),
  [_MEDIA] = LAYOUT_split_3x5_3(
    KC_MRWD, XXXXXXX, XXXXXXX, KC_MFFD, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,                            XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LCMD,
    XXXXXXX, KC_MUTE, KC_MUTE, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               KC_MUTE, KC_MPLY, KC_MSTP,          XXXXXXX, XXXXXXX, XXXXXXX
  ),
};

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
    case KC_MINS:
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
      return true;

      // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}
