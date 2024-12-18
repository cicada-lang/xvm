#include "index.h"

#define WIDTH (60 * TILE)
#define HEIGHT (40 * TILE)
#define SCALE 4

static void
init_canvas_theme(canvas_t *canvas) {
    canvas->palette[BG_COLOR] = 0xffffffff;
    canvas->palette[SL_COLOR] = 0xffff8888;
    canvas->palette[FG_COLOR] = 0xffffffff;
    canvas->palette[AP_COLOR] = 0xff000000;
}

static void
init_canvas_asset_store(canvas_t *canvas) {
    char *root = dirname(dirname(dirname(string_dup(__FILE__))));
    canvas_init_asset_store(canvas, string_append(root, "/assets"));
}

static void
init_canvas_font(canvas_t *canvas) {
    blob_t *blob = canvas_asset_store_get(canvas, "fonts/unifont_all-16.0.02.hex");
    canvas->font = font_from_hex_string(blob_string(blob));
}

font_editor_t *
font_editor_new(font_t *font) {
    font_editor_t *self = new(font_editor_t);

    self->font = font;
    self->glyph = font_first_glyph(font);
    self->page = 0;

    canvas_t *canvas = canvas_new(WIDTH, HEIGHT, SCALE);
    canvas->state = self;
    canvas->title = "app";
    self->canvas = canvas;

    init_canvas_theme(canvas);
    init_canvas_asset_store(canvas);
    init_canvas_font(canvas);

    return self;
}

void
font_editor_destroy(font_editor_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        font_editor_t *self = *self_pointer;
        canvas_destroy(&self->canvas);
        font_destroy(&self->font);
        free(self);
        *self_pointer = NULL;
    }
}

static void
draw_background_grid(font_editor_t *self, canvas_t *canvas) {
    (void) self;

    for (size_t i = 0; i < WIDTH / TILE; i++) {
        for (size_t j = 0; j < HEIGHT / TILE; j++) {
            canvas_draw_pixel(canvas, i * TILE, j * TILE, 0xffff0000);
        }
    }
}

static void
draw_glyph(font_editor_t *self, canvas_t *canvas) {
    if (!self->glyph) return;

    size_t x = 38 * TILE;
    size_t y = 4 * TILE;

    size_t thickness = 2;
    size_t width = glyph_width(self->glyph) * TILE;
    size_t height = glyph_height(self->glyph) * TILE;
    canvas_draw_rect(
        canvas,
        x - thickness,
        y - thickness,
        width + thickness * 2,
        height + thickness * 2,
        thickness,
        canvas->palette[SL_COLOR]);

    for (size_t i = 1; i < width / TILE; i++) {
        for (size_t j = 1; j < height / TILE; j++) {
            canvas_draw_pixel(
                canvas,
                x + i * TILE,
                y + j * TILE,
                canvas->palette[SL_COLOR]);
        }
    }

    size_t scale = TILE;
    canvas_draw_glyph(
        canvas,
        x, y,
        self->glyph,
        scale,
        TR_AP_BLENDING);
}

static void
draw_glyph_info(font_editor_t *self, canvas_t *canvas) {
    (void) self;
    (void) canvas;
}

static void
on_click_page(font_editor_t *self, canvas_t *canvas, uint8_t button, bool is_release) {
    (void) self;
    (void) canvas;

    if (button == 1 && !is_release) {
        size_t x_offset = 4 * TILE;
        size_t y_offset = 4 * TILE;

        size_t col = (canvas->cursor->x - x_offset) / (2 * TILE);
        size_t row = (canvas->cursor->y - y_offset) / (2 * TILE);
        code_point_t code_point = self->page * (16 * 16) + row * 16 + col;
        glyph_t *glyph = font_get(self->font, code_point);
        if (glyph) {
            self->glyph = glyph;
        }
    }
}

static void
draw_page(font_editor_t *self, canvas_t *canvas) {
    size_t x_offset = 4 * TILE;
    size_t y_offset = 4 * TILE;

    canvas_add_clickable_area(
        canvas,
        x_offset,
        y_offset,
        16 * 2 * TILE,
        16 * 2 * TILE,
        (on_click_fn_t *) on_click_page);

    size_t scale = 1;
    for (size_t row = 0; row < 16; row++) {
        for (size_t col = 0; col < 16; col++) {
            code_point_t code_point = self->page * (16 * 16) + row * 16 + col;
            glyph_t *glyph = font_get(self->font, code_point);
            if (glyph) {
                if (glyph == self->glyph) {
                    canvas_fill_rect(
                        canvas,
                        x_offset + col * 2 * TILE,
                        y_offset + row * 2 * TILE,
                        glyph_width(glyph),
                        glyph_height(glyph),
                        canvas->palette[SL_COLOR]);
                }

                canvas_draw_glyph(
                    canvas,
                    x_offset + col * 2 * TILE,
                    y_offset + row * 2 * TILE,
                    glyph,
                    scale,
                    TR_AP_BLENDING);
            }
        }
    }
}

static void
on_frame(font_editor_t *self, canvas_t *canvas, uint64_t passed) {
    (void) passed;

    canvas->window->background_pixel = canvas->palette[BG_COLOR];
    canvas_fill_bottom_right(canvas, 0, 0, canvas->palette[BG_COLOR]);
    canvas_clear_clickable_area(canvas);

    (void) draw_background_grid;
    // draw_background_grid(self, canvas);

    draw_glyph(self, canvas);
    draw_glyph_info(self, canvas);
    draw_page(self, canvas);
}

static void
on_key(
    font_editor_t *self,
    canvas_t *canvas,
    const char *key_name,
    bool is_release
) {
    (void) canvas;

    if (is_release) {
        if (string_equal_mod_case(key_name, "space")) {
            self->page++;
            if (self->page > MAX_CODE_POINT / (16 * 16)) {
                self->page = 0;
            }
            code_point_t code_point = self->page * (16 * 16);
            glyph_t *glyph = font_next_glyph(self->font, code_point - 1);
            if (glyph) {
                self->glyph = glyph;
            } else {
                self->glyph = NULL;
            }
        }
    }
}

void
font_editor_start(font_t *font) {
    font_editor_t *self = font_editor_new(font);
    self->canvas->on_frame = (on_frame_fn_t *) on_frame;
    self->canvas->on_key = (on_key_fn_t *) on_key;

    canvas_open(self->canvas);

    font_editor_destroy(&self);
}
