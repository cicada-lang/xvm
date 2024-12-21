[xemu] `xemu_emu(const blob_t *blob)`

- with the help of `blob_copy_into`

# xemu

[xemu] `x emu` command -- call `xemu_emu`
[run] `x run` command -- call both `xasm_asm` and `xemu_emu`

[xemu] `OP_OK` for testing

# xemu

[xemu] opcode about `xbool` -- `OP_AND` `OP_OR` `OP_NOT`

[xemu] `OP_EQ`
[xemu] `OP_OK` -- as `assert`
[xemu] `OP_DUP`
[xemu] `OP_DROP`
[xemu] `OP_SWAP`
[xemu] `OP_ROT`
[xemu] `OP_OVER`
[xemu] `OP_TUCK`

[xemu] `xint` -- `int64_t` but truncate the lower 3 bits

[xasm] `xasm_step` -- handle lit int

[xemu] `xint_add`
[xemu] `xint_sub`
[xemu] `xint_mul`
[xemu] `xint_div`
[xemu] `xint_mod`

[xemu] `OP_ADD` `OP_SUB` `OP_MUL` `OP_DIV` `OP_MOD`

[xemu] `xfloat` -- double-precision floating-point but truncate the lower 3 bits
[xemu] `xfloat_add`
[xemu] `xfloat_sub`
[xemu] `xfloat_mul`
[xemu] `xfloat_div`
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
