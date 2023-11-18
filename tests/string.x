"abc" "abc" string_equal assert
"abc" "abcd" string_equal bool_not assert

"a" "b" string_drop
"a" string_equal assert

"a" string_dup
"a" string_equal assert
"a" string_equal assert
