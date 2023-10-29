#include "index.h"

void print(xvm_t *vm) {
    value_t value = xvm_value_stack_pop(vm);
    printf("%ld", value);
}

int
main(void) {
    xvm_t *vm = xvm_create();

    {
        word_t *word = xvm_word(vm, "abc");
        assert(word == xvm_word(vm, "abc"));
    }

    {
        xvm_value_stack_push(vm, 1);
        xvm_value_stack_push(vm, 2);
        xvm_value_stack_push(vm, 3);
        assert(xvm_value_stack_pop(vm) == 3);
        assert(xvm_value_stack_pop(vm) == 2);
        assert(xvm_value_stack_pop(vm) == 1);
    }

    {
        program_t *program = xvm_program(vm, "sixsixsix");
        assert(program_byte_size(program) == 0);

        program_append_value(program, 666);
        assert(program_byte_size(program) == sizeof(instruction_t) + sizeof(value_t));
        assert(program_fetch_byte(program, 0) == VALUE);
        assert(program_fetch_instruction(program, 0) == VALUE);
        assert(program_fetch_value(program, 1) == 666);
    }

    {
        program_t *program = xvm_program(vm, "square");
        assert(program_byte_size(program) == 0);

        program_append_call(program, xvm_word(vm, "dup"));
        size_t unit_size = sizeof(instruction_t) + sizeof(value_t);
        assert(program_byte_size(program) == unit_size);

        program_append_call(program, xvm_word(vm, "mul"));
        assert(program_byte_size(program) == unit_size * 2);
        assert(program_fetch_byte(program, 0) == CALL);
        assert(program_fetch_word(program, 1) == xvm_word(vm, "dup"));
        assert(program_fetch_byte(program, unit_size) == CALL);
        assert(program_fetch_word(program, unit_size + 1) == xvm_word(vm, "mul"));
    }


    {
        program_t *program = xvm_program(vm, "sixsixsix");
        program_append_value(program, 666);
        program_append_call(program, xvm_word(vm, "print"));

        xvm_primitive_set(vm, "print", print);
        xvm_load(vm, program);
        xvm_run(vm);
    }

    xvm_destroy(&vm);
    return 0;
}
