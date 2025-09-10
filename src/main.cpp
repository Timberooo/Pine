#include "io/terminal.h"
#include "math.h"

#include "color.h"

#include <string>



int testFunc()
{
    return 0;
}



constexpr float test()
{
    Pine::Point2D<float> p1(0.5, 0);
    Pine::Point2D<int> p2(1, 0);

    return Pine::distance(p1, Pine::Point2D<float>(p2));
}



int main()
{
    Pine::Terminal::setBufferSize(1024);

    Pine::Terminal::setBackgroundColor(Pine::Color4Bit::Black);
    Pine::Terminal::write(std::to_string((int)Pine::Color4Bit::Black));
    Pine::Terminal::setBackgroundColor(Pine::Color4Bit::Bright_Black);
    Pine::Terminal::write(std::to_string((int)Pine::Color4Bit::Bright_Black));
    Pine::Terminal::setBackgroundColor(Pine::Color4Bit::White);
    Pine::Terminal::setForegroundColor(Pine::Color4Bit::Black);
    Pine::Terminal::write(std::to_string((int)Pine::Color4Bit::White));
    Pine::Terminal::setBackgroundColor(Pine::Color4Bit::Bright_White);
    Pine::Terminal::writeLine(std::to_string((int)Pine::Color4Bit::Bright_White));

    Pine::Terminal::resetForegroundColor();

    for (std::size_t i = 0; i < 256; i++)
    {
        if (i % 32 == 0)
            Pine::Terminal::write('\n');

        Pine::Color4Bit color = Pine::quantize({(unsigned char)i, (unsigned char)i, (unsigned char)i});
        // Pine::Terminal::write(std::to_string((int)color));
        
        Pine::Terminal::setBackgroundColor(color);
        Pine::Terminal::write(' ');
    }

    Pine::Terminal::resetBackgroundColor();
    Pine::Terminal::write('\n');

    Pine::Terminal::flush();

    return 0;
}