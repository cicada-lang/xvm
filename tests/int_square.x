'dup2 [ int_t - int_t int_t ] claim
'int_mul [ int_t - int_t - int_t ] claim

'int_square [ int_t - int_t ] claim
'int_square [ dup int_mul ] define

1 int_square 1 int_equal assert
2 int_square 4 int_equal assert
3 int_square 9 int_equal assert
4 int_square 16 int_equal assert
