#include <iostream>
#include <string>

#include "Monopoly/Printer/Printer.h"
#include "Monopoly/Game.h"

int main() {
    Monopoly::Printer print;

    print.setColorEnabled(false);

    print.writeln("Loading game...");

    try {
        Monopoly::Game game("testgame");
        print.writeln("Game Loaded!");

        while (game.gameTick()) {
            game.printGame(print);
        }
    } catch (Monopoly::MonopolyException e) {
        print.changeColor(Monopoly::BrightRed);
        print.writeln("Error: " + e.getMessage());
    }
}
