'abc word_print newline

'a word_dup
'a word_equal assert
'a word_equal assert

'a 'b 'c word_drop word_drop
'a word_equal assert

'abc 'abc word_equal assert
'abc 'abcd word_equal bool_not assert
