#ifndef H_MONOPOLY_GAME
#define H_MONOPOLY_GAME

#include "Storage/Vector.h"
#include "Monopoly/Randomizer/Randomizer.h"
#include "Monopoly/Fields/Field.h"
#include "Monopoly/Player/Player.h"

namespace Monopoly {

    class Game {
    private:
        Randomizer* random = nullptr;
        sbl::vector<Field> fields;
        sbl::vector<Player> players;
    public:
        Game(std::string filename);
        ~Game();
    };

}

#endif
