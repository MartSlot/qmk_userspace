#include QMK_KEYBOARD_H

#include "keymap.h"
#include "layers.h"
#include "oneshot.h"
#include "swapper.h"

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,

    SW_WIN,
    SW_TAB,

    UC_TST1,
    UC_TST2,
};

// Aliases for readability
#define __NOP__ KC_NO

#define UC_UNDO C(KC_Z)
#define UC_CUT C(KC_X)
#define UC_COPY C(KC_C)
#define UC_PSTE C(KC_V)
#define UC_REDO C(KC_Y)

#define UC_NTAB C(KC_TAB)
#define UC_PTAB C(S(KC_TAB))
#define UC_STAB S(KC_TAB)

#define UC_PREV A(KC_LEFT)
#define UC_NEXT A(KC_RGHT)

#define LA_QWER DF(LAYER_QWERTY)
#define LA_NAVI MO(LAYER_NAVIGATION)
#define LA_SYMB MO(LAYER_SYMBOLS)

#define LA_GAME DF(LAYER_GAMING)
#define LA_GAMX MO(LAYER_GAMING_EXTRA)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT_myr(
      KC_ESC,  __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, UC_TST2,
      __NOP__, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             __NOP__, __NOP__,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    UC_TST1,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             __NOP__, __NOP__,          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, __NOP__,
      __NOP__, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,  KC_ENT,  __NOP__, __NOP__, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, __NOP__,
                                 __NOP__, KC_LGUI, __NOP__, LA_NAVI, KC_SPC,  KC_LSFT, LA_SYMB, __NOP__, KC_LEFT, KC_RGHT,

      KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE,                         KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE
    ), 

    [LAYER_NAVIGATION] = LAYOUT_myr(
      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, KC_VOLU,
      __NOP__, KC_ESC,  SW_WIN,  UC_PTAB, UC_NTAB, QK_AREP,          __NOP__, __NOP__,          KC_DEL,  KC_HOME, KC_UP,   KC_END,  __NOP__, KC_VOLD,
      __NOP__, OS_GUI,  OS_ALT,  OS_CTRL, OS_SHFT, QK_REP,           __NOP__, __NOP__,          QK_LEAD, KC_LEFT, KC_DOWN, KC_RGHT, __NOP__, KC_MUTE,
      __NOP__, UC_UNDO, UC_CUT,  UC_COPY, UC_PSTE, UC_REDO, KC_BSPC, __NOP__, __NOP__, __NOP__, KC_ENT,  KC_PGDN, KC_PGUP, __NOP__, __NOP__, KC_MPLY,
                                 LA_GAME, __NOP__, __NOP__, _______, _______, _______, _______, __NOP__, __NOP__, __NOP__,

      __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__,                   __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__
    ),

    [LAYER_SYMBOLS] = LAYOUT_myr(
      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, KC_VOLU,
      __NOP__, KC_QUOT, KC_LABK, KC_RABK, KC_DQUO, __NOP__,          __NOP__, __NOP__,          KC_GRV,  KC_COLN, KC_LBRC, KC_RBRC, KC_PERC, KC_VOLD,
      __NOP__, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,          __NOP__, __NOP__,          KC_PIPE, KC_UNDS, KC_LPRN, KC_RPRN, KC_QUES, KC_MUTE,
      __NOP__, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_DLR,  __NOP__, __NOP__, __NOP__, __NOP__, KC_TILD, KC_AMPR, KC_LCBR, KC_RCBR, KC_AT,   KC_MPLY,
                                 __NOP__, __NOP__, __NOP__, _______, _______, _______, _______, __NOP__, __NOP__, __NOP__,

      __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__,                   __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__
    ), 

    [LAYER_NUMBERS] = LAYOUT_myr(
      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             __NOP__, __NOP__,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    __NOP__,
      __NOP__, OS_GUI,  OS_ALT,  OS_CTRL, OS_SHFT, KC_F11,           __NOP__, __NOP__,          KC_F12,  OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,  __NOP__,
      __NOP__, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   __NOP__, __NOP__, __NOP__, __NOP__, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  __NOP__,
                                 __NOP__, __NOP__, __NOP__, _______, _______, _______, _______, __NOP__, __NOP__, __NOP__,

      __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__,                   __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__
    ),
    
    [LAYER_GAMING] = LAYOUT_myr(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             __NOP__, __NOP__,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    __NOP__,
      __NOP__, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,             __NOP__, __NOP__,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    __NOP__,
      __NOP__, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,             __NOP__, __NOP__,          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, __NOP__,
      __NOP__, KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    __NOP__, __NOP__, __NOP__, __NOP__, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, __NOP__,
                                 __NOP__, KC_LGUI, __NOP__, KC_SPC,  LA_GAMX, KC_LSFT, LA_QWER, __NOP__, KC_LEFT, KC_RGHT,

      __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__,                   __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__
    ),

    [LAYER_GAMING_EXTRA] = LAYOUT_myr(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,             __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, KC_B,    KC_G,    KC_T,    KC_I,    KC_M,    __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
                                 __NOP__, __NOP__, __NOP__, KC_ENT,  _______, _______, _______, __NOP__, __NOP__, __NOP__,

      __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__,                   __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__
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

bool    sw_win_active  = false;
bool    sw_lang_active = false;
uint8_t char_offset    = 0;

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

    if (keycode == UC_TST1) {
        if (record->event.pressed) {
            char_offset += 10;
        }
    }
    if (keycode == UC_TST2) {
        if (record->event.pressed) {
            char_offset -= 10;
        }
    }

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
