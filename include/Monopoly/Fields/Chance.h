#ifndef H_MONOPOLY_CHANCE
#define H_MONOPOLY_CHANCE

#include "Monopoly/Fields/Field.h"
#include <vector>
#include <iostream>

namespace Monopoly {

    class Chance : public Field {
    private:
    public:
        Chance();
        void loadField(std::istream& in);

        int moneyChange();
    };

}

#endif
