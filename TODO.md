# cli

[command] what should be the name of the class for command-line interface utils?

- cmd? not so good.

[command] api design

- problem: we need to parse argv, and route command to functions, and generate docs.
- solution: parse the argv to a little database, and use builder pattern to add route, with docs.

[command] `x run` -- read from file
[command] `x repl`

[command] `x help`

- `x --help`
- `x -h`

[command] `x version`

- `x --version`
- `x -v`

# tests

setup language tests -- for example tests/hello-world.x

# parser

lexer_lex -- handle JSON int

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
