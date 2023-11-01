#include "index.h"

void newline(xvm_t * vm) {
    (void) vm;
    printf("\n");
}

void int_print(xvm_t *vm) {
    int_t value = xvm_value_stack_pop(vm);
    printf("%ld", value);
}

void int_dup(xvm_t * vm) {
    int_t value = xvm_value_stack_pop(vm);
    xvm_value_stack_push(vm, value);
    xvm_value_stack_push(vm, value);
}

void int_mul(xvm_t * vm) {
    int_t x = xvm_value_stack_pop(vm);
    int_t y = xvm_value_stack_pop(vm);
    xvm_value_stack_push(vm, x * y);
}

void string_print(xvm_t * vm) {
    char *s = (char *) xvm_value_stack_pop(vm);
    printf("%s", s);
}
