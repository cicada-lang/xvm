---
title: Simple linear type system
author: Xie Yuheng
date: 2023-11-04
---

We should not use `[ ... -- ... ]` to specify type of a program,
we should factor the complicated syntax to pure postfix word composition,
using `type_unify`.

```
[ int_t type_unify int_t ] 'square claim
[ int_dup int_mul ] 'square define
```

`?a` is a `type_var`.

We can use `-` as an abbreviation of `type_unify`.

```
[ ?a list_t ] 'list_null claim
[ ?a list_t - ?a - ?a list_t ] 'list_cons claim
```

Beside `value_stack` we can use `input_stack`
to handle stack underflow during type checking.

When calling `define`, we should perform type checking.
During which instructions will be interpreted in a new context,
which stores substitution.
