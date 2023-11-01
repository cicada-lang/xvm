#include "index.h"

void print(xvm_t *vm) {
    value_t value = xvm_value_stack_pop(vm);
    printf("%ld", value);
}

void println(xvm_t *vm) {
    value_t value = xvm_value_stack_pop(vm);
    printf("%ld\n", value);
}

void newline(xvm_t * vm) {
    (void) vm;
    printf("\n");
}

void dup(xvm_t * vm) {
    value_t value = xvm_value_stack_pop(vm);
    xvm_value_stack_push(vm, value);
    xvm_value_stack_push(vm, value);
}

void mul(xvm_t * vm) {
    value_t x = xvm_value_stack_pop(vm);
    value_t y = xvm_value_stack_pop(vm);
    xvm_value_stack_push(vm, x * y);
}

void string_print(xvm_t * vm) {
    char *s = (char *) xvm_value_stack_pop(vm);
    printf("%s", s);
}
