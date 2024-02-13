#include "swapper.h"
#include "keymap.h"

bool swap_win_active = false;
bool swap_tab_active = false;

void update_swapper(uint16_t keycode, const keyrecord_t *record, bool *active, uint16_t next_key, uint16_t prev_key, uint16_t holddown_key, uint16_t reverse_key) {
    if (keycode == next_key || keycode == prev_key) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(holddown_key);
            }
            if (keycode == prev_key) {
                register_code(reverse_key);
            }
            register_code(KC_TAB);
        } else {
            if (keycode == prev_key) {
                unregister_code(reverse_key);
            }
            unregister_code(KC_TAB);
        }
    } else if (*active && keycode != reverse_key && keycode != KC_LEFT && keycode != KC_RIGHT) {
        unregister_code(holddown_key);
        *active = false;
    }
}

bool process_record_swapper(uint16_t keycode, keyrecord_t *record) {
    update_swapper(keycode, record, &swap_win_active, SW_NWIN, SW_PWIN, KC_LALT, KC_LSFT);
    update_swapper(keycode, record, &swap_tab_active, SW_NTAB, SW_PTAB, KC_LCTL, KC_LSFT);
    return true;
}
