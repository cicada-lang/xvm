#pragma once

struct image_viewer_t {
    const char *path;
    blending_t blending;
    size_t scale;
    bool is_changed;
};

image_viewer_t *image_viewer_new(const char *path);
void image_viewer_destroy(image_viewer_t **self_pointer);

void image_viewer_start(const char *path);
