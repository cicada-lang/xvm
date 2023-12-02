[ [ "hello, true!" ]
  [ "hello, false!" ]
  if_else
] 'bool_format_hello define

true bool_format_hello "hello, true!" string_equal assert
false bool_format_hello "hello, false!" string_equal assert
