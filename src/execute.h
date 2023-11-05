#pragma once

void execute(const vm_t *self, frame_t *frame);
void execute_call(const vm_t *self, frame_t *frame);
void execute_literal_value(const vm_t *self, frame_t *frame);
