#include "index.h"

void
execute(emulator_t *emulator, frame_t *frame, value_t value) {
    (void) frame;

    if (!value_is_xopcode(value)) {
        stack_push(emulator->value_stack, value);
        return;
    }

    if (value == xopcode_end()) {
        return;
    }

    if (value == xopcode_call()) {
        void *address = value_to_address(stack_pop(emulator->value_stack));
        stack_push(emulator->return_stack, frame_new(address));
        return;
    }

    assert(false && "[execute] unknown opcode");
}
