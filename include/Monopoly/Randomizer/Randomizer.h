#ifndef H_MONOPOLY_RANDOMIZER
#define H_MONOPOLY_RANDOMIZER

#include <iostream>

namespace Monopoly {

    class Randomizer {
    public:
        virtual void loadRandomizer(std::istream& in) = 0;
        virtual int DiceRoll() = 0;
    };

}

#endif
