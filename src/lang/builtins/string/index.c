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
    char *first = (char *) vm_value_stack_pop(vm);
    char *second = (char *) vm_value_stack_pop(vm);
    size_t first_length = strlen(first);
    size_t second_length = strlen(second);
    char *result = malloc(first_length + second_length + 1);
    result[0] = '\0';
    strcat(result, second);
    strcat(result, first);
    free(first);
    free(second);
    vm_value_stack_push(vm, (value_t) result);
}
