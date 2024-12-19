# vm

[vm] `xaddress`
[vm] `value_is_xaddress`
[vm] `value_to_address`

[vm] `execute` -- handle `xopcode_call`

[vm] `xchar`
[vm] `xint`
[vm] `xfloat` -- double-precision floating-point but truncate the lower 3 bits
[vm] `xobject` -- first field must be `kind`

[vm] `xstring`
[vm] `xtuple`

[vm] `x emu` command

# asm

[asm] `x asm` command

# run

[run] `x run` command

# later

[vm] `xsymbol` -- should not use lisp-like symbol for module system

- [vm] xsymbol_inline -- within 64bits -- max length is 7 bytes
- [vm] xsymbol_long
