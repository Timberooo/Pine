#include "color.h"

#include "color/color4bit.h"
#include "color/color8bit.h"
#include "color/color24bit.h"
#include "math.h"

#include <array>
#include <cmath>
#include <cstddef>

namespace
{
    float colorDistance(const ::Pine::Color24Bit& color1, const ::Pine::Color24Bit& color2);

    template <typename T, std::size_t S>
    T quantize(const std::array<::Pine::Color24Bit, S>& palette, const ::Pine::Color24Bit& color);



    float colorDistance(const ::Pine::Color24Bit& color1, const ::Pine::Color24Bit& color2)
    {
        int rDif = static_cast<int>(color1.r) - static_cast<int>(color2.r);
        int gDif = static_cast<int>(color1.g) - static_cast<int>(color2.g);
        int bDif = static_cast<int>(color1.b) - static_cast<int>(color2.b);
        return std::sqrt(static_cast<float>(::Pine::square(rDif) + ::Pine::square(gDif) + ::Pine::square(bDif)));
    }



    template <typename T, std::size_t S>
    T quantize(const std::array<::Pine::Color24Bit, S>& palette, const ::Pine::Color24Bit& color)
    {
        std::size_t closestIndex    = 0;
        float       closestDistance = colorDistance(color, palette.at(0));

        // Starting at 1 since closestIndex and closestDistance are initialzied to the values at 0
        for (std::size_t i = 1; i < palette.size(); i++)
        {
            float distance = colorDistance(color, palette.at(i));

            // Update closest
            if (distance < closestDistance)
            {
                closestDistance = distance;
                closestIndex = i;
            }
        }

        return static_cast<T>(closestIndex);
    }
}

namespace Pine
{
    Color4Bit quantizeToColor4Bit(const std::array<Color24Bit, 16>& palette, const Color24Bit& color)
    {
        return quantize<Color4Bit>(palette, color);
    }



    Color8Bit quantizeToColor8Bit(const Color24Bit& color)
    {
        // TODO: Implement function.
        return 0;
    }
}