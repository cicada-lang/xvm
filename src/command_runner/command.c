#include "index.h"

struct _command_t {
    const char *name;
    const char *description;
    const char *help;
    command_run_fn_t *run_fn;
};

command_t *
command_create(const char *name) {
    command_t *self = allocate(sizeof(command_t));
    self->name = name;
    self->description = NULL;
    self->help = NULL;
    self->run_fn = NULL;
    return self;
}

void
command_destroy(command_t **self_ptr) {
    assert(self_ptr);
    if (*self_ptr) {
        command_t *self = *self_ptr;
        free(self);
        *self_ptr = NULL;
    }
}
