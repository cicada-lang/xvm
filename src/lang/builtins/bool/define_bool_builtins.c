#include "../../index.h"

void
define_bool_builtins(vm_t *self) {
    vm_define_primitive(self, "true", _true);
    vm_define_primitive(self, "false", _false);
    vm_define_primitive(self, "bool_print", _bool_print);
    vm_define_primitive(self, "bool_dup", _bool_dup);
    vm_define_primitive(self, "bool_not", _bool_not);
    vm_define_primitive(self, "bool_and", _bool_and);
    vm_define_primitive(self, "bool_or", _bool_or);
    vm_define_primitive(self, "bool_choose", _bool_choose);
}
