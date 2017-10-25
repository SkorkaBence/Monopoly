#include <iostream>
#include <string>
#include <map>

#include "Monopoly/Printer/Printer.h"
#include "Monopoly/Game.h"
#include "Monopoly/Randomizer/OneDice.h"

int main() {
    Monopoly::Printer print;

    print.setColorEnabled(true);

    std::map<std::string, int> pontok;
    std::map<std::string, int> gyozelmek;
    pontok["Careful"] = 0;
    pontok["Greedy"] = 0;
    pontok["Tacti"] = 0;
    gyozelmek["Careful"] = 0;
    gyozelmek["Greedy"] = 0;
    gyozelmek["Tacti"] = 0;

    for (int i = 0; i < 1000000; i++) {
        try {
            Monopoly::Game game("testgame");
            while (game.gameTick()) {}

            sbl::vector<Monopoly::Player*> lose = game.getLoseList();

            int i = 0;
            while (!lose.empty()) {
                if (i == 0) {
                    gyozelmek[lose.back()->getName()]++;
                }
                pontok[lose.back()->getName()] += lose.size() - i;
                i++;
                lose.pop_back();
            }
        } catch (Monopoly::MonopolyException e) {}
    }

    print.writeln("Pontok:");
    for (std::map<std::string, int>::iterator it = pontok.begin(); it != pontok.end(); it++) {
        print.writeln(it->first + ": " + Monopoly::toStr(it->second));
    }
    print.writeln("Gyozelmek:");
    for (std::map<std::string, int>::iterator it = gyozelmek.begin(); it != gyozelmek.end(); it++) {
        print.writeln(it->first + ": " + Monopoly::toStr(it->second));
    }

    /*
    try {
        Monopoly::Game game("testgame");
        print.writeln("Game Loaded!");

        do {
            game.printGame(print);
        } while (game.gameTick());
        game.printGame(print);

        sbl::vector<Monopoly::Player*> lose = game.getLoseList();

        if (lose.size() == 4) {
            game.printGame(print);
            print.writeln("!!!!!!!!!");
        }
    } catch (Monopoly::MonopolyException e) {
        print.changeColor(Monopoly::BrightRed);
        print.writeln("Error: " + e.getMessage());
    }
    */
}
