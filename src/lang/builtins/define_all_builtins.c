#include "../index.h"

void
define_all_builtins(vm_t *self) {
    vm_define_primitive(self, "newline", _newline);

    vm_define_primitive(self, "int_print", _int_print);
    vm_define_primitive(self, "int_dup", _int_dup);
    vm_define_primitive(self, "int_add", _int_add);
    vm_define_primitive(self, "int_sub", _int_sub);
    vm_define_primitive(self, "int_mul", _int_mul);

    vm_define_primitive(self, "string_print", _string_print);
    vm_define_primitive(self, "string_append", _string_append);
    vm_define_primitive(self, "string_dup", _string_dup);
    vm_define_primitive(self, "string_length", _string_length);

    vm_define_primitive(self, "word_print", _word_print);

    vm_define_primitive(self, "define", _define);
}
