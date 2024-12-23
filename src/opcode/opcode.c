#include "index.h"

const char *
opcode_to_mnemonic(opcode_t opcode) {
    return opcode_table[opcode];
}

bool
is_mnemonic(const char *string) {
    for (size_t i = 0; i < 256; i++) {
        opcode_t opcode = (opcode_t) i;
        const char *mnemonic = opcode_table[opcode];
        if (!mnemonic) continue;

        if (string_equal(string, mnemonic)) {
            return true;
        }
    }

    return false;
}

opcode_t
mnemonic_to_opcode(const char *string) {
    for (size_t i = 0; i < 256; i++) {
        opcode_t opcode = (opcode_t) i;
        const char *mnemonic = opcode_table[opcode];
        if (!mnemonic) continue;

        if (string_equal(string, mnemonic)) {
            return opcode;
        }
    }

    assert(false);
}
