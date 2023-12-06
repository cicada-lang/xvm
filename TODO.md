# remove runtime type

bind datatype to name
bind data_constructor to name

data_t -- data of algebraic datatype

- has data_constructor
- has args of values

_match_softly -- does NOT free the matched data
_match -- free the match data

add runtime algebraic data type

```
'list_t datatype_define
  'null 0 arity_case
  'cons 2 arity_case
datatype_close
```

```
'list_lenght [
  'null [ zero ]
  'cons [ swap drop list_length add1 ]
  'list_t match_softly
] define
```

# maybe

quit using opcode, all that in the body of a program should be words

- a primitive word can do anything to the vm during execution.

- we need hidden word entry -- like forth.

  - simply use word with space

    - `(hidden) literal_atom`
    - `(hidden) literal_string` -- need to clone string
    - `(hidden) literal_program` -- NO need to clone program

# repl

[repl] repl_command

# dict

dict_word -- handle collision by linked list

- test collision by using a small dict size

# command-line

[command-line] parse options

[command-line] `x --help`
[command-line] `x -h`
[command-line] `x --version`
[command-line] `x -v`
