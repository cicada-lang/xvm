#include "index.h"

void
execute(emulator_t *emulator, frame_t *frame, opcode_t opcode) {
    switch (opcode) {
    case NOP: {
        return;
    }

    case LIT: {
        (void) emulator;
        (void) frame;
        (void) opcode;
        // TODO
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
