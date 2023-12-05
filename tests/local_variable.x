'my_swap [
  'y set 'x set
  'y get 'x get
] define

1 2 my_swap
1 int_equal assert
2 int_equal assert
