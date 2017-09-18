#include "factorii/ui/interface.h"

static int QUIT = 0;

void fii_quit() { QUIT = 1; }

static void fii_init(struct nk_context **pp_ctx, GLFWwindow **pp_win) {
    struct nk_context *ctx;
    GLFWwindow *win;

    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        fprintf(stdout, "[GFLW] failed to init!\n");
        exit(1);
    }

    glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
    glfwWindowHint(GLFW_TRANSPARENT, GLFW_TRUE);
    // glTexParameteri(GL_NEAREST);

    win = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Factorii", NULL, NULL);
    glfwMakeContextCurrent(win);

    // Place on secondary monitor for development purposes.
    /* glfwSetWindowPos(win, 2700, 100); */

    /* GUI */
    ctx = nk_glfw3_init(win, NK_GLFW3_INSTALL_CALLBACKS);

    *pp_ctx = ctx;
    *pp_win = win;
}

void fii_interface(fii_options *opts) {
    if (opts != NULL) {
    }

    struct nk_context *ctx = NULL;
    GLFWwindow *win = NULL;

    int w = 0, h = 0;

    fii_init(&ctx, &win);

    assert(ctx && ctx != NULL && ctx != 0);
    assert(win && win != NULL && win != 0);

    fii_fonts_load(ctx);
    fii_colors_init();
    drag_start(win);

    glfwGetWindowSize(win, &w, &h);
    float width = (float)w, height = (float)h;

    glfwSetWindowSizeLimits(win, WINDOW_WIDTH, WINDOW_HEIGHT, 900, 800);

    /* struct nk_user_font font = fii_font(ctx, 20); */
    /* nk_style_set_font(ctx, &font); */
    
    while (!glfwWindowShouldClose(win)) {
        /* Input */
        glfwWaitEvents();

        nk_glfw3_new_frame();
        glfwGetWindowSize(win, &w, &h);
        width = (float)w;
        height = (float)h;

        fii_sidebar(win, ctx, width, height);
        fii_content(win, ctx, width, height);
        fii_header(win, ctx, width);

        // drag_apply(win);

        /* Draw */
        {
            glViewport(0, 0, (GLsizei)width, (GLsizei)height);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(0, 0, 0, 0.5);

            nk_glfw3_render(NK_ANTI_ALIASING_ON);
            glfwSwapBuffers(win);
            // glSwapAPPLE();
        }

        if (QUIT) {
            break;
        }
    }

    nk_glfw3_shutdown();
    glfwTerminate();
}
