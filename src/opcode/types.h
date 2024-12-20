#pragma once

// one opcode is one byte.

typedef enum {
    OP_NOP        = 0x00,
    OP_LIT        = 0x01,
    OP_CALL       = 0x02,
    // ...
    OP_END        = 0xff,
} opcode_t;
