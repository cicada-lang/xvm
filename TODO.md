[opcode] extract mnemonic_to_opcode
[value] xnull constant
[value] xtrue and xfalse should be constant
[xasm] constant_table and find_constant
[xasm] xasm_step -- use find_constant

[xasm] $name for local variable

[xemu] TO-INT and TO-FLOAT -- explicit convert between xint and xfloat

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
