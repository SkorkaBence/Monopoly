#include <stdlib.h>
#include <time.h>
#include "Monopoly/Randomizer/OneDice.h"

namespace Monopoly {

    OneDice::OneDice() {
        srand(time(NULL));
    }

    void OneDice::loadRandomizer(std::istream& in) {

    }

    int OneDice::DiceRoll() {
        return rand() % 6 + 1;
    }

}
