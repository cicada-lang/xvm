#include "index.h"

name_table_t *
name_table_new(void) {
    name_table_t *self = new(name_table_t);
    self->name_hash = hash_new();
    hash_set_destroy_fn(self->name_hash, (destroy_fn_t *) name_entry_destroy);
    return self;
}

void
name_table_destroy(name_table_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        name_table_t *self = *self_pointer;
        hash_destroy(&self->name_hash);
        free(self);
        *self_pointer = NULL;
    }
}
