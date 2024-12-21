#pragma once

blob_t *blob_new(size_t size);
void blob_destroy(blob_t **self_pointer);

size_t blob_size(blob_t *self);
uint8_t *blob_bytes(blob_t *self);
char *blob_string(blob_t *self);

void blob_copy_from(blob_t *self, uint8_t *bytes);

bool blob_equal(blob_t *left, blob_t *right);
blob_t *blob_dup(blob_t *self);
