[xemu] OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD -- support xfloat

[xemu] INT and FLOAT -- explicit convert between xint and xfloat

[value] constant_table
[xasm] xasm_step -- use constant_table

# xasm

[xasm] `xasm_step_label` -- need 2 passes
[xasm] `xasm_step_address` -- need 2 passes
[xasm] `xasm_step_call` -- address and CALL

# xemu

[xemu] xsymbol
[xemu] [maybe] xsymbol_inline -- within 64bits -- max length is 7 bytes
[xemu] [maybe] xsymbol_long

[xemu] xobject -- first field must be kind
[xemu] xstruct

[xemu] xstring
[xemu] xtuple
[xemu] xchar

[xemu] OP_OK -- execute report value stack and frame stack

[xemu] [maybe] use utf8-style opcode encoding -- to be extensible
