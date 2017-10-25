#include <stdlib.h>
#include <time.h>
#include "Monopoly/Randomizer/OneDice.h"

namespace Monopoly {

    unsigned int OneDice::current_seed = time(NULL);

    OneDice::OneDice() {
        srand(current_seed);
        current_seed = rand();
        srand(current_seed);
    }

    void OneDice::loadRandomizer(std::istream& in) {

    }

    int OneDice::DiceRoll() {
        return rand() % 6 + 1;
    }

}
