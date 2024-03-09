#pragma once
#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "layers.h"

enum keycodes {
    SW_NWIN = SAFE_RANGE,
    SW_PWIN,
    SW_NTAB,
    SW_PTAB,

    CO_DELETE,
    CO_BACKSPACE,
    CO_TAB,
    CO_SHIFT_TAB,
    CO_ENTER,

    UC_CAPS_WORD,
    UC_SNAKE_WORD,
    UC_SCREAMING_SNAKE_WORD,
    UC_CAMEL_WORD,
    UC_NUM_WORD
};

#define __NOP__ KC_NO

#define HOME_ROW_1(kc) LGUI_T(kc)
#define HOME_ROW_2(kc) LALT_T(kc)
#define HOME_ROW_3(kc) LCTL_T(kc)
#define HOME_ROW_4(kc) LSFT_T(kc)

#define HOME_ROW_5(kc) RSFT_T(kc)
#define HOME_ROW_6(kc) RCTL_T(kc)
#define HOME_ROW_7(kc) LALT_T(kc)
#define HOME_ROW_8(kc) RGUI_T(kc)

#define MT_GA HOME_ROW_1(KC_A)
#define MT_AS HOME_ROW_2(KC_S)
#define MT_CD HOME_ROW_3(KC_D)
#define MT_SF HOME_ROW_4(KC_F)

#define MT_SJ HOME_ROW_5(KC_J)
#define MT_CK HOME_ROW_6(KC_K)
#define MT_AL HOME_ROW_7(KC_L)
#define MT_GS HOME_ROW_8(KC_SCLN)

#define MT_G1 HOME_ROW_1(KC_1)
#define MT_A2 HOME_ROW_2(KC_2)
#define MT_C3 HOME_ROW_3(KC_3)
#define MT_S4 HOME_ROW_4(KC_4)

#define MT_S7 HOME_ROW_5(KC_7)
#define MT_C8 HOME_ROW_6(KC_8)
#define MT_A9 HOME_ROW_7(KC_9)
#define MT_G0 HOME_ROW_8(KC_0)

#define MT_GF1 HOME_ROW_1(KC_F1)
#define MT_AF2 HOME_ROW_2(KC_F2)
#define MT_CF3 HOME_ROW_3(KC_F3)
#define MT_SF4 HOME_ROW_4(KC_F4)

#define MT_SF7 HOME_ROW_5(KC_F7)
#define MT_CF8 HOME_ROW_6(KC_F8)
#define MT_AF9 HOME_ROW_7(KC_F9)
#define MT_GF10 HOME_ROW_8(KC_F10)

#define UC_REPEAT_KEY_ALIAS KC_F13

#define LT_NSPC LT(LAYER_NAVIGATION, KC_SPACE)
#define LT_SREP LT(LAYER_SYMBOLS, UC_REPEAT_KEY_ALIAS)

#define LA_QWER DF(LAYER_QWERTY)
#define LA_SHRT MO(LAYER_SHORTCUTS)
#define LA_NAVI MO(LAYER_NAVIGATION)
#define LA_FUNC MO(LAYER_FUNCTION)
#define LA_SYMB MO(LAYER_SYMBOLS)

#define LA_GAME DF(LAYER_GAMING)
#define LA_GAMX MO(LAYER_GAMING_EXTRA)

uint16_t get_tap_keycode_for_key(uint16_t keycode);
