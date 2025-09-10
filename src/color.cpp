#include "color.h"

#include "math.h"

#include "io/terminal.h"

#include <string>

#include <cmath>
#include <cstddef>

namespace Pine
{
    constexpr Color24Bit lookupTable[16] = { Color24Bit{0, 0, 0},      // Black
                                                Color24Bit{205, 0, 0},    // Red
                                                Color24Bit{0, 205, 0},    // green
                                                Color24Bit{205, 205, 0},  // Yellow
                                                Color24Bit{0, 0, 238},    // Blue
                                                Color24Bit{205, 0, 205},  // Magenta
                                                Color24Bit{0, 205, 205},  // Cyan
                                                Color24Bit{229, 229, 229}, // White
                                                Color24Bit{127, 127, 127}, // Gray
                                                Color24Bit{255, 0, 0}, // Bright Red
                                                Color24Bit{0, 255, 0}, // Bright Green
                                                Color24Bit{255, 255, 0}, // Bright yellow
                                                Color24Bit{92, 92, 255}, // bright blue
                                                Color24Bit{255, 0, 255}, // bright magenta
                                                Color24Bit{0, 255, 255}, // bright cyan
                                                Color24Bit{255, 255, 255} // bright white
                                                };



    Color4Bit quantize(const Color24Bit& color)
    {
        float closestDistance = -1.0f;
        std::size_t closestIndex = 0;

        for (std::size_t i = 0; i < 16; i++)
        {
            float distance = std::sqrt((float)(square((int)lookupTable[i].r - (int)color.r) + square((int)lookupTable[i].g - (int)color.g) + square((int)lookupTable[i].b - (int)color.b)));
            // Terminal::writeLine("distance: " + std::to_string(distance));

            if (closestDistance == -1.0f)
                closestDistance = distance;

            if (distance < closestDistance)
            {
                closestDistance = distance;
                closestIndex = i;
            }
        }

        int offset = closestIndex < 8 ? 30 : (90 - 8);

        return (Color4Bit)(closestIndex + offset);
    }
}