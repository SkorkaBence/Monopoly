#ifndef H_MONOPOLY_FIELD
#define H_MONOPOLY_FIELD

#include <iostream>
#include <string>

namespace Monopoly {

    class Field {
    protected:
        std::string name;
    public:
        virtual void loadField(std::istream& in) = 0;
        virtual int moneyChange() = 0;

        std::string getName();
        std::string getShortName();
    };

}

#endif
