#include "index.h"

int
main(void) {
    xvm_t *vm = xvm_create();

    {
        word_t *word = xvm_word(vm, "abc");
        printf("%ld\n", (uint64_t) word);
    }

    {
        word_t *word = xvm_word(vm, "abc");
        printf("%ld\n", (uint64_t) word);
    }

    xvm_program(vm, "square");
    // program_t *program = xvm_program(vm, "square");
    // program_call(program, "dup");
    // program_call(program, "mul");
    // program_end(program);

    xvm_destroy(&vm);
    return 0;
}
