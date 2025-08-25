#include "io/terminal.h"
#include "math.h"
#include "callback.h"

#include <string>



int testFunc()
{
    return 0;
}



int main()
{
    Pine::Terminal::setBufferSize(1024);
    
    Pine::Point2D<int> p1(3, 2);
    Pine::Point2D<int> p2(1, 5);

    Pine::Vector2D v = p2 - p1;

    Pine::Terminal::writeLine("distance: " + std::to_string(Pine::distance(p1, p2)));
    Pine::Terminal::writeLine("v length: " + std::to_string(v.length()));

    Pine::Callback<int (*)()> callback = testFunc;
    Pine::Callback<int (*)()> c = testFunc;

    Pine::Terminal::writeLine(std::to_string(callback.tryCall(p1.x)));

    Pine::Terminal::flush();

    return 0;
}