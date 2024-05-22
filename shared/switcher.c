#include <os_detection.h>
#include "switcher.h"
#include "keymap.h"

enum switch_mode { SM_DISABLED, SM_TABS, SM_WINDOWS };

enum switch_mode current_switchmode = SM_DISABLED;

bool process_record_switcher(uint16_t keycode, keyrecord_t *record) {
    uint16_t window_switch_hold_keycode = KC_LALT;
    uint16_t tab_switch_hold_keycode    = KC_LCTL;
    if (detected_host_os() == OS_MACOS) {
        window_switch_hold_keycode = KC_LCTL;
        tab_switch_hold_keycode    = KC_LEFT_GUI;
    }

    if (keycode == KC_UP || keycode == KC_DOWN || keycode == KC_LEFT || keycode == KC_RIGHT) {
        return true;
    }
    if (current_switchmode == SM_WINDOWS && keycode != SW_WIN && keycode != SW_PREV) {
        unregister_code(window_switch_hold_keycode);
        current_switchmode = SM_DISABLED;
    }
    if (current_switchmode == SM_TABS && keycode != SW_TAB && keycode != SW_PREV) {
        unregister_code(tab_switch_hold_keycode);
        current_switchmode = SM_DISABLED;
    }

    if (!record->event.pressed) {
        return true;
    }

    if (keycode == SW_WIN) {
        if (current_switchmode == SM_DISABLED) {
            current_switchmode = SM_WINDOWS;
            register_code(window_switch_hold_keycode);
        }
        tap_code16(KC_TAB);
    }

    if (keycode == SW_TAB) {
        if (current_switchmode != SM_TABS) {
            current_switchmode = SM_TABS;
            register_code(tab_switch_hold_keycode);
        }
        tap_code16(KC_TAB);
    }

    if (keycode == SW_PREV) {
        if (current_switchmode == SM_DISABLED) {
            current_switchmode = SM_WINDOWS;
            register_code(window_switch_hold_keycode);
        }
        tap_code16(S(KC_TAB));
    }
    return true;
}
