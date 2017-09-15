#ifndef UI_FONTS_H
#define UI_FONTS_H
#include <factorii/ui/nuk.h>
#include <stdio.h>
#include <ubelt/utils.h>

void fii_fonts_load(struct nk_context *ctx);
struct nk_user_font fii_font(struct nk_context *ctx, int size);
#endif
