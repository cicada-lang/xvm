'dup2 [ int_t - int_t int_t ] claim
'mul [ int_t - int_t - int_t ] claim

'int_square [ int_t - int_t ] claim
'int_square [ dup mul ] define

1 int_square 1 eq assert
2 int_square 4 eq assert
3 int_square 9 eq assert
4 int_square 16 eq assert
