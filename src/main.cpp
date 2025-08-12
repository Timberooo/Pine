#include <string>

#include "io/terminal.h"



int main()
{
    Pine::Terminal::setBufferSize(1024);
    Pine::Terminal::writeLine("test");

    return 0;
}