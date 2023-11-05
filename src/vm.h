#pragma once

vm_t *vm_create(void);
void vm_destroy(vm_t **self_ptr);

word_t *vm_word(vm_t *self, const char *name);

value_t vm_value_stack_pop(vm_t *self);
void vm_value_stack_push(vm_t *self, value_t value);
bool vm_value_stack_is_empty(vm_t *self);

frame_t *vm_return_stack_pop(vm_t *self);
void vm_return_stack_push(vm_t *self, frame_t *frame);
bool vm_return_stack_is_empty(vm_t *self);

void vm_load_program(vm_t *self, program_t *program);
void vm_step(vm_t *self);
void vm_run(vm_t *self);

program_t *vm_build_program(vm_t *self, const char *name);
void vm_define_primitive(vm_t *self, const char *name, primitive_t *primitive);
void vm_define_builtins(vm_t *self);

vm_t *vm_init(void);
