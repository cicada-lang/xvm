# emulator

[emulator] `emulator_t` has `ram`

[emulator] `frame_t` has `ram` -- `program_counter` should be a `uint64_t`

[emulator] `frame_fetch_byte`
[emulator] `frame_fetch_opcode`


[emulator] `execute` handle opcodes

[emulator] `xchar`
[emulator] `xint`
[emulator] `xfloat` -- double-precision floating-point but truncate the lower 3 bits
[emulator] `xobject` -- first field must be `kind`

[emulator] `xstring`
[emulator] `xtuple`

[emulator] `x emu` command -- call `emulator_emulate`



# assembler

[assembler] `assembler_t` -- has `lexer`
[assembler] `assembler_new`
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

# later

[emulator] `xsymbol` -- should not use lisp-like symbol for module system
[emulator] [maybe] `xsymbol_inline` -- within 64bits -- max length is 7 bytes
[emulator] [maybe] `xsymbol_long`
