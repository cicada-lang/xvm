# parser

parser/token.h

token_t *token_lex(char *code);

xvm_load_code(char *code);
xvm_load_tokens(token_t *tokens);

parser/token.c

use JSON string https://www.json.org/json-en.html

# dict

dict_word -- handle collision by linked list
dict_create -- find prime number above given size

# linear type

[note] with linear type, programs with local variables can still be composed.

we also need record effects in the type, to support exceptions (throw and try catch)

only simple type (with generic)

[maybe] with an object model (abstract away from pointer)

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
