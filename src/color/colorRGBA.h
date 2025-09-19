#ifndef PINE_COLOR_COLORRGBA_H
#define PINE_COLOR_COLORRGBA_H

#include "../core.h"

namespace Pine
{
    struct ColorRGBA;



    struct ColorRGBA
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

        union {
            Byte a;
            Byte alpha;
        };


        inline ColorRGBA();
        inline ColorRGBA(Byte r, Byte g, Byte b, Byte a);
    };



    inline ColorRGBA::ColorRGBA() : ColorRGBA(0, 0, 0, 0) {}

    inline ColorRGBA::ColorRGBA(Byte r, Byte g, Byte b, Byte a) : r(r), g(g), b(b), a(a) {}
}

#endif // PINE_COLOR_COLORRGBA_H