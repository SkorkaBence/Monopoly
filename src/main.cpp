#include <iostream>
#include <string>

#include "Monopoly/Printer/Printer.h"
#include "Monopoly/Game.h"

int main() {
    Monopoly::Printer print;

    print.changeColor(Monopoly::BrightGreen);
    print.writeln("Hello World");

    try {
        Monopoly::Game game("testgame");
    } catch (Monopoly::MonopolyException e) {
        print.changeColor(Monopoly::BrightRed);
        print.writeln("Error: " + e.getMessage());
    }
}
