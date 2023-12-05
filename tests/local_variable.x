'my_swap [
  'top set
  'lower set
  'top get
  'lower get
] define

1 2 my_swap
1 int_equal assert
2 int_equal assert
