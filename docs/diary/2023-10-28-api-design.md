---
title: API design
author: Xie Yuheng
date: 2023-10-28
---

```c
void xvm_define_program(xvm_t *vm);
void xvm_define_primitive(xvm_t *vm);
```

```c
xvm_define_program(vm, "square", (char ){
  "dup",
  "mul",
});

xvm_define_primitive(vm, );
```
