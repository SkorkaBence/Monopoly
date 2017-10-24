#include "Monopoly/Player/AI/Tactician.h"

namespace Monopoly {

    bool Tactician::confirmPurchase(int price) {
        purchasenum++;
        return (purchasenum % 2 == 1);
    }

}
