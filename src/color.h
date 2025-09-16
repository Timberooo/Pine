/* * * * * * * * * * * * * * * * * * NOTES * * * * * * * * * * * * * * * * * *\
 * - The lookup table for 4 bit colors will need to support custom color     *
 *   palettes since each console has a unique palette. Make sure to add      *
 *   palette presets for known palettes and an option for a custom palette   *
 *   for any that're missed/not covered.                                     *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef PINE_COLOR_H
#define PINE_COLOR_H

#include "color/color4bit.h"
#include "color/color8bit.h"
#include "color/color24bit.h"

#include <array>

namespace Pine
{
    Color4Bit quantizeToColor4Bit(const std::array<Color24Bit, 16>& palette, const Color24Bit& color);

    Color8Bit quantizeToColor8Bit(const Color24Bit& color);
}

#endif // PINE_COLOR_H