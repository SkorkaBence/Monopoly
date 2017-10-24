#include "Monopoly/Randomizer/PreDefined.h"

namespace Monopoly {

    PreDefined::PreDefined() {

    }

    void PreDefined::loadRandomizer(std::istream& in) {
        int num;
        in >> num;
        rolls.resize(num);
        for (int i = 0; i < num; i++) {
            in >> rolls[i];
        }
    }

    int PreDefined::DiceRoll() {
        currentRollId++;
        return rolls[currentRollId - 1];
    }

}
