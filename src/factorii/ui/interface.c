#include "factorii/ui/interface.h"

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

void fii_interface(fii_options *opts) {
    if (opts != NULL) {
    }

    /* Platform */
    struct nk_color background;
    static GLFWwindow *win;
    struct nk_context *ctx;
    int width = 0, height = 0;

    /* GLFW */
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        fprintf(stdout, "[GFLW] failed to init!\n");
        exit(1);
    }

    int monitors = 0;
    glfwGetMonitors(&monitors);

    win = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Factorii", monitors,
                           NULL);

    glfwMakeContextCurrent(win);
    glfwGetWindowSize(win, &width, &height);

    /* GUI */
    ctx = nk_glfw3_init(win, NK_GLFW3_INSTALL_CALLBACKS);
    /* Load Fonts: if none of these are loaded a default font will be used  */
    /* Load Cursor: if you uncomment cursor loading please hide the cursor */
    {
        struct nk_font_atlas *atlas;
        nk_glfw3_font_stash_begin(&atlas);
        /*struct nk_font *droid = nk_font_atlas_add_from_file(atlas,
         * "../../../extra_font/DroidSans.ttf", 14, 0);*/
        /*struct nk_font *roboto = nk_font_atlas_add_from_file(atlas,
         * "../../../extra_font/Roboto-Regular.ttf", 14, 0);*/
        /*struct nk_font *future = nk_font_atlas_add_from_file(atlas,
         * "../../../extra_font/kenvector_future_thin.ttf", 13, 0);*/
        /*struct nk_font *clean = nk_font_atlas_add_from_file(atlas,
         * "../../../extra_font/ProggyClean.ttf", 12, 0);*/
        /*struct nk_font *tiny = nk_font_atlas_add_from_file(atlas,
         * "../../../extra_font/ProggyTiny.ttf", 10, 0);*/
        /*struct nk_font *cousine = nk_font_atlas_add_from_file(atlas,
         * "../../../extra_font/Cousine-Regular.ttf", 13, 0);*/
        nk_glfw3_font_stash_end();
        /*nk_style_load_all_cursors(ctx, atlas->cursors);*/
        /*nk_style_set_font(ctx, &droid->handle);*/
    }

    /* style.c */
    /*set_style(ctx, THEME_WHITE);*/
    /*set_style(ctx, THEME_RED);*/
    /*set_style(ctx, THEME_BLUE);*/
    /*set_style(ctx, THEME_DARK);*/

    background = nk_rgb(28, 48, 62);
    while (!glfwWindowShouldClose(win)) {
        /* Input */
        glfwPollEvents();
        nk_glfw3_new_frame();
        glfwGetWindowSize(win, &width, &height);

        fii_sidebar(ctx, width, height);
        fii_content(ctx, width, height);

        /* -------------- EXAMPLES ---------------- */
        /*calculator(ctx);*/
        /*overview(ctx);*/
        /*node_editor(ctx);*/
        /* ----------------------------------------- */

        /* Draw */
        {
            float bg[4];
            nk_color_fv(bg, background);
            glViewport(0, 0, width, height);
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(bg[0], bg[1], bg[2], bg[3]);

            /* IMPORTANT: `nk_glfw_render` modifies some global OpenGL state
             * with blending, scissor, face culling and depth test and defaults
             * everything
             * back into a default state. Make sure to either save and restore
             * or
             * reset your own state after drawing rendering the UI. */
            nk_glfw3_render(NK_ANTI_ALIASING_ON);
            glfwSwapBuffers(win);
        }
    }

    nk_glfw3_shutdown();
    glfwTerminate();
}
