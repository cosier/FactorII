#include <factorii/ui/helpers.h>

static double cursor_pos_x = 0;
static double cursor_pos_y = 0;
static int window_drag_active = 0;

void error_callback(int e, const char *d) {
    // handle errors
    util_error("Error %d: %s\n", e, d);
}

void drag_start(GLFWwindow *win) {
    if (!window_drag_active) {
        window_drag_active = 1;

        double x, y;
        glfwGetCursorPos(win, &x, &y);
        cursor_pos_x = x;
        cursor_pos_y = y;
    }
}

void drag_stop() {
    // no longer dragging!
    if (window_drag_active) {
        window_drag_active = 0;
    }
}

void drag_apply(GLFWwindow *win) {
    if (window_drag_active) {
        double cx, cy, delta_x, delta_y;
        int x, y;
        glfwGetCursorPos(win, &cx, &cy);
        delta_x = cx - cursor_pos_x;
        delta_y = cy - cursor_pos_y;

        glfwGetWindowPos(win, &x, &y);
        glfwSetWindowPos(win, x + delta_x, y + delta_y);
    }
}

int sidebar_width(int win_width) {
    int w = win_width < 200 ? win_width : 230;
    return w;
}

int content_width(int win_width) {
    // content is the entire width minus the sidebar
    return win_width - sidebar_width(win_width);
}
