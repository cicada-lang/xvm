#include "../index.h"

void
test_value_stack(void) {
    printf("- test_value_stack: ");

    vm_t *vm = vm_init();

    vm_value_stack_push(vm, 1);
    vm_value_stack_push(vm, 2);
    vm_value_stack_push(vm, 3);
    assert(vm_value_stack_pop(vm) == 3);
    assert(vm_value_stack_pop(vm) == 2);
    assert(vm_value_stack_pop(vm) == 1);

    printf("OK\n");
}
