#include "keymap.h"

#include "casemode.h"
#include "combos.h"
#include "switcher.h"

#include QMK_KEYBOARD_H

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
