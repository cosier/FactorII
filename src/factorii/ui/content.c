#include <factorii/ui/content.h>

void fii_content(GLFWwindow *win, struct nk_context *ctx, int width,
                 int height) {
    if (!win) {
    }

    int ow = 220;
    struct nk_color off_white = nk_rgb(ow, ow, ow);

    // struct nk_command_buffer *out = NULL;

    nk_style_push_style_item(ctx, &ctx->style.window.fixed_background,
                             nk_style_item_color(off_white));

    if (nk_begin(ctx, "Content", nk_rect(sidebar_width(width), 50,
                                         content_width(width), height),
                 0)) {
    }

    nk_style_pop_style_item(ctx);
    nk_end(ctx);
}
