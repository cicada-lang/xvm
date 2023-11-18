#include "../../index.h"

void
define_word_builtins(vm_t *vm) {
    vm_define_primitive(vm, "word_print", _word_print);
    vm_define_primitive(vm, "word_dup", _word_dup);
    vm_define_primitive(vm, "word_drop", _word_drop);
    vm_define_primitive(vm, "word_equal", _word_equal);
}
