#include "keymap_common.h"
#include "layer.h"
#include "macro.h"
#include "function.h"
#include "init.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* Layer 0: Default Layer
    * ,---------------------------------------------------------------.
    * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|Ins|
    * |---------------------------------------------------------------|
    * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|Del|
    * |---------------------------------------------------------------|
    * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |PgU|
    * |---------------------------------------------------------------|
    * |Shif|   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgD|
    * |---------------------------------------------------------------|
    * |Ctrl|Gui |Alt |         Space       | FN1 |Ctrl |  |Lef|Dow|Rig|
    * `---------------------------------------------------------------'
    */
    [L_NORMAL] = KEYMAP( \
	ESC, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, MINS, EQL, BSLS, GRV, INS, \
	TAB, Q, W, E, R, T, Y, U, I, O, P, LBRC, RBRC, BSPC, DEL, \
	CAPS, A, S, D, F, G, H, J, K, L, SCLN, QUOT, NUHS, ENT, PGUP, \
	LSFT, NUBS, Z, X, C, V, B, N, M, COMM, DOT, SLSH, RSFT, UP, PGDN, \
	LCTL, LGUI, LALT, SPC, FN0, RCTL, NO, LEFT, DOWN, RGHT \
    ),

   /* Layer 0: Default Layer
    * ,---------------------------------------------------------------.
    * |FN1 | F1| F2| F3| F4| F5| F6| F7| F8| F9| F0|F11|F12|TRNS| TRNS| TRNS|
    * |---------------------------------------------------------------|
    * | TRNS | TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS | TRNS  |
    * |---------------------------------------------------------------|
    * |  TRNS  |  TRNS|  TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS   |V U|
    * |---------------------------------------------------------------|
    * |   TRNS   | TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS| TRNS|TRNS   |PGDN|V D|
    * |---------------------------------------------------------------|
    * | TRNS | TRNS | TRNS |          TRNS         | FN1 | TRNS |  |HOM|PGUP|END|
    * `---------------------------------------------------------------'
    */
	[L_MACRO] = KEYMAP( \
    FN0, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS, TRNS, TRNS, \
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, VOLU,\
    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, PGUP, VOLD,\
    TRNS, TRNS, TRNS, TRNS, TRNS, NO, TRNS, HOME, PGDN, END \
	),
};

/**
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TOGGLE(F_SWITCH_LAYOUT_MACRO),
    [4] = ACTION_MACRO(M_GINKGO), // ginkgo -r -race -untilItFails -randomizeAllSpecs
    [5] = ACTION_MACRO(M_DESCRIBE), // Describe Block
    [6] = ACTION_MACRO(M_CONTEXT), // Context Block
    [7] = ACTION_MACRO(M_IT)  // It Block
};
