[xasm] xasm_disasm
[xasm] setup disasm command
[xemu] OP_OK -- execute report value stack and frame stack

[xemu] frame has locals -- 32 max
[opcode] LOCAL_SET LOCAL_GET -- just use int as index
[xasm] [maybe] use $1! and $1 for LOCAL_SET and LOCAL_GET

[xemu] xsymbol
[xemu] [maybe] xsymbol_inline -- within 64bits -- max length is 7 bytes
[xemu] [maybe] xsymbol_long

[xemu] xobject -- first field must be kind
[xemu] xstruct

[xemu] xstring
[xemu] xtuple
[xemu] xchar

[xemu] [maybe] use utf8-style opcode encoding -- to be extensible

[motivation] at worst, xvm will provide inet tagged primitive values
