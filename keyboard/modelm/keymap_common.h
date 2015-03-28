/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"


extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];


/* GH60 keymap definition macro
 * K2C, K31 and  K3C are extra keys for ISO
 */
#define KEYMAP( \
    K20, K32, K42, K41, K40, K60, K80, K91, K92, K62, K63, KB3, KC3,      KF3, KF4, KE6,                     \
    K22, K23, K33, K43, K53, K52, K72, K73, K83, K93, KA3, KA2, K82, K61, KC2, KE2, KD2, KB6, KC6, KD6, KD7, \
    K21, K24, K34, K44, K54, K15, K71, K74, K84, K94, KA4, KA1, K81, K65, KB2, KE3, KD3, KB4, KC4, KD4, KE4, \
    K31, K25, K35, K45, K55, K50, K70, K75, K85, K95, KA5, KA0, K66,                     KB1, KC1, KD1,      \
    K11, K26, K36, K46, K56, K57, K77, K76, K86, K96, KA7, K16,                KE0,      KB5, KC5, KD5, KE5, \
    K02,      KF0,                K67,                KF7,      K06,      KE7, KB7, KC7, KC0,      KD0       \
) { \
    { KC_##K20, KC_##K32, KC_##K42, KC_##K41, KC_##K40, KC_##K60, KC_##K80, KC_##K91, KC_##K92, KC_##K62, KC_##K63, KC_##KB3, KC_##KC3, KC_NO   , KC_##KF3, KC_##KF4, KC_##KE6, KC_NO   , KC_NO   , KC_NO   , KC_NO    }, \
    { KC_##K22, KC_##K23, KC_##K33, KC_##K43, KC_##K53, KC_##K52, KC_##K72, KC_##K73, KC_##K83, KC_##K93, KC_##KA3, KC_##KA2, KC_##K82, KC_##K61, KC_##KC2, KC_##KE2, KC_##KD2, KC_##KB6, KC_##KC6, KC_##KD6, KC_##KD7 }, \
    { KC_##K21, KC_##K24, KC_##K34, KC_##K44, KC_##K54, KC_##K15, KC_##K71, KC_##K74, KC_##K84, KC_##K94, KC_##KA4, KC_##KA1, KC_##K81, KC_##K65, KC_##KB2, KC_##KE3, KC_##KD3, KC_##KB4, KC_##KC4, KC_##KD4, KC_##KE4 }, \
    { KC_##K31, KC_##K25, KC_##K35, KC_##K45, KC_##K55, KC_##K50, KC_##K70, KC_##K75, KC_##K85, KC_##K95, KC_##KA5, KC_##KA0, KC_##K66, KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_##KB1, KC_##KC1, KC_##KD1, KC_NO    }, \
    { KC_##K11, KC_##K26, KC_##K36, KC_##K46, KC_##K56, KC_##K57, KC_##K77, KC_##K76, KC_##K86, KC_##K96, KC_##KA7, KC_##K16, KC_NO   , KC_NO   , KC_NO   , KC_##KE0, KC_NO   , KC_##KB5, KC_##KC5, KC_##KD5, KC_##KE5 }, \
    { KC_##K02, KC_NO   , KC_##KF0, KC_NO   , KC_NO   , KC_NO   , KC_##K67, KC_NO   , KC_NO   , KC_NO   , KC_##KF7, KC_NO   , KC_##K06, KC_NO   , KC_##KE7, KC_##KB7, KC_##KC7, KC_##KC0, KC_NO   , KC_##KD0, KC_NO    }  \
}

/* ANSI valiant. No extra keys for ISO */
#define KEYMAP_ANSI( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, \
    K30, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,           K3D, \
    K40, K41, K42,           K45,                     K4A, K4B, K4C, K4D  \
) KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, NO,  K2D, \
    K30, NO,  K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, NO,  K3D, \
    K40, K41, K42,           K45,                NO,  K4A, K4B, K4C, K4D  \
)


#define KEYMAP_HHKB( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K49,\
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, \
    K30, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D, K3C, \
    K40, K41, K42,           K45,                     K4A, K4B, K4C, K4D  \
) KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, NO,  K2D, \
    K30, NO,  K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, \
    K40, K41, K42,           K45,                K49, K4A, K4B, K4C, K4D  \
)

#endif
