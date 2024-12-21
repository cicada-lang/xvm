rename exe command to emu
remove xexe just use blob

# xvm

[xvm] `xvm_exe(xexe_t xexe)`
[xvm] `x exe` command -- call `xvm_exe`
[xvm] `OP_OK` for testing

# run

[run] `x run` command

# xvm

[xvm] opcode about `xbool` -- `OP_AND` `OP_OR` `OP_NOT`

[xvm] `OP_EQ`
[xvm] `OP_OK` -- as `assert`
[xvm] `OP_DUP`
[xvm] `OP_DROP`
[xvm] `OP_SWAP`
[xvm] `OP_ROT`
[xvm] `OP_OVER`
[xvm] `OP_TUCK`

[xvm] `xint` -- `int64_t` but truncate the lower 3 bits

[xasm] `xasm_asm_token` -- handle lit int

[xvm] `xint_add`
[xvm] `xint_sub`
[xvm] `xint_mul`
[xvm] `xint_div`
[xvm] `xint_mod`

[xvm] `OP_ADD` `OP_SUB` `OP_MUL` `OP_DIV` `OP_MOD`

[xvm] `xfloat` -- double-precision floating-point but truncate the lower 3 bits
[xvm] `xfloat_add`
[xvm] `xfloat_sub`
[xvm] `xfloat_mul`
[xvm] `xfloat_div`
[xvm] `xchar`

[xvm] `xobject` -- first field must be `kind`
[xvm] `xstruct`
[xvm] `xstring`
[xvm] `xtuple`

[xvm] [maybe] use utf8-style opcode encoding -- to be extensible

# xexe

[xexe] `xexe_t` with `lexicon`

# xvm

[xvm] `xsymbol` -- should not use lisp-like symbol for module system
[xvm] [maybe] `xsymbol_inline` -- within 64bits -- max length is 7 bytes
[xvm] [maybe] `xsymbol_long`
