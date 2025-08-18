#include "terminal.h"

#include "../color.h"
#include "../core.h"
#include "../math.h"

#include <algorithm>
#include <cstddef>
#include <new>
#include <string>
#include <string_view>
#include <type_traits>

#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>



namespace
{
    struct TerminalData
    {
        std::string outputBufferStr  = std::string();
        std::size_t outputBufferSize = 0;

        bool altScreenBufferEnabled;

        const termios originalAttributes;


        TerminalData();

        ~TerminalData();

    private:

        static inline termios getCurrentAttributes();
    };



    TerminalData::TerminalData() : originalAttributes(getCurrentAttributes())
    {
        altScreenBufferEnabled = false;
    }



    TerminalData::~TerminalData()
    {
        Pine::Terminal::setBufferSize(0);
        
        Pine::Terminal::enableAltScreenBuffer(false);
        Pine::Terminal::resetColor();
        Pine::Terminal::showCursor(true);

        (void)tcsetattr(STDIN_FILENO, TCSAFLUSH, &originalAttributes);
    }



    inline termios TerminalData::getCurrentAttributes()
    {
        termios attributes;
        (void)tcgetattr(STDIN_FILENO, &attributes);
        return attributes;
    }



    static typename std::aligned_storage<sizeof(TerminalData), alignof(TerminalData)>::type g_terminalDataBuffer;

    TerminalData& g_terminalData = reinterpret_cast<TerminalData&>(g_terminalDataBuffer);
}



namespace Pine::Terminal
{
    std::size_t Init::s_counter = 0;



    Init::Init()
    {
        if (s_counter == 0)
            new(&g_terminalData)TerminalData();
        
        s_counter++;
    }



    Init::~Init()
    {
        s_counter--;

        if (s_counter == 0)
            g_terminalData.~TerminalData();
    }
}



namespace
{
    constexpr tcflag_t cookedModeInputFlags = IXON | // Ctrl-S and Ctrl-Q
                                              ICRNL; // Ctrl-M
    
    constexpr tcflag_t cookedModeOutputFlags = ECHO   | // Prints typed kets to the terminal
                                               ICANON | // Read input line-by-line
                                               ISIG   | // Ctrl-C and Ctrl-Z
                                               IEXTEN;  // Ctrl-V
    
    constexpr tcflag_t newlineReturnFlag = OPOST; // Process "\n" as "\r\n"
    
    
    
    void writeInternal(std::string_view str);

    void writeInternal(char character);



    void writeInternal(std::string_view str)
    {
        (void)write(STDOUT_FILENO, str.data(), str.size());
    }

    void writeInternal(char character)
    {
        (void)write(STDOUT_FILENO, &character, 1);
    }
}



namespace Pine::Terminal
{
    void write(std::string_view str)
    {
        if (bufferedOutput())
        {
            if (g_terminalData.outputBufferStr.size() + str.size() > g_terminalData.outputBufferSize)
            {
                flush();
                writeInternal(str);
            }
            else
                g_terminalData.outputBufferStr += str;
        }
        else
            writeInternal(str);
    }

    void write(char character)
    {
        if (bufferedOutput())
        {
            if (g_terminalData.outputBufferStr.size() + 1 > g_terminalData.outputBufferSize)
            {
                flush();
                writeInternal(character);
            }
            else
                g_terminalData.outputBufferStr += character;
        }
        else
            writeInternal(character);
    }



    std::string readLine()
    {
        // TODO: Filter out escape sequences and other undesireable inputs.
        flush();

        constexpr std::size_t inputBufferSize = 32;
        char*                 inputBuffer     = new char[inputBufferSize];
        bool                  finishedReading = false;

        std::string input;

        do
        {
            ssize_t bytesRead = read(STDIN_FILENO, inputBuffer, inputBufferSize);
            
            // TODO: Error handling.
            if (bytesRead < 1)
                finishedReading = true;
            else
            {
                // If no more input to capture
                if (bytesRead < inputBufferSize || inputBuffer[inputBufferSize - 1] == '\n')
                {
                    inputBuffer[bytesRead - 1] = '\0';
                    finishedReading = true;
                }

                input += inputBuffer;
            }
        } while (!finishedReading);

        return input;
    }



    char readChar()
    {
        flush();

        char c = '\0';
        (void)read(STDIN_FILENO, &c, 1);

        return c;
    }



    void flush()
    {
        if (g_terminalData.outputBufferStr.size() > 0)
        {
            writeInternal(g_terminalData.outputBufferStr);
            g_terminalData.outputBufferStr.clear();
        }
    }



    void setBufferSize(std::size_t bufferSize)
    {
        flush();
        
        g_terminalData.outputBufferStr = std::string();
        g_terminalData.outputBufferStr.reserve(bufferSize);

        g_terminalData.outputBufferSize = bufferSize;
    }



    std::size_t getBufferSize()
    {
        return g_terminalData.outputBufferSize;
    }



    void setForegroundColor(Color4Bit color)
    {
        write("\033[" + std::to_string((int)color) + 'm');
    }

    void setForegroundColor(Color8Bit color)
    {
        write("\033[38;5;" + std::to_string(color) + 'm');
    }

    void setForegroundColor(Color24Bit color)
    {
        write("\033[38;2;" + color.red + ';' + color.green + ';' + color.blue + 'm');
    }



    void setBackgroundColor(Color4Bit color)
    {
        write("\033[" + std::to_string(((int)color) + 10) + 'm');
    }

    void setBackgroundColor(Color8Bit color)
    {
        write("\033[48;5;" + std::to_string(color) + 'm');
    }

    void setBackgroundColor(Color24Bit color)
    {
        write("\033[48;2;" + color.red + ';' + color.green + ';' + color.blue + 'm');
    }



    void resetForegroundColor()
    {
        write("\033[39m");
    }



    void resetBackgroundColor()
    {
        write("\033[49m");
    }



    void resetColor()
    {
        write("\033[0m");
    }



    void enableAltScreenBuffer(bool enable)
    {
        if (g_terminalData.altScreenBufferEnabled == enable)
            return;
        
        if (enable)
            write("\033[?1049h");
        else
            write("\033[?1049l");
        
        g_terminalData.altScreenBufferEnabled = enable;
    }



    void mode(Mode terminalMode)
    {
        termios attributes;
        tcgetattr(STDIN_FILENO, &attributes);

        if (terminalMode == Mode::Cooked)
        {
            attributes.c_iflag |= cookedModeInputFlags;
            attributes.c_lflag |= cookedModeOutputFlags;
            attributes.c_cc[VMIN] = g_terminalData.originalAttributes.c_cc[VMIN];
            attributes.c_cc[VTIME] = g_terminalData.originalAttributes.c_cc[VTIME];
        }
        else
        {
            attributes.c_iflag &= ~cookedModeInputFlags;
            attributes.c_lflag &= ~cookedModeOutputFlags;
            attributes.c_cc[VMIN] = 0; // Read returns when any input is present
            attributes.c_cc[VTIME] = 1; // Read waits for 100 milliseconds
        }

        (void)tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
    }



    void showCursor(bool show)
    {
        if (show)
            write("\033[?25h");
        else
            write("\033[?25l");
    }



    void moveCursor(MoveCursorDirection direction, int amount)
    {
        if (amount < 1)
            return;
        
        write("\033[" + std::to_string(amount) + (char)direction);
    }



    void moveCursor(int xAmount, int yAmount)
    {
        MoveCursorDirection directon;

        if (xAmount > 0)
            directon = MoveCursorDirection::Right;
        else
        {
            directon = MoveCursorDirection::Left;
            xAmount *= -1;
        }

        moveCursor(directon, xAmount);

        if (yAmount > 0)
            directon = MoveCursorDirection::Up;
        else
        {
            directon = MoveCursorDirection::Down;
            yAmount *= -1;
        }

        moveCursor(directon, yAmount);
    }



    void setCursorPosition(Point2D<int> position)
    {
        Size2D<int> terminalSize = size();

        position.x = std::clamp(position.x, 0, terminalSize.width);
        position.y = std::clamp(position.y, 0, terminalSize.height);

        write("\033[" + std::to_string(position.y + 1) + ';' + std::to_string(position.x + 1) + 'H');
    }



    void clear()
    {
        write("\033[2J");
    }



    Size2D<int> size()
    {
        winsize terminalSize;
        (void)ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminalSize);

        return { terminalSize.ws_col, terminalSize.ws_row };
    }
}