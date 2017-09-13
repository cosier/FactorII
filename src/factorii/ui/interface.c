#include "factorii/ui/interface.h"
static double cursor_pos_x = 0;
static double cursor_pos_y = 0;
static int window_drag_active = 0;
static GLFWwindow *win;

static void error_callback(int e, const char *d) {
    printf("Error %d: %s\n", e, d);
}

static int get_sidebar_width(int width) {
    int w = width < 200 ? width : 200;
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
                 nk_rect(0, 0, get_sidebar_width(width), height), 0)) {
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

    if (nk_begin(ctx, "Content", nk_rect(get_sidebar_width(width), 0,
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
    window_drag_active = 0;
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
    int header_height = 40;
    int ow = 34;

    struct nk_color off_white = nk_rgba(ow, ow, ow, 0);
    struct nk_input *in = &ctx->input;

    nk_style_push_style_item(ctx, &ctx->style.window.fixed_background,
                             nk_style_item_color(off_white));

    nk_window_show(ctx, "AppHeader", NK_SHOWN);

    if (nk_begin(ctx, "AppHeader", nk_rect(0, 0, width, header_height), 0)) {
        int left_mouse_down = in && in->mouse.buttons[NK_BUTTON_LEFT].down;
        int left_mouse_click_in_cursor =
            left_mouse_down &&
            nk_input_has_mouse_click_down_in_rect(
                in, NK_BUTTON_LEFT, ctx->current->bounds, nk_true);

        if (left_mouse_down && left_mouse_click_in_cursor) {
            drag_start();
        } else {
            if (window_drag_active == 1) {
                drag_stop();
            }
        }
    }

    nk_window_set_focus(ctx, "AppHeader");
    nk_style_pop_style_item(ctx);
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

    glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
    win = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Factorii", NULL, NULL);

    glfwMakeContextCurrent(win);
    glfwGetWindowSize(win, &width, &height);

    // Place on secondary monitor for development purposes.
    // glfwSetWindowPos(win, 2700, 100);

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
    }

    nk_glfw3_shutdown();
    glfwTerminate();
}
