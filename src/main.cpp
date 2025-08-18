#include "io/terminal.h"

#include <string>



void printVectorData(std::string name, Pine::Vector2D v);
void printVectorData(std::string name, Pine::Vector3D v);



int main()
{
    Pine::Terminal::setBufferSize(1024);

    Pine::Vector3D a;
    a.x = 1;
    a.y = 2;
    a.z = 3;
    printVectorData("a", a);
    
    Pine::Vector3D b;
    b.x = 4;
    b.y = 5;
    b.z = 6;
    printVectorData("b", b);

    Pine::Vector3D abCross = Pine::cross(a, b);
    printVectorData("a x b", abCross);
    printVectorData("norm(a x b)", Pine::normalize(abCross));

    // Pine::Vector2D v;
    // v.x = 1;
    // v.y = 1;
    // printVectorData("v", v);

    // Pine::Vector2D u;
    // u.x = 0;
    // u.y = -2;
    // printVectorData("u", u);

    // Pine::Vector2D w = v + u;
    // printVectorData("w = v + u", w);

    // w *= -5;
    // printVectorData("w * -5", w);

    // w = Pine::normalize(w);
    // printVectorData("w norm", w);

    Pine::Terminal::flush();

    return 0;
}



void printVectorData(std::string name, Pine::Vector2D v)
{
    Pine::Terminal::writeLine(name + " values: (" + std::to_string(v.x) + ", " + std::to_string(v.y) + ") length: " + std::to_string(v.length()));
}

void printVectorData(std::string name, Pine::Vector3D v)
{
    Pine::Terminal::writeLine(name + " values: (" + std::to_string(v.x) + ", " + std::to_string(v.y) + ", " + std::to_string(v.z) + ") length: " + std::to_string(v.length()));
}