#include "index.h"

struct _interpreter_t {
    vm_t *vm;
    list_t *token_list;
};
