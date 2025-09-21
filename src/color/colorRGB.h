#ifndef PINE_COLOR_COLORRGB_H
#define PINE_COLOR_COLORRGB_H

#include "../core.h"

namespace Pine
{
    struct ColorRGB;



    struct ColorRGB
    {
        union {
            Byte r;
            Byte red;
        };

        union {
            Byte g;
            Byte green;
        };

        union {
            Byte b;
            Byte blue;
        };


        inline ColorRGB();
        inline ColorRGB(Byte r, Byte g, Byte b);
    };



    inline ColorRGB::ColorRGB() : ColorRGB(0, 0, 0) {}

    inline ColorRGB::ColorRGB(Byte r, Byte g, Byte b) : r(r), g(g), b(b) {}
}

#endif // PINE_COLOR_COLORRGB_H