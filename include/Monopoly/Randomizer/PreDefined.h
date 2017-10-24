#ifndef H_MONOPOLY_PREDEFINED
#define H_MONOPOLY_PREDEFINED

#include "Monopoly/Randomizer/Randomizer.h"
#include "Storage/Vector.h"

namespace Monopoly {

    class PreDefined : public Randomizer {
    private:
        int currentRollId = 0;
        sbl::vector<int> rolls;
    public:
        PreDefined();
        void loadRandomizer(std::istream& in);
        int DiceRoll();
    };

}

#endif
