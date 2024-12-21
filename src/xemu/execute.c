#include "index.h"

void
execute(xemu_t *xemu, frame_t *frame, opcode_t opcode) {
    switch (opcode) {
    case OP_NOP: {
        return;
    }

    case OP_LIT: {
        value_t value = frame_fetch_value(frame, xemu->ram);
        stack_push(xemu->value_stack, value);
        return;
    }

    case OP_CALL: {
        size_t address = value_to_address(stack_pop(xemu->value_stack));
        stack_push(xemu->return_stack, frame_new(address));
        return;
    }

    case OP_END: {
        return;
    }
    }

    assert(false && "[execute] unknown opcode");
}
