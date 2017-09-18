#include <factorii/ui/sidebar.h>

static int sidebar_initialized = 0;

static void init() {
  if (sidebar_initialized) {
    return;
  }

  sidebar_initialized = 1;
}

void fii_sidebar(GLFWwindow *win, struct nk_context *ctx, float win_width,
                 float win_height) {
    init();

    //float ratio;
    float width, height;

    // struct nk_command_buffer *out = NULL;

    nk_style_push_style_item(ctx, &ctx->style.window.fixed_background,
                             nk_style_item_color(CLR_sidebar));
    struct nk_rect sidebar_rect = nk_rect(0.0, 50.0, sidebar_width(win_width), win_height);

    if (nk_begin(ctx, "Sidebar", sidebar_rect, 0)) {
      width = 200 || sidebar_rect.w;
      height = sidebar_rect.h;

    }

    nk_style_pop_style_item(ctx);
    nk_end(ctx);
}
