#include "index.h"

struct _command_t {
    char *name;
    char *description;
    char *help;
    command_run_fn_t *run_fn;
};

command_t *
command_create(char *name) {
    command_t *self = allocate(sizeof(command_t));
    self->name = name;
    self->description = NULL;
    self->help = NULL;
    self->run_fn = NULL;
    return self;
}

// void
// command_destroy(command_t **self_ptr) {

// }
