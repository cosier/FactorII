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
#include <factorii/ui/nukes.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 800

#define UNUSED(a) (void)a
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define LEN(a) (sizeof(a) / sizeof(a)[0])

void fii_interface();

#endif
