#pragma once
#include "keycodes.h"
#include "layers.h"
#include QMK_KEYBOARD_H

enum keycodes {
    SW_WIN = SAFE_RANGE,
    SW_TAB,
    SW_PREV,

    CO_DELETE,
    CO_BACKSPACE,
    CO_TAB,
    CO_SHIFT_TAB,
    CO_ENTER,

    UC_NUM_WORD
};

#define __NOP__ KC_NO

#define UC_ONESHOT_SHIFT KC_F13
#define UC_CAPS_WORD KC_F14
#define UC_SNAKE_WORD KC_F15
#define UC_CAMEL_WORD KC_F16

// Home row helpers (should only be used below)
#define HOME_ROW_1(kc) LGUI_T(kc)
#define HOME_ROW_2(kc) LALT_T(kc)
#define HOME_ROW_3(kc) LCTL_T(kc)
#define HOME_ROW_4(kc) LSFT_T(kc)

#define HOME_ROW_5(kc) RSFT_T(kc)
#define HOME_ROW_6(kc) RCTL_T(kc)
#define HOME_ROW_7(kc) LALT_T(kc)
#define HOME_ROW_8(kc) RGUI_T(kc)

// Default home row
#define MT_A HOME_ROW_1(KC_A)
#define MT_S HOME_ROW_2(KC_S)
#define MT_D HOME_ROW_3(KC_D)
#define MT_F HOME_ROW_4(KC_F)

#define MT_J HOME_ROW_5(KC_J)
#define MT_K HOME_ROW_6(KC_K)
#define MT_L HOME_ROW_7(KC_L)
#define MT_SCLN HOME_ROW_8(KC_SCLN)

// Symbols home row
#define MT_CMLW HOME_ROW_2(UC_CAMEL_WORD)
#define MT_SNKW HOME_ROW_3(UC_SNAKE_WORD)
#define MT_CAPW HOME_ROW_4(UC_CAPS_WORD)

// Numbers home row
#define MT_1 HOME_ROW_1(KC_1)
#define MT_2 HOME_ROW_2(KC_2)
#define MT_3 HOME_ROW_3(KC_3)
#define MT_4 HOME_ROW_4(KC_4)

#define MT_7 HOME_ROW_5(KC_7)
#define MT_8 HOME_ROW_6(KC_8)
#define MT_9 HOME_ROW_7(KC_9)
#define MT_0 HOME_ROW_8(KC_0)

// Function home row
#define MT_F1 HOME_ROW_1(KC_F1)
#define MT_F2 HOME_ROW_2(KC_F2)
#define MT_F3 HOME_ROW_3(KC_F3)
#define MT_F4 HOME_ROW_4(KC_F4)

#define MT_F7 HOME_ROW_5(KC_F7)
#define MT_F8 HOME_ROW_6(KC_F8)
#define MT_F9 HOME_ROW_7(KC_F9)
#define MT_F10 HOME_ROW_8(KC_F10)

// Layer tap and layers
#define LT_SBSP LT(LAYER_SHORTCUTS, KC_BACKSPACE)
#define LT_SDEL LT(LAYER_SHORTCUTS, KC_DELETE)
#define LT_NSPC LT(LAYER_NAVIGATION, KC_SPACE)
#define LT_SOSS LT(LAYER_SYMBOLS, UC_ONESHOT_SHIFT)
#define LT_FENT LT(LAYER_FUNCTION, KC_ENTER)

#define LA_QWER DF(LAYER_QWERTY)
#define LA_SHRT MO(LAYER_SHORTCUTS)
#define LA_FUNC MO(LAYER_FUNCTION)
#define LA_GAME DF(LAYER_GAMING)
#define LA_GAMX MO(LAYER_GAMING_EXTRA)

uint16_t get_pressed_keycode_for_event(uint16_t keycode, const keyrecord_t *record);
