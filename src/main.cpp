#include "io/terminal.h"

#include <string>



void printVectorData(std::string name, Pine::Vector2D v);
void printVectorData(std::string name, Pine::Vector3D v);



int main()
{
    Pine::Terminal::setBufferSize(1024);

    Pine::Size2D<int> terminalSize = Pine::Terminal::size();
    const Pine::Array2D<Pine::Color8Bit> outputBuffer(terminalSize.width, terminalSize.height, 35);
    
    for (std::size_t y = 0; y < outputBuffer.size().height; y++)
    {
        for (std::size_t x = 0; x < outputBuffer.size().width; x++)
        {
            Pine::Terminal::setBackgroundColor(outputBuffer.at(x, y));
            Pine::Terminal::write(' ');
        }
    }

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