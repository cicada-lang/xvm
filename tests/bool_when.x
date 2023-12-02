'bool_hello [
  bool_dup
  [ "hello, true!" string_print newline ] if
  [ "hello, false!" string_print newline ] if
] define

true bool_hello
false bool_hello
