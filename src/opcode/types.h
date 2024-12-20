#pragma once

// one opcode is one byte.

typedef uint8_t opcode_t;

#define OP_NOP   ((opcode_t) 0x00)
#define OP_LIT   ((opcode_t) 0x01)
#define OP_CALL  ((opcode_t) 0x02)
// ...
#define OP_END   ((opcode_t) 0xff)
