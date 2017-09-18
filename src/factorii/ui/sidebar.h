#ifndef UI_SIDEBAR_H
#define UI_SIDEBAR_H

#include <factorii/gfx/gl.h>
#include <factorii/ui/colors.h>
#include <factorii/ui/helpers.h>
#include <factorii/ui/nuk.h>
#include <deps/linmath.h>

void fii_sidebar(GLFWwindow *win, struct nk_context *ctx, float win_width,
                 float win_height);

#endif
