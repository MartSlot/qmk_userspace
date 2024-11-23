#pragma once

#include "shared/keymap.h"

#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [LAYER_QWERTY] = SHARED_LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_VOLU,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_VOLD,
        KC_LSFT, MT_A,    MT_S,    MT_D,    MT_F,    KC_G,                      KC_H,    MT_J,    MT_K,    MT_L,    MT_QUOT, KC_MUTE,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  __NOP__, KC_MPLY,
                                                     KC_DEL,  KC_ENT,  __NOP__, __NOP__,
                          __NOP__, KC_LGUI, __NOP__, LT_SBSP, LT_NSPC, LT_SOSS, LT_FENT, __NOP__, KC_LEFT, KC_RGHT
    ),

    [LAYER_COMBOS] = SHARED_LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    __NOP__,
        __NOP__, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    __NOP__,
        __NOP__, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, __NOP__,
        __NOP__, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  __NOP__, __NOP__,
                                                     __NOP__, __NOP__, __NOP__, __NOP__,
                          __NOP__, KC_LGUI, __NOP__, KC_1,    KC_2,    KC_3,    KC_4,    __NOP__, KC_LEFT, KC_RGHT
    ),

    [LAYER_SHORTCUTS] = SHARED_LAYOUT(
        KC_ESC,  __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,                   __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
        __NOP__, C(KC_Q), C(KC_W), C(KC_E), C(KC_R), C(KC_T),                   __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
        __NOP__, C(KC_A), C(KC_S), C(KC_D), C(KC_F), C(KC_G),                   __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
        __NOP__, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y),                   __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
                                                     KC_DEL , KC_ENT,  __NOP__, __NOP__,
                          __NOP__, KC_LGUI, __NOP__, _______, _______, QK_AREP, _______, __NOP__, __NOP__, __NOP__
    ),

    [LAYER_NAVIGATION] = SHARED_LAYOUT(
        KC_ESC,  __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,                   __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
        __NOP__, KC_ESC,  SW_PREV, SW_TAB,  SW_WIN,  __NOP__,                   KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_PGDN, __NOP__,
        __NOP__, KC_LGUI, MT_CMLW, MT_SNKW, MT_CAPW, __NOP__,                   QK_LEAD, KC_LEFT, KC_DOWN, KC_RGHT, __NOP__, __NOP__,
        __NOP__, LA_GAME, __NOP__, KC_LEFT, KC_RGHT, __NOP__,                   __NOP__, KC_ENT,  KC_BSPC, KC_DEL,  __NOP__, __NOP__,
                                                     KC_BSPC, KC_ENT,  __NOP__, __NOP__,
                          LA_GAME, __NOP__, __NOP__, _______, _______, _______, _______, __NOP__, __NOP__, __NOP__
    ),

    [LAYER_SYMBOLS] = SHARED_LAYOUT(
        KC_ESC,  __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,                   __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
        __NOP__, KC_QUOT, KC_LABK, KC_RABK, KC_DQUO, KC_GRV,                    KC_SCLN, KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, __NOP__,
        __NOP__, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,                   KC_COLN, KC_UNDS, KC_LPRN, KC_RPRN, KC_QUES, __NOP__,
        __NOP__, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_DLR,                    KC_TILD, KC_PIPE, KC_LCBR, KC_RCBR, KC_AT,   __NOP__,
                                                     __NOP__, __NOP__, __NOP__, __NOP__,
                          __NOP__, __NOP__, __NOP__, LT_SDEL, _______, _______, _______, __NOP__, __NOP__, __NOP__
    ),

    [LAYER_NUMBERS] = SHARED_LAYOUT(
        KC_ESC,  __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,                   __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
        __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,                   __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
        __NOP__, MT_1,    MT_2,    MT_3,    MT_4,    KC_5,                      KC_6,    MT_7,    MT_8,    MT_9,    MT_0,    __NOP__,
        __NOP__, KC_MINS, KC_SLSH, KC_ASTR, KC_BSLS, __NOP__,                   __NOP__, __NOP__, KC_COMM, KC_DOT,  __NOP__, __NOP__,
                                                     __NOP__, __NOP__, __NOP__, __NOP__,
                          __NOP__, __NOP__, __NOP__, _______, _______, _______, _______, __NOP__, __NOP__, __NOP__
    ),

    [LAYER_FUNCTION] = SHARED_LAYOUT(
        KC_ESC,  __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,                   __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
        __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,                   __NOP__, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, __NOP__,
        __NOP__, MT_F1,   MT_F2,   MT_F3,   MT_F4,   KC_F5,                     KC_F6,   MT_F7,   MT_F8,   MT_F9,   MT_F10 , __NOP__,
        __NOP__, __NOP__, __NOP__, __NOP__, KC_F11,  __NOP__,                   __NOP__, KC_F12,  __NOP__, __NOP__, __NOP__, __NOP__,
                                                     __NOP__, __NOP__, __NOP__, __NOP__,
                          __NOP__, __NOP__, __NOP__, _______, _______, _______, _______, __NOP__, __NOP__, __NOP__
    ),

    [LAYER_GAMING] = SHARED_LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_VOLU,
        __NOP__, KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_VOLD,
        __NOP__, KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MUTE,
        __NOP__, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, KC_MPLY,
                                                     __NOP__, __NOP__, __NOP__, __NOP__,
                          __NOP__, KC_LGUI, __NOP__, LA_GAMX, KC_SPC,  LA_QWER, LA_GAMX, __NOP__, KC_LEFT, KC_RGHT
    ),

    [LAYER_GAMING_EXTRA] = SHARED_LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    __NOP__,
        __NOP__, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      SW_WIN,  KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, __NOP__,
        __NOP__, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
        __NOP__, KC_B,    KC_G,    KC_T,    KC_I,    KC_M,                      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
                                                     __NOP__, __NOP__, __NOP__, __NOP__,
                          __NOP__, __NOP__, __NOP__, _______, KC_ENT, _______, _______, __NOP__, __NOP__, __NOP__
    ),
};
// clang-format on
