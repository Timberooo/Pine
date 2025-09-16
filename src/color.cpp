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



    float colorDistance(const ::Pine::Color24Bit& color1, const ::Pine::Color24Bit& color2)
    {
        int rDif = static_cast<int>(color1.r) - static_cast<int>(color2.r);
        int gDif = static_cast<int>(color1.g) - static_cast<int>(color2.g);
        int bDif = static_cast<int>(color1.b) - static_cast<int>(color2.b);
        return std::sqrt(static_cast<float>(::Pine::square(rDif) + ::Pine::square(gDif) + ::Pine::square(bDif)));
    }
}

namespace Pine
{
    Color4Bit quantizeToColor4Bit(const std::array<Color24Bit, 16>& palette, const Color24Bit& color)
    {
        unsigned char closestIndex    = 0;
        float         closestDistance = colorDistance(color, palette.at(0));

        // Starting at 1 since closestIndex and closestDistance are initialzied to the values at 0
        for (unsigned char i = 1; i < 16; i++)
        {
            float distance = colorDistance(color, palette.at(i));

            if (distance < closestDistance)
            {
                closestDistance = distance;
                closestIndex = i;
            }
        }

        return static_cast<Color4Bit>(closestIndex);
    }



    Color8Bit quantizeToColor8Bit(const Color24Bit& color)
    {
        // TODO: Implement function.
        return 0;
    }
}