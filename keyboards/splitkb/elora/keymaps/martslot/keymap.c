#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "swapper.h"

enum layers {
    LAYER_QWERTY = 0,
    LAYER_NAVIGATION,
    LAYER_SYMBOLS,
    LAYER_NUMBERS,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,

    SW_WIN,
    SW_TAB,
	
	UC_TST1,
	UC_TST2,
};


// Aliases for readability
#define __NOP__ KC_NO 

#define QWERTY   DF(L_QWERTY)

#define UC_NTAB C(KC_TAB)
#define UC_PTAB C(S(KC_TAB))
#define UC_STAB S(KC_TAB)

#define UC_PREV A(KC_LEFT)
#define UC_NEXT A(KC_RGHT)

#define LA_NAV MO(LAYER_NAVIGATION)
#define LA_SYM MO(LAYER_SYMBOLS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = LAYOUT_myr(
      __NOP__ , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,          _______, _______,          KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 , UC_TST2,
      __NOP__ , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,          _______, _______,          KC_Y ,  KC_U ,  KC_I ,   KC_O ,  KC_P , UC_TST1,
      KC_LCTL , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,          _______, _______,          KC_H ,  KC_J ,  KC_K ,   KC_L ,KC_SCLN, __NOP__,
      __NOP__ , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , __NOP__, __NOP__, __NOP__, __NOP__, KC_N ,  KC_M ,KC_COMM, KC_DOT ,KC_QUOT, __NOP__,
                                __NOP__ , KC_LGUI, __NOP__, LA_NAV,  KC_SPC,  KC_LSFT, LA_SYM, __NOP__, KC_LEFT, KC_RGHT,

      KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE,                         KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE
    ),

    [LAYER_NAVIGATION] = LAYOUT_myr(
      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, KC_VOLU,
      __NOP__, SW_TAB,  SW_WIN,  UC_PTAB, UC_NTAB, KC_DEL,           __NOP__, __NOP__,          KC_DEL,  KC_HOME, KC_UP,   KC_END,  __NOP__, KC_VOLD,
      __NOP__, OS_GUI,  OS_ALT,  OS_CTRL, OS_SHFT, KC_BSPC,          __NOP__, __NOP__,          KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, __NOP__, KC_MUTE,
      __NOP__, UC_PREV, UC_NEXT, UC_STAB, KC_TAB,  KC_ENT,  __NOP__, __NOP__, __NOP__, __NOP__, KC_ENT,  KC_PGDN, KC_PGUP, __NOP__, __NOP__, KC_MPLY,
                                 __NOP__, __NOP__, __NOP__, _______, _______, _______, _______, __NOP__, __NOP__, __NOP__,

      __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__,                   __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__
    ),

    [LAYER_SYMBOLS] = LAYOUT_myr(
      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD,          __NOP__, __NOP__,          KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV,  __NOP__,
      __NOP__, KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR,           __NOP__, __NOP__,          KC_HASH, OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI, __NOP__,
      __NOP__, KC_PLUS, KC_PIPE, KC_AT,   KC_SLSH, KC_PERC, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, KC_BSLS, KC_AMPR, KC_EXLM, KC_QUES, __NOP__,
                                 __NOP__, __NOP__, __NOP__, _______, _______, _______, _______, __NOP__, __NOP__, __NOP__,

      __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__,                   __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__
    ),

    [LAYER_NUMBERS] = LAYOUT_myr(
      __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__, __NOP__,          __NOP__, __NOP__, __NOP__, __NOP__, __NOP__, __NOP__,
      __NOP__, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             __NOP__, __NOP__,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    __NOP__,
      __NOP__, OS_GUI,  OS_ALT,  OS_CTRL, OS_SHFT, KC_F11,           __NOP__, __NOP__,          KC_F12,  OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,  __NOP__,
      __NOP__, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   __NOP__, __NOP__, __NOP__, __NOP__, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  __NOP__,
                                 __NOP__, __NOP__, __NOP__, _______, _______, _______, _______, __NOP__, __NOP__, __NOP__,

      __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__,                   __NOP__, __NOP__, __NOP__, __NOP__,          __NOP__
    ),

/*
    [LAYER_QWERTY] = LAYOUT_myr(
      KC_ESC  , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,          _______, _______,          KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 , KC_BSPC,
      KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,          _______, _______,          KC_Y ,  KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
      KC_LCTL , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,          _______, _______,          KC_H ,  KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
      KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , __NOP__, __NOP__, __NOP__, __NOP__, KC_N ,  KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                __NOP__ , KC_LGUI, __NOP__, LA_NAV,  KC_SPC,  KC_LSFT, LA_SYM, __NOP__, KC_LEFT, KC_RGHT,

      KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE,                         KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP,    KC_MUTE
    ),
*/

// /*
//  * Layer template - LAYOUT_myr
//  *
//  * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  *
//  * ,-----------------------------.      ,------.                ,---------------------------.      ,------.
//  * |        |      |      |      |      |      |                |      |      |      |      |      |      |
//  * `-----------------------------'      `------'                `---------------------------'      '------'
//  */
//     [_LAYERINDEX] = LAYOUT_myr(
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//
//       _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,          _______
//     ),
};


bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_GUI:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool sw_lang_active = false;
uint8_t char_offset = 0;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LALT, KC_TAB, SW_WIN, OS_SHFT,
        keycode, record
    );
    update_swapper(
        &sw_lang_active, KC_LCTL, KC_TAB, SW_TAB, OS_SHFT,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LGUI, OS_GUI,
        keycode, record
    );
	
    if (keycode == UC_TST1) {
        if (record->event.pressed) {
			char_offset += 10;
		}
	}	
    if (keycode == UC_TST2) {
        if (record->event.pressed) {
			char_offset -= 10;
		}
	}

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, LAYER_NAVIGATION, LAYER_SYMBOLS, LAYER_NUMBERS);
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    if (is_keyboard_master()) {
		
      /*        uint8_t layer = get_highest_layer(layer_state | default_layer_state); 
		
		oled_write_P(PSTR("Layer: "), false);
        oled_write(get_u8_str(layer, ' '), false);
		
        oled_write_P(PSTR("Size: "), false);
        oled_write(get_u8_str(oled_max_lines(), '0'), false);
        oled_write_P(PSTR("x"), false);
        oled_write(get_u8_str(oled_max_chars(), '0'), false); */
		
		oled_write_P(PSTR("Offset: "), false);
        oled_write(get_u8_str(char_offset, ' '), false);
		oled_advance_page(true);
		
		
		for (int i = 0; i < 10; i++)
		{
			oled_write_char(char_offset + i, false);
			oled_write_P(PSTR(" "), false);		
		}
		
        // Keyboard LED Status
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock ? PSTR(" NUM") : PSTR("    "), false);
        oled_write_P(led_usb_state.caps_lock ? PSTR("CAP") : PSTR("   "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCR") : PSTR("   "), false);

        // QMK Logo
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x81,0x82,0x83,0x84,0x0a,
            0xa1,0xa2,0xa3,0xa4,0x85,0x86,0x87,0x88,0x89,0x0a,
            0xc1,0xc2,0xc3,0xc4,0xa5,0xa6,0xa7,0xa8,0xa9,0x0a,
            0x8a,0x8b,0x8c,0x8d,0xc5,0xc6,0xc7,0xc8,0xc9,0x0a,
            0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0x00
        };
        // clang-format on
        oled_set_cursor(0, oled_max_lines()-5);
        oled_write_P(qmk_logo, false);
    } else {
        // Elora sigil
        // clang-format off
        static const char PROGMEM elora_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,224,240,248,120, 56, 60,188,158,158,222,206,207,207,207,239,239,239,239,239,239,207,207,207,206,222,158,158,188, 60, 56,120,248,240,224,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,224,248,252,126, 31,143,199,227,243,249,124, 60, 30, 31, 15,  7,  7,  3,  3,  3,131,193,225,241,249,253,255,255,255,255,127, 63, 31, 15,  7,  7,  7,143,223,254,252,252,249,243,227,199,143, 31,126,252,248,224,192,  0,  0,  0,  0,  0,
            0,192,240,254,255, 63,  7,227,248,252,127, 31, 15,  3,  1,  0,  0,  0,128,192,224,240,248,252,254,255,255,255,127, 63, 31, 15,  7,  3,  1,128,192,224,240,248,252,254,255,255,255,255,127, 63, 31, 15,  7, 15, 31,255,252,248,227,  7, 63,255,254,240,192,  0,252,255,255,255,  1,224,255,255,255,  7,  0,  0,  0,  0,  0,  0,  0,  0, 31, 31, 31, 31, 31, 15,  7,  3,  1,  0,  0,  0,240,248,252,254,255,255,255,255,127, 63, 31, 15,  7,  3,  1,128,192,224,240,248,252,254,255,255,255,255,255,255,224,  1,255,255,255,252,
            63,255,255,255,128,  7,255,255,255,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,224,240,248,248,248,248,248,248,  0,  3,  3,  3,  3,  3,  3,  1,128,192,224,240,248,252,254,255,255,255,127, 63, 31, 15,  7,  3,  1,224,255,255,255,  7,128,255,255,255, 63,  0,  3, 15,127,255,252,224,199, 31, 63,254,248,240,192,128,  0,  0,  0,  0, 31, 31, 31, 31, 31, 31, 15,  7,  3,  1,  0,  0,  0,  0,  0,  0, 62, 63, 63, 63, 63, 63, 31, 15,  7,  3,  1,  0,  0,  0,128,192,240,248,254, 63, 31,199,224,252,255,127, 15,  3,  0, 
            0,  0,  0,  0,  0,  3,  7, 31, 63,126,248,241,227,199,207,159, 62, 60,120,248,240,224,224,192,192,192,192,128,128,128,128,128,128,128,128,128,128,192,192,192,192,224,224,240,248,120, 60, 62,159,207,199,227,241,248,126, 63, 31,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7,  7, 15, 31, 30, 28, 60, 61,121,121,123,115,243,243,243,247,247,247,247,247,247,243,243,243,115,123,121,121, 61, 60, 28, 30, 31, 15,  7,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        };
        // clang-format on
        oled_set_cursor(0, (oled_max_lines()/2)-4); // logo is 8 lines high, so center vertically
        oled_write_raw_P(elora_logo, sizeof(elora_logo));
    }

    return false;
}
#endif

/*
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  // Your code goes here
}
#endif
*/
