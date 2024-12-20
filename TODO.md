# xasm

[xasm] has `ram_expand_step`

[xasm] `xasm_emit_byte` -- call `ram_expand` if needed
[xasm] `xasm_emit_opcode` -- call `ram_expand` if needed
[xasm] `xasm_emit_value` -- call `ram_expand` if needed

[xasm] `xasm_asm` -- call `xasm_step`
[xasm] `xasm_step`

# xexe

[xexe] `xexe_t` -- simple just `bytes` for now
[xexe] `xexe_new`
[xexe] `xexe_destroy`
[xexe] `xexe_read`
[xexe] `xexe_write`

# xvm

[xvm] `xvm_exe`
[xvm] `x exe` command -- call `xvm_exe`

# xasm

[xasm] `x asm` command -- call `xasm_asm` and `xasm_link` to get `xexe`

# name table

[name table] setup `name_path`
[name table] `name_path_t` -- has `name_list`
[name table] `name_path_new`
[name table] `name_path_destroy`

# about object

问题：

- 如何处理函数中的 object？
- 尤其是 const object。

方案 A：

- 在编译时在 heap 中生成 object，保存指针到当前位置。

  ```
  @user-name <comptime> "xieyuheng" here </comptime> end
  ```

  这要求在 assemble 的过程中可以运行 xvm。

方案 B：

- object 只在运行时存在。
  每次都生成新的 object，
  让处理 object 的函数带有 linear 语义，
  在需要的时候主动调用相关的 dup 和 free。

  ```
  @main "xieyuheng" string-dup string-print string-free end
  ```

方案 C：

- 放弃任意的 object in heap，
  只支持 string 和 struct。
  struct 需要在汇编中定义。
  像 C 的 stack frame 一样，
  `frame_t` 有一片区域用来保存 local struct。
  struct-spec 用类似 inet 中 node-spec 的方案来解决。

  ```
  @user/struct :name! :age END
  @main "xieyuheng" 123 &user new END
  ```

讨论：

- 是否应该放弃 tagged value？
  如果放弃，就完全不用考虑 heap memory 的问题了。
  如果放弃了，如何实现 inet？
  可以在实现 inet 的编译器的时候，再加上 tagged value。

- 可以是「方案 C」 和「方案 B」的结合。
  我们很难放弃 xasm + xvm 的方案，
  因为考虑 inet 的实现，就算是用 lisp 语法，也要编译的 stack vm。
  既然觉得可以有 inet-asm，那么 xasm 中也可以加 struct。

  - 模仿 jai。struct 可以标记对 field 的 ownership，
    这样就可以递归的 free。

  - 如何处理 array 对元素的 ownership？
    learn from jai。

# run

[run] `x run` command

# xvm

[xvm] use utf8-style opcode encoding -- to be extensible

[xvm] opcode about `xbool` -- `OP_AND` `OP_OR` `OP_NOT`
[xvm] `OP_EQ`
[xvm] `OP_OK` -- as `assert`
[xvm] `OP_DUP`
[xvm] `OP_DROP`
[xvm] `OP_SWAP`
[xvm] `OP_ROT`
[xvm] `OP_OVER`
[xvm] `OP_TUCK`
[xvm] `xint` -- `int64_t` but truncate the lower 3 bits
[xvm] `xint_add`
[xvm] `xint_sub`
[xvm] `xint_mul`
[xvm] `xint_div`
[xvm] `xint_mod`
[xvm] `OP_ADD` `OP_SUB` `OP_MUL` `OP_DIV` `OP_MOD`
[xvm] `xfloat` -- double-precision floating-point but truncate the lower 3 bits
[xvm] `xfloat_add`
[xvm] `xfloat_sub`
[xvm] `xfloat_mul`
[xvm] `xfloat_div`
[xvm] `xchar`
[xvm] `xobject` -- first field must be `kind`
[xvm] `xstring`
[xvm] `xtuple`

# xexe

[xexe] `xexe_t` with `name_table`

# later

[xvm] `xsymbol` -- should not use lisp-like symbol for module system
[xvm] [maybe] `xsymbol_inline` -- within 64bits -- max length is 7 bytes
[xvm] [maybe] `xsymbol_long`
