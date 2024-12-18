#pragma once

typedef void *value_t;

// value = higher 61 bits data + lower 3 bits tag.
// thus we have 8 tags.

typedef enum {
    XOBJECT = 0,
    // address in code is different from
    // address of pointer (object).
    XADDRESS = 1,
    XINT = 2,
    XIMMEDIATE = 3,
} tag_t;
