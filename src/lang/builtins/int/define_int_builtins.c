#include "../../index.h"

void
define_int_builtins(vm_t *self) {
    vm_define_primitive(self, "int_print", _int_print);
    vm_define_primitive(self, "int_dup", _int_dup);
    vm_define_primitive(self, "int_add", _int_add);
    vm_define_primitive(self, "int_sub", _int_sub);
    vm_define_primitive(self, "int_mul", _int_mul);
}
