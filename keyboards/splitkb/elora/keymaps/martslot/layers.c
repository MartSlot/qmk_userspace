#include "layers.h"
#include "combos.h"
#include QMK_KEYBOARD_H

bool is_number_layer_locked = false;

void lock_number_layer(void) {
    is_number_layer_locked = true;
    layer_on(LAYER_NUMBERS);
}

void unlock_number_layer(void) {
    is_number_layer_locked = false;
    layer_off(LAYER_NUMBERS);
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    default_layer_state_set_combo(state);
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    const layer_state_t NUMBER_LAYER_MASK = ((layer_state_t)1 << LAYER_NUMBERS);

    bool is_navigation_layer_on = IS_LAYER_ON_STATE(state, LAYER_NAVIGATION);
    bool is_symbol_layer_on     = IS_LAYER_ON_STATE(state, LAYER_SYMBOLS);

    if (is_number_layer_locked) {
        if (is_navigation_layer_on || is_symbol_layer_on) {
            state = (state & ~NUMBER_LAYER_MASK);
        } else {
            state = state | NUMBER_LAYER_MASK;
        }
    } else {
        if (is_navigation_layer_on && is_symbol_layer_on) {
            state = state | NUMBER_LAYER_MASK;
        } else {
            state = (state & ~NUMBER_LAYER_MASK);
        }
    }
    return state;
}
