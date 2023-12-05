'abs [
  dup 0 lt
  [ -1 mul ] if
] define

0 abs 0 eq assert
1 abs 1 eq assert
-1 abs 1 eq assert
