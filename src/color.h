#ifndef PINE_COLOR_H
#define PINE_COLOR_H

#include "color/color4.h"
#include "color/color8.h"
#include "color/colorRGB.h"
#include "color/colorRGBf.h"
#include "color/colorRGBA.h"
#include "color/colorRGBAf.h"

#include <array>

namespace Pine
{
    typedef std::array<ColorRGB, 16>  Color4Palette;
    typedef std::array<ColorRGB, 256> Color8Palette;


    Color4 quantizeToColor4(const Color4Palette& palette, const ColorRGB& color);
    Color8 quantizeToColor8(const Color8Palette& palette, const ColorRGB& color);
}

#endif // PINE_COLOR_H