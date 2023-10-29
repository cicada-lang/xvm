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
        program_t *program = xvm_build_program(vm, "sixsixsix");
        assert(program_byte_size(program) == 0);

        program_append_value(program, 666);
        assert(program_byte_size(program) == sizeof(instruction_t) + sizeof(value_t));
        assert(program_fetch_byte(program, 0) == VALUE);
        assert(program_fetch_instruction(program, 0) == VALUE);
        assert(program_fetch_value(program, 1) == 666);
    }

    {
        program_t *program = xvm_build_program(vm, "square_test");
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
        program_t *program = xvm_build_program(vm, "sixsixsix");
        program_append_value(program, 666);
        program_append_call(program, xvm_word(vm, "println"));
        program_append_value(program, 666);
        program_append_call(program, xvm_word(vm, "print"));
        program_append_call(program, xvm_word(vm, "newline"));

        xvm_define_primitive(vm, "print", print);
        xvm_define_primitive(vm, "println", println);
        xvm_define_primitive(vm, "newline", newline);
        xvm_load(vm, program);
        xvm_run(vm);
    }

    {
        program_t *program = xvm_build_program(vm, "square");
        program_append_call(program, xvm_word(vm, "dup"));
        program_append_call(program, xvm_word(vm, "mul"));

        xvm_define_primitive(vm, "dup", dup);
        xvm_define_primitive(vm, "mul", mul);
    }

    {
        program_t *program = xvm_build_program(vm, "six");
        program_append_value(program, 6);
    }

    {
        program_t *program = xvm_build_program(vm, "main");
        program_append_call(program, xvm_word(vm, "six"));
        program_append_call(program, xvm_word(vm, "println"));
        program_append_call(program, xvm_word(vm, "six"));
        program_append_call(program, xvm_word(vm, "square"));
        program_append_call(program, xvm_word(vm, "println"));

        xvm_load(vm, program);
        xvm_run(vm);
    }

    xvm_destroy(&vm);
    return 0;
}
