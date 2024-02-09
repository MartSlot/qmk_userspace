#include QMK_KEYBOARD_H
#include "keymap.h"

enum combos {
    COMBO_DELETE,
    COMBO_BACKSPACE,
    COMBO_ENTER,
    COMBO_TAB,
};

const uint16_t PROGMEM combo_delete[]    = {MT_GA, MT_AS, MT_CD, COMBO_END};
const uint16_t PROGMEM combo_backspace[] = {MT_AS, MT_CD, MT_SF, COMBO_END};
const uint16_t PROGMEM combo_enter[]     = {MT_SJ, MT_CK, MT_AL, COMBO_END};
const uint16_t PROGMEM combo_tab[]       = {MT_CK, MT_AL, MT_GS, COMBO_END};
combo_t                key_combos[]      = {
    [COMBO_DELETE]    = COMBO(combo_delete, KC_DEL),
    [COMBO_BACKSPACE] = COMBO(combo_backspace, KC_BSPC),
    [COMBO_ENTER]     = COMBO(combo_tab, KC_TAB),
    [COMBO_TAB]       = COMBO(combo_enter, KC_ENT),
};
