---
title: Initial plan
author: Xie Yuheng
date: 2023-10-20
---

Instead of a VM for byte code,
I want a VM for forth-like word code.
Because people use byte code for fast load time,
but forth-like system is trivial to parse,
thus already have first load time.

# Basic features

- Two stacks, value stack and return stack.
- Indirect threaded code interpreter.
- No GC, use explicit memory management.
- Every value is 64 bits number.

# Additions to forth

- Be able to quote program (no closure).
- Be able to collect values in stack from a quoted program.
- Module system (one file one module).

# Primitive datatypes

- string (simply use c string)
- int and float number (both 64 bits)
- word (address of entry in hash map)

# Syntax

- Except for quotation`[ ... ]`, all syntax should be pure postfix.
- Mostly whitespace separated words, except for string and quotation.
  - Use JSON string: https://www.json.org

# Semantics

- To define a word (in a dictionary),
  is to map a word to a sequence of words.

# Examples

```
[ 'int_mul 'int_t ] "./int.x" import
"./int.x" require

[ int_t type_unify int_t ] 'square claim
[ value_dup int_mul ] 'square define
```
