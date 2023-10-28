return_stack_t
return_stack_pop & return_stack_push

# program

program_byte_size
program_fetch_byte
program_fetch_value
program_append_bytes
program_append_call
program_append_value

# xvm

xvm_primitive_set
xvm_primitive
xvm_load
xvm_step

# dict

dict_word -- handle collision by linked list
dict_create -- find prime number above given size

# linear type

[note] with linear type, programs with local variables can still be composed.

we also need record effects in the type, to support exceptions (throw and try catch)

only simple type (with generic)

[maybe] with an object model (abstract away from pointer)

# parser

# learn

read the c book -- learn about array and pointer and struct
learn makefile -- maybe from learn-assembly/x86/day1
setup tdd -- to first write API examples
learn zlist for basic c class example
dict & word -- hash table from word to list of words
- learn from zhash
- [maybe] we should say "word" instead of "symbol"
