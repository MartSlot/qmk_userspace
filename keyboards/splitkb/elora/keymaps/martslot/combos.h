#pragma once
#include QMK_KEYBOARD_H

bool process_record_combo(uint16_t keycode, keyrecord_t *record);

void default_layer_state_set_combo(layer_state_t state);
