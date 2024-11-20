"abc" "abc" string_equal assert
"abc" "abcd" string_equal not assert

"a" "b" string_free
"a" string_equal assert

"a" string_clone
"a" string_equal assert
"a" string_equal assert
