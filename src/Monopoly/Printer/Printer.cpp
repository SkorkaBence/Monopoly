#include "Monopoly/Printer/Printer.h"
#include <iostream>
#include <string>

namespace Monopoly {

    Printer::Printer() {

    }

    Printer::~Printer() {
        resetColor();
    }

    void Printer::changeColor(ConsoleColors color) {
        if (color == 100) {
            // invalid
        } else if (color >= 100) {
            // bright
            int cm = color - 100;
            std::string str = "%c[1;" + toStr(cm) + "m";
            const char * c = str.c_str();
            printf(c, 27);
        } else {
            // normal
            int cm = color;
            std::string str = "%c[0;" + toStr(cm) + "m";
            const char * c = str.c_str();
            printf(c, 27);
        }
    }

    void Printer::resetColor() {
        changeColor(White);
    }

    void Printer::write(std::string str) {
        std::cout << str;
    }

    void Printer::writeln(std::string str) {
        std::cout << str << std::endl;
    }

}
