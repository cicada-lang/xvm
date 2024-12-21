[opcode] `opcode_mnemonic`

# xemu

[xemu] `OP_EQ`

[xemu] `OP_AND` `OP_OR` `OP_NOT`
[xemu] `OP_DUP` `OP_DROP` `OP_SWAP` `OP_ROT` `OP_OVER` `OP_TUCK`

[xemu] `xint` -- `int64_t` but truncate the lower 3 bits

[xemu] `xfloat` -- double-precision floating-point but truncate the lower 3 bits


[xasm] `xasm_step` -- handle lit int

[xemu] `xint_add`
[xemu] `xint_sub`
[xemu] `xint_mul`
[xemu] `xint_div`
[xemu] `xint_mod`

[xemu] `xfloat_add`
[xemu] `xfloat_sub`
[xemu] `xfloat_mul`
[xemu] `xfloat_div`

[xemu] `OP_ADD` `OP_SUB` `OP_MUL` `OP_DIV` `OP_MOD`

[xemu] `xchar`

[xemu] `xobject` -- first field must be `kind`
[xemu] `xstruct`
[xemu] `xstring`
[xemu] `xtuple`

[xemu] [maybe] use utf8-style opcode encoding -- to be extensible

# xemu

[xemu] `xsymbol` -- should not use lisp-like symbol for module system
[xemu] [maybe] `xsymbol_inline` -- within 64bits -- max length is 7 bytes
[xemu] [maybe] `xsymbol_long`
