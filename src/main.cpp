#include <iostream>
#include <string>
#include <map>

#include "Monopoly/Printer/Printer.h"
#include "Monopoly/Game.h"
#include "Monopoly/Randomizer/OneDice.h"

#define TEST_RUN

#ifdef TEST_RUN
#include "tests.hpp"
#else

int main() {
    Monopoly::Printer print;

    print.setColorEnabled(true);

    try {
        Monopoly::Game game("real");
        print.writeln("Game Loaded!");

        do {
            print.printGameState(game);
        } while (game.gameTick());
        print.printGameState(game);
    } catch (Monopoly::MonopolyException e) {
        print.changeColor(Monopoly::BrightRed);
        print.writeln("Error: " + e.getMessage());
    }
}

#endif
