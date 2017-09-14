#ifndef UI_HEADER_H
#define UI_HEADER_H

#include <GLFW/glfw3.h>
#include <factorii/ui/cursor.h>
#include <factorii/ui/helpers.h>
#include <factorii/ui/interface.h>
#include <factorii/ui/nuk.h>

void fii_header(GLFWwindow *win, struct nk_context *ctx, int width);

#endif
