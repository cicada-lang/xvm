# vm

[vm] setup `frame`
[vm] `frame_t` -- only has `program_counter` for now -- will have local variables
[vm] `frame_new`
[vm] `frame_destroy`

[vm] `vm_new` -- `frame_stack` -- use `frame_destroy`

[vm] `vm_step`
[vm] `vm_run_until`

[vm] `execute`

values/xint
values/xaddress
values/xobject -- with `kind`

objects/xstring
objects/xtuple

[vm] `x emu` command

# asm

[asm] `x asm` command

# run

[run] `x run` command
