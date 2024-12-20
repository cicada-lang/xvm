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
        // TODO
    }

    case END: {
        return;
    }
    }

    assert(false && "[execute] unknown opcode");
}
