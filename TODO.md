# builtins

[builtins] _string_equal

[builtins] _int_equal
[builtins] _int_greater
[builtins] _int_lesser
[builtins] _int_greater_or_equal
[builtins] _int_lesser_or_equal

[builtins] _word_equal
[builtins] _bool_equal

[builtins] _string_free
[builtins] _int_drop
[builtins] _word_drop
[builtins] _bool_drop

# dict

dict_word -- handle collision by linked list

- test collision by using a small dict size

# linear type

support linear local variable by `'name set` and `'name get`

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
