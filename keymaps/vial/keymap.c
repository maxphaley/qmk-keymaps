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

// Layer Declarations
enum layers {
  U_BASE,
  U_NUM,
  U_SYM,
  U_NAV,
  U_FUN,
  U_MEDIA
};

#define LT_BASE(KC) LT(U_BASE, KC)
#define LT_NUM(KC) LT(U_NUM, KC)
#define LT_SYM(KC) LT(U_SYM, KC)
#define LT_NAV(KC) LT(U_NAV, KC)
#define LT_FUN(KC) LT(U_FUN, KC)
#define LT_MEDIA(KC) LT(U_MEDIA, KC)

#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [U_BASE] = LAYOUT(
    KC_Q         , KC_W         , KC_E           , KC_R           , KC_T            , KC_Y   , KC_U           , KC_I             , KC_O         , KC_P            ,
    LGUI_T(KC_A) , LALT_T(KC_S) , LCTL_T(KC_D)   , LSFT_T(KC_F)   , KC_G            , KC_H   , LSFT_T(KC_J)   , LCTL_T(KC_K)     , LALT_T(KC_L) , LGUI_T(KC_QUOT) ,
    KC_Z         , KC_X         , KC_C           , KC_V           , KC_B            , KC_N   , KC_M           , KC_COMM          , KC_DOT       , KC_SLSH         ,
                                  LT_FUN(KC_DEL) , LT_NUM(KC_SPC) , LT_SYM(KC_BSPC) , KC_TAB , LT_NAV(KC_ENT) , LT_MEDIA(KC_ESC)
  ),
  [U_NUM] = LAYOUT(
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_LBRC , KC_7 , KC_8   , KC_9 , KC_RBRC ,
    KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , KC_NO , KC_EQL  , KC_4 , KC_5   , KC_6 , KC_SCLN ,
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_BSLS , KC_1 , KC_2   , KC_3 , KC_GRV  ,
                        KC_NO   , KC_NO   , KC_NO , KC_MINS , KC_0 , KC_DOT
  ),
  [U_SYM] = LAYOUT(
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_LCBR , KC_AMPR , KC_ASTR , KC_LPRN , KC_RCBR ,
    KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , KC_NO , KC_PLUS , KC_DLR  , KC_PERC , KC_CIRC , KC_COLN ,
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_PIPE , KC_EXLM , KC_AT   , KC_HASH , KC_TILD ,
                        KC_NO   , KC_NO   , KC_NO , KC_UNDS , KC_LPRN , KC_RPRN
  ),
  [U_NAV] LAYOUT(
    KC_PGUP , KC_HOME , KC_UP   , KC_END  , KC_INS  , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,
    KC_PGDN , KC_LEFT , KC_DOWN , KC_RGHT , CW_TOGG , KC_NO , KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI ,
    U_UND   , U_CUT   , U_CPY   , U_PST   , U_RDO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,
                        KC_DEL  , KC_ENT  , KC_BSPC , KC_NO , KC_NO   , KC_NO
  ),
  [U_FUN] = LAYOUT(
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_PSCR , KC_F7  , KC_F8  , KC_F9 , KC_F12 ,
    KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , KC_NO , KC_SCRL , KC_F4  , KC_F5  , KC_F6 , KC_F11 ,
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_PAUS , KC_F1  , KC_F2  , KC_F3 , KC_F10 ,
                        KC_NO   , KC_NO   , KC_NO , KC_TAB  , KC_ENT , KC_APP
  ),
  [U_MEDIA] = LAYOUT(
    RGB_HUI , RGB_SAI , KC_VOLU , RGB_VAI , RGB_TOG , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,
    RGB_MOD , KC_MPRV , KC_VOLD , KC_MNXT , KC_NO   , KC_NO , KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI ,
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,
                        KC_MUTE , KC_MPLY , KC_MSTP , KC_NO , KC_NO   , KC_NO
  )
};

