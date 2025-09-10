#ifndef PINE_COLOR_COLOR24BIT_H
#define PINE_COLOR_COLOR24BIT_H

namespace Pine
{
    struct Color24Bit;



    struct Color24Bit
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
    };
}

#endif // PINE_COLOR_COLOR24BIT_H