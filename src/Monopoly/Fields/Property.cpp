#include "Monopoly/Fields/Property.h"

namespace Monopoly {

    Property::Property() {
        
    }

    void Property::loadField(std::istream& in) {
        in >> price;
        in >> housePrice;
        in >> stepPrice;
        in >> stepPriceWithHouse;
    }

}
