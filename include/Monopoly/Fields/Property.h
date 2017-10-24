#ifndef H_MONOPOLY_PROPERTY
#define H_MONOPOLY_PROPERTY

#include "Monopoly/Fields/Field.h"
#include "Storage/Vector.h"
#include <iostream>

namespace Monopoly {
    class Property : public Field {
    private:
        int price;
        int housePrice;
        int basicTrespassingFee;
        int houseTrespassingFee;

        bool sold = false;
        bool souldHouse = false;
    public:
        Property();
        void loadField(std::istream& in);
    };

}

#endif
