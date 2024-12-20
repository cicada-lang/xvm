# rom

[rom] setup `rom/`
[rom] `rom_t`
[rom] executable format -- `[address, length, words...]`

# const object

问题：如何处理函数中的 const object？

方案 A：

- 在编译时在 heap 中生成 object，保存指针到当前位置。

  ```
  @user-name <comptime> "xieyuheng" here </comptime> end
  ```

  这要求在 assemble 的过程中可以运行 emulator。

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
  @user/struct
    :name string? TODO 想要用这些 predicate 就需要 standard lib
    :age int?
    END

  @main
    &user cons TODO 可以区分 local 和 heap 的 struct
    &user new
    END
  ```

讨论：

- 是否应该放弃 tagged value？
  如果放弃，就完全不用考虑 heap memory 的问题了。
  如果放弃了，如何实现 inet？
  可以在实现 inet 的编译器的时候，再加上 tagged value。

- 可以是「方案 C」 和「方案 B」的结合。
  我们很难放弃 xasm + xemu 的方案，
  因为考虑 inet 的实现，就算是用 lisp 语法，也要编译的 stack vm。
  既然觉得可以有 inet-asm，那么 xasm 中也可以加 struct。

  - 模仿 jai。struct 可以标记对 field 的 ownership，
    这样就可以递归的 free。

  - 如何处理 array 对元素的 ownership？
    learn from jai。

# assembler

[assembler] `assembler_t` has `rom`
[assembler] setup `name_t`
[assembler] `name_new`
[assembler] `name_destroy`
[assembler] `name_t` -- has `sub_name_hash`
[assembler] `assembler_t` -- has `name_hash`
[assembler] `assembler_step`
[assembler] `x asm` command -- call `assembler_assemble`

# run

[run] `x run` command

# emulator

[emulator] use utf8-style opcode encoding -- to be extensible

[emulator] opcode about `xbool` -- `OP_AND` `OP_OR` `OP_NOT`
[emulator] `OP_EQ`
[emulator] `OP_OK` -- as `assert`
[emulator] `OP_DUP`
[emulator] `OP_DROP`
[emulator] `OP_SWAP`
[emulator] `OP_ROT`
[emulator] `OP_OVER`
[emulator] `OP_TUCK`
[emulator] `xint` -- `int64_t` but truncate the lower 3 bits
[emulator] `xint_add`
[emulator] `xint_sub`
[emulator] `xint_mul`
[emulator] `xint_div`
[emulator] `xint_mod`
[emulator] `OP_ADD` `OP_SUB` `OP_MUL` `OP_DIV` `OP_MOD`
[emulator] `xfloat` -- double-precision floating-point but truncate the lower 3 bits
[emulator] `xfloat_add`
[emulator] `xfloat_sub`
[emulator] `xfloat_mul`
[emulator] `xfloat_div`
[emulator] `xchar`
[emulator] `xobject` -- first field must be `kind`
[emulator] `xstring`
[emulator] `xtuple`
[emulator] `x emu` command -- call `emulator_emulate`

# later

[emulator] `xsymbol` -- should not use lisp-like symbol for module system
[emulator] [maybe] `xsymbol_inline` -- within 64bits -- max length is 7 bytes
[emulator] [maybe] `xsymbol_long`
