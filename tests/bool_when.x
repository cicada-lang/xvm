[ bool_dup
  [ "hello, true!" string_print newline ] if
  [ "hello, false!" string_print newline ] if
] 'bool_hello define

true bool_hello
false bool_hello
