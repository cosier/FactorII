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

    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
    win = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Factorii", NULL, NULL);

    glfwMakeContextCurrent(win);

    // Place on secondary monitor for development purposes.
    glfwSetWindowPos(win, 2700, 100);

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

    int width = 0, height = 0;

    fii_init(&ctx, &win);

    assert(ctx && ctx != NULL && ctx != 0);
    assert(win && win != NULL && win != 0);

    fii_fonts_load(ctx);
    fii_colors_init();
    drag_start(win);

    glfwGetWindowSize(win, &width, &height);

    while (!glfwWindowShouldClose(win)) {
        /* Input */
        glfwWaitEvents();

        nk_glfw3_new_frame();
        glfwGetWindowSize(win, &width, &height);

        fii_sidebar(win, ctx, width, height);
        fii_content(win, ctx, width, height);
        fii_header(win, ctx, width);

        drag_apply(win);

        /* Draw */
        {
            float bg[4];
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
