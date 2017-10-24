#include "Monopoly/Fields/Luck.h"

namespace Monopoly {

    Luck::Luck() {

    }

    void Luck::loadField(std::istream& in) {
        in >> price;
    }

    int Luck::getGift() {
        return price;
    }

    int Luck::moneyChange() {
        return price;
    }

}
