[string] string_parse_xint

[xasm] xasm_step_int -- handle lit int

[value] xint_add xint_sub xint_mul xint_div xint_mod

[xemu] OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD

[value] xfloat -- double-precision floating-point but truncate the lower 3 bits
[value] is_xfloat
[value] to_doule

[value] xfloat_add xfloat_sub xfloat_mul xfloat_div

[xemu] OP_ADD OP_SUB OP_MUL OP_DIV -- support xfloat

[xemu] INT and FLOAT -- explicit convert between xint and xfloat

[value] constant_table
[xasm] xasm_step -- use constant_table

[xemu] xchar

[xemu] xobject -- first field must be kind
[xemu] xstruct
[xemu] xstring
[xemu] xtuple

[xemu] [maybe] use utf8-style opcode encoding -- to be extensible

[xemu] OP_OK -- execute report value stack and frame stack

# xemu

[xemu] xsymbol -- should not use lisp-like symbol for module system
[xemu] [maybe] xsymbol_inline -- within 64bits -- max length is 7 bytes
[xemu] [maybe] xsymbol_long
