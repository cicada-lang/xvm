#include "index.h"

opcode_table_entry_t opcode_table[] = {
    { "NOP", OP_NOP },
    { "LIT", OP_LIT },
    { "CALL", OP_CALL },
    { "OK", OP_OK },
    { "RET", OP_RET },
    { "EQ", OP_EQ },

    { "AND", OP_AND },
    { "OR", OP_OR },
    { "NOT", OP_NOT },

    { "DUP", OP_DUP },
    { "DROP", OP_DROP },
    { "SWAP", OP_SWAP },
    { "ROT", OP_ROT },
    { "OVER", OP_OVER },
    { "TUCK", OP_TUCK },

    { "ADD", OP_ADD },
    { "SUB", OP_SUB },
    { "MUL", OP_MUL },
    { "DIV", OP_DIV },
    { "MOD", OP_MOD },

    { "TO-INT", OP_TO_INT },
    { "TO-FLOAT", OP_TO_FLOAT },

    { "APPLY", OP_APPLY },
};

const char *
opcode_to_mnemonic(opcode_t opcode) {
    size_t length = sizeof(opcode_table) / sizeof(opcode_table_entry_t);
    for (size_t i = 0; i < length; i++) {
        if (opcode == opcode_table[i].opcode) {
            return opcode_table[i].mnemonic;
        }
    }

    assert(false && "[opcode_to_mnemonic] unknown opcode");
}

bool
string_is_mnemonic(const char *string) {
    size_t length = sizeof(opcode_table) / sizeof(opcode_table_entry_t);
    for (size_t i = 0; i < length; i++) {
        if (string_equal(string, opcode_table[i].mnemonic)) {
            return true;
        }
    }

    return false;
}

opcode_t
mnemonic_to_opcode(const char *string) {
    size_t length = sizeof(opcode_table) / sizeof(opcode_table_entry_t);
    for (size_t i = 0; i < length; i++) {
        if (string_equal(string, opcode_table[i].mnemonic)) {
            return opcode_table[i].opcode;
        }
    }

    assert(false && "[mnemonic_to_opcode] unknown mnemonic");
}
