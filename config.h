//

#pragma once

/* Key matrix configuration. */

#define USE_SERIAL
#define MATRIX_COL_PINS_RIGHT {C6, D7, E6, B4, B5}

/* Handedness. */
#define EE_HANDS
#define BOOTMAGIC_LITE_ROW_RIGHT 4
#define BOOTMAGIC_LITE_COLUMN_RIGHT 4

// Tap-hold configuration for home row mods.
#define TAPPING_TERM 230
#define IGNORE_MOD_TAP_INTERRUPT
// ignore-mod-tap-interrupt is being removed, does it really require hold_on_other_key_press fn => false
// #define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 100

// combos
#define COMBO_TERM 50

