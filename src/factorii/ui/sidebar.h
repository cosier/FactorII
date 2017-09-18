#ifndef UI_SIDEBAR_H
#define UI_SIDEBAR_H

#define GL_GLEXT_PROTOTYPES 1
#define GL_PROTOTYPES 1
#include <GL/gl.h>

#include <GLFW/glfw3.h>
#include <factorii/ui/colors.h>
#include <factorii/ui/helpers.h>
#include <factorii/ui/nuk.h>
#include <deps/linmath.h>

void fii_sidebar(GLFWwindow *win, struct nk_context *ctx, int win_width,
                 int win_height);

#endif
