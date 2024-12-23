#pragma once

const char *opcode_to_mnemonic(opcode_t opcode);
bool string_is_mnemonic(const char *string);
opcode_t mnemonic_to_opcode(const char *string);
