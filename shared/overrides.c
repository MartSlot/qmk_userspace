#include QMK_KEYBOARD_H

const key_override_t override_comma     = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_COMM);
const key_override_t override_dot       = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_DOT);
const key_override_t override_semicolon = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, KC_SCLN);
const key_override_t override_quote     = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_QUOT);

const key_override_t **key_overrides = (const key_override_t *[]){&override_comma, &override_dot, &override_semicolon, &override_quote, NULL};
