#include "everything.h"

int
main(void) {
    xvm_t *vm = xvm_new();

    {
        word_t *word = dict_word(vm->dict, "abc");
        printf("%ld\n", (uint64_t) word);
    }

    {
        word_t *word = dict_word(vm->dict, "abc");
        printf("%ld\n", (uint64_t) word);
    }

    xvm_define(vm, "square", (const char *[]){ "dup", "mul", NULL });

    xvm_destroy(&vm);
    return 0;
}
