#ifndef UI_CURSOR_H
#define UI_CURSOR_H

#include <GLFW/glfw3.h>

void fii_cursor_hand(GLFWwindow *win);
void fii_cursor_arrow(GLFWwindow *win);
void fii_cursor_move(GLFWwindow *win);

int fii_cursor_current();
void fii_cursor_set(GLFWwindow *win, int cur);

#endif
