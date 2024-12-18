remove font editor and image viewer

# new plan

xvm -- xasm and xemu -- 用最经典的 4-bit tag + 62-bit value runtime 编码
- xasm 重点在于能以灵活的方式把 byte 写入 rom
- xemu 重点在于实现起来简单
- 如何设计一个带有 symbol 的 rom（可执行文件格式）？
  - symbol 的语法是 :symbol
  - 或者直接用 string？
