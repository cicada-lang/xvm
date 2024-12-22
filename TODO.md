# xasm

[xasm] xasm_run -- fill xaddress_blank_t at the end
[xasm] xasm_step_call -- address and CALL

# xemu

[xemu] INT and FLOAT -- explicit convert between xint and xfloat

[value] constant_table
[xasm] xasm_step -- use constant_table

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
