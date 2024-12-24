fix step_call
APPLY vs CALL
[xasm] also output .lexicon -- to support disasm
[xasm] support disasm

[xasm] LOCAL_SET LOCAL_GET -- just use int as index
rename END to RET
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

[motivation] at worst, xvm will provide inet tagged primitive values
