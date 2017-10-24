#ifndef H_MONOPOLY_ONEDICE
#define H_MONOPOLY_ONEDICE

#include "Monopoly/Randomizer/Randomizer.h"

namespace Monopoly {

    class OneDice : public Randomizer {
    public:
        OneDice();
        int DiceRoll();
    };

}

#endif
