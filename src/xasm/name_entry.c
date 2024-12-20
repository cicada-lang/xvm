#include "index.h"

name_entry_t *
name_entry_new(char *name) {
    name_entry_t *self = new(name_entry_t);
    self->name = name;
    return self;
}
