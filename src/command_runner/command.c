#include "index.h"

command_t *
command_create(const char *name) {
    command_t *self = allocate(sizeof(command_t));
    self->name = name;
    self->description = NULL;
    self->help = NULL;
    self->run = NULL;
    return self;
}

void
command_free(command_t *self) {
    free(self);
}

void
command_destroy(command_t **self_ptr) {
    assert(self_ptr);
    if (*self_ptr) {
        command_free(*self_ptr);
        *self_ptr = NULL;
    }
}
