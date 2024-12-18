# vm

[vm] setup `value.c`

[vm] `value_t` -- 用最经典的 3-bit tag + 61-bit value runtime 编码
[vm] `tag_t`
[vm] `value_tag`

[vm] `vm_t` -- has `value_stack` and `return_stack`
[vm] `vm_new`
[vm] `vm_destroy`

values/xint
values/xaddress
values/xobject

```
xobject_t   -- 0
- xstring_t -- XSTRING
- xtuple_t  -- XTUPLE
xaddress_t  -- 1 -- address in code is different from address of pointer
xint_t      -- 2

x_immediate_t -- 3
- xbool_t    --
- xchar_t    --
- xnull_t    --
```

[vm] `x emu` command

# asm

[asm] `x asm` command

# run

[run] `x run` command
