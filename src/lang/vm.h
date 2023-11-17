#pragma once

vm_t *vm_create(void);
void vm_destroy(vm_t **self_pointer);

word_t *vm_word(const vm_t *self, const char *name);

value_t vm_value_stack_pop(const vm_t *self);
void vm_value_stack_push(const vm_t *self, value_t value);
bool vm_value_stack_is_empty(const vm_t *self);

frame_t *vm_return_stack_pop(const vm_t *self);
void vm_return_stack_push(const vm_t *self, frame_t *frame);
bool vm_return_stack_is_empty(const vm_t *self);

void vm_load_program(const vm_t *self, program_t *program);
void vm_step(const vm_t *self);
void vm_run(const vm_t *self);
void vm_run_word(const vm_t *self, word_t *word);

program_t *vm_build_program(vm_t *self, const char *name);
void vm_define_primitive(vm_t *self, const char *name, primitive_t *primitive);

vm_t *vm_init(void);
void vm_interpret_code(vm_t *self, const char *code);
