#pragma once
#include QMK_KEYBOARD_H

// Layer Declarations
enum layers {
  _BASE,
  _NUM,
  _SYM,
  _NAV,
  _FUN,
  _MEDIA,
};

#define LT_BASE(KC) LT(_BASE, KC)
#define LT_NUM(KC) LT(_NUM, KC)
#define LT_SYM(KC) LT(_SYM, KC)
#define LT_NAV(KC) LT(_NAV, KC)
#define LT_FUN(KC) LT(_FUN, KC)
#define LT_MEDIA(KC) LT(_MEDIA, KC)

#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO

// define home row keys
#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LSFT_T(KC_F)
#define HM_J LSFT_T(KC_J)
#define HM_K LCTL_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_QUOT LGUI_T(KC_QUOT)

// thumb keys
#define LTHUMB_L LT_FUN(KC_DEL)
#define LTHUMB_M LT_NUM(KC_SPC)
#define LTHUMB_R LT_SYM(KC_TAB)
#define RTHUMB_L KC_LSFT
#define RTHUMB_M LT_NAV(KC_ENT)
#define RTHUMB_R LT_MEDIA(KC_ESC)
