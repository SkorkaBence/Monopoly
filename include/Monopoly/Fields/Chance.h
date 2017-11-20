#ifndef H_MONOPOLY_CHANCE
#define H_MONOPOLY_CHANCE

#include "Monopoly/Fields/Field.h"
#include "Monopoly/Player/Player.h"
#include <vector>
#include <iostream>

namespace Monopoly {

    class Chance : public Field {
    private:
    public:
        Chance();
        void loadField(std::istream& in);

        virtual int moneyChange() override;
        virtual void steppedOn(Player* player) override;
    };

}

#endif
