#include "casemode.h"
#include "keymap.h"
#include "layers.h"

casemode_type current_casemode       = CM_DISABLED;
uint16_t      casemode_start_time    = 0;
bool          next_space_is_exit     = false;
uint16_t      tap_before_next_letter = KC_NO;
bool          next_letter_is_upper   = false;
bool          all_letters_are_upper  = false;

void disable_casemode() {
    current_casemode = CM_DISABLED;
    unlock_number_layer();
}

void begin_casemode(casemode_type casemode) {
    disable_casemode();
    if (casemode == CM_DISABLED) {
        return;
    }
    casemode_start_time    = timer_read();
    next_space_is_exit     = false;
    tap_before_next_letter = KC_NO;
    all_letters_are_upper  = (casemode == CM_CAPS_WORD || casemode == CM_CAPS_LOCK || casemode == CM_SCREAMING_SNAKE_WORD);
    next_letter_is_upper   = false;
    if (casemode == CM_NUM_WORD || casemode == CM_NUM_LOCK) {
        lock_number_layer();
    }
    current_casemode = casemode;
}

casemode_type get_current_casemode() {
    return current_casemode;
}

bool start_casemode_and_return_if_started(uint16_t pressed_keycode) {
    switch (pressed_keycode) {
        case UC_CAPS_WORD:
            if (current_casemode == CM_CAPS_WORD && timer_elapsed(casemode_start_time) < 750) {
                begin_casemode(CM_CAPS_LOCK);
            } else if (current_casemode == CM_CAPS_WORD || current_casemode == CM_CAPS_LOCK) {
                disable_casemode();
            } else {
                begin_casemode(CM_CAPS_WORD);
            }
            return true;
        case UC_SNAKE_WORD:
            if (current_casemode == CM_SNAKE_WORD && timer_elapsed(casemode_start_time) < 750) {
                begin_casemode(CM_SCREAMING_SNAKE_WORD);
            } else if (current_casemode == CM_SNAKE_WORD || current_casemode == CM_SCREAMING_SNAKE_WORD) {
                disable_casemode();
            } else {
                begin_casemode(CM_SNAKE_WORD);
            }
            return true;
        case UC_CAMEL_WORD:
            if (current_casemode == CM_CAMEL_WORD && timer_elapsed(casemode_start_time) < 750) {
                next_letter_is_upper = true;
            } else if (current_casemode == CM_CAMEL_WORD) {
                disable_casemode();
            } else {
                begin_casemode(CM_CAMEL_WORD);
            }
            return true;
        case UC_NUM_WORD:
            if (current_casemode == CM_NUM_WORD && timer_elapsed(casemode_start_time) < 750) {
                begin_casemode(CM_NUM_LOCK);
            } else if (current_casemode == CM_NUM_WORD || current_casemode == CM_NUM_LOCK) {
                disable_casemode();
            } else {
                begin_casemode(CM_NUM_WORD);
            }
            return true;
        default:
            break;
    }
    return false;
}

bool process_record_casemode(uint16_t keycode, keyrecord_t *record) {
    uint16_t pressed_keycode = get_pressed_keycode_for_event(keycode, record);
    if (start_casemode_and_return_if_started(pressed_keycode)) {
        return true;
    }
    if (current_casemode == CM_DISABLED || pressed_keycode == KC_NO) {
        return true;
    }

    if (pressed_keycode == KC_SPC) {
        if (next_space_is_exit) {
            disable_casemode();
            return true;
        }

        switch (current_casemode) {
            case CM_CAPS_WORD:
            case CM_NUM_WORD:
                disable_casemode();
                return true;

            case CM_SNAKE_WORD:
            case CM_SCREAMING_SNAKE_WORD:
                tap_before_next_letter = KC_UNDERSCORE;
                next_space_is_exit     = true;
                return false;

            case CM_CAMEL_WORD:
                next_letter_is_upper = true;
                next_space_is_exit   = true;
                return false;

            case CM_CAPS_LOCK:
            case CM_NUM_LOCK:
            case CM_DISABLED:
                break;
        }
        return true;
    }
    next_space_is_exit = false;

    if (pressed_keycode == KC_BSPC) {
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

    switch (pressed_keycode) {
        case KC_A ... KC_Z:
            if (tap_before_next_letter != KC_NO) {
                tap_code16(tap_before_next_letter);
                tap_before_next_letter = KC_NO;
            }
            if (next_letter_is_upper || all_letters_are_upper) {
                add_oneshot_mods(MOD_LSFT);
                next_letter_is_upper = false;
            }
            break;

        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_UNDS:
        case KC_UP:
        case KC_DOWN:
        case KC_LEFT:
        case KC_RIGHT:
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
            if (current_casemode == CM_NUM_WORD) {
                break;
            }
            // Fallthrough!
        default:
            if (current_casemode != CM_CAPS_LOCK && current_casemode != CM_NUM_LOCK) {
                disable_casemode();
            }
            return true;
    }

    return true;
}
