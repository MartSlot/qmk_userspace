#include "combos.h"
#include "keycodes.h"

enum combos { COMBO_DELETE, COMBO_BACKSPACE, COMBO_TAB, COMBO_SHIFT_TAB, COMBO_ENTER, COMBO_CAPS_WORD, COMBO_SNAKE_WORD, COMBO_SCREAMING_SNAKE_WORD, COMBO_CAMEL_WORD, COMBO_NUM_WORD };

const uint16_t PROGMEM combo_delete[]               = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_backspace[]            = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_tab[]                  = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_shift_tab[]            = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_enter[]                = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_caps_word[]            = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM combo_snake_word[]           = {KC_D, KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM combo_screaming_snake_word[] = {KC_S, KC_D, KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM combo_pascal_word[]          = {KC_F, KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_camel_word[]           = {KC_F, KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_num_word[]             = {KC_2, KC_3, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    [COMBO_DELETE]               = COMBO(combo_delete, CO_DELETE),
    [COMBO_BACKSPACE]            = COMBO(combo_backspace, CO_BACKSPACE),
    [COMBO_TAB]                  = COMBO(combo_tab, CO_TAB),
    [COMBO_SHIFT_TAB]            = COMBO(combo_shift_tab, S(CO_SHIFT_TAB)),
    [COMBO_ENTER]                = COMBO(combo_enter, CO_ENTER),
    [COMBO_CAPS_WORD]            = COMBO(combo_caps_word, UC_CAPS_WORD),
    [COMBO_SNAKE_WORD]           = COMBO(combo_snake_word, UC_SNAKE_WORD),
    [COMBO_SCREAMING_SNAKE_WORD] = COMBO(combo_screaming_snake_word, UC_SCREAMING_SNAKE_WORD),
    [COMBO_CAMEL_WORD]           = COMBO(combo_camel_word, UC_CAMEL_WORD),
    [COMBO_NUM_WORD]             = COMBO(combo_num_word, UC_NUM_WORD),
};
// clang-format on

uint16_t last_keycode    = 0;
uint16_t last_event_time = 0;

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case COMBO_CAPS_WORD:
        case COMBO_SNAKE_WORD:
        case COMBO_SCREAMING_SNAKE_WORD:
        case COMBO_CAMEL_WORD:
        case COMBO_NUM_WORD:
            return true;
    }
    if (combo->keycode == last_keycode && timer_elapsed(last_event_time) < 1000) {
        return false;
    }
    return true;
}

bool process_record_combo(uint16_t keycode, keyrecord_t *record) {
    last_keycode    = keycode;
    last_event_time = record->event.time;

    switch (keycode) {
        case CO_DELETE:
            if (record->event.pressed) {
                register_code(KC_DELETE);
            } else {
                unregister_code(KC_DELETE);
            }
            break;
        case CO_BACKSPACE:
            if (record->event.pressed) {
                register_code(KC_BACKSPACE);
            } else {
                unregister_code(KC_BACKSPACE);
            }
            break;
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
        case CO_ENTER:
            if (record->event.pressed) {
                register_code(KC_ENTER);
            } else {
                unregister_code(KC_ENTER);
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
