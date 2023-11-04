# parser

extract method out of vm.h
interpret.h -- interpret_code interpret_token
vm_t -- COMPILING v.s. INTERPRETING mode
use INT instead of VALUE as instruction -- for the type system
refactor lexer_lex
lexer_lex -- support JSON string
lexer_lex -- support JSON int

# dict

dict_word -- handle collision by linked list
dict_create -- find prime number above given size

# linear type

support linear local variable by `'name set` and `'name get`

we also need record effects in the type, to support exceptions (throw and try catch)

only simple type (with generic)

# program

program_append_program

# learn

read the c book -- learn about array and pointer and struct
read czmq -- learn C API

# device

port uxn console IO -- design better API

port uxn screen IO -- design better API

do something like the uxn screen IO but for 3D!

learn freecad and instead of the editor-based UI,
design a XML-based UI for modelling 3D objects.
