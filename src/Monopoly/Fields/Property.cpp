#include "Monopoly/Fields/Property.h"
#include "Monopoly/MonopolyException.h"

namespace Monopoly {

    Property::Property() {

    }

    void Property::loadField(std::istream& in) {
        in >> price;
        in >> housePrice;
        in >> basicTrespassingFee;
        in >> houseTrespassingFee;
    }

    int Property::moneyChange() {
        if (sold) {
            if (souldHouse) {
                return -1 * houseTrespassingFee;
            } else {
                return -1 * basicTrespassingFee;
            }
        } else {
            return 0;
        }
    }

    int Property::getUpgradePrice() {
        if (sold) {
            if (souldHouse) {
                return 0;
            } else {
                return housePrice;
            }
        } else {
            return price;
        }
    }

    void Property::buy(Player* buyer) {
        if (!sold) {
            owner = buyer;
            sold = true;
        } else if (!souldHouse) {
            souldHouse = true;
        } else {
            throw MonopolyException("Invalid purchase");
        }
    }

    void Property::reset() {
        sold = false;
        owner = nullptr;
        souldHouse = false;
    }

    bool Property::isMine(Player* me) {
        return (!sold) || (owner == me);
    }

    bool Property::isSold() {
        return sold;
    }

    bool Property::hasHouse() {
        return souldHouse;
    }

    Player* Property::getOwner() {
        return owner;
    }

}
