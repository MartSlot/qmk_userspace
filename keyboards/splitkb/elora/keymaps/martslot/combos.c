#include QMK_KEYBOARD_H

const uint16_t PROGMEM combo_delete[]    = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM combo_backspace[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM combo_tab[]       = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_shift_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_enter[]     = {KC_J, KC_K, COMBO_END};
combo_t                key_combos[]      = {
    COMBO(combo_delete, KC_DEL), COMBO(combo_backspace, KC_BSPC), COMBO(combo_tab, KC_TAB), COMBO(combo_shift_tab, S(KC_TAB)), COMBO(combo_enter, KC_ENT),
};
