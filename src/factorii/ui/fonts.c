#include <factorii/ui/fonts.h>

void fii_fonts_load(struct nk_context *ctx) {
    struct nk_font_atlas *atlas;
    nk_glfw3_font_stash_begin(&atlas);

    char *font_path = "vendor/nuklear/extra_font/DroidSans.ttf";
    FILE *font_fd = fopen(font_path, "rb");

    if (!font_fd) {
        util_error("failed to open: %s\n", font_path);
        exit(1);
    }

    struct nk_font *droid =
        nk_font_atlas_add_from_file(atlas, font_path, 14, 0);

    nk_glfw3_font_stash_end();
    nk_style_set_font(ctx, &droid->handle);
}
