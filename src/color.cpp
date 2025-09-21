#include "color.h"

#include "color/color4.h"
#include "color/color8.h"
#include "color/colorRGB.h"
#include "math.h"

#include <array>
#include <cstddef>

namespace
{
    template <std::size_t S>
    std::size_t closestIndex(const std::array<Pine::ColorRGB, S>& palette, const ::Pine::ColorRGB& color);

    int colorDistanceSquared(const ::Pine::ColorRGB& color1, const ::Pine::ColorRGB& color2);



    template <std::size_t S>
    std::size_t closestIndex(const std::array<Pine::ColorRGB, S>& palette, const ::Pine::ColorRGB& color)
    {
        std::size_t closest = 0;
        int closestDistanceSquared = colorDistanceSquared(color, palette.at(0));

        // Starting at index 1 since the closest values are already initialized to index 0
        for (std::size_t i = 1; i < palette.size(); i++)
        {
            float distanceSquared = colorDistanceSquared(color, palette.at(i));

            if (distanceSquared < closestDistanceSquared)
            {
                closestDistanceSquared = distanceSquared;
                closest = i;
            }
        }

        return closest;
    }



    int colorDistanceSquared(const ::Pine::ColorRGB& color1, const ::Pine::ColorRGB& color2)
    {
        int rDif = static_cast<int>(color1.r) - static_cast<int>(color2.r);
        int gDif = static_cast<int>(color1.g) - static_cast<int>(color2.g);
        int bDif = static_cast<int>(color1.b) - static_cast<int>(color2.b);
        return ::Pine::square(rDif) + ::Pine::square(gDif) + ::Pine::square(bDif);
    }
}



namespace Pine
{
    Color4 quantizeToColor4(const Color4Palette& palette, const ColorRGB& color)
    {
        return static_cast<Color4>(closestIndex(palette, color));
    }

    Color8 quantizeToColor8(const Color8Palette& palette, const ColorRGB& color)
    {
        return static_cast<Color8>(closestIndex(palette, color));
    }
}