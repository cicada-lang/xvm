# assembler

[assembler] setup `assembler`
[assembler] setup `builtins/`
[assembler] `x asm` command
[assembler] `x asm` command call `assembler_assemble`

# emulator

[emulator] `xchar`
[emulator] `xint`
[emulator] `xfloat` -- double-precision floating-point but truncate the lower 3 bits
[emulator] `xobject` -- first field must be `kind`

[emulator] `xstring`
[emulator] `xtuple`

[emulator] `x emu` command

# run

[run] `x run` command

# later

[emulator] `xsymbol` -- should not use lisp-like symbol for module system

- [emulator] xsymbol_inline -- within 64bits -- max length is 7 bytes
- [emulator] xsymbol_long
