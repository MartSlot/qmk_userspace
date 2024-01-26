#include "leader.h"

bool leader_active = false;

bool is_leader_active(void) {
    return leader_active;
}

void leader_start_user() {
    leader_active = true;
}

void leader_end_user(void) {
    leader_active = false;
    if (leader_sequence_one_key(KC_AT) || leader_sequence_two_keys(KC_A, KC_T)) {
        SEND_STRING("martslot@proton.me");
    } else if (leader_sequence_two_keys(KC_M, KC_S)) {
        SEND_STRING("Mart Slot");
    } else if (leader_sequence_three_keys(KC_A, KC_D, KC_D)) {
        SEND_STRING("Soeverein 78\n3817 HV\nAmersfoort");
    } else if (leader_sequence_five_keys(KC_P, KC_H, KC_O, KC_N, KC_E)) {
        SEND_STRING("+31630511860");
    } else if (leader_sequence_four_keys(KC_F, KC_O, KC_O, KC_N)) {
        SEND_STRING("0630511860");
    } else if (leader_sequence_four_keys(KC_C, KC_A, KC_P, KC_S)) {
        SEND_STRING(SS_TAP(X_CAPS_LOCK));
    }
}