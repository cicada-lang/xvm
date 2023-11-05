#include "index.h"

// The interpreter does not own `vm` and `token_list`.

struct _interpreter_t {
    vm_t *vm;
    list_t *token_list;
};

interpreter_t *
interpreter_create(vm_t *vm, list_t *token_list) {
    interpreter_t *self = allocate(sizeof(interpreter_t));
    self->vm = vm;
    self->token_list = token_list;
    return self;
}
