'dup2 [
  'y set 'x set
  'x get dup 'x set
  'y get dup 'y set
  'x get
  'y get
] define

1 2 dup2
2 eq assert
1 eq assert
2 eq assert
1 eq assert

'int_gcd [
  dup2 eq
  [ drop ]
  [ dup2 gt
    [ dup2 sub rot drop ]
    [ dup2 swap sub swap drop ]
    if_else
    int_gcd ]
  if_else
] define

8 12 int_gcd
4 eq assert

17 5 int_gcd
1 eq assert

1 1 int_gcd
1 eq assert
