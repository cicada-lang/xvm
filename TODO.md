# remove runtime type

add runtime algebraic data type

```
'list_t datatype_begin
  'null 0 arity_case
  'cons 2 arity_case
datatype_end
```

```
'list_lenght [
  'null [ zero ]
  'cons [ swap drop list_length add1 ]
  'list_t match
] define
```

# NbE

to compare two function types (types of two quoted programs)
we need to first normalize them into two type effects.

# later

`execute` -- handle tail call

# linear local variable

`frame` -- has `locals`

[builtins] `_set`
[builtins] `_get`

support linear local variable by `'name set` and `'name get`

# dict

dict_word -- handle collision by linked list

- test collision by using a small dict size

# maybe

quit using opcode, all that in the body of a program should be words

- a primitive word can do anything to the vm during execution.

# instruction set architecture

design a 32bits stack-based instruction set architecture

- we do not define function, we give label to a list of instructions.

# linear type

we also need record effects in the type, to support exceptions (throw and try catch)

only simple type (with generic)

[maybe] type of `if_else`

```
[ type_merge $merged_type_program bool_t - merged_type_program apply ] 'if_else claim
```

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
