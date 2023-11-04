#include "src/index.h"
#include "src/tests/index.h"

int
main(void) {
    vm_t *vm = vm_init();

    test_word();
    test_value_stack();
    test_build_program();
    test_builtin_int();

    {
        program_t *program = vm_build_program(vm, "test_string_print");
        program_append_value(program, (value_t) string_dup("hello, world!"));
        program_append_call(program, vm_word(vm, "string_print"));
        program_append_call(program, vm_word(vm, "newline"));

        vm_load(vm, program);
        vm_run(vm);
    }

    {
        program_t *program = vm_build_program(vm, "test_string_append");
        program_append_value(program, (value_t) string_dup("hello, "));
        program_append_value(program, (value_t) string_dup("world!"));
        program_append_call(program, vm_word(vm, "string_append"));
        program_append_call(program, vm_word(vm, "string_dup"));
        program_append_call(program, vm_word(vm, "string_dup"));
        program_append_call(program, vm_word(vm, "string_append"));
        program_append_call(program, vm_word(vm, "string_print"));
        program_append_call(program, vm_word(vm, "newline"));
        program_append_call(program, vm_word(vm, "string_length"));
        program_append_call(program, vm_word(vm, "int_print"));
        program_append_call(program, vm_word(vm, "newline"));

        vm_load(vm, program);
        vm_run(vm);
    }

    vm_destroy(&vm);
    return 0;
}
