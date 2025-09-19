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

        union {
            float a;
            float alpha;
        };


        inline ColorRGBf();
        inline ColorRGBf(float r, float g, float b, float a);
    };



    inline ColorRGBf::ColorRGBf() : ColorRGBf(0.0f, 0.0f, 0.0f, 0.0f) {}

    inline ColorRGBf::ColorRGBf(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
}

#endif // PINE_COLOR_COLORRGBF_H