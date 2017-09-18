#ifndef UI_FONTS_H
#define UI_FONTS_H
#ifdef WINDOWS_OS
#include <Windows.h>
#endif
#include <factorii/ui/nuk.h>
#include <stdio.h>
#include <ubelt/utils.h>

//#include <ft2build.h>
//#include <freetype/freetype.h>
//#include <freetype/ftglyph.h>
//#include <freetype/ftoutln.h>
//#include <freetype/fttrigon.h>

#include <factorii/build.h>

void fii_fonts_load(struct nk_context *ctx);
struct nk_user_font fii_font(struct nk_context *ctx, float size);
#endif
