#ifndef H_MONOPOLY_PRINTER
#define H_MONOPOLY_PRINTER

#include <string>
#include <sstream>
#include "Monopoly/Game.h"

namespace Monopoly {

    enum ConsoleColors {
        Black = 30,
        Red = 31,
        Green = 32,
        Yellow = 33,
        Blue = 34,
        Magenta = 35,
        Cyan = 36,
        White = 37,
        BrightModifier = 100,
        BrightBalck = BrightModifier + Black,
        BrightRed = BrightModifier + Red,
        BrightGreen = BrightModifier + Green,
        BrightYellow = BrightModifier + Yellow,
        BrightBlue = BrightModifier + Blue,
        BrightMagenta = BrightModifier + Magenta,
        BrightCyan = BrightModifier + Cyan,
        BrightWhite = BrightModifier + White
    };

    class Printer {
    private:
        bool enableColors = true;
    public:
        Printer();
        ~Printer();
        void changeColor(ConsoleColors color);
        void resetColor();
        void write(std::string str);
        void writeln(std::string str);
        void rainbow(std::string str);
        std::string getColorChar(ConsoleColors color);
        unsigned int colorCharLength();

        void setColorEnabled(bool status);

        void printGameState(const Game& game);
    };

    template<typename T>
    std::string toStr(T a) {
        std::stringstream ss;
        ss << a;
        return ss.str();
    }
}

#endif
