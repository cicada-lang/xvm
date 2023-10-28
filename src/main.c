#include "index.h"

int
main(void) {
    xvm_t *vm = xvm_new();

    {
        word_t *word = xvm_word(vm, "abc");
        printf("%ld\n", (uint64_t) word);
    }

    {
        word_t *word = xvm_word(vm, "abc");
        printf("%ld\n", (uint64_t) word);
    }

    xvm_destroy(&vm);
    return 0;
}
