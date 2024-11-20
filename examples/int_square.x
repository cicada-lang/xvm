'dup2 [ int_t - int_t int_t ] claim
'mul [ int_t - int_t - int_t ] claim

'square [ int_t - int_t ] claim
'square [ dup mul ] define

1 square 1 eq assert
2 square 4 eq assert
3 square 9 eq assert
4 square 16 eq assert
