/* Copyright 2023 splitkb.com <support@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// Myriad boilerplate
// #define MYRIAD_ENABLE

// Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed
#define DEBOUNCE 10

// Above is default settings

#define PERMISSIVE_HOLD_PER_KEY
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM 200

#undef RGBLIGHT_DEFAULT_ON
#define RGBLIGHT_DEFAULT_ON false

#define SPLIT_LAYER_STATE_ENABLE

#define LEADER_NO_TIMEOUT
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 750

#define AUTO_SHIFT_MODIFIERS

#define COMBO_ONLY_FROM_LAYER 1
#define COMBO_SHOULD_TRIGGER
#define COMBO_TERM 50
#define COMBO_MUST_TAP_PER_COMBO
