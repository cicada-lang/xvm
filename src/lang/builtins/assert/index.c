#include "../../index.h"

void _assert(const vm_t *vm) {
    char *message = (char *) vm_value_stack_pop(vm);
    bool target = vm_value_stack_pop(vm);
    if (target) {
        return;
    } else {
        printf("[assert] %s\n", message);
        exit(1);
    }
}
