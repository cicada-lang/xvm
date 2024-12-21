[value] `xbool_and`
[value] `xbool_or`
[value] `xbool_not`

[xemu] `OP_AND` `OP_OR` `OP_NOT`

[value] `constant_table`
[xasm] `xasm_step` -- use `constant_table`

[xemu] `OP_DUP` `OP_DROP` `OP_SWAP` `OP_ROT` `OP_OVER` `OP_TUCK`

[value] `xint` -- `int64_t` but truncate the lower 3 bits
[value] `xfloat` -- double-precision floating-point but truncate the lower 3 bits

[xasm] `xasm_step` -- handle lit int

[value] `xint_add`
[value] `xint_sub`
[value] `xint_mul`
[value] `xint_div`
[value] `xint_mod`

[value] `xfloat_add`
[value] `xfloat_sub`
[value] `xfloat_mul`
[value] `xfloat_div`

[xemu] `OP_ADD` `OP_SUB` `OP_MUL` `OP_DIV` `OP_MOD`

[xemu] `xchar`

[xemu] `xobject` -- first field must be `kind`
[xemu] `xstruct`
[xemu] `xstring`
[xemu] `xtuple`

[xemu] [maybe] use utf8-style opcode encoding -- to be extensible

[xemu] `OP_OK` -- `execute` report value stack and frame stack

# xemu

[xemu] `xsymbol` -- should not use lisp-like symbol for module system
[xemu] [maybe] `xsymbol_inline` -- within 64bits -- max length is 7 bytes
[xemu] [maybe] `xsymbol_long`
