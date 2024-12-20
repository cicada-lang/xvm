#pragma once

typedef void *value_t;

// value = higher 61 bits data + lower 3 bits tag.
// thus we have 8 tags.

// xobject is 8 bytes aligned.
// xaddress is not (thus need shift).

// TODO maybe this is wrong,
// object should not be c pointer,
// but be index to `emulator->ram`.

typedef enum {
    XOBJECT      = 0, // 0b000
    XADDRESS     = 1, // 0b001
    XINT         = 2, // 0b010
    XFLOAT       = 3, // 0b011
    // TODO      = 4, // 0b100
    // TODO      = 5, // 0b101
    // TODO      = 6, // 0b110
    XEXTENDED    = 7, // 0b111
} tag_t;

// one opcode is one byte.

typedef enum {
    NOP      = 0x00,
    LIT      = 0x01,
    CALL     = 0x02,
} opcode_t;

typedef struct ram_t ram_t;
typedef struct emulator_t emulator_t;
typedef struct frame_t frame_t;
