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

'abs [ dup 0 lt [ -1 mul ] if ] define
'gcd [ dup2 eq [ drop ] [ dup2 sub abs gcd ] if_else ] define

8 12 gcd
4 eq assert

17 5 gcd
1 eq assert

1 1 gcd
1 eq assert
