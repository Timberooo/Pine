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

    Pine::Matrix3x3 a({2, 3, 5}, {5, 1, 11}, {5, 15, 0});
    Pine::Matrix3x3 b({4, 6, -6}, {8, 7, 4}, {0, 2, -1});

    Pine::Vec3 v(5, 3, 8);
    Pine::Vector3D u;

    u = a * b * v;
    Pine::Terminal::writeLine("a * b * v = " + std::to_string(u.x) + ' ' + std::to_string(u.y) + ' ' + std::to_string(u.z));
    u = b * a * v;
    Pine::Terminal::writeLine("b * a * v = " + std::to_string(u.x) + ' ' + std::to_string(u.y) + ' ' + std::to_string(u.z));

    Pine::Terminal::flush();

    return 0;
}