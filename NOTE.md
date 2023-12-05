# NbE

To compare two function types (types of two quoted programs)
we need to first normalize them into two type effects.

# instruction set architecture

Design a 32bits stack-based instruction set architecture.

- we do not define function, we give label to a list of instructions.

# linear type

We also need record effects in the type, to support exceptions (throw and try catch).

- Only simple type (with generic)

Maybe type of `if_else` should be:

```
[ type_merge 'merged set bool_t - 'merged get apply ] 'if_else claim
```
