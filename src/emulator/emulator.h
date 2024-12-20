#pragma once

struct emulator_t {
    size_t ram_size;
    void *ram;
    stack_t *value_stack;
    stack_t *return_stack;
};

emulator_t *emulator_new(size_t ram_size);
void emulator_destroy(emulator_t **self_pointer);

void emulator_step(emulator_t *self);
void emulator_run_until(emulator_t *self, size_t base_length);
