#ifndef H_MONOPOLY_FIELD
#define H_MONOPOLY_FIELD

#include <iostream>
#include <string>

namespace Monopoly {

    class Player;

    class Field {
    protected:
        std::string name;
    public:
        virtual ~Field();
        virtual void loadField(std::istream& in) = 0;
        virtual int moneyChange() = 0;
        virtual void steppedOn(Player* player) = 0;
        virtual void reset(Player* player);

        std::string getName();
        std::string getShortName();
    };

}

#endif
