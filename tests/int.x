123 int_print newline
-123 int_print newline

011 9 int_equal assert
0xFF 255 int_equal assert

1 int_dup
1 int_equal assert
1 int_equal assert

1 2 3 int_drop int_drop
1 int_equal assert

123 -123 int_add 0 int_equal assert

1 1 int_add 2 int_equal assert
2 1 int_sub 1 int_equal assert
2 2 int_mul 4 int_equal assert
3 3 int_mul 9 int_equal assert

1 2 int_lesser assert
1 2 int_lesser_or_equal assert
2 2 int_lesser_or_equal assert

2 1 int_greater assert
2 1 int_greater_or_equal assert
2 2 int_greater_or_equal assert
