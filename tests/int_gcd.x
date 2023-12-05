'dup2 [
  'y set 'x set
  'x get dup 'x set
  'y get dup 'y set
  'x get
  'y get
] define

1 2 dup2
2 int_equal assert
1 int_equal assert
2 int_equal assert
1 int_equal assert

'int_gcd [
  dup2 int_equal
  [ drop ]
  [ dup2 int_greater
    [ dup2 int_sub rot drop ]
    [ dup2 swap int_sub swap drop ]
    if_else
    int_gcd ]
  if_else
] define

8 12 int_gcd
4 int_equal assert

17 5 int_gcd
1 int_equal assert

1 1 int_gcd
1 int_equal assert
