#include "index.h"

void
execute(xemu_t *xemu, frame_t *frame, opcode_t opcode) {
    fprintf(stderr, "[execute] opcode: 0x%02x\n", opcode);

    if (opcode != OP_NOP && opcode != OP_CALL) {
        // maybe need to handle tail call on OP_CALL.
        stack_push(xemu->return_stack, frame);
    }

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
        // handle tail-call here.
        if (frame_is_end(frame, xemu->ram)) {
            frame_destroy(&frame);
        } else {
            stack_push(xemu->return_stack, frame);
        }

        size_t address = value_to_address(stack_pop(xemu->value_stack));
        stack_push(xemu->return_stack, frame_new(address));
        return;
    }

    case OP_OK: {
        bool ok = value_to_bool(stack_pop(xemu->value_stack));
        fprintf(stderr, "[execute] ok\n");
        if (!ok) {
            fprintf(stderr, "[execute] assertion failed\n");
            exit(1);
        }
        return;
    }

    case OP_END: {
        frame_destroy(&frame);
        return;
    }
    }

    assert(false && "[execute] unknown opcode");
}
