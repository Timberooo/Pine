#ifndef PINE_COLOR_COLORRGBAF_H
#define PINE_COLOR_COLORRGBAF_H

namespace Pine
{
    struct ColorRGBAf;



    struct ColorRGBAf
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


        inline ColorRGBAf();
        inline ColorRGBAf(float r, float g, float b, float a);
    };



    inline ColorRGBAf::ColorRGBAf() : ColorRGBAf(0.0f, 0.0f, 0.0f, 0.0f) {}

    inline ColorRGBAf::ColorRGBAf(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
}

#endif // PINE_COLOR_COLORRGBAF_H