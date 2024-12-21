#include "index.h"

const char *
opcode_mnemonic(opcode_t opcode) {
    return opcode_table[opcode];
}
