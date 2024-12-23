#include "index.h"

const char *
opcode_to_mnemonic(opcode_t opcode) {
    return opcode_table[opcode];
}
