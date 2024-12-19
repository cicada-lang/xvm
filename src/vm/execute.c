#include "index.h"

void
execute(vm_t *vm, frame_t *frame, value_t value) {
    if (!value_is_xopcode(value)) {
        stack_push(vm->value_stack, value);
        return;
    }

    if (value == xopcode_end()) {
        return;
    }

    if (value == xopcode_call()) {
        (void) frame;
        // TODO
        return;
    }

    assert(false && "[execute] unknown opcode");
}
