---
title: Algebraic data type
author: Xie Yuheng
date: 2023-12-03
---

We need to design a runtime algebraic data type,
and also keep it type checkable.

For the runtime, all we need is a `data_t` type,
which have the type tag and case tag.

```
'list_t [ type_t -- type_t ] claim
'null [ -- :a list_t ] claim
'cons [ :a :a list_t -- :a list_t ] claim
```

Designing new syntax like `data` and `match` in lisp feels effortless,
but how should we design new syntax for concatenative language?

```scheme
(data List ((E U)) ()
  (nil () (List E))
  (:: ((e E) (es (List E))) (List E))
  ind-List)
```

```scheme
(claim length
  (Pi ((E U))
    (-> (List E) Nat)))

(define length
  (lambda (E es)
    (match es
      (nil zero)
      ((:: x xs) (add1 (length xs))))))
```
