#include "index.h"

static void
draw_blending_table(canvas_t *canvas) {
    size_t offset = TILE;

    for (uint8_t x = 0; x < 4; x++) {
        for (uint8_t y = 0; y < 4; y++) {
            blending_t blending = x + y * 4;
            canvas_draw_image(
                canvas,
                offset + x * 2 * TILE,
                offset + y * 2 * TILE,
                "blending-02x02.chr",
                blending);
        }
    }
}

static void
on_frame(void *state, canvas_t *canvas, uint64_t passed) {
    (void) state;
    (void) passed;

    canvas->window->background_pixel = 0xffaaaaaa;
    canvas_fill_bottom_right(canvas, 0, 0, 0xffaaaaaa);
    canvas_clear_clickable_area(canvas);

    draw_blending_table(canvas);
}

void
example_blending_start(void) {
    canvas_t *canvas = canvas_new(0xa * TILE, 0xa * TILE, 0x8);
    canvas->state = NULL;
    canvas->frame_rate = 16;
    canvas->on_frame = (on_frame_fn_t *) on_frame;
    canvas_init_asset_store(canvas, dirname(string_dup(__FILE__)));
    canvas->title = "example blending";

    canvas_open(canvas);
    canvas_destroy(&canvas);
}
