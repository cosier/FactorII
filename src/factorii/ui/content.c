#include <factorii/ui/content.h>

void fii_content(GLFWwindow *win, struct nk_context *ctx, float width,
                 float height) {
    if (!win) {
    }

    nk_style_push_style_item(ctx, &ctx->style.window.fixed_background,
                             nk_style_item_color(CLR_content));

    if (nk_begin(ctx, "Content", nk_rect((float)sidebar_width(width), (float)50,
                                         (float)content_width(width), (float)height),
                 0)) {
    }

    nk_style_pop_style_item(ctx);
    nk_end(ctx);
}
