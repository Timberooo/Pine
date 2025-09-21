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

    Pine::Terminal::setBackgroundColor(Pine::Color4::Black);
    Pine::Terminal::write(std::to_string((int)Pine::Color4::Black));
    Pine::Terminal::setBackgroundColor(Pine::Color4::Bright_Black);
    Pine::Terminal::write(std::to_string((int)Pine::Color4::Bright_Black));
    Pine::Terminal::setBackgroundColor(Pine::Color4::White);
    Pine::Terminal::setForegroundColor(Pine::Color4::Black);
    Pine::Terminal::write(std::to_string((int)Pine::Color4::White));
    Pine::Terminal::setBackgroundColor(Pine::Color4::Bright_White);
    Pine::Terminal::writeLine(std::to_string((int)Pine::Color4::Bright_White));

    Pine::Terminal::resetForegroundColor();

    std::array<Pine::ColorRGB, 16> lut;
    lut.at(0) =  {0,   0,   0};
    lut.at(1) =  {205, 0,   0};
    lut.at(2) =  {0,   205, 0};
    lut.at(3) =  {205, 205, 0};
    lut.at(4) =  {0,   0,   238};
    lut.at(5) =  {205, 0,   205};
    lut.at(6) =  {0,   205, 205};
    lut.at(7) =  {229, 229, 229};
    lut.at(8) =  {127, 127, 127};
    lut.at(9) =  {255, 0,   0};
    lut.at(10) = {0,   255, 0};
    lut.at(11) = {255, 255, 0};
    lut.at(12) = {92,  92,  255};
    lut.at(13) = {255, 0,   255};
    lut.at(14) = {0,   255, 255};
    lut.at(15) = {255, 255, 255};

    for (std::size_t i = 0; i < 256; i++)
    {
        if (i % 32 == 0)
            Pine::Terminal::write('\n');

        Pine::Color4 color = Pine::quantizeToColor4(lut, {(unsigned char)i, (unsigned char)i, (unsigned char)i});
        
        Pine::Terminal::setBackgroundColor(color);
        Pine::Terminal::write(' ');
    }

    Pine::Terminal::resetBackgroundColor();
    Pine::Terminal::write('\n');

    Pine::Terminal::flush();

    return 0;
}