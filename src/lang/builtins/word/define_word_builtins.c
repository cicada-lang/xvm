#include "../../index.h"

void
define_word_builtins(vm_t *self) {
    vm_define_primitive(self, "word_print", _word_print);
    vm_define_primitive(self, "word_dup", _word_dup);
}
