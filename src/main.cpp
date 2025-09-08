#include "io/terminal.h"
#include "math.h"

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
    
    Pine::Matrix2x2 a({2, 3}, {5, 1});
    Pine::Matrix2x2 b({4, 6}, {8, 7});
    Pine::Vector2D  v(5, 3);

    // a = Pine::Matrix2x2::identity();
    // a = Pine::Matrix2x2::zero();

    a *= b;

    Pine::Terminal::writeLine(std::to_string(a.col1.x) + ' ' + std::to_string(a.col2.x));
    Pine::Terminal::writeLine(std::to_string(a.col1.y) + ' ' + std::to_string(a.col2.y));

    Pine::Terminal::flush();

    return 0;
}