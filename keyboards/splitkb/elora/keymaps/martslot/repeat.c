#include "repeat.h"
#include "keymap.h"

bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
    switch (keycode) {
        case KC_UP:
        case KC_DOWN:
        case KC_LEFT:
        case KC_RIGHT:
        case LT_SREP:
            return false;
    }

    return true;
}

bool process_record_repeat(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_SREP:
            if (record->tap.count) {
                repeat_key_invoke(&record->event);
                return false; // ignore further processing of key
            }
            break;
        default:
            break;
    }
    return true;
}
