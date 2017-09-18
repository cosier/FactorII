#include <factorii/ui/fonts.h>
static struct nk_font *droid;

static float font_width_calc(nk_handle handle, float height, const char *text,
                             int len) {
    //
    return 100;
}

void fii_fonts_load(struct nk_context *ctx) {
    struct nk_font_atlas *atlas;
    nk_glfw3_font_stash_begin(&atlas);

    char *font_path = APP_ROOT  "/vendor/nuklear/extra_font/Roboto-Bold.ttf";
    /*FILE *font_fd = fopen(font_path, "rb");

    if (!font_fd) {
        util_error("failed to open: %s\n", font_path);
        exit(1);
    }*/

    float size = 24;
    struct nk_font_config cfg = nk_font_config(size);
    cfg.oversample_h = 1;
    cfg.oversample_v = 1;
    droid = nk_font_atlas_add_from_file(atlas, font_path, size, &cfg);

    nk_glfw3_font_stash_end();
    nk_style_set_font(ctx, &droid->handle);
}

struct nk_user_font fii_font(struct nk_context *ctx, float size) {
    struct nk_user_font font;

    font.height = size;
    font.userdata.ptr = &droid->handle;
    font.width = &font_width_calc;

    return font;
}
