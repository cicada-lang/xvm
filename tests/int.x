011 9 eq assert
0xFF 255 eq assert

1 dup
1 eq assert
1 eq assert

1 2 3 drop drop
1 eq assert

123 -123 add 0 eq assert

1 1 add 2 eq assert
2 1 sub 1 eq assert
2 2 mul 4 eq assert
3 3 mul 9 eq assert

1 2 lesser assert
1 2 lteq assert
2 2 lteq assert

2 1 greater assert
2 1 greater_or_equal assert
2 2 greater_or_equal assert
