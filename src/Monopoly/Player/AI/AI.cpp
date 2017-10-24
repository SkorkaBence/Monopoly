#include "Monopoly/Player/AI/AI.h"

namespace Monopoly {

    void AI::spendMoney(int mn) {
        moneySpent += mn;
    }

    void AI::clearSpendings(int money) {
        moneySpent = 0;
        moneyAtRoundStart = money;
    }

}
