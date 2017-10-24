#ifndef H_MONOPOLY_SERVICE
#define H_MONOPOLY_SERVICE

#include "Monopoly/Fields/Field.h"
#include <iostream>

namespace Monopoly {

    class Service : public Field {
    private:
        int price;
    public:
        Service();
        void loadField(std::istream& in);

        int getServiceFee();
        int moneyChange();
    };

}

#endif
