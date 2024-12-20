#pragma once

// one opcode is one byte.

typedef enum {
    OP_NOP        = 0x00,
    OP_LIT        = 0x01,
    OP_CALL       = 0x02,
    // ...
    OP_END        = 0xff,
} opcode_t;

typedef struct ram_t ram_t;
typedef struct frame_t frame_t;
typedef struct xvm_t xvm_t;
