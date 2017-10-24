#include <iostream>
#include <string>

#include "Monopoly/Printer/Printer.h"
#include "Monopoly/Game.h"

int main() {
    Monopoly::Printer print;

    print.writeln("Loading game...");

    try {
        Monopoly::Game game("testgame");
        print.writeln("Game Loaded!");

        while (game.gameTick()) {
            print.printGame(game);
        }
    } catch (Monopoly::MonopolyException e) {
        print.changeColor(Monopoly::BrightRed);
        print.writeln("Error: " + e.getMessage());
    }
}
