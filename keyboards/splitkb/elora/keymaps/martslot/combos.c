#include QMK_KEYBOARD_H
#include "keymap.h"

enum combos {
    COMBO_DELETE,
    COMBO_BACKSPACE,
    COMBO_TAB,
    COMBO_SHIFT_TAB,
    COMBO_ENTER,
};

const uint16_t PROGMEM combo_delete[]    = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_backspace[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_tab[]       = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_shift_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_enter[]     = {KC_J, KC_K, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    [COMBO_DELETE]    = COMBO(combo_delete, KC_DEL),
    [COMBO_BACKSPACE] = COMBO(combo_backspace, KC_BSPC),
    [COMBO_TAB]       = COMBO(combo_tab, KC_TAB),
    [COMBO_SHIFT_TAB] = COMBO(combo_shift_tab, S(KC_TAB)),
    [COMBO_ENTER]     = COMBO(combo_enter, KC_ENT),
};
// clang-format on

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool get_combo_must_hold(uint16_t index, combo_t *combo) {
    // For now, all combos are tap only
    return false;
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // For now, all combos are tap only
    return true;
}
