/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

#define LT_1(KC) LT(1, KC)
#define LT_2(KC) LT(2, KC)
#define LT_3(KC) LT(3, KC)
#define LT_4(KC) LT(4, KC)
#define LT_5(KC) LT(5, KC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
      KC_Q         , KC_W         , KC_E         , KC_R         , KC_T         , KC_Y          , KC_U         , KC_I         , KC_O         , KC_P            ,
      LGUI_T(KC_A) , LALT_T(KC_S) , LCTL_T(KC_D) , LSFT_T(KC_F) , KC_G         , KC_H          , LSFT_T(KC_J) , LCTL_T(KC_K) , LALT_T(KC_L) , LGUI_T(KC_SCLN) ,
      KC_Z         , KC_X         , KC_C         , KC_V         , KC_B         , KC_N          , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH         ,
      LT_3(KC_ESC) , LT_2(KC_SPC) , KC_TAB       , LT_5(KC_DEL) , LT_1(KC_ENT) , LT_4(KC_BSPC)
  ),
  [1] = LAYOUT(
      KC_LBRC , KC_7 , KC_8    , KC_9    , KC_RBRC , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
      KC_SCLN , KC_4 , KC_5    , KC_6    , KC_EQL  , XXXXXXX , KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI ,
      KC_GRV  , KC_1 , KC_2    , KC_3    , KC_BSLS , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
      KC_DOT  , KC_0 , KC_MINS , XXXXXXX , _______ , XXXXXXX
  ),
  [2] = LAYOUT(
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_PGUP , KC_HOME , KC_UP   , KC_END   , XXXXXXX ,
      KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , XXXXXXX , KC_PGDN , KC_LEFT , KC_DOWN , KC_RIGHT , XXXXXXX ,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , S(KC_EQL) , KC_MINS , S(KC_MINS)  , XXXXXXX ,
      XXXXXXX , _______ , XXXXXXX , KC_DEL  , KC_ENT  , KC_BSPC
  ),
  [3] = LAYOUT(
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_VOLU , XXXXXXX , XXXXXXX ,
      KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , XXXXXXX , XXXXXXX , KC_MPRV , KC_VOLD , KC_VOLU , KC_MNXT ,
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
      _______ , XXXXXXX , XXXXXXX , KC_STOP , KC_MPLY , KC_MUTE
  ),

  [4] = LAYOUT(
      KC_F12  , KC_F7  , KC_F8  , KC_F9   , KC_PSCR , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
      KC_F11  , KC_F4  , KC_F5  , KC_F6   , KC_SCRL , XXXXXXX , KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI ,
      KC_F10  , KC_F1  , KC_F2  , KC_F3   , KC_PAUS , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
      XXXXXXX , KC_SPC , KC_TAB , XXXXXXX , XXXXXXX , _______
  ),

  [5] = LAYOUT(
      S(KC_COMM) , KC_LBRC    , KC_RBRC    , S(KC_DOT) , S(KC_2)    , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
      S(KC_SCLN) , S(KC_9)    , S(KC_0)    , KC_RBRC   , S(KC_EQL)  , XXXXXXX , KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI ,
      S(KC_GRV)  , S(KC_LBRC) , S(KC_RBRC) , S(KC_1)   , S(KC_BSLS) , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
      S(KC_9)    , S(KC_0)    , S(KC_MINS) , _______   , XXXXXXX    , XXXXXXX
  )
};
