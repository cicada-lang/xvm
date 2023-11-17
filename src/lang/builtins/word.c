#include "../index.h"

void _word_print(const vm_t *vm) {
    word_t *word = (word_t *) vm_value_stack_pop(vm);
    printf("%s", word_name(word));
}
