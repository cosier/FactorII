#ifndef UI_CONTENT_H
#define UI_CONTENT_H

#include <factorii/gfx/gl.h>
#include <factorii/ui/colors.h>
#include <factorii/ui/helpers.h>
#include <factorii/ui/nuk.h>

void fii_content(GLFWwindow *win, struct nk_context *ctx, float width,
                 float height);

#endif
