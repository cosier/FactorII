#include <factorii/ui/content.h>

void fii_content(GLFWwindow *win, struct nk_context *ctx, int width,
                 int height) {
    if (!win) {
    }

    nk_style_push_style_item(ctx, &ctx->style.window.fixed_background,
                             nk_style_item_color(CLR_content));

    if (nk_begin(ctx, "Content", nk_rect(sidebar_width(width), 50,
                                         content_width(width), height),
                 0)) {
    }

    nk_style_pop_style_item(ctx);
    nk_end(ctx);
}
