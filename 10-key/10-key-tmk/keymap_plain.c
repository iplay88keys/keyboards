/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

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
#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,-----------------------------.
     * |Esc |    | ESC| SLS| MUL| MIN|
     * |-----------------------------|
     * |FN4 |    |  7 |  8 |  9 |  < |
     * |-------------------------PLUS|
     * |FN3 |    |  4 |  5 |  6 |    |
     * |-----------------------------|
     * |FN2 |    |  1 |  2 |  3 |  < |
     * |-------------------------ENTR|
     * |FN1 |    |  ^ 0    |  . |    |
     * `-----------------------------'
     */
    [0] = KEYMAP( \
	ESC, PEQL, PSLS, PAST, PMNS, \
	NO, 7, 8, 9, PPLS, \
	FN3, 4, 5, 6, \
	FN2, 1, 2, 3, PENT,\
	FN1, 0, PDOT \
    ),
    /* Layer 1: Mouse/Music Layer
     * ,-----------------------------.
     * | FN1|    |MNXT|MPRV|MPLY| NO |
     * |-----------------------------|
     * |VolU|    | Cl2| MU | Cl1| <  |
     * |------------------------- NO |
     * |VolD|    | ML | MD | MR |    |
     * |-----------------------------|
     * |MUTE|    | WU | WL | WD |  < |
     * |------------------------- NO |
     * | NO |    |  ^ NO   | NO |    |
     * `-----------------------------'
     */
    [1] = KEYMAP( \
	FN1, MNXT, MPRV, MPLY, NO, \
	VOLU, BTN1, MS_U, BTN2, NO, \
	VOLD, MS_L, MS_D, MS_R, \
	MUTE, WH_U, WH_L, WH_D, NO,\
	NO, NO, NO \
    ),
    /* Layer 2: Arrow Layer
     * ,-----------------------------.
     * |FN2 |    | ESC| NO | NO | NO |
     * |-----------------------------|
     * | NO |    |  Y | AU |  P | <  |
     * |------------------------- NO |
     * | NO |    | AL | AD | AR |    |
     * |-----------------------------|
     * | NO |    | NO | NO | NO |  < |
     * |-------------------------ENTR|
     * | NO |    |  ^ NO   | NO |    |
     * `-----------------------------'
     */
    [2] = KEYMAP( \
	FN2, ESC, NO, NO, NO, \
	NO, Y, UP, P, NO, \
	NO, LEFT, DOWN, RIGHT, \
	NO, NO, NO, NO, PENT,\
	NO, NO, NO \
    ),
    /* Layer 3: MACRO Layer
     * ,-----------------------------.
     * |FN3 |    |GINK|DESC|CONT| IT |
     * |-----------------------------|
     * | NO |    | NO | NO | NO | <  |
     * |------------------------- NO |
     * | NO |    | NO | NO | NO |    |
     * |-----------------------------|
     * | NO |    | NO | NO | NO |  < |
     * |------------------------- NO |
     * | NO |    |  ^ NO   | NO |    |
     * `-----------------------------'
     */
    [3] = KEYMAP( \
	FN3, FN4, FN5, FN6, FN7, \
	NO, NO, NO, NO, NO, \
	NO, NO, NO, NO, \
	NO, NO, NO, NO, NO,\
	NO, NO, NO \
    ),
};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TOGGLE(0),
    [1] = ACTION_LAYER_TOGGLE(1),
    [2] = ACTION_LAYER_TOGGLE(2),
    [3] = ACTION_LAYER_TOGGLE(3),
    [4] = ACTION_MACRO(0), // ginkgo -r -race -untilItFails -randomizeAllSpecs
    [5] = ACTION_MACRO(1), // Describe Block
    [6] = ACTION_MACRO(2), // Context Block
    [7] = ACTION_MACRO(3)  // It Block
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch (id) {
	    case 0:
	        return MACRO( \
			    T(G), T(I), T(N), T(K), T(G), T(O), T(SPACE), \
			    T(MINS), T(R), T(SPACE), \
			    T(MINS), T(R), T(A), T(C), T(E), T(SPACE), \
			    T(MINS), T(U), T(N), T(T), T(I), T(L), \
			    D(LSFT), T(I), U(LSFT), T(T), \
			    D(LSFT), T(F), U(LSFT), T(A), T(I), T(L), T(S), T(SPACE), \
			    T(MINS), T(R), T(A), T(N), T(D), T(O), T(M), T(I), T(Z), T(E), \
			    D(LSFT), T(A), U(LSFT), T(L), T(L), \
			    D(LSFT), T(S), U(LSFT), T(P), T(E), T(C), T(S), T(ENT), END \
			    );
            case 1:
                return MACRO( \
			    T(O), \
			    D(LSFT), T(D), U(LSFT), T(E), T(S), T(C), T(R), T(I), T(B), T(E), \
			    T(SPACE), T(ESC), END \
			    );
            case 2:
                return MACRO( \
			    T(O), \
			    D(LSFT), T(C), U(LSFT), T(O), T(N), T(T), T(E), T(X), T(T), \
			    T(SPACE), T(ESC), END \
	                    );
            case 3:
                return MACRO( \
			    T(O), \
			    D(LSFT), T(I), U(LSFT), T(T), T(SPACE), T(ESC), END \
			    );
        }
    }
    return MACRO_NONE;
}
