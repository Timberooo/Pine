#ifndef PINE_COLOR_COLORRGBF_H
#define PINE_COLOR_COLORRGBF_H

namespace Pine
{
    struct ColorRGBf;



    struct ColorRGBf
    {
        union {
            float r;
            float red;
        };

        union {
            float g;
            float green;
        };

        union {
            float b;
            float blue;
        };


        inline ColorRGBf();
        inline ColorRGBf(float r, float g, float b);
    };



    inline ColorRGBf::ColorRGBf() : ColorRGBf(0.0f, 0.0f, 0.0f) {}

    inline ColorRGBf::ColorRGBf(float r, float g, float b) : r(r), g(g), b(b) {}
}

#endif // PINE_COLOR_COLORRGBF_H