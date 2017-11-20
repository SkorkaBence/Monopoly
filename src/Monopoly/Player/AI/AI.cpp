#include "Monopoly/Player/AI/AI.h"
#include "Monopoly/Player/Player.h"

namespace Monopoly {

    AI::~AI() {

    }

    void AI::init(Player* owner) {
        player = owner;
    }

    void AI::spendMoney(int mn) {
        moneySpent += mn;
    }

    void AI::clearSpendings(int money) {
        moneySpent = 0;
        moneyAtRoundStart = money;
    }

}
