#ifndef H_MONOPOLY_FIELD
#define H_MONOPOLY_FIELD

#include <iostream>

namespace Monopoly {

    class Field {
    public:
        virtual void loadField(std::istream& in) = 0;
    };

}

#endif
