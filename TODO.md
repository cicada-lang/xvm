# vm

[vm] setup `xbool`
[vm] `as_xbool`
[vm] `is_xbool`
[vm] `xbool_value`

[vm] setup `xnull`

[vm] `value_encode_16_bit` & `value_decode_16_bit`

[vm] xopcode
[vm] xchar

[vm] `frame_is_finished` -- need `end_opcode`

[vm] xint
[vm] xfloat -- double-precision floating-point but truncate the lower 3 bits
[vm] xaddress
[vm] xobject -- with `kind`

[vm] `execute`

[vm] xstring
[vm] xsymbol -- should not use lisp-like symbol for module system
- [vm] xsymbol_inline -- withing 64bits
- [vm] xsymbol_long
[vm] xtuple

[vm] `x emu` command

# asm

[asm] `x asm` command

# run

[run] `x run` command
