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

[assembler] setup `builtins/`

# xrom

[xrom] executable format -- `[address, length, words...]`

# emulator

[emulator] `xchar`
[emulator] `xint`
[emulator] `xfloat` -- double-precision floating-point but truncate the lower 3 bits
[emulator] `xobject` -- first field must be `kind`

[emulator] `xstring`
[emulator] `xtuple`

[emulator] `x emu` command -- call `emulator_emulate`

# run

[run] `x run` command

# later

[emulator] `xsymbol` -- should not use lisp-like symbol for module system
[emulator] [maybe] `xsymbol_inline` -- within 64bits -- max length is 7 bytes
[emulator] [maybe] `xsymbol_long`
