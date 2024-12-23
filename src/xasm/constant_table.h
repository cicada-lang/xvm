#pragma once

struct constant_table_entry_t {
    const char *name;
    value_t value;
};

typedef struct constant_table_entry_t constant_table_entry_t;

extern constant_table_entry_t constant_table[];
