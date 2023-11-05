#pragma once

void execute(vm_t *self, frame_t *frame);
void execute_call(vm_t *self, frame_t *frame);
void execute_literal_value(vm_t *self, frame_t *frame);
