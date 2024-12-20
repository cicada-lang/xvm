# assembler

[assembler] `assembler_destroy`

[assembler] setup `name_t`
[assembler] `name_new`
[assembler] `name_destroy`
[assembler] `name_t` -- has `sub_name_hash`
[assembler] `assembler_t` -- has `name_hash`

[assembler] `x asm` command -- call `assembler_assemble`

# xrom

[xrom] executable format -- `[address, length, words...]`

# run

[run] `x run` command

# emulator

[emulator] opcode about `xbool` -- `OP_AND` `OP_OR` `OP_NOT`

[emulator] `OP_EQ`
[emulator] `OP_OK` -- as `assert`
[emulator] `OP_DUP`
[emulator] `OP_DROP`
[emulator] `OP_SWAP`
[emulator] `OP_ROT`
[emulator] `OP_OVER`
[emulator] `OP_TUCK`

[emulator] `xint` -- `int64_t` but truncate the lower 3 bits

[emulator] `xint_add`
[emulator] `xint_sub`
[emulator] `xint_mul`
[emulator] `xint_div`
[emulator] `xint_mod`

[emulator] `OP_ADD` `OP_SUB` `OP_MUL` `OP_DIV` `OP_MOD`

[emulator] `xfloat` -- double-precision floating-point but truncate the lower 3 bits

[emulator] `xfloat_add`
[emulator] `xfloat_sub`
[emulator] `xfloat_mul`
[emulator] `xfloat_div`

[emulator] `xchar`
[emulator] `xobject` -- first field must be `kind`

[emulator] `xstring`
[emulator] `xtuple`

[emulator] `x emu` command -- call `emulator_emulate`

# later

[emulator] `xsymbol` -- should not use lisp-like symbol for module system
[emulator] [maybe] `xsymbol_inline` -- within 64bits -- max length is 7 bytes
[emulator] [maybe] `xsymbol_long`
