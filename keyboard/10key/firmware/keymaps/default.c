#include "keymap_common.h"
#include "layer.h"
#include "macro.h"
#include "function.h"
#include "init.h"

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
    [L_NORMAL] = KEYMAP( \
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
    [L_MOUSE] = KEYMAP( \
	FN1, MNXT, MPRV, MPLY, NO, \
	VOLU, BTN1, MS_U, BTN2, NO, \
	VOLD, MS_L, MS_D, MS_R, \
	MUTE, WH_U, WH_L, WH_D, NO,\
	NO, NO, NO \
    ),
    /* Layer 2: Vim Layer
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
    [L_VIM] = KEYMAP( \
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
    [L_MACRO] = KEYMAP( \
	FN3, FN4, FN5, FN6, FN7, \
	NO, NO, NO, NO, NO, \
	NO, NO, NO, NO, \
	NO, NO, NO, NO, NO,\
	NO, NO, NO \
    ),
};



/**
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TOGGLE(F_SWITCH_LAYOUT_NORMAL),
    [1] = ACTION_LAYER_TOGGLE(F_SWITCH_LAYOUT_MOUSE),
    [2] = ACTION_LAYER_TOGGLE(F_SWITCH_LAYOUT_VIM),
    [3] = ACTION_LAYER_TOGGLE(F_SWITCH_LAYOUT_MACRO),
    [4] = ACTION_MACRO(M_GINKGO), // ginkgo -r -race -untilItFails -randomizeAllSpecs
    [5] = ACTION_MACRO(M_DESCRIBE), // Describe Block
    [6] = ACTION_MACRO(M_CONTEXT), // Context Block
    [7] = ACTION_MACRO(M_IT)  // It Block
};
