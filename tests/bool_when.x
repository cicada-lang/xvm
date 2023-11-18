[ bool_dup
  [ "hello, true!" string_print newline ] bool_when
  [ "hello, false!" string_print newline ] bool_when
] 'bool_hello define

true bool_hello
false bool_hello
