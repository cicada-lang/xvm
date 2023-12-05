true dup assert assert

true false drop
true bool_equal assert

true true bool_equal assert
false false bool_equal assert
true false bool_equal not assert

true not false bool_equal assert
false not true bool_equal assert

true false and false bool_equal assert
true true and true bool_equal assert

true false or true bool_equal assert
false false or false bool_equal assert
