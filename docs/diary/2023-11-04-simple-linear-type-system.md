---
title: Simple linear type system
author: Xie Yuheng
date: 2023-11-04
---

We should not use `[ ... -- ... ]` to specify type of a program,
we should factor the complicated syntax to pure postfix word composition,
using `-` -- which takes two types from the stack and unify them.

```
'square [ int_t - int_t ] claim
'square [ dup mul ] define
```

- The type of `-` would be `[ type_t - type_t - ]`,
  which can also be used in normal program.

- `type_t` is a sum type of `type_term_t` and `type_var_t`.

`:a` generate `type_var`, and it will be scoped
in current type program context (not current frame).

- I also thought about using `?a`, but
  a lot of `?` in the code feels too noisy.

```
'list_null [ :a list_t ] claim
'list_cons [ :a - :a list_t - :a list_t ] claim
'list_match [ [ :a - :a list_t - :b ] - [ :b ] - :a list_t - :b ] claim
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
'list_null [ :a list_t ] claim
'list_cons [ :a list_t :a -- :a list_t ] claim
'list_match [ :a list_t [ :b ] [ :a list_t :a -- :b ] -- :b ] claim
```

But the semantics of composition is so good.
It feels evil, but maybe I can implement both `-` and `--`.

How to implement `--`?

A frame can record the stack pointer on enter,
`--` can use this stack pointer to collect types into `input_type_stack`.

Or the general form of a program should be `[ ... -- ... ]`.

# Defining types

About defining types,
because the arity is all we need for now,
I come up with this crazy long word first:

```
'int_t 0 define_type_constructor_by_arity
'list_t 1 define_type_constructor_by_arity
```

But actually a type constructor definition
is like a `claim` plus a trivial arity-based runtime behavior,
thus maybe we should write:

```
'int_t [ type_t ] type_claim
'list_t [ type_t - type_t ] type_claim
```
