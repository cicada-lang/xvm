#pragma once

void _word_print(const vm_t *vm);
void _word_dup(const vm_t *vm);

void define_word_builtins(vm_t *self);
