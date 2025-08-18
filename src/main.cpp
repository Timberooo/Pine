#include "io/terminal.h"

#include <string>



int main()
{
    Pine::Terminal::setBufferSize(1024);

    std::string test = Pine::Terminal::readLine();
    Pine::Terminal::writeLine(test);



    // Pine::Terminal::setBufferSize(1024);
    // Pine::Terminal::writeLine("test");

    // for (std::size_t i = 0; i < 990000; i++)
    // {
    //     Pine::Terminal::setBackgroundColor((i % 256));
    //     Pine::Terminal::write(' ');
    //     Pine::Terminal::flush();
    // }

    // Pine::Terminal::resetBackgroundColor();

    // std::string test = Pine::Terminal::readLine();
    // Pine::Terminal::writeLine(test);
    // Pine::Terminal::write(Pine::Terminal::readLine());



    // while (Pine::Terminal::readChar() != 'q')
    // {
    //     Pine::Terminal::writeLine("hewwo");
    // }

    return 0;
}