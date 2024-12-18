#pragma once

struct font_editor_t {
    canvas_t *canvas;
    blending_t blending;
    font_t *font;
    glyph_t *glyph;
    size_t page;
};

font_editor_t *font_editor_new(font_t *font);
void font_editor_destroy(font_editor_t **self_pointer);

void font_editor_start(font_t *font);
