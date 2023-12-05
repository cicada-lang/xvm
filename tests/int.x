011 9 int_equal assert
0xFF 255 int_equal assert

1 dup
1 int_equal assert
1 int_equal assert

1 2 3 drop drop
1 int_equal assert

123 -123 add 0 int_equal assert

1 1 add 2 int_equal assert
2 1 sub 1 int_equal assert
2 2 mul 4 int_equal assert
3 3 mul 9 int_equal assert

1 2 lesser assert
1 2 lesser_or_equal assert
2 2 lesser_or_equal assert

2 1 greater assert
2 1 greater_or_equal assert
2 2 greater_or_equal assert
