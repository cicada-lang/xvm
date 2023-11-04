#include "src/index.h"

int
main(void) {
    vm_t *vm = vm_init();

    {
        word_t *word = vm_word(vm, "abc");
        assert(word == vm_word(vm, "abc"));
    }

    {
        vm_value_stack_push(vm, 1);
        vm_value_stack_push(vm, 2);
        vm_value_stack_push(vm, 3);
        assert(vm_value_stack_pop(vm) == 3);
        assert(vm_value_stack_pop(vm) == 2);
        assert(vm_value_stack_pop(vm) == 1);
    }

    {
        program_t *program = vm_build_program(vm, "sixsixsix");
        assert(program_byte_size(program) == 0);

        program_append_value(program, 666);
        size_t unit_size = sizeof(instruction_t) + sizeof(value_t);
        assert(program_byte_size(program) == unit_size);
        assert(program_fetch_byte(program, 0) == VALUE);
        assert(program_fetch_instruction(program, 0) == VALUE);
        assert(program_fetch_value(program, 1) == 666);
    }

    {
        program_t *program = vm_build_program(vm, "square_test");
        assert(program_byte_size(program) == 0);

        program_append_call(program, vm_word(vm, "int_dup"));
        size_t unit_size = sizeof(instruction_t) + sizeof(value_t);
        assert(program_byte_size(program) == unit_size);

        program_append_call(program, vm_word(vm, "int_mul"));
        assert(program_byte_size(program) == unit_size * 2);
        assert(program_fetch_byte(program, 0) == CALL);
        assert(program_fetch_word(program, 1) == vm_word(vm, "int_dup"));
        assert(program_fetch_byte(program, unit_size) == CALL);
        assert(program_fetch_word(program, unit_size + 1) == vm_word(vm, "int_mul"));
    }


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
