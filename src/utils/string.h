#pragma once

char* string_dup(const char *s);
bool string_equal(const char *x, const char *y);
size_t string_hash(const char *s, size_t size);
bool string_is_int(const char *restrict s);
int64_t string_to_int(const char *s);
