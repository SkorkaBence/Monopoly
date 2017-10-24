#include "Monopoly/Player/AI/Careful.h"

namespace Monopoly {

    bool Careful::confirmPurchase(int price) {
        return (moneySpent + price) <= (moneyAtRoundStart / 2);
    }

}
