#include <iostream>

#include "Monopoly/Printer/Printer.h"
#include "Monopoly/Game.h"

int main() {
    Monopoly::Printer print;

    print.changeColor(Monopoly::BrightRed);
    print.writeln("Hello World");

    Monopoly::Game game("testgame");
}
