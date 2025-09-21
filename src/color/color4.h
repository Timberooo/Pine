// 4-bit color format that supports 16 colors. While this format actually uses
// more than 4 bits its still potentially necessary and useful for terminals
// that only support 4-bit color modes.

#ifndef PINE_COLOR_COLOR4_H
#define PINE_COLOR_COLOR4_H

#include "../core.h"

namespace Pine
{
    enum class Color4 : Byte {
        Black          = 0,
        Red            = 1,
        Green          = 2,
        Yellow         = 3,
        Blue           = 4,
        Magenta        = 5,
        Cyan           = 6,
        White          = 7,
        Bright_Black   = 8,
        Bright_Red     = 9,
        Bright_Green   = 10,
        Bright_Yellow  = 11,
        Bright_Blue    = 12,
        Bright_Magenta = 13,
        Bright_Cyan    = 14,
        Bright_White   = 15
    };
}

#endif // PINE_COLOR_COLOR4_H