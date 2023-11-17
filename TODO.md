move vm_define_builtins to builtins/define_builtins

interpreter_compile_token -- handle 'word

# builtins

[builtins] _define
[builtins] _assert

# dict

dict_word -- handle collision by linked list
dict_create -- find prime number above given size

# linear type

support linear local variable by `'name set` and `'name get`

we also need record effects in the type, to support exceptions (throw and try catch)

only simple type (with generic)

# command-line

[command-line] run_command -- refactor

# command-line

[command-line] parse options

[command-line] `x --help`
[command-line] `x -h`
[command-line] `x --version`
[command-line] `x -v`

# repl

[repl] repl_command

# device

port uxn console IO -- design better API

port uxn screen IO -- design better API

do something like the uxn screen IO but for 3D!

learn freecad and instead of the editor-based UI,
design a XML-based UI for modelling 3D objects.
