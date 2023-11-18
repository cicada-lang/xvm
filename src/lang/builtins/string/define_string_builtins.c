#include "../../index.h"

void
define_string_builtins(vm_t *self) {
    vm_define_primitive(self, "string_print", _string_print);
    vm_define_primitive(self, "string_append", _string_append);
    vm_define_primitive(self, "string_dup", _string_dup);
    vm_define_primitive(self, "string_length", _string_length);
}
