#ifndef H_MONOPOLY_GAME
#define H_MONOPOLY_GAME

#include "Monopoly/MonopolyException.h"
#include "Storage/Vector.h"
#include "Monopoly/Randomizer/Randomizer.h"
#include "Monopoly/Fields/Field.h"
#include "Monopoly/Player/Player.h"
#include "Monopoly/Printer/Printer.h"

namespace Monopoly {

    class Game {
    private:
        Randomizer* random = nullptr;
        sbl::vector<Field*> fields;
        sbl::vector<Player*> players;

        int nextPlayer = 0;
        int tick = 0;

        void loadGame(std::string filename);
    public:
        Game(std::string filename);
        ~Game();
        bool gameTick();
        void printGame(Printer& printer);
    };

}

#endif
