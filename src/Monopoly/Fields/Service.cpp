#include "Monopoly/Fields/Service.h"

namespace Monopoly {

    Service::Service() {

    }

    void Service::loadField(std::istream& in) {
        in >> name;
        in >> price;
    }

    int Service::moneyChange() {
        return -1 * price;
    }

    void Service::steppedOn(Player* player) {
        player->changeMoney(-price);
    }

}
