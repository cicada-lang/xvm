#include "../index.h"

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

void string_append(xvm_t * vm) {
    char *first = (char *) xvm_value_stack_pop(vm);
    char *second = (char *) xvm_value_stack_pop(vm);
    size_t first_length = strlen(first);
    size_t second_length = strlen(second);
    char *result = malloc(first_length + second_length + 1);
    result[0] = '\0';
    strcat(result, second);
    strcat(result, first);
    free(first);
    free(second);
    xvm_value_stack_push(vm, (value_t) result);
}
