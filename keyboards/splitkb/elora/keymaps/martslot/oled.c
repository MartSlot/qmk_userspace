#include "shared/keymap.h"
#include "shared/layers.h"
#include "shared/leader.h"
#include "shared/casemode.h"

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        uint8_t layer = get_highest_layer(layer_state | default_layer_state);
        oled_write_ln_P(PSTR("Layer:"), false);
        switch (layer) {
            case LAYER_QWERTY:
                oled_write_ln_P(PSTR("> QWERTY"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("Q W E R T"), false);
                oled_write_ln_P(PSTR("A S D F G"), false);
                oled_write_ln_P(PSTR("Z X C V B"), false);
                oled_write_ln_P(PSTR("   Bsp Spc"), false);
                break;
            case LAYER_SHORTCUTS:
                oled_write_P(PSTR("> Shortcut"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("Q W E R T"), false);
                oled_write_ln_P(PSTR("A S D F G"), false);
                oled_write_ln_P(PSTR("Z X C V Y"), false);
                oled_write_ln_P(PSTR("   Bsp Spc"), false);
                break;
            case LAYER_NAVIGATION:
                oled_write_P(PSTR("> Navigatn"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_P(PSTR("Esc\x09 NwPw\x09"), false);
                oled_write_P(PSTR("g a c s Re"), false);
                oled_write_ln_P(PSTR("Gam NtPt\x09"), false);
                oled_write_ln_P(PSTR("   Bsp Spc"), false);
                break;
            case LAYER_SYMBOLS:
                oled_write_ln_P(PSTR("> Symbols"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("' < > \" `"), false);
                oled_write_ln_P(PSTR("! - + = #"), false);
                oled_write_ln_P(PSTR("^ / * \\ $"), false);
                oled_write_ln_P(PSTR("   Del Num"), false);
                break;
            case LAYER_NUMBERS:
                oled_write_ln_P(PSTR("> Numbers"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("\x09 \x09 \x09 \x09 \x09"), false);
                oled_write_ln_P(PSTR("1 2 3 4 5"), false);
                oled_write_ln_P(PSTR("\x09 \x09 \x09 \x09 \x09"), false);
                oled_write_ln_P(PSTR("   Bsp Spc"), false);
                break;
            case LAYER_FUNCTION:
                oled_write_P(PSTR("> Function"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("\x09 \x09 \x09 \x09 \x09"), false);
                oled_write_P(PSTR("F1F2F3F4F5"), false);
                oled_write_ln_P(PSTR("\x09 \x09\x09 F11\x09"), false);
                oled_write_ln_P(PSTR("   Bsp Spc"), false);
                break;
            case LAYER_GAMING:
                oled_write_ln_P(PSTR("> Game"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("e Q W E R"), false);
                oled_write_ln_P(PSTR("s A S D G"), false);
                oled_write_ln_P(PSTR("c Z X C V"), false);
                oled_write_ln_P(PSTR("   Bsp Spc"), false);
                break;
            case LAYER_GAMING_EXTRA:
                oled_write_ln_P(PSTR("> Game+"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("1 2 3 4 5"), false);
                oled_write_ln_P(PSTR("6 7 8 9 0"), false);
                oled_write_ln_P(PSTR("B G T I M"), false);
                oled_write_ln_P(PSTR("   Bsp Spc"), false);
                break;
        }

        oled_advance_page(true);
        oled_advance_page(true);

        oled_write_P(PSTR("Lead: "), false);
        if (leader_active) {
            oled_write_ln_P(PSTR("On"), true);
        } else {
            oled_write_ln_P(PSTR("Off"), false);
        }

        oled_write_P(PSTR("Case Mode:"), false);
        switch (get_current_casemode()) {
            case CM_DISABLED:
                oled_write_ln_P(PSTR("Disabled"), false);
                break;
            case CM_CAPS_WORD:
                oled_write_ln_P(PSTR("Caps Word"), true);
                break;
            case CM_CAPS_LOCK:
                oled_write_ln_P(PSTR("Caps Lock"), true);
                break;
            case CM_SNAKE_WORD:
                oled_write_ln_P(PSTR("Snake"), true);
                break;
            case CM_SCREAMING_SNAKE_WORD:
                oled_write_ln_P(PSTR("Scr.Snake"), true);
                break;
            case CM_CAMEL_WORD:
                oled_write_ln_P(PSTR("Camel"), true);
                break;
            case CM_NUM_WORD:
                oled_write_ln_P(PSTR("Num Case"), true);
                break;
            case CM_NUM_LOCK:
                oled_write_ln_P(PSTR("Num Lock"), true);
                break;
        }

        /*oled_write_P(PSTR("Offset: "), false);
        oled_write(get_u8_str(char_offset, ' '), false);
        oled_advance_page(true);

        for (int i = 0; i < 10; i++)
        {
            oled_write_char(char_offset + i, false);
            oled_write_P(PSTR(" "), false);
        }*/
    } else {
        uint8_t layer = get_highest_layer(layer_state | default_layer_state);
        oled_write_ln_P(PSTR("Layer:"), false);
        switch (layer) {
            case LAYER_QWERTY:
                oled_write_ln_P(PSTR("> QWERTY"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("Y U I O P"), false);
                oled_write_ln_P(PSTR("H J K L '"), false);
                oled_write_ln_P(PSTR("N M , . \x09"), false);
                oled_write_ln_P(PSTR("Sft Ent"), false);
                break;
            case LAYER_SHORTCUTS:
                oled_write_P(PSTR("> Shortcut"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("\x09 \x09 \x09 \x09 \x09"), false);
                oled_write_ln_P(PSTR("\x09 \x09 \x09 \x09 \x09"), false);
                oled_write_ln_P(PSTR("\x09 \x09 \x09 \x09 \x09"), false);
                oled_write_ln_P(PSTR("Sft Ent"), false);
                break;
            case LAYER_NAVIGATION:
                oled_write_P(PSTR("> Navigatn"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_P(PSTR("PuHo\x18 EnPd"), false);
                oled_write_ln_P(PSTR("\x11 \x1B \x19 \x1A \x09"), false);
                oled_write_P(PSTR("\x09 RtBsDel\x09"), false);
                oled_write_ln_P(PSTR("Sft Ent"), false);
                break;
            case LAYER_SYMBOLS:
                oled_write_ln_P(PSTR("> Symbols"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("; & [ ] %"), false);
                oled_write_ln_P(PSTR(": _ ( ) ?"), false);
                oled_write_ln_P(PSTR("~ | { } @"), false);
                oled_write_ln_P(PSTR("Sft Ent"), false);
                break;
            case LAYER_NUMBERS:
                oled_write_ln_P(PSTR("> Numbers"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("\x09 \x09 \x09 \x09 \x09"), false);
                oled_write_ln_P(PSTR("6 7 8 9 0"), false);
                oled_write_ln_P(PSTR("\x09 \x09 \x09 \x09 \x09"), false);
                oled_write_ln_P(PSTR("Sft Ent"), false);
                break;
            case LAYER_FUNCTION:
                oled_write_P(PSTR("> Function"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("\x09 \x09 \x09 \x09 \x09"), false);
                oled_write_P(PSTR("F6F7F8F9F0"), false);
                oled_write_ln_P(PSTR("\x09 F12\x09 \x09 \x09"), false);
                oled_write_ln_P(PSTR("Sft Ent"), false);
                break;
            case LAYER_GAMING:
                oled_write_ln_P(PSTR("> Game"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_ln_P(PSTR("Y U I O P"), false);
                oled_write_ln_P(PSTR("H J K L :"), false);
                oled_write_ln_P(PSTR("N M , . '"), false);
                oled_write_ln_P(PSTR("Sft Sym"), false);
                break;
            case LAYER_GAMING_EXTRA:
                oled_write_ln_P(PSTR("> Game+"), false);
                oled_write_ln_P(PSTR(""), false);
                oled_write_P(PSTR("\x09 SwMpV+V-"), false);
                oled_write_ln_P(PSTR("\x09 \x09 \x09 \x09 \x09"), false);
                oled_write_ln_P(PSTR("\x09 \x09 \x09 \x09 \x09"), false);
                oled_write_ln_P(PSTR("Sft Exit"), false);
                break;
        }
    }

    return false;
}
#endif
