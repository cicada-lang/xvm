`execute_word` -- handle `type_constructor`

vm has scope for type variables -- enter the scope during running of a type

`:a` create `type_var_t`

`-` as a builtin word -- `type_unify`

`--` as a builtin word -- `type_unify_many`

# later

`execute` -- handle tail call

[builtins] `_type_claim` -- need to get arity from `input_type_stack`

```
[ type_t ] 'int_t type_claim
[ type_t - type_t ] 'list_t type_claim
```

# linear local variable

`frame` -- has `locals`

[builtins] `_set`
[builtins] `_get`

support linear local variable by `'name set` and `'name get`

# dict

dict_word -- handle collision by linked list

- test collision by using a small dict size

# linear type

we also need record effects in the type, to support exceptions (throw and try catch)

only simple type (with generic)

[maybe] type of `bool_choose`

```
[ type_merge $merged_type_program bool_t - merged_type_program apply ] 'bool_choose claim
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
