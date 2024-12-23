#include "index.h"

const char *opcode_table[256] = {
    "NOP", "LIT", "CALL", "OK", "END", "EQ",
    "AND", "OR", "NOT",
    "DUP", "DROP", "SWAP", "ROT", "OVER", "TUCK",
    "ADD", "SUB", "MUL", "DIV", "MOD",
    "TO-INT", "TO-FLOAT",
};
