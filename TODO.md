remove old code
init new c project by cicada-lang/c-modules

# new plan

xvm -- xasm and xemu -- 用最经典的 4-bit tag + 62-bit value runtime 编码
- xasm 重点在于能以灵活的方式把 byte 写入 rom
- xemu 重点在于实现起来简单
- 如何设计一个带有 symbol 的 rom（可执行文件格式）？
  - symbol 的语法是 :symbol
  - 或者直接用 string？

# algebraic datatype

entry in word should be a tagged_t

primitive datatype data_constructor program should have tag

a function that maps tag to name

bind datatype to name
bind data_constructor to name

data_t -- data of algebraic datatype

- has data_constructor
- has args of values

_match -- does NOT free the matched data
_decons -- free the match data

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
  'list_t match
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
