#include "../index.h"

void _int_print(xvm_t *vm) {
    int_t value = xvm_value_stack_pop(vm);
    printf("%ld", value);
}

void _int_dup(xvm_t * vm) {
    int_t value = xvm_value_stack_pop(vm);
    xvm_value_stack_push(vm, value);
    xvm_value_stack_push(vm, value);
}

void _int_mul(xvm_t * vm) {
    int_t x = xvm_value_stack_pop(vm);
    int_t y = xvm_value_stack_pop(vm);
    xvm_value_stack_push(vm, x * y);
}
