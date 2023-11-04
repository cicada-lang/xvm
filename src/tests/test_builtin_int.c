#include "../index.h"

void
test_builtin_int(void) {
    printf("<test_builtin_int>");

    vm_t *vm = vm_init();

    {
        program_t *program = vm_build_program(vm, "sixsixsix");
        program_append_value(program, 666);
        program_append_call(program, vm_word(vm, "int_print"));
        program_append_call(program, vm_word(vm, "newline"));
        program_append_value(program, 666);
        program_append_call(program, vm_word(vm, "int_print"));
        program_append_call(program, vm_word(vm, "newline"));

        vm_load(vm, program);
        vm_run(vm);
    }

    {
        program_t *program = vm_build_program(vm, "int_square");
        program_append_call(program, vm_word(vm, "int_dup"));
        program_append_call(program, vm_word(vm, "int_mul"));
    }

    {
        program_t *program = vm_build_program(vm, "six");
        program_append_value(program, 6);
    }

    {
        program_t *program = vm_build_program(vm, "test_int_square");
        program_append_call(program, vm_word(vm, "six"));
        program_append_call(program, vm_word(vm, "int_print"));
        program_append_call(program, vm_word(vm, "newline"));
        program_append_call(program, vm_word(vm, "six"));
        program_append_call(program, vm_word(vm, "int_square"));
        program_append_call(program, vm_word(vm, "int_print"));
        program_append_call(program, vm_word(vm, "newline"));

        vm_load(vm, program);
        vm_run(vm);
    }

    vm_destroy(&vm);

    printf("</test_builtin_int>\n");
}
