#include "Monopoly/Printer/Printer.h"
#include <iostream>
#include <sstream>
#include <string>

namespace Monopoly {

    Printer::Printer() {

    }

    Printer::~Printer() {
        changeColor(White);
    }

    void Printer::changeColor(ConsoleColors color) {
        if (color == 100) {
            // invalid
        } else if (color >= 100) {
            // bright
            int cm = color - 100;
            std::string str = "%c[1;" + IntToStr(cm) + "m";
            const char * c = str.c_str();
            printf(c, 27);
        } else {
            // normal
            int cm = color;
            std::string str = "%c[0;" + IntToStr(cm) + "m";
            const char * c = str.c_str();
            printf(c, 27);
        }
    }

    void Printer::write(std::string str) {
        std::cout << str;
    }

    void Printer::writeln(std::string str) {
        std::cout << str << std::endl;
    }

    std::string Printer::IntToStr(int a) {
        std::stringstream ss;
        ss << a;
        return ss.str();
    }

    void Printer::printGame(const Game& game) {
        writeln("Tick " + IntToStr(game.getTicks()) + "...");
    }

}
