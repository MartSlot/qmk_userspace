#pragma once

#include QMK_KEYBOARD_H

typedef enum { CM_DISABLED, CM_CAPS_WORD, CM_CAPS_LOCK, CM_SNAKE_WORD, CM_SCREAMING_SNAKE_WORD, CM_PASCAL_WORD, CM_CAMEL_WORD, CM_NUM_WORD, CM_NUM_LOCK } casemode_type;

void          disable_casemode(void);
void          begin_casemode(casemode_type type);
casemode_type get_current_casemode(void);

bool process_record_casemode(uint16_t keycode, keyrecord_t *record);
