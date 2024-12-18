#pragma once

typedef void *value_t;

// value = higher 61 bits data + lower 3 bits tag.
// thus we have 8 tags.

// address in vm ram is different from
// address of pointer (object).
typedef enum {
    XOBJECT       = 0, // 0b000
    XADDRESS      = 1, // 0b001
    XINT          = 2, // 0b010
    // TODO       = 3, // 0b011
    // TODO       = 4, // 0b100
    // TODO       = 5, // 0b101
    // TODO       = 6, // 0b110
    XEXTENDED     = 7, // 0b111
} tag_t;

// extended_tag_t ?

// - xbool_t  -- TODO 0b111
// - xchar_t  -- TODO 0b111
// - xnull_t  -- TODO 0b111
// - xop_t    -- TODO 0b111

typedef struct vm_t vm_t;
