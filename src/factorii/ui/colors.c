#include <factorii/ui/colors.h>

void fii_colors_init() {
    // initialize global colors
    CLR_sidebar = nk_rgb(255, 255, 255);
    CLR_content = nk_rgb(220, 220, 220);

    CLR_h1 = nk_rgb(0, 0, 0);
    CLR_tx = nk_rgba(0, 0, 0, 0);

    CLR_white = nk_rgb(255, 255, 255);
    CLR_black = nk_rgb(0, 0, 0);

    CLR_primary = nk_rgb(0, 0, 0);
    CLR_secondary = nk_rgb(0, 0, 0);
}
