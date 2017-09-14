#include <factorii/ui/cursor.h>

#define FII_CURSOR_ARROW 0
#define FII_CURSOR_HAND 1
#define FII_CURSOR_MOVE 2

static int current_cursor = 0;

void fii_cursor_hand(GLFWwindow *win) {
    if (current_cursor != FII_CURSOR_HAND) {
        GLFWcursor *cursor = glfwCreateStandardCursor(GLFW_HAND_CURSOR);
        glfwSetCursor(win, cursor);
        current_cursor = FII_CURSOR_HAND;
    }
}

void fii_cursor_arrow(GLFWwindow *win) {
    if (current_cursor != FII_CURSOR_ARROW) {
        GLFWcursor *cursor = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
        glfwSetCursor(win, cursor);
        current_cursor = FII_CURSOR_ARROW;
    }
}

void fii_cursor_move(GLFWwindow *win) {
    if (current_cursor != FII_CURSOR_MOVE) {
        GLFWcursor *cursor = glfwCreateStandardCursor(GLFW_HAND_CURSOR);
        glfwSetCursor(win, cursor);
        current_cursor = FII_CURSOR_MOVE;
    }
}

int fii_cursor_current() { return current_cursor; }

void fii_cursor_set(GLFWwindow *win, int cur) {
    if (current_cursor != cur) {
        int cc = current_cursor;
        if (cc == FII_CURSOR_MOVE) {
            fii_cursor_move(win);
        } else if (cc == FII_CURSOR_ARROW) {
            fii_cursor_arrow(win);
        } else if (cc == FII_CURSOR_HAND) {
            fii_cursor_hand(win);
        } else {
            return;
        }
    }
}
