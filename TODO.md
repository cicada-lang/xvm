# vm

[vm] `xchar`
[vm] `xint`
[vm] `xfloat` -- double-precision floating-point but truncate the lower 3 bits
[vm] `xaddress`
[vm] `xobject` -- first field must be `kind`

[vm] `execute`

[vm] `xstring`
[vm] `xsymbol` -- should not use lisp-like symbol for module system
- [vm] xsymbol_inline -- within 64bits -- max length is 7 bytes
- [vm] xsymbol_long
[vm] `xtuple`

[vm] `x emu` command

# asm

[asm] `x asm` command

# run

[run] `x run` command
