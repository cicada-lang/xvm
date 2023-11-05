# parser

[maybe] opcode.h -- use enum

lexer -- has lexer_mode -- IN_SPACE & IN_WORD -- instead of in_space_p
lexer -- lexer_mode -- IN_DOUBLE_QUOTES

lexer_lex -- support JSON string
lexer_lex -- support JSON int

execute should free frame

interpret_token

vm_t -- COMPILING v.s. INTERPRETING mode

# dict

dict_word -- handle collision by linked list
dict_create -- find prime number above given size

# linear type

support linear local variable by `'name set` and `'name get`

we also need record effects in the type, to support exceptions (throw and try catch)

only simple type (with generic)

# learn

read the c book -- learn about array and pointer and struct
read czmq -- learn C API

# device

port uxn console IO -- design better API

port uxn screen IO -- design better API

do something like the uxn screen IO but for 3D!

learn freecad and instead of the editor-based UI,
design a XML-based UI for modelling 3D objects.
