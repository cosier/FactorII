#ifndef FII_NUKES_H
#define FII_NUKES_H

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <string.h>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#include "nuklear.h"

enum nk_glfw_init_state { NK_GLFW3_DEFAULT = 0, NK_GLFW3_INSTALL_CALLBACKS };
NK_API struct nk_context* nk_glfw3_init(GLFWwindow* win,
                                        enum nk_glfw_init_state);
NK_API void nk_glfw3_font_stash_begin(struct nk_font_atlas** atlas);
NK_API void nk_glfw3_font_stash_end(void);

NK_API void nk_glfw3_new_frame(void);
NK_API void nk_glfw3_render(enum nk_anti_aliasing);
NK_API void nk_glfw3_shutdown(void);

NK_API void nk_glfw3_char_callback(GLFWwindow* win, unsigned int codepoint);
NK_API void nk_gflw3_scroll_callback(GLFWwindow* win, double xoff, double yoff);

#endif
