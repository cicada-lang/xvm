#include "index.h"

void
execute(vm_t *vm, frame_t *frame, value_t value) {
    (void) frame;

    if (!value_is_xopcode(value)) {
        stack_push(vm->value_stack, value);
        return;
    }

    if (value == xopcode_end()) {
        return;
    }

    if (value == xopcode_call()) {
        void *address = value_to_address(stack_pop(vm->value_stack));
        stack_push(vm->return_stack, frame_new(address));
        return;
    }

    assert(false && "[execute] unknown opcode");
}
