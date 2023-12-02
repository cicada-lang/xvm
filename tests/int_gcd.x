[
  [ x y ] swap
  [ y x ] int_dup
  [ y x x ] rot
  [ x x y ] int_dup
  [ x x y y ] rot
  [ x y y x ] swap
  [ x y x y ]
]

'int_dup2 [ swap int_dup rot int_dup rot swap ] define

1 2 int_dup2
2 int_equal assert
1 int_equal assert
2 int_equal assert
1 int_equal assert

'int_gcd [
  int_dup2 int_equal
  [ int_drop ]
  [ int_dup2 int_greater
    [ int_dup2 int_sub rot int_drop ]
    [ int_dup2 swap int_sub swap int_drop ]
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
