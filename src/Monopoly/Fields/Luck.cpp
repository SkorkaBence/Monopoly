#include "Monopoly/Fields/Luck.h"

namespace Monopoly {

    Luck::Luck() {

    }

    void Luck::loadField(std::istream& in) {
        in >> name;
        in >> price;
    }

    int Luck::moneyChange() {
        return price;
    }

    void Luck::steppedOn(Player* player) {
        player->changeMoney(price);
    }

}
