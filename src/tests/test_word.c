#include "../index.h"

void
test_word(void) {
    printf("- test_word: ");

    vm_t *vm = vm_init();

    word_t *word = vm_word(vm, "abc");
    assert(word == vm_word(vm, "abc"));

    vm_destroy(&vm);

    printf("OK\n");
}
