#include <factorii/ui/header.h>

void fii_header(GLFWwindow *win, struct nk_context *ctx, int width) {
    struct nk_color transparent = nk_rgba(255, 255, 255, 0);
    struct nk_color black = nk_rgb(0, 0, 0);
    struct nk_color red = nk_rgb(255, 0, 0);
    struct nk_input *in = &ctx->input;
    int header_height = 50;

    nk_style_push_style_item(ctx, &ctx->style.window.fixed_background,
                             nk_style_item_color(transparent));

    nk_style_push_style_item(ctx, &ctx->style.button.normal,
                             nk_style_item_color(transparent));

    nk_style_push_style_item(ctx, &ctx->style.button.hover,
                             nk_style_item_color(transparent));

    nk_style_push_style_item(ctx, &ctx->style.button.active,
                             nk_style_item_color(transparent));

    nk_style_push_color(ctx, &ctx->style.button.text_background, transparent);
    nk_style_push_color(ctx, &ctx->style.button.text_active, red);
    nk_style_push_color(ctx, &ctx->style.button.text_normal, black);
    nk_style_push_color(ctx, &ctx->style.button.text_hover, red);
    nk_style_push_float(ctx, &ctx->style.button.border, 0);

    struct nk_vec2 zero_padding = nk_vec2(0, 0);
    nk_style_push_vec2(ctx, &ctx->style.window.padding, zero_padding);

    int flags = NK_WINDOW_NO_SCROLLBAR;
    if (nk_begin(ctx, "AppHeader", nk_rect(0, 0, width, header_height),
                 flags)) {

        int mouse_down = in && in->mouse.buttons[NK_BUTTON_LEFT].down;
        int mouse_inside = mouse_down && nk_input_has_mouse_click_down_in_rect(
                                             in, NK_BUTTON_LEFT,
                                             ctx->current->bounds, nk_true);

        if (mouse_down && mouse_inside) {
            drag_start(win);
        } else {
            drag_stop();
        }

        int sb_width = sidebar_width(width);

        struct nk_command_buffer *canvas = nk_window_get_canvas(ctx);

        // nk_layout_row_static(ctx, header_height, width, 1);
        nk_layout_space_begin(ctx, NK_STATIC, header_height, INT_MAX);
        // nk_layout_space_push(
        //     ctx, nk_rect(sb_width, 0, width - sb_width, header_height));
        struct nk_rect bgrect =
            nk_rect(sb_width, 0, width - sb_width + 100, header_height);
        nk_fill_rect(canvas, bgrect, 0, nk_rgb(220, 220, 220));

        nk_layout_space_push(ctx, nk_rect(width - 30, 5, 20, 20));

        if (nk_button_label(ctx, "X")) {
            fii_quit();
        }
    }

    // nk_window_set_focus(ctx, "AppHeader");

    nk_style_pop_style_item(ctx);
    nk_style_pop_style_item(ctx);
    nk_style_pop_style_item(ctx);
    nk_style_pop_style_item(ctx);
    nk_style_pop_color(ctx);
    nk_style_pop_color(ctx);
    nk_style_pop_color(ctx);
    nk_style_pop_color(ctx);
    nk_style_pop_float(ctx);
    nk_style_pop_vec2(ctx);
    nk_end(ctx);
}
