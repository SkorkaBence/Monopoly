#ifndef H_MONOPOLY_PROPERTY
#define H_MONOPOLY_PROPERTY

#include "Monopoly/Fields/Field.h"
#include "Storage/Vector.h"
#include "Monopoly/Player/Player.h"
#include <iostream>

namespace Monopoly {
    class Property : public Field {
    private:
        Player* owner = nullptr;

        int price;
        int housePrice;
        int basicTrespassingFee;
        int houseTrespassingFee;

        bool sold = false;
        bool souldHouse = false;
    public:
        Property();
        void loadField(std::istream& in);
        virtual int moneyChange() override;
        int getUpgradePrice();
        void buy(Player* buyer);
        virtual void reset(Player* player) override;
        bool isSold();
        bool hasHouse();
        Player* getOwner();
        virtual void steppedOn(Player* player) override;
    };

}

#endif
