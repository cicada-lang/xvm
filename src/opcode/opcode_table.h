#pragma once

struct opcode_table_entry_t {
    const char *mnemonic;
    opcode_t opcode;
};

typedef struct opcode_table_entry_t opcode_table_entry_t;

extern opcode_table_entry_t opcode_table[];

const char *opcode_to_mnemonic(opcode_t opcode);
bool string_is_mnemonic(const char *string);
opcode_t mnemonic_to_opcode(const char *string);
