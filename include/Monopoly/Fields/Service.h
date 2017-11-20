#ifndef H_MONOPOLY_SERVICE
#define H_MONOPOLY_SERVICE

#include "Monopoly/Fields/Field.h"
#include "Monopoly/Player/Player.h"
#include <iostream>

namespace Monopoly {

    class Service : public Field {
    private:
        int price;
    public:
        Service();
        void loadField(std::istream& in);

        virtual int moneyChange() override;
        virtual void steppedOn(Player* player) override;
    };

}

#endif
