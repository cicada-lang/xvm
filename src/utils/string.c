#include "index.h"

char*
string_dup(const char *s) {
    size_t length = strlen(s);
    char *s_dup = malloc(length + 1);
    assert(s_dup);
    strcpy(s_dup, s);
    return s_dup;
}

bool
string_equal(const char *lhs, const char *rhs) {
    return strcmp(lhs, rhs) == 0;
}

size_t
string_hash(const char *s, size_t size) {
    size_t max_index = 64 - 8;
    size_t index = 0;
    size_t hash = 0;
    while (*s) {
        hash += (*s) << (index % max_index);
        if (hash > size) hash %= size;
        index++;
        s++;
    }

    return hash;
}

bool
string_is_int(const char *s) {
    char *int_end = NULL;
    strtol(s, &int_end, 0);
    if (int_end == s) return false;
    return *int_end == '\0';
}

int64_t
string_to_int(const char *s) {
    char *int_end = NULL;
    return strtol(s, &int_end, 0);
}

bool
string_starts_with(const char *target, const char *prefix) {
    size_t target_length = strlen(target);
    size_t prefix_length = strlen(prefix);

    if (target_length < prefix_length) return false;

    return strncmp(target, prefix, prefix_length) == 0;
}
