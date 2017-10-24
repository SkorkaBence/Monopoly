#ifndef H_MONOPOLY_LUCK
#define H_MONOPOLY_LUCK

#include "Monopoly/Fields/Field.h"
#include <iostream>

namespace Monopoly {

    class Luck : public Field {
    private:
        int price;
    public:
        Luck();
        void loadField(std::istream& in);

        int getGift();
    };

}

#endif
