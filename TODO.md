# builtins

问题：

- 为了保持 xrom 的稳定，不应该像之前一样使用 builtins 了。

方案 A：

- 给每个 tag 一些空间，比如 lower byte `0b1<tag>1111`，
  来把相关的 builtins 编码成稳定的 instruction。

- 这个问题是 64 bits 减去这些 tag，空间太大了，
  不适合用来编码只是从 stack 中取参数的 instruction，太浪费了。
  一些参数应该直接编码在 instruction 中，
  但是这又太复杂了。

- 也许可以设计一个方案，使得多个指令可以被压缩到一个 64bit word 中。

- call 太常用了，应该直接分配一个 tag。

讨论：

- 可以看看其他 64bit 的指令集是如何设计以节省空间的。

- 也许浪费空间为了保持简单也要这样设计。

- 我很难放弃 xrom + xasm 这种设计，
  因为就算是要实现高层的 inet-lisp，
  也许要有一个编译对象。

- 可能应该避免用 64bit 来编码指令，只保持 value 是 64bit 就可以了。

  - 学习 wasm 和 java 的一些设计。

# assembler

[assembler] `assembler_t` -- has `lexer`
[assembler] `assembler_new`
[assembler] `assembler_destroy`

[assembler] setup `name_t`
[assembler] `name_new`
[assembler] `name_destroy`
[assembler] `name_t` -- has `sub_name_hash`
[assembler] `assembler_t` -- has `name_hash`

[assembler] `x asm` command -- call `assembler_assemble`

# xrom

[xrom] executable format -- `[address, length, words...]`

# emulator

[emulator] `xchar`
[emulator] `xint`
[emulator] `xfloat` -- double-precision floating-point but truncate the lower 3 bits
[emulator] `xobject` -- first field must be `kind`

[emulator] `xstring`
[emulator] `xtuple`

[emulator] `x emu` command -- call `emulator_emulate`

# run

[run] `x run` command

# later

[emulator] `xsymbol` -- should not use lisp-like symbol for module system
[emulator] [maybe] `xsymbol_inline` -- within 64bits -- max length is 7 bytes
[emulator] [maybe] `xsymbol_long`
