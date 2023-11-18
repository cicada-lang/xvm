#include "../../index.h"

void
define_word_builtins(vm_t *vm) {
    vm_define_primitive(vm, "word_print", _word_print);
    vm_define_primitive(vm, "word_dup", _word_dup);
}
