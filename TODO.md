learn uxn
learn c
learn scalable c

two stacks of 64 bits numbers
no GC
every value is a 64 bits number
be able to quote
be able to collect values in stack from a quote
primitive datatypes
- string (length + address)
- number
- symbol (index to a hash map of string)

module system (one file one module)

except for [] all syntax are pure postfix exc

every symbol may maps to a sequence of words

- words whitespace separated

```
[ 'add 'sub ] "..." import

[  ] 'asd define

[ [  ]
  'fib
  'fib call
  'fib jump
] 'fib define
```
