#pragma once

struct name_entry_t {
    char *name;
    name_table_t *name_table;
};

name_entry_t *name_entry_new(char *name);
