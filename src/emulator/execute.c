#include "index.h"

void
execute(emulator_t *emulator, frame_t *frame, opcode_t opcode) {
    switch (opcode) {
    case NOP: {
        return;
    }

    case LIT: {
        value_t value = frame_fetch_value(frame, emulator->ram);
        stack_push(emulator->value_stack, value);
        return;
    }

    case CALL: {
        size_t address = value_to_address(stack_pop(emulator->value_stack));
        stack_push(emulator->return_stack, frame_new(address));
        return;
    }

    case END: {
        return;
    }
    }

    assert(false && "[execute] unknown opcode");
}
