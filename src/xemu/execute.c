#include "index.h"

void
execute(xemu_t *xemu, frame_t *frame, opcode_t opcode) {
    // debug
    // {
    //     fprintf(stderr, "[execute] opcode: %s\n", opcode_mnemonic(opcode));
    // }

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

        size_t address = to_address(stack_pop(xemu->value_stack));
        stack_push(xemu->return_stack, frame_new(address));
        return;
    }

    case OP_OK: {
        bool ok = to_bool(stack_pop(xemu->value_stack));
        if (!ok) {
            fprintf(
                stderr,
                "[execute] assertion failed, address: 0x%08lx\n",
                frame->address - 1);

            exit(1);
        }

        return;
    }

    case OP_END: {
        frame_destroy(&frame);
        return;
    }

    case OP_EQ: {
        value_t y = stack_pop(xemu->value_stack);
        value_t x = stack_pop(xemu->value_stack);
        stack_push(xemu->value_stack, xbool(x == y));
        return;
    }

    case OP_AND: {
        value_t y = stack_pop(xemu->value_stack);
        value_t x = stack_pop(xemu->value_stack);
        stack_push(xemu->value_stack, xbool_and(x, y));
        return;
    }

    case OP_OR: {
        value_t y = stack_pop(xemu->value_stack);
        value_t x = stack_pop(xemu->value_stack);
        stack_push(xemu->value_stack, xbool_or(x, y));
        return;
    }

    case OP_NOT: {
        value_t x = stack_pop(xemu->value_stack);
        stack_push(xemu->value_stack, xbool_not(x));
        return;
    }

    case OP_DUP: {
        value_t x = stack_pop(xemu->value_stack);
        stack_push(xemu->value_stack, x);
        stack_push(xemu->value_stack, x);
        return;
    }

    case OP_DROP: {
        (void) stack_pop(xemu->value_stack);
        return;
    }

    case OP_SWAP: {
        value_t y = stack_pop(xemu->value_stack);
        value_t x = stack_pop(xemu->value_stack);
        stack_push(xemu->value_stack, y);
        stack_push(xemu->value_stack, x);
        return;
    }

    case OP_ROT: {
        value_t z = stack_pop(xemu->value_stack);
        value_t y = stack_pop(xemu->value_stack);
        value_t x = stack_pop(xemu->value_stack);
        stack_push(xemu->value_stack, y);
        stack_push(xemu->value_stack, z);
        stack_push(xemu->value_stack, x);
        return;
    }

    case OP_OVER: {
        value_t y = stack_pop(xemu->value_stack);
        value_t x = stack_pop(xemu->value_stack);
        stack_push(xemu->value_stack, x);
        stack_push(xemu->value_stack, y);
        stack_push(xemu->value_stack, x);
        return;
    }

    case OP_TUCK: {
        value_t y = stack_pop(xemu->value_stack);
        value_t x = stack_pop(xemu->value_stack);
        stack_push(xemu->value_stack, y);
        stack_push(xemu->value_stack, x);
        stack_push(xemu->value_stack, y);
        return;
    }
    }

    assert(false && "[execute] unknown opcode");
}
