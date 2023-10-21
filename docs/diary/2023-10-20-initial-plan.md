---
title: Initial plan
author: Xie Yuheng
date: 2023-10-20
---

Instead of a VM for byte code,
I want a VM for forth-like string code.
Because people use byte code for fast load time,
but forth-like system is trivial to parse,
thus already have first load time.

# Basic features

- Two stacks, value stack and return stack.
- Indirect threaded code interpreter.
- No GC, use explicit memory management.
- Every value is a 64 bits number.

# Additions to forth

- Be able to quote program (no closure).
- Be able to collect values in stack from a quoted program.
- Module system (one file one module).

# Primitive datatypes

- string (length + address)
- number (64 bits)
- symbol (index to a hash map of string)

# Syntax

- Except for quotation`[ ... ]`, all syntax should be pure postfix.
- Mostly whitespace separated words, except for string.
  - Use JSON string: https://www.json.org

# Semantics

- To define a word (in a dictionary),
  is to map a word (symbol) to a sequence of words.

# Examples

```
[ 'mul ] "./int.cvm" import

[ dup mul ] 'square define
```
