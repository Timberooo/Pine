#ifndef PINE_COLOR_COLORRGBA_H
#define PINE_COLOR_COLORRGBA_H

#include "colorRGB.h"
#include "../core.h"

namespace Pine
{
    struct ColorRGBA;



    struct ColorRGBA : public ColorRGB
    {
        union {
            Byte a;
            Byte alpha;
        };


        inline ColorRGBA();
        inline ColorRGBA(Byte r, Byte g, Byte b, Byte a);
    };



    inline ColorRGBA::ColorRGBA() : ColorRGBA(0, 0, 0, 0) {}

    inline ColorRGBA::ColorRGBA(Byte r, Byte g, Byte b, Byte a) : ColorRGB(r, g, b), a(a) {}
}

#endif // PINE_COLOR_COLORRGBA_H