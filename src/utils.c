#include "index.h"

char*
string_dup(const char *s) {
    size_t length = strlen(s);
    char *s_dup = malloc(length + 1);
    assert(s_dup);
    strcpy(s_dup, s);
    return s_dup;
}

size_t
string_hash(const char *s) {
    size_t max_index = 64 - 8;
    size_t index = 0;
    size_t hash = 0;
    while (*s) {
        hash += (*s) << (index % max_index);
        index++;
        s++;
    }

    return hash;
}
