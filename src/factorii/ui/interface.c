#include "factorii/ui/interface.h"
static double cursor_pos_x = 0;
static double cursor_pos_y = 0;
static int window_drag_active = 0;
static GLFWwindow *win;
static int QUIT = 0;

static void error_callback(int e, const char *d) {
    printf("Error %d: %s\n", e, d);
}

static int get_sidebar_width(int width) {
    int w = width < 200 ? width : 230;
    return w;
}

static int get_content_width(int width) {
    return width - get_sidebar_width(width);
}

void fii_sidebar(struct nk_context *ctx, int width, int height) {
    int ow = 255;
    struct nk_color white = nk_rgb(ow, ow, ow);

    // struct nk_command_buffer *out = NULL;

    nk_style_push_style_item(ctx, &ctx->style.window.fixed_background,
                             nk_style_item_color(white));

    if (nk_begin(ctx, "Sidebar",
                 nk_rect(0, 50, get_sidebar_width(width), height), 0)) {
    }

    nk_style_pop_style_item(ctx);
    nk_end(ctx);
}

void fii_content(struct nk_context *ctx, int width, int height) {
    int ow = 220;
    struct nk_color off_white = nk_rgb(ow, ow, ow);

    // struct nk_command_buffer *out = NULL;

    nk_style_push_style_item(ctx, &ctx->style.window.fixed_background,
                             nk_style_item_color(off_white));

    if (nk_begin(ctx, "Content", nk_rect(get_sidebar_width(width), 50,
                                         get_content_width(width), height),
                 0)) {
    }

    nk_style_pop_style_item(ctx);
    nk_end(ctx);
}

static inline void drag_start() {
    if (!window_drag_active) {
        // printf("draw_start!\n");
        window_drag_active = 1;

        double x, y;
        glfwGetCursorPos(win, &x, &y);
        cursor_pos_x = x;
        cursor_pos_y = y;
    }
}

static inline void drag_stop() {
    // no longer dragging!
    if (window_drag_active) {
        window_drag_active = 0;
    }
}

static inline void drag_apply(GLFWwindow *win) {
    if (window_drag_active) {
        double cx, cy, delta_x, delta_y;
        int x, y;
        glfwGetCursorPos(win, &cx, &cy);
        delta_x = cx - cursor_pos_x;
        delta_y = cy - cursor_pos_y;

        glfwGetWindowPos(win, &x, &y);
        glfwSetWindowPos(win, x + delta_x, y + delta_y);
    }
}

void fii_header(struct nk_context *ctx, int width) {
    struct nk_color transparent = nk_rgba(255, 255, 255, 0);
    struct nk_color black = nk_rgb(0, 0, 0);
    struct nk_color red = nk_rgb(255, 0, 0);
    struct nk_input *in = &ctx->input;
    int header_height = 50;

    nk_style_push_style_item(ctx, &ctx->style.window.fixed_background,
                             nk_style_item_color(transparent));

    nk_style_push_style_item(ctx, &ctx->style.button.normal,
                             nk_style_item_color(transparent));

    nk_style_push_style_item(ctx, &ctx->style.button.hover,
                             nk_style_item_color(transparent));

    nk_style_push_style_item(ctx, &ctx->style.button.active,
                             nk_style_item_color(transparent));

    nk_style_push_color(ctx, &ctx->style.button.text_background, transparent);
    nk_style_push_color(ctx, &ctx->style.button.text_active, red);
    nk_style_push_color(ctx, &ctx->style.button.text_normal, black);
    nk_style_push_color(ctx, &ctx->style.button.text_hover, red);
    nk_style_push_float(ctx, &ctx->style.button.border, 0);

    struct nk_vec2 zero_padding = nk_vec2(0, 0);
    nk_style_push_vec2(ctx, &ctx->style.window.padding, zero_padding);

    int flags = NK_WINDOW_NO_SCROLLBAR;
    if (nk_begin(ctx, "AppHeader", nk_rect(0, 0, width, header_height),
                 flags)) {

        int mouse_down = in && in->mouse.buttons[NK_BUTTON_LEFT].down;
        int mouse_inside = mouse_down && nk_input_has_mouse_click_down_in_rect(
                                             in, NK_BUTTON_LEFT,
                                             ctx->current->bounds, nk_true);

        if (mouse_down && mouse_inside) {
            drag_start();
        } else {
            drag_stop();
        }

        int sb_width = get_sidebar_width(width);

        struct nk_command_buffer *canvas = nk_window_get_canvas(ctx);

        // nk_layout_row_static(ctx, header_height, width, 1);
        nk_layout_space_begin(ctx, NK_STATIC, header_height, INT_MAX);
        // nk_layout_space_push(
        //     ctx, nk_rect(sb_width, 0, width - sb_width, header_height));
        struct nk_rect bgrect =
            nk_rect(sb_width, 0, width - sb_width + 100, header_height);
        nk_fill_rect(canvas, bgrect, 0, nk_rgb(220, 220, 220));

        nk_layout_space_push(ctx, nk_rect(width - 30, 5, 20, 20));

        if (nk_button_label(ctx, "X")) {
            QUIT = 1;
        }
    }

    // nk_window_set_focus(ctx, "AppHeader");

    nk_style_pop_style_item(ctx);
    nk_style_pop_style_item(ctx);
    nk_style_pop_style_item(ctx);
    nk_style_pop_style_item(ctx);
    nk_style_pop_color(ctx);
    nk_style_pop_color(ctx);
    nk_style_pop_color(ctx);
    nk_style_pop_color(ctx);
    nk_style_pop_float(ctx);
    nk_style_pop_vec2(ctx);
    nk_end(ctx);
}

void fii_interface(fii_options *opts) {
    if (opts != NULL) {
    }

    /* Platform */
    struct nk_color background;
    struct nk_context *ctx;
    int width = 0, height = 0;

    /* GLFW */
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        fprintf(stdout, "[GFLW] failed to init!\n");
        exit(1);
    }

    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
    win = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Factorii", NULL, NULL);

    glfwMakeContextCurrent(win);
    glfwGetWindowSize(win, &width, &height);

    // Place on secondary monitor for development purposes.
    glfwSetWindowPos(win, 2700, 100);

    /* GUI */
    ctx = nk_glfw3_init(win, NK_GLFW3_INSTALL_CALLBACKS);
    {
        struct nk_font_atlas *atlas;
        nk_glfw3_font_stash_begin(&atlas);
        nk_glfw3_font_stash_end();
    }

    drag_start();

    background = nk_rgb(255, 255, 255);
    while (!glfwWindowShouldClose(win)) {
        /* Input */
        glfwWaitEvents();

        nk_glfw3_new_frame();
        glfwGetWindowSize(win, &width, &height);

        fii_sidebar(ctx, width, height);
        fii_content(ctx, width, height);
        fii_header(ctx, width);

        drag_apply(win);

        /* Draw */
        {
            float bg[4];
            nk_color_fv(bg, background);
            glViewport(0, 0, width, height);
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(bg[0], bg[1], bg[2], bg[3]);

            nk_glfw3_render(NK_ANTI_ALIASING_ON);
            glfwSwapBuffers(win);
        }

        if (QUIT) {
            break;
        }
    }

    nk_glfw3_shutdown();
    glfwTerminate();
}
