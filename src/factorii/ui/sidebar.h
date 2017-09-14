#ifndef UI_SIDEBAR_H
#define UI_SIDEBAR_H

#include <GLFW/glfw3.h>
#include <factorii/ui/helpers.h>
#include <factorii/ui/nuk.h>

void fii_sidebar(GLFWwindow *win, struct nk_context *ctx, int win_width,
                 int win_height);

#endif
