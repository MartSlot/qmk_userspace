#include "combos.h"

enum combos { COMBO_REBOOT_LEFT, COMBO_REBOOT_RIGHT, COMBO_TAB, COMBO_SHIFT_TAB };

const uint16_t PROGMEM combo_reboot_left[]  = {KC_1, KC_2, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_reboot_right[] = {KC_3, KC_4, KC_P, COMBO_END};
const uint16_t PROGMEM combo_tab[]          = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_shift_tab[]    = {KC_S, KC_D, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    [COMBO_REBOOT_LEFT]          = COMBO(combo_reboot_left, QK_BOOTLOADER),
    [COMBO_REBOOT_RIGHT]         = COMBO(combo_reboot_right, QK_BOOTLOADER),
    [COMBO_TAB]                  = COMBO(combo_tab, CO_TAB),
    [COMBO_SHIFT_TAB]            = COMBO(combo_shift_tab, S(CO_SHIFT_TAB)),
};
// clang-format on

uint16_t last_keycode    = 0;
uint16_t last_event_time = 0;

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (timer_elapsed(last_event_time) < 100 && combo->keycode != last_keycode) {
        return false;
    }
    return true;
}

bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    if (combo->keycode == last_keycode && timer_elapsed(last_event_time) < 1000) {
        return false;
    }
    return true;
}

bool process_record_combo(uint16_t keycode, keyrecord_t *record) {
    last_keycode    = keycode;
    last_event_time = record->event.time;

    switch (keycode) {
        case CO_TAB:
            if (record->event.pressed) {
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case CO_SHIFT_TAB:
            if (record->event.pressed) {
                register_weak_mods(MOD_LSFT);
                register_code(KC_TAB);
                unregister_weak_mods(MOD_LSFT);
            } else {
                register_weak_mods(MOD_LSFT);
                unregister_code(KC_TAB);
                unregister_weak_mods(MOD_LSFT);
            }
            break;
        default:
            break;
    }

    return true;
}

void default_layer_state_set_combo(layer_state_t state) {
    if (IS_LAYER_ON_STATE(state, LAYER_GAMING)) {
        combo_disable();
    } else {
        combo_enable();
    }
}
