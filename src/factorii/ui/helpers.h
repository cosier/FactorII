#ifndef UI_HELPERS_H
#define UI_HELPERS_H

#include <factorii/gfx/gl.h>
#include <ubelt/utils.h>
#include <assert.h>
#include <limits.h>

void error_callback(int e, const char *d);

void drag_start(GLFWwindow *win);
void drag_stop();
void drag_apply(GLFWwindow *win);
int is_dragging();

float sidebar_width(float win_width);
float content_width(float win_width);

#endif
