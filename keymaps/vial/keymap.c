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
#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q , KC_W , KC_E     , KC_R     , KC_T     , KC_Y     , KC_U     , KC_I     , KC_O   , KC_P    ,
    HM_A , HM_S , HM_D     , HM_F     , KC_G     , KC_H     , HM_J     , HM_K     , HM_L   , HM_QUOT ,
    KC_Z , KC_X , KC_C     , KC_V     , KC_B     , KC_N     , KC_M     , KC_COMM  , KC_DOT , KC_SLSH ,
                  LTHUMB_L , LTHUMB_M , LTHUMB_R , RTHUMB_L , LTHUMB_M , RTHUMB_R
  ),
  [_NUM] = LAYOUT(
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_LBRC , KC_7 , KC_8   , KC_9 , KC_RBRC ,
    KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , KC_NO , KC_EQL  , KC_4 , KC_5   , KC_6 , KC_SCLN ,
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_BSLS , KC_1 , KC_2   , KC_3 , KC_GRV  ,
                        KC_NO   , KC_NO   , KC_NO , KC_MINS , KC_0 , KC_DOT
  ),
  [_SYM] = LAYOUT(
    KC_NO   , KC_LCBR , KC_RCBR , KC_NO   , KC_NO , KC_LCBR , KC_AMPR , KC_ASTR , KC_LPRN , KC_RCBR ,
    KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , KC_NO , KC_PLUS , KC_DLR  , KC_PERC , KC_CIRC , KC_COLN ,
    KC_NO   , KC_LBRC , KC_RBRC , KC_NO   , KC_NO , KC_PIPE , KC_EXLM , KC_AT   , KC_HASH , KC_TILD ,
                        KC_NO   , KC_NO   , KC_NO , KC_UNDS , KC_LPRN , KC_RPRN
  ),
  [_NAV] LAYOUT(
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_PGUP , KC_HOME , KC_UP   , KC_END   , KC_NO   ,
    KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , KC_NO   , KC_PGDN , KC_LEFT , KC_DOWN , KC_RIGHT , KC_BSPC ,
    U_UND   , U_CUT   , U_CPY   , U_PST   , U_RDO   , CW_TOGG , KC_ENT  , KC_NO   , KC_NO    , KC_DEL  ,
                        KC_DEL  , KC_TAB  , KC_BSPC , KC_NO   , KC_NO   , KC_NO
  ),
  [_FUN] = LAYOUT(
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_PSCR , KC_F7  , KC_F8  , KC_F9 , KC_F12 ,
    KC_LGUI , KC_LALT , KC_LCTL , KC_LSFT , KC_NO , KC_SCRL , KC_F4  , KC_F5  , KC_F6 , KC_F11 ,
    KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_PAUS , KC_F1  , KC_F2  , KC_F3 , KC_F10 ,
                        KC_NO   , KC_NO   , KC_NO , KC_TAB  , KC_ENT , KC_APP
  ),
  [_MEDIA] = LAYOUT(
    KC_NO , KC_NO   , KC_VOLU , KC_NO   , KC_BRIU , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,
    KC_NO , KC_MPRV , KC_VOLD , KC_MNXT , KC_BRID , KC_NO , KC_LSFT , KC_LCTL , KC_LALT , KC_LGUI ,
    KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,
                      KC_MUTE , KC_MPLY , KC_MSTP , KC_NO , KC_NO   , KC_NO
  )
};

// ## KEY OVERRIDES
// shift bspace -> delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// grave escape
const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRV));
const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_ALT, KC_ESC, KC_GRV);

// brightness mapping
const key_override_t brightness_up_override = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_VOLU, KC_BRIU, 1<<_MEDIA, MOD_MASK_CSG, ko_option_no_reregister_trigger);
const key_override_t brightness_down_override = ko_make_with_layers_negmods_and_options(MOD_MASK_ALT, KC_VOLD, KC_BRID, 1<<_MEDIA, MOD_MASK_SAG, ko_option_no_reregister_trigger);

const key_override_t *key_overrides[] = {
  &delete_key_override,
  &tilde_esc_override,
  &grave_esc_override,
  &brightness_up_override,
  &brightness_down_override,
};

// ## Combos
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM comma_dot_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM l_quot_combo[] = {HM_L, HM_QUOT, COMBO_END};
combo_t key_combos_UNSETTABLE_USING_VIAL[] = {
    COMBO(we_combo, KC_ESC),
    COMBO(io_combo, KC_BSPC),
    COMBO(xc_combo, KC_TAB),
    COMBO(comma_dot_combo, KC_ENT),
    COMBO(l_quot_combo, KC_SCLN),
};
