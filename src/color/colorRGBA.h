#ifndef PINE_COLOR_COLORRGBA_H
#define PINE_COLOR_COLORRGBA_H

#include "../core.h"

namespace Pine
{
    struct ColorRGBA;



    struct ColorRGBA
    {
        union {
            unsigned char r;
            unsigned char red;
        };

        union {
            unsigned char g;
            unsigned char green;
        };

        union {
            unsigned char b;
            unsigned char blue;
        };

        union {
            unsigned char a;
            unsigned char alpha;
        };


        inline ColorRGBA();
        inline ColorRGBA(Byte r, Byte g, Byte b, Byte a);
    };



    inline ColorRGBA::ColorRGBA() : ColorRGBA(0, 0, 0, 0) {}

    inline ColorRGBA::ColorRGBA(Byte r, Byte g, Byte b, Byte a) : r(r), g(g), b(b), a(a) {}
}

#endif // PINE_COLOR_COLORRGBA_H