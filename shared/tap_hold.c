#include "keymap.h"
#include QMK_KEYBOARD_H

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
