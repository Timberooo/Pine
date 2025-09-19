#ifndef PINE_IO_TERMINAL_H
#define PINE_IO_TERMINAL_H

#include <cstddef>
#include <string_view>

#include "../color.h"
#include "../math.h"



namespace Pine::Terminal
{
    class Init
    {
    public:

        Init();

        ~Init();

    private:
        
        static std::size_t s_counter;
    };



    static Init terminalInit;



    enum class Mode {
        Cooked,
        Raw
    };

    enum class MoveCursorDirection {
        Up    = 65,
        Down  = 66,
        Right = 67,
        Left  = 68
    };


    void write(std::string_view str);

    void write(char character);

    inline void writeLine(std::string_view str);

    inline void writeLine(char character);


    std::string readLine();

    char readChar();


    void flush();

    void setBufferSize(std::size_t bufferSize);

    std::size_t getBufferSize();

    inline bool bufferedOutput();


    inline void setColor(Color4 foregroundColor, Color4 backgroundColor);

    inline void setColor(Color8 foregroundColor, Color8 backgroundColor);

    inline void setColor(ColorRGB foregroundColor, ColorRGB backgroundColor);

    void setForegroundColor(Color4 color);

    void setForegroundColor(Color8 color);

    void setForegroundColor(ColorRGB color);

    void setBackgroundColor(Color4 color);

    void setBackgroundColor(Color8 color);

    void setBackgroundColor(ColorRGB color);

    void resetForegroundColor();

    void resetBackgroundColor();

    void resetColor();


    void enableAltScreenBuffer(bool enable);

    void mode(Mode terminalMode);


    void showCursor(bool show);

    void moveCursor(MoveCursorDirection direction, int amount);

    void moveCursor(int xAmount, int yAmount);

    void setCursorPosition(Point2D<int> position);

    inline void setCursorPosition(int x, int y);


    void clear();


    Size2D<int> size();



    inline void writeLine(std::string_view str) {
        write(str);
        write('\n');
    }

    inline void writeLine(char character) {
        write(character);
        write('\n');
    }



    inline bool bufferedOutput() {
        return getBufferSize() > 0;
    }



    inline void setColor(Color4 foregroundColor, Color4 backgroundColor) {
        setForegroundColor(foregroundColor);
        setBackgroundColor(backgroundColor);
    }

    inline void setColor(Color8 foregroundColor, Color8 backgroundColor) {
        setForegroundColor(foregroundColor);
        setBackgroundColor(backgroundColor);
    }

    inline void setColor(ColorRGB foregroundColor, ColorRGB backgroundColor) {
        setForegroundColor(foregroundColor);
        setBackgroundColor(backgroundColor);
    }



    inline void setCursorPosition(int x, int y) {
        setCursorPosition({ x, y });
    }
}

#endif // PINE_IO_TERMINAL_H