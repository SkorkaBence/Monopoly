#ifndef H_MONOPOLY_PLAYER
#define H_MONOPOLY_PLAYER

#include "Monopoly/Player/AI/AI.h"
#include <string>

namespace Monopoly {

    class Player {
    private:
        std::string name;
        int money = 0;
        AI* brain = nullptr;
    public:
        Player(std::string nm, int start_money);
        ~Player();

        std::string getName();
        int getMoney();
        void setBrain(AI* aiptr);
    };

}

#endif
