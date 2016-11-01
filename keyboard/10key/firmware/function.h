#include "action_layer.h"
#include "action_util.h"
#include "action.h"

enum function_id {
    F_SWITCH_LAYOUT_NORMAL,
    F_SWITCH_LAYOUT_MOUSE,
    F_SWITCH_LAYOUT_VIM,
    F_SWITCH_LAYOUT_MACRO,
};

uint32_t default_layer_state;
uint32_t qwerty_fallback_previous_state;

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt __attribute__ ((unused))) {
    switch (id) {
        case F_SWITCH_LAYOUT_NORMAL:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_NORMAL);
                clear_keyboard();
            }
            break;
        case F_SWITCH_LAYOUT_MOUSE:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_MOUSE);
                clear_keyboard();
            }
            break;
        case F_SWITCH_LAYOUT_VIM:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_VIM);
                clear_keyboard();
            }
            break;
        case F_SWITCH_LAYOUT_MACRO:
            if (record->event.pressed) {
                default_layer_set(1UL<<L_MACRO);
                clear_keyboard();
            }
            break;
    }
};
