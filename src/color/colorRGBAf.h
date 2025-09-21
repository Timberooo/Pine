#ifndef PINE_COLOR_COLORRGBAF_H
#define PINE_COLOR_COLORRGBAF_H

#include "colorRGBf.h"

namespace Pine
{
    struct ColorRGBAf;



    struct ColorRGBAf : public ColorRGBf
    {
        union {
            float a;
            float alpha;
        };


        inline ColorRGBAf();
        inline ColorRGBAf(float r, float g, float b, float a);
    };



    inline ColorRGBAf::ColorRGBAf() : ColorRGBAf(0.0f, 0.0f, 0.0f, 0.0f) {}

    inline ColorRGBAf::ColorRGBAf(float r, float g, float b, float a) : ColorRGBf(r, g, b), a(a) {}
}

#endif // PINE_COLOR_COLORRGBAF_H