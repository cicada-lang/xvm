#include "index.h"

int
main(void) {
    xvm_t *vm = xvm_create();

    {
        word_t *word = xvm_word(vm, "abc");
        printf("word address of abc: %ld\n", (uint64_t) word);
    }

    {
        word_t *word = xvm_word(vm, "abc");
        printf("word address of abc: %ld\n", (uint64_t) word);
    }

    {
        xvm_value_stack_push(vm, 1);
        xvm_value_stack_push(vm, 2);
        xvm_value_stack_push(vm, 3);
        printf("xvm_value_stack_pop: %ld\n", xvm_value_stack_pop(vm));
        printf("xvm_value_stack_pop: %ld\n", xvm_value_stack_pop(vm));
        printf("xvm_value_stack_pop: %ld\n", xvm_value_stack_pop(vm));
    }

    {
        program_t *program = xvm_program(vm, "square");
        printf("program address of square: %ld\n", (uint64_t) program);
        printf("program_byte_size: %ld\n", program_byte_size(program));
        program_append_value(program, 666);
        printf("program address of square: %ld\n", (uint64_t) program);
        printf("program_byte_size: %ld\n", program_byte_size(program));
        printf("program first byte: %d\n", program_fetch_byte(program, 0));
        printf("program first value: %ld\n", program_fetch_value(program, 1));
        // xvm_program(vm, "square");
        // program_t *program = xvm_program(vm, "square");
        // program_call(program, "dup");
        // program_call(program, "mul");
        // program_end(program);
        xvm_run(vm);
    }

    xvm_destroy(&vm);
    return 0;
}
