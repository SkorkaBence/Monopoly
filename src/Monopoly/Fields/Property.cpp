#include "Monopoly/Fields/Property.h"

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

}
