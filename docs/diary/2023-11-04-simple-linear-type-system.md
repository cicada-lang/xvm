---
title: Simple linear type system
author: Xie Yuheng
date: 2023-11-04
---

We should not use `[ ... -- ... ]` to specify type of a program,
we should factor the complicated syntax to pure postfix word composition,
using `-` -- which takes two types from the stack and unify them.

```
[ int_t - int_t ] 'square claim
[ int_dup int_mul ] 'square define
```

- The type of `-` would be `[ type_t - type_t - ]`,
  which can also be used in normal program.

- `type_t` is a sum type of `type_term_t` and `type_var_t`.

`:a` generate `type_var`, and it will be scoped
in current type program context (not current frame).

- I also thought about using `?a`, but
  a lot of `?` in the code feels too noisy.

```
[ :a list_t ] 'list_null claim
[ :a - :a list_t - :a list_t ] 'list_cons claim
[ [ :a - :a list_t - :b ] - [ :b ] - :a list_t - :b ] 'list_match claim
```

Beside `value_stack` we can use `input_stack`
to handle stack underflow during type checking.

When calling `define`, we should perform type checking.
During which instructions will be interpreted in a new context,
which stores substitution.

# Maybe also [ ... -- ... ]

Maybe have everything reversed is not ok.
Because it feels so un-intuitive that
every inputs have to be in reverse.

```
[ :a list_t ] 'list_null claim
[ :a list_t :a -- :a list_t ] :list_cons claim
[ :a list_t [ :b ] [ :a list_t :a -- :b ] -- :b ] 'list_match claim
```

But the semantics of composition is so good.
It feels evil, but maybe I can implement both `-` and `--`.

How to implement `--`?

A frame can record the stack pointer on enter,
`--` can use this stack pointer to collect types into `input_type_stack`.

# Defining types

About defining types,
because the arity is all we need for now,
I come up with this crazy long word first:

```
0 'int_t define_type_constructor_by_arity
1 'list_t define_type_constructor_by_arity
```

But actually a type constructor definition
is like a `claim` plus a trivial arity-based runtime behavior,
thus maybe we should write:

```
[ type_t ] 'int_t type_claim
[ type_t - type_t ] 'list_t type_claim
```
