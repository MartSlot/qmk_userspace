#pragma once
#include "oneshot.h"

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,

    SW_WIN,
    SW_TAB,
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

#define LT_NSPC LT(LAYER_NAVIGATION, KC_SPACE)
#define LT_SREP LT(LAYER_SYMBOLS, QK_REPEAT_KEY)

#define UC_UNDO C(KC_Z)
#define UC_CUT C(KC_X)
#define UC_COPY C(KC_C)
#define UC_PSTE C(KC_V)
#define UC_REDO C(KC_Y)

#define UC_NTAB C(KC_TAB)
#define UC_PTAB C(S(KC_TAB))

#define LA_QWER DF(LAYER_QWERTY)
#define LA_SHRT MO(LAYER_SHORTCUTS)
#define LA_NAVI MO(LAYER_NAVIGATION)
#define LA_FUNC MO(LAYER_FUNCTION)
#define LA_SYMB MO(LAYER_SYMBOLS)

#define LA_GAME DF(LAYER_GAMING)
#define LA_GAMX MO(LAYER_GAMING_EXTRA)

extern oneshot_state os_shft_state;
extern oneshot_state os_ctrl_state;
extern oneshot_state os_alt_state;
extern oneshot_state os_win_state;
