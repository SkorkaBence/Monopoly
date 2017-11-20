#include "Monopoly/Fields/Chance.h"
#include <string>

namespace Monopoly {

    Field::~Field() {

    }

    std::string Field::getName() {
        return name;
    }

    std::string Field::getShortName() {
        if (name.length() > 10) {
            return name.substr(0, 10) + "...";
        } else {
            return name;
        }
    }

    void Field::reset(Player* player) {}

}
