#ifndef FII_UI_INTERFACE_H
#define FII_UI_INTERFACE_H

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <GLFW/glfw3.h>
#include <factorii/options.h>
#include <factorii/ui/nuk.h>

// UI Components
#include <factorii/ui/colors.h>
#include <factorii/ui/content.h>
#include <factorii/ui/cursor.h>
#include <factorii/ui/fonts.h>
#include <factorii/ui/header.h>
#include <factorii/ui/helpers.h>
#include <factorii/ui/sidebar.h>

#define WINDOW_WIDTH 550
#define WINDOW_HEIGHT 500

#define UNUSED(a) (void)a
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define LEN(a) (sizeof(a) / sizeof(a)[0])

struct fii_context {
    GLFWwindow *win;
    struct nk_context *ctx;
};

void fii_interface(fii_options *opts);
void fii_quit();

#endif
