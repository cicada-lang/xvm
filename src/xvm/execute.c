#include "index.h"

void
execute(xvm_t *xvm, frame_t *frame, opcode_t opcode) {
    switch (opcode) {
    case OP_NOP: {
        return;
    }

    case OP_LIT: {
        value_t value = frame_fetch_value(frame, xvm->ram);
        stack_push(xvm->value_stack, value);
        return;
    }

    case OP_CALL: {
        size_t address = value_to_address(stack_pop(xvm->value_stack));
        stack_push(xvm->return_stack, frame_new(address));
        return;
    }

    case OP_END: {
        return;
    }
    }

    assert(false && "[execute] unknown opcode");
}
