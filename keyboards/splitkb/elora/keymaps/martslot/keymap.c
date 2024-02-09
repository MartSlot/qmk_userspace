#include QMK_KEYBOARD_H

#include "keymap.h"
#include "layers.h"
#include "oneshot.h"
#include "swapper.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT(
      KC_ESC,  __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             __NOP__, __NOP__,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    __NOP__,
      KC_LCTL, MT_GA,   MT_AS,   MT_CD,   MT_SF,   KC_G,             __NOP__, __NOP__,          KC_H,    MT_SJ,   MT_CK,   MT_AL,   MT_GS,   __NOP__,
      __NOP__, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,  KC_ENT,  __NOP__, __NOP__, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, __NOP__,
                                 __NOP__, KC_LGUI, __NOP__, LA_SHRT, LT_NSPC, LT_SREP, LA_FUNC, __NOP__, KC_LEFT, KC_RGHT
    ),

    [LAYER_COMBOS] = LAYOUT(
      KC_ESC,  __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             __NOP__, __NOP__,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    __NOP__,
      __NOP__, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             __NOP__, __NOP__,          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, __NOP__,
      __NOP__, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    __NOP__, __NOP__, __NOP__, __NOP__, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, __NOP__,
                                 __NOP__, KC_LGUI, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, KC_LEFT, KC_RGHT
    ),

    [LAYER_SHORTCUTS] = LAYOUT(
      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, C(KC_Q), C(KC_W), C(KC_E), C(KC_R), C(KC_T),          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, C(KC_A), C(KC_S), C(KC_D), C(KC_F), C(KC_G),          __NOP__, __NOP__,          __NOP__, OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,  __NOP__,
      __NOP__, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y), KC_DEL , KC_ENT,  __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
                                 __NOP__, KC_LGUI, __NOP__, _______, _______, QK_AREP, _______, __NOP__, __NOP__, __NOP__
    ),

    [LAYER_NAVIGATION] = LAYOUT(
      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, KC_VOLU,
      __NOP__, KC_ESC,  __NOP__, __NOP__, SW_WIN,  __NOP__,          __NOP__, __NOP__,          KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PGDN, KC_VOLD,
      __NOP__, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, __NOP__,          __NOP__, __NOP__,          QK_LEAD, KC_LEFT, KC_DOWN, KC_RGHT, __NOP__, KC_MUTE,
      __NOP__, __NOP__, __NOP__, __NOP__, SW_TAB,  __NOP__, KC_BSPC, KC_ENT,  __NOP__, __NOP__, __NOP__, KC_ENT,  KC_BSPC, KC_DEL,  __NOP__, KC_MPLY,
                                 LA_GAME, __NOP__, __NOP__, _______, _______, _______, _______, __NOP__, __NOP__, __NOP__
    ),

    [LAYER_SYMBOLS] = LAYOUT(
      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, KC_VOLU,
      __NOP__, KC_QUOT, KC_LABK, KC_RABK, KC_DQUO, __NOP__,          __NOP__, __NOP__,          KC_GRV,  KC_COLN, KC_LBRC, KC_RBRC, KC_PERC, KC_VOLD,
      __NOP__, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,          __NOP__, __NOP__,          KC_PIPE, KC_UNDS, KC_LPRN, KC_RPRN, KC_QUES, KC_MUTE,
      __NOP__, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_DLR,  __NOP__, __NOP__, __NOP__, __NOP__, KC_TILD, KC_AMPR, KC_LCBR, KC_RCBR, KC_AT,   KC_MPLY,
                                 __NOP__, __NOP__, __NOP__, _______, _______, _______, _______, __NOP__, __NOP__, __NOP__
    ),

    [LAYER_NUMBERS] = LAYOUT(
      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, MT_G1,   MT_A2,   MT_C3,   MT_S4,   KC_5,             __NOP__, __NOP__,          KC_6,    MT_S7,   MT_C8,   MT_A9,   MT_G0,   __NOP__,
      __NOP__, KC_MINS, KC_SLSH, KC_ASTR, KC_BSLS, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, KC_COMM, KC_DOT,  __NOP__, __NOP__,
                                 __NOP__, __NOP__, __NOP__, _______, _______, _______, _______, __NOP__, __NOP__, __NOP__
    ),

    [LAYER_FUNCTION] = LAYOUT(
      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, MT_GF1,  MT_AF2,  MT_CF3,  MT_SF4,  KC_F5,            __NOP__, __NOP__,          KC_F6,   MT_SF7,  MT_CF8,  MT_AF9,  MT_GF10, __NOP__,
      __NOP__, __NOP__, __NOP__, __NOP__, KC_F11,  __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, KC_F12,  __NOP__, __NOP__,  __NOP__, __NOP__,
                                 __NOP__, __NOP__, __NOP__, _______, _______, _______, _______, __NOP__, __NOP__, __NOP__
    ),
    
    [LAYER_GAMING] = LAYOUT(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             __NOP__, __NOP__,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    __NOP__,
      __NOP__, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,             __NOP__, __NOP__,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    __NOP__,
      __NOP__, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,             __NOP__, __NOP__,          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, __NOP__,
      __NOP__, KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    __NOP__, __NOP__, __NOP__, __NOP__, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, __NOP__,
                                 __NOP__, KC_LGUI, __NOP__, LA_GAMX, KC_SPC,  KC_LSFT, LA_QWER, __NOP__, KC_LEFT, KC_RGHT
    ),

    [LAYER_GAMING_EXTRA] = LAYOUT(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,             __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, KC_B,    KC_G,    KC_T,    KC_I,    KC_M,    __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
                                 __NOP__, __NOP__, __NOP__, _______, KC_ENT, _______, _______, __NOP__, __NOP__, __NOP__
    ),

};
// clang-format on

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case LA_SYMB:
        case LA_NAVI:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case LA_SYMB:
        case LA_NAVI:
        case KC_LSFT:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_GUI:
            return true;
        default:
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1, KC_BSPC):
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

bool sw_win_active  = false;
bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_win_state  = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(&sw_win_active, KC_LALT, KC_TAB, SW_WIN, OS_SHFT, keycode, record);
    update_swapper(&sw_lang_active, KC_LCTL, KC_TAB, SW_TAB, OS_SHFT, keycode, record);

    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_win_state, KC_LGUI, OS_GUI, keycode, record);

    return true;
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    return false;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    layer_state_t new_state = update_tri_layer_state(state, LAYER_NAVIGATION, LAYER_SYMBOLS, LAYER_NUMBERS);

    if (get_highest_layer(state) >= LAYER_GAMING) {
        combo_disable();
    } else {
        combo_enable();
    }

    return new_state;
}
