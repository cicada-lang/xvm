'int_abs [
  dup 0 lesser
  [ -1 mul ] if
] define

0 int_abs 0 eq assert
1 int_abs 1 eq assert
-1 int_abs 1 eq assert
