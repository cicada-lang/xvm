#include "../../index.h"

void _assert(const vm_t *vm) {
    bool target = vm_value_stack_pop(vm);
    // TODO Should print source code context.
    assert(target);
}
