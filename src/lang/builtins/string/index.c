#include "../../index.h"

void _string_print(const vm_t *vm) {
    char *s = (char *) vm_value_stack_pop(vm);
    printf("%s", s);
    free(s);
}

void _string_dup(const vm_t *vm) {
    char *s = (char *) vm_value_stack_pop(vm);
    vm_value_stack_push(vm, (value_t) s);
    vm_value_stack_push(vm, (value_t) string_dup(s));
}

void _string_length(const vm_t *vm) {
    char *s = (char *) vm_value_stack_pop(vm);
    vm_value_stack_push(vm, strlen(s));
    free(s);
}

void _string_append(const vm_t *vm) {
    char *right = (char *) vm_value_stack_pop(vm);
    char *left = (char *) vm_value_stack_pop(vm);
    char *result = string_append(left, right);
    free(left);
    free(right);
    vm_value_stack_push(vm, (value_t) result);
}
