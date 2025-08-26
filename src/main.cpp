#include "io/terminal.h"
// #include "math.h"
// #include "callback.h"

#include "math/point.h"

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

    Pine::Terminal::writeLine(std::to_string(test()));
    
    Pine::Point2D<float> p1(0, 0);
    Pine::Point2D<int> p2(1, 1);

    Pine::Terminal::write("Enter p1's x value: ");
    p1.x = std::stoi(Pine::Terminal::readLine());
    Pine::Terminal::write("Enter p1's y value: ");
    p1.y = std::stoi(Pine::Terminal::readLine());
    Pine::Terminal::write("Enter p2's x value: ");
    p2.x = std::stoi(Pine::Terminal::readLine());
    Pine::Terminal::write("Enter p2's y value: ");
    p2.y = std::stoi(Pine::Terminal::readLine());

    Pine::Terminal::writeLine("distance: " + std::to_string(Pine::distance(Pine::Point2D<int>(p1), p2)));

    Pine::Terminal::flush();

    return 0;
}