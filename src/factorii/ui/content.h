#ifndef UI_CONTENT_H
#define UI_CONTENT_H

#include <GLFW/glfw3.h>
#include <factorii/ui/helpers.h>
#include <factorii/ui/nukes.h>

void fii_content(GLFWwindow *win, struct nk_context *ctx, int width,
                 int height);

#endif
