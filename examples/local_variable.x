'my_swap [
  'y set 'x set
  'y get 'x get
] define

1 2 my_swap
1 eq assert
2 eq assert
