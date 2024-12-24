#pragma once

#define OP_NOP         ((opcode_t) 0x00)
#define OP_LIT         ((opcode_t) 0x01)
#define OP_CALL        ((opcode_t) 0x02)
#define OP_OK          ((opcode_t) 0x03)
#define OP_RET         ((opcode_t) 0x04)
#define OP_EQ          ((opcode_t) 0x05)

#define OP_AND         ((opcode_t) 0x06)
#define OP_OR          ((opcode_t) 0x07)
#define OP_NOT         ((opcode_t) 0x08)

#define OP_DUP         ((opcode_t) 0x09)
#define OP_DROP        ((opcode_t) 0x0a)
#define OP_SWAP        ((opcode_t) 0x0b)
#define OP_ROT         ((opcode_t) 0x0c)
#define OP_OVER        ((opcode_t) 0x0d)
#define OP_TUCK        ((opcode_t) 0x0e)

#define OP_ADD         ((opcode_t) 0x0f)
#define OP_SUB         ((opcode_t) 0x10)
#define OP_MUL         ((opcode_t) 0x11)
#define OP_DIV         ((opcode_t) 0x12)
#define OP_MOD         ((opcode_t) 0x13)

#define OP_TO_INT      ((opcode_t) 0x14)
#define OP_TO_FLOAT    ((opcode_t) 0x15)

#define OP_APPLY       ((opcode_t) 0x16)
