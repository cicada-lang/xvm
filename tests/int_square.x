[ int_t - int_t int_t ] 'int_dup claim
[ int_t - int_t - int_t ] 'int_mul claim

[ int_t - int_t ] 'int_square claim
[ int_dup int_mul ] 'int_square define

1 int_square 1 int_equal assert
2 int_square 4 int_equal assert
3 int_square 9 int_equal assert
4 int_square 16 int_equal assert
