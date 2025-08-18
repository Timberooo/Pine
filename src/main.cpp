#include "io/terminal.h"

#include <string>



void printVectorData(std::string name, Pine::Vector2D v);



int main()
{
    Pine::Terminal::setBufferSize(1024);

    Pine::Vector2D v;
    v.x = 1;
    v.y = 1;
    printVectorData("v", v);

    Pine::Vector2D u;
    u.x = 0;
    u.y = -2;
    printVectorData("u", u);

    Pine::Vector2D w = v + u;
    printVectorData("w = v + u", w);

    w *= -5;
    printVectorData("w * -5", w);

    w = Pine::normalize(w);
    printVectorData("w norm", w);

    Pine::Terminal::flush();

    return 0;
}



void printVectorData(std::string name, Pine::Vector2D v)
{
    Pine::Terminal::writeLine(name + " values: (" + std::to_string(v.x) + ", " + std::to_string(v.y) + ") length: " + std::to_string(v.length()));
}