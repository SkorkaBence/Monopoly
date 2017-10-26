#include "Monopoly/Fields/Chance.h"

namespace Monopoly {

    Chance::Chance() {

    }

    void Chance::loadField(std::istream& in) {
        in >> name;
    }

    int Chance::moneyChange() {
        return 0;
    }

}
