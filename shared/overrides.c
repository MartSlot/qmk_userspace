#include QMK_KEYBOARD_H

const key_override_t override_comma = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_EXLM);
const key_override_t override_dot   = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUES);

const key_override_t **key_overrides = (const key_override_t *[]){&override_comma, &override_dot, NULL};
