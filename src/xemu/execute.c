#include "index.h"

void
execute(xemu_t *xemu, frame_t *frame, opcode_t opcode) {
    // debug
    // {
    //     fprintf(stderr, "[execute] opcode: %s\n", opcode_to_mnemonic(opcode));
    // }

    if (!(opcode == OP_NOP ||
          opcode == OP_CALL ||
          opcode == OP_APPLY))
    {
        // maybe need to handle tail call on OP_CALL and OP_APPLY.
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
        size_t address = to_address(frame_fetch_value(frame, xemu->ram));

        // handle tail-call here.
        if (frame_is_at_tail(frame, xemu->ram)) {
            frame_destroy(&frame);
        } else {
            stack_push(xemu->return_stack, frame);
        }

        stack_push(xemu->return_stack, frame_new(address));
        return;
    }

    case OP_APPLY: {
        // handle tail-call here.
        if (frame_is_at_tail(frame, xemu->ram)) {
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

    case OP_RET: {
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

    case OP_ADD: {
        value_t y = stack_pop(xemu->value_stack);
        value_t x = stack_pop(xemu->value_stack);

        if (is_xint(x) && is_xint(y)) {
            stack_push(xemu->value_stack, xint_add(x, y));
            return;
        }

        if (is_xfloat(x) && is_xfloat(y)) {
            stack_push(xemu->value_stack, xfloat_add(x, y));
            return;
        }

        fprintf(stderr, "ADD type mismatch\n");
        return;
    }

    case OP_SUB: {
        value_t y = stack_pop(xemu->value_stack);
        value_t x = stack_pop(xemu->value_stack);

        if (is_xint(x) && is_xint(y)) {
            stack_push(xemu->value_stack, xint_sub(x, y));
            return;
        }

        if (is_xfloat(x) && is_xfloat(y)) {
            stack_push(xemu->value_stack, xfloat_sub(x, y));
            return;
        }

        fprintf(stderr, "SUB type mismatch\n");
        return;
    }

    case OP_MUL: {
        value_t y = stack_pop(xemu->value_stack);
        value_t x = stack_pop(xemu->value_stack);

        if (is_xint(x) && is_xint(y)) {
            stack_push(xemu->value_stack, xint_mul(x, y));
            return;
        }

        if (is_xfloat(x) && is_xfloat(y)) {
            stack_push(xemu->value_stack, xfloat_mul(x, y));
            return;
        }

        fprintf(stderr, "MUL type mismatch\n");
        return;
    }

    case OP_DIV: {
        value_t y = stack_pop(xemu->value_stack);
        value_t x = stack_pop(xemu->value_stack);

        if (is_xint(x) && is_xint(y)) {
            stack_push(xemu->value_stack, xint_div(x, y));
            return;
        }

        if (is_xfloat(x) && is_xfloat(y)) {
            stack_push(xemu->value_stack, xfloat_div(x, y));
            return;
        }

        fprintf(stderr, "DIV type mismatch\n");
        return;
    }

    case OP_MOD: {
        value_t y = stack_pop(xemu->value_stack);
        value_t x = stack_pop(xemu->value_stack);

        if (is_xint(x) && is_xint(y)) {
            stack_push(xemu->value_stack, xint_mod(x, y));
            return;
        }

        if (is_xfloat(x) && is_xfloat(y)) {
            stack_push(xemu->value_stack, xfloat_mod(x, y));
            return;
        }

        fprintf(stderr, "MOD type mismatch\n");
        return;
    }

    case OP_TO_INT: {
        value_t x = stack_pop(xemu->value_stack);

        if (is_xint(x)) {
            stack_push(xemu->value_stack, x);
            return;
        }

        if (is_xfloat(x)) {
            stack_push(xemu->value_stack, xint((uint64_t) to_double(x)));
            return;
        }

        fprintf(stderr, "TO-INT type mismatch\n");
        return;
    }

    case OP_TO_FLOAT: {
        value_t x = stack_pop(xemu->value_stack);

        if (is_xint(x)) {
            stack_push(xemu->value_stack, xfloat((double) to_int64(x)));
            return;
        }

        if (is_xfloat(x)) {
            stack_push(xemu->value_stack, x);
            return;
        }

        fprintf(stderr, "TO-INT type mismatch\n");
        return;
    }
    }

    assert(false && "[execute] unknown opcode");
}
