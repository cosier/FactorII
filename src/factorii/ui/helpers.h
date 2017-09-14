#ifndef UI_HELPERS_H
#define UI_HELPERS_H

#include <GLFW/glfw3.h>
#include <assert.h>
#include <limits.h>
#include <ubelt/utils.h>

void error_callback(int e, const char *d);

void drag_start(GLFWwindow *win);
void drag_stop();
void drag_apply(GLFWwindow *win);
int is_dragging();

int sidebar_width(int win_width);
int content_width(int win_width);

#endif
