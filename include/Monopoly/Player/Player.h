#ifndef H_MONOPOLY_PLAYER
#define H_MONOPOLY_PLAYER

#include "Monopoly/Fields/Field.h"
#include "Monopoly/Player/AI/AI.h"
#include <string>

namespace Monopoly {

    class Player {
    private:
        bool isPlaying = true;
        std::string name;
        int money = 0;
        AI* brain = nullptr;
        int position = -1;
    public:
        Player(std::string nm, int start_money);
        ~Player();

        std::string getName();
        int getMoney();
        void setBrain(AI* aiptr);
        void stepTo(int pos, Field* field);
        int getCurrentPosition();
        bool isStillPlaying();
        void finishedRound();
        void changeMoney(int add);
    };

}

#endif
