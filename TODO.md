# vm

[vm] `frame_t`
[vm] `vm_new` -- `frame_stack` -- use `frame_destroy`

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
- xop_t      --
```

[vm] `x emu` command

# asm

[asm] `x asm` command

# run

[run] `x run` command
