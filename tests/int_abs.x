'int_abs [
  dup 0 lesser
  [ -1 mul ] if
] define

0 int_abs 0 int_equal assert
1 int_abs 1 int_equal assert
-1 int_abs 1 int_equal assert
