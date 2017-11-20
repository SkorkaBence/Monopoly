#ifndef H_MONOPOLY_PLAYER
#define H_MONOPOLY_PLAYER

#include "Monopoly/Fields/Field.h"
#include "Monopoly/Player/AI/AI.h"
#include <string>

namespace Monopoly {

    class Player {
    private:
        std::string name;
        int money = 0;
        AI* brain = nullptr;
        unsigned int position = -1;
    public:
        Player(std::string nm, int start_money);
        ~Player();

        std::string getName();
        std::string getShortName();
        int getMoney();
        void setBrain(AI* aiptr);
        AI* getBrain() const;
        void setCurrentPosition(unsigned int pos);
        unsigned int getCurrentPosition() const;
        bool isStillPlaying() const;
        void finishedRound();
        void changeMoney(int add);
    };

}

#endif
