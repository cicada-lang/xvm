#pragma once

struct name_table_t {
    hash_t *name_hash;
};

name_table_t *name_table_new(void);
void name_table_destroy(name_table_t **self_pointer);
