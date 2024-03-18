#include QMK_KEYBOARD_H
#include "keymap.h"

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PLUS:
        case KC_MINUS:
        case KC_ASTERISK:
        case KC_SLASH:
        case KC_EQUAL:
        case KC_EXCLAIM:
        case KC_LEFT_ANGLE_BRACKET:
        case KC_RIGHT_ANGLE_BRACKET:
        case KC_AMPERSAND:
        case KC_PIPE:
        case KC_COLON:
        case KC_DOUBLE_QUOTE:
        case KC_LEFT_BRACKET:
        case KC_LEFT_PAREN:
        case KC_LEFT_CURLY_BRACE:
            return true;
    }
    return false;
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    if (!shifted) {
        register_code16(keycode);
        return;
    }

    switch (keycode) {
        case KC_PLUS:
            SEND_STRING("+=");
            break;
        case KC_MINUS:
            SEND_STRING("-=");
            break;
        case KC_ASTERISK:
            SEND_STRING("*=");
            break;
        case KC_SLASH:
            SEND_STRING("//");
            break;
        case KC_EQUAL:
            SEND_STRING("==");
            break;
        case KC_EXCLAIM:
            SEND_STRING("!=");
            break;
        case KC_LEFT_ANGLE_BRACKET:
            SEND_STRING("<=");
            break;
        case KC_RIGHT_ANGLE_BRACKET:
            SEND_STRING(">=");
            break;
        case KC_AMPERSAND:
            SEND_STRING("&&");
            break;
        case KC_PIPE:
            SEND_STRING("||");
            break;
        case KC_COLON:
            SEND_STRING("::");
            break;
        case KC_DOUBLE_QUOTE:
            SEND_STRING("\"\"" SS_TAP(X_LEFT));
            break;
        case KC_LEFT_BRACKET:
            SEND_STRING("[]" SS_TAP(X_LEFT));
            break;
        case KC_LEFT_PAREN:
            SEND_STRING("()" SS_TAP(X_LEFT));
            break;
        case KC_LEFT_CURLY_BRACE:
            SEND_STRING("{}" SS_TAP(X_LEFT));
            break;
        default:
            register_code16(keycode);
            break;
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    if (!shifted) {
        unregister_code16(keycode);
        return;
    }

    switch (keycode) {
        case KC_PLUS:
        case KC_MINUS:
        case KC_ASTERISK:
        case KC_SLASH:
        case KC_EQUAL:
        case KC_EXCLAIM:
        case KC_LEFT_ANGLE_BRACKET:
        case KC_RIGHT_ANGLE_BRACKET:
        case KC_AMPERSAND:
        case KC_PIPE:
        case KC_COLON:
        case KC_DOUBLE_QUOTE:
        case KC_LEFT_BRACKET:
        case KC_LEFT_PAREN:
        case KC_LEFT_CURLY_BRACE:
            break;
        default:
            unregister_code16(keycode);
            break;
    }
}
