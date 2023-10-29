---
title: Revised plan
author: Xie Yuheng
date: 2023-10-29
---

Let's design a scripting language for scalable c.

We can try to implement linear type,
maybe without variables, forth is naturally linear type?

We will need to implement borrowing of pointer.
Because a pointer might be passed to subroutine,
while subroutine should not delete the pointer

If linear type does not work we go back to simple type.
