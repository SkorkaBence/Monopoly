#include "Monopoly/Player/AI/Tactician.h"

namespace Monopoly {

    bool Tactician::confirmPurchase(int price) {
        return (moneySpent + price) <= (moneyAtRoundStart / 2);
    }

}
