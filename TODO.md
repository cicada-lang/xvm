# vm


[vm] setup `vm/`
[vm] `value_t` -- 用最经典的 4-bit tag + 62-bit value runtime 编码

```
xobject_t  -- 0x0000
- xstring_t -- STRING_VALUE
- xtuple_t  -- TUPLE_VALUE
xaddr_t    -- 0x0001
xint_t     -- 0x0010

x_immediate_t -- 0x0011
- xbool_t    --
- xchar_t    --
- xnull_t    --
```

[vm] `x emu` command

# asm

[asm] `x asm` command

# run

[run] `x run` command
