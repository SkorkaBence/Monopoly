#include "Monopoly/Fields/Service.h"

namespace Monopoly {

    Service::Service() {

    }

    void Service::loadField(std::istream& in) {
        in >> price;
    }

}
