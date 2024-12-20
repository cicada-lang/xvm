#pragma once

struct name_table_t {
    hash_t *name_hash;
};

name_table_t *name_table_new(void);
