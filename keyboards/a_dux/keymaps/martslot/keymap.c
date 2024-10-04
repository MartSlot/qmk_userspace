#include "shared/keymap.h"

#include "shared/casemode.h"
#include "shared/combos.h"
#include "shared/layers.h"
#include "shared/switcher.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        MT_A,    MT_S,    MT_D,    MT_F,    KC_G,                      KC_H,    MT_J,    MT_K,    MT_L,    MT_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  __NOP__,
                                            LT_SBSP, LT_NSPC, LT_SOSS, LT_FENT
    ),

    [LAYER_COMBOS] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
                                            KC_1,    KC_2,    KC_3,    KC_4
    ),

    [LAYER_SHORTCUTS] = LAYOUT(
        C(KC_Q), C(KC_W), C(KC_E), C(KC_R), C(KC_T),                   __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
        C(KC_A), C(KC_S), C(KC_D), C(KC_F), C(KC_G),                   __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
        C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y),                   __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
                                            _______, _______, QK_AREP, _______
    ),

    [LAYER_NAVIGATION] = LAYOUT(
        KC_ESC,  SW_PREV, SW_TAB,  SW_WIN,  __NOP__,                   KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PGDN,
        KC_LGUI, MT_CMLW, MT_SNKW, MT_CAPW, __NOP__,                   QK_LEAD, KC_LEFT, KC_DOWN, KC_RGHT, __NOP__,
        LA_GAME, __NOP__, KC_LEFT, KC_RGHT, __NOP__,                   __NOP__, KC_ENT,  KC_BSPC, KC_DEL,  __NOP__,
                                            _______, _______, _______, _______
    ),

    [LAYER_SYMBOLS] = LAYOUT(
        KC_QUOT, KC_LABK, KC_RABK, KC_DQUO, __NOP__,                   KC_GRV,  KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC,
        KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,                   KC_COLN, KC_UNDS, KC_LPRN, KC_RPRN, KC_QUES,
        KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_DLR,                    KC_TILD, KC_PIPE, KC_LCBR, KC_RCBR, KC_AT,
                                            LT_SDEL, _______, _______, _______
    ),

    [LAYER_NUMBERS] = LAYOUT(
        __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,                   __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
        MT_1,    MT_2,    MT_3,    MT_4,    KC_5,                      KC_6,    MT_7,    MT_8,    MT_9,    MT_0,
        KC_MINS, KC_SLSH, KC_ASTR, KC_BSLS, __NOP__,                   __NOP__, __NOP__, KC_COMM, KC_DOT,  __NOP__,
                                            _______, _______, _______, _______
    ),

    [LAYER_FUNCTION] = LAYOUT(
        __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,                   __NOP__, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU,
        MT_F1,   MT_F2,   MT_F3,   MT_F4,   KC_F5,                     KC_F6,   MT_F7,   MT_F8,   MT_F9,   MT_F10 ,
        __NOP__, __NOP__, __NOP__, KC_F11,  __NOP__,                   __NOP__, KC_F12,  __NOP__, __NOP__, __NOP__,
                                            _______, _______, _______, _______
    ),
    
    [LAYER_GAMING] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
                                            LA_GAMX, KC_SPC,  KC_LSFT, LA_QWER
    ),

    [LAYER_GAMING_EXTRA] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
        KC_B,    KC_G,    KC_T,    KC_I,    KC_M,                      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
                                             _______, KC_ENT, _______, _______
    ),

};
// clang-format on

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_NSPC:
        case LT_SOSS:
            return true;
        default:
            return false;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_NSPC:
        case LT_SOSS:
            return QUICK_TAP_TERM - 40;
        default:
            return QUICK_TAP_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_casemode(keycode, record)) {
        return false;
    }
    if (!process_record_switcher(keycode, record)) {
        return false;
    }
    if (!process_record_combo(keycode, record)) {
        return false;
    }

    if (get_pressed_keycode_for_event(keycode, record) == UC_ONESHOT_SHIFT) {
        add_oneshot_mods(MOD_LSFT);
        return false;
    }

    return true;
}

uint16_t get_pressed_keycode_for_event(uint16_t keycode, const keyrecord_t *record) {
    if (!record->event.pressed) {
        return KC_NO;
    }

    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            if (record->tap.count == 0) {
                return KC_NO;
            }
            return QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            if (record->tap.count == 0) {
                return KC_NO;
            }
            return QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
        case CO_DELETE:
            return KC_DELETE;
        case CO_BACKSPACE:
            return KC_BACKSPACE;
        case CO_TAB:
            return KC_TAB;
        case CO_SHIFT_TAB:
            return LSFT(KC_TAB);
        case CO_ENTER:
            return KC_ENTER;
        default:
            return keycode;
    }
}
