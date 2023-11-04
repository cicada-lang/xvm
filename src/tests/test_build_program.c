#include "../index.h"

void
test_build_program(void) {
    printf("- test_build_program: ");

    vm_t *vm = vm_init();

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

    printf("OK\n");
}
