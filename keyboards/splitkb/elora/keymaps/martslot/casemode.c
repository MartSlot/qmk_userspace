#include "casemode.h"
#include "keymap.h"
#include "layers.h"

casemode_type current_mode           = CM_DISABLED;
bool          next_space_is_exit     = false;
uint16_t      tap_before_next_letter = KC_NO;
bool          next_letter_is_upper   = false;
bool          all_letters_are_upper  = false;

void disable_casemode() {
    current_mode = CM_DISABLED;
    unlock_number_layer();
    layer_move(LAYER_QWERTY);
}

void begin_casemode(casemode_type casemode) {
    disable_casemode();
    if (casemode == CM_DISABLED) {
        return;
    }
    next_space_is_exit     = (casemode != CM_SNAKE_WORD && casemode != CM_SCREAMING_SNAKE_WORD);
    tap_before_next_letter = KC_NO;
    all_letters_are_upper  = (casemode == CM_CAPS_WORD || casemode == CM_CAPS_LOCK || casemode == CM_SCREAMING_SNAKE_WORD);
    next_letter_is_upper   = (casemode == CM_PASCAL_WORD);
    if (casemode == CM_NUM_WORD || casemode == CM_NUM_LOCK) {
        lock_number_layer();
    }
    current_mode = casemode;
}

casemode_type get_current_casemode() {
    return current_mode;
}

bool start_casemode_and_return_if_started(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return false;
    }

    switch (keycode) {
        case UC_CAPS_WORD:
            switch (current_mode) {
                case CM_CAPS_LOCK:
                    disable_casemode();
                    break;
                case CM_CAPS_WORD:
                    begin_casemode(CM_CAPS_LOCK);
                    break;
                default:
                    begin_casemode(CM_CAPS_WORD);
                    break;
            }
            return true;
        case UC_SNAKE_WORD:
            begin_casemode(CM_SNAKE_WORD);
            return true;
        case UC_SCREAMING_SNAKE_WORD:
            begin_casemode(CM_SCREAMING_SNAKE_WORD);
            return true;
        case UC_PASCAL_WORD:
            begin_casemode(CM_PASCAL_WORD);
            return true;
        case UC_CAMEL_WORD:
            begin_casemode(CM_CAMEL_WORD);
            return true;
        case UC_NUM_WORD:
            switch (current_mode) {
                case CM_DISABLED:
                    begin_casemode(CM_NUM_WORD);
                    break;
                case CM_NUM_WORD:
                    begin_casemode(CM_NUM_LOCK);
                    break;
                default:
                    disable_casemode();
                    break;
            }
            return true;
        default:
            break;
    }
    return false;
}

bool should_ignore_event(uint16_t keycode, keyrecord_t *record) {
    if (current_mode == CM_DISABLED || !record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            if (record->tap.count == 0) {
                return true;
            }
        default:
            break;
    }
    return false;
}
uint16_t last_key = KC_NO;

bool process_record_casemode(uint16_t keycode, keyrecord_t *record) {
    if (start_casemode_and_return_if_started(keycode, record)) {
        return true;
    }
    if (should_ignore_event(keycode, record)) {
        return true;
    }
    uint16_t tap_keycode = get_tap_keycode_for_key(keycode);

    if (tap_keycode == KC_SPC) {
        if (next_space_is_exit) {
            disable_casemode();
            return false;
        }
        next_space_is_exit = true;

        switch (current_mode) {
            case CM_CAPS_WORD:
            case CM_NUM_WORD:
                tap_code16(KC_SPC);
                disable_casemode();
                break;

            case CM_SNAKE_WORD:
            case CM_SCREAMING_SNAKE_WORD:
                tap_before_next_letter = KC_UNDERSCORE;
                break;

            case CM_PASCAL_WORD:
            case CM_CAMEL_WORD:
                next_letter_is_upper = true;
                break;

            case CM_CAPS_LOCK:
            case CM_NUM_LOCK:
            case CM_DISABLED:
                tap_code16(KC_SPC);
                break;
        }
        return false;
    }
    next_space_is_exit = false;

    if (tap_keycode == KC_BSPC) {
        if (next_letter_is_upper) {
            next_letter_is_upper = false;
            return false;
        }
        if (tap_before_next_letter != KC_NO) {
            tap_before_next_letter = KC_NO;
            return false;
        }
        tap_code16(KC_BSPC);
        return false;
    }

    switch (tap_keycode) {
        case KC_A ... KC_Z:
            if (tap_before_next_letter != KC_NO) {
                tap_code16(tap_before_next_letter);
                tap_before_next_letter = KC_NO;
            }
            if (next_letter_is_upper || all_letters_are_upper) {
                tap_code16(LSFT(tap_keycode));
                next_letter_is_upper = false;
            } else {
                tap_code16(tap_keycode);
            }
            return false;

        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_UNDS:
        case KC_UP:
        case KC_DOWN:
        case KC_LEFT:
        case KC_RIGHT:
            last_key = tap_keycode;
            if (tap_before_next_letter != KC_NO) {
                tap_code16(tap_before_next_letter);
                tap_before_next_letter = KC_NO;
            }
            next_letter_is_upper = false;
            break;

        case KC_DOT:
        case KC_PERC:
        case KC_COMM:
        case KC_PLUS:
        case KC_SLSH:
        case KC_ASTERISK:
        case KC_EQL:
        case KC_LPRN:
        case KC_RPRN:
            if (current_mode == CM_NUM_WORD) {
                break;
            }
            // Fallthrough!
        default:
            if (current_mode != CM_CAPS_LOCK && current_mode != CM_NUM_LOCK) {
                disable_casemode();
            }
            return true;
    }

    return true;
}
