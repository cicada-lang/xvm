true bool_print newline
false bool_print newline

true bool_dup assert assert

true false bool_drop
true bool_equal assert

true true bool_equal assert
false false bool_equal assert
true false bool_equal bool_not assert

true bool_not false bool_equal assert
false bool_not true bool_equal assert

true false bool_and false bool_equal assert
true true bool_and true bool_equal assert

true false bool_or true bool_equal assert
false false bool_or false bool_equal assert
