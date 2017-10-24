#ifndef H_MONOPOLY_PROPERTY
#define H_MONOPOLY_PROPERTY

#include "Monopoly/Fields/Field.h"
#include <iostream>

namespace Monopoly {

    class Property : public Field {
    private:
        int price;
        int housePrice;
        int stepPrice;
        int stepPriceWithHouse;
    public:
        Property();
        void loadField(std::istream& in);
    };

}

#endif
