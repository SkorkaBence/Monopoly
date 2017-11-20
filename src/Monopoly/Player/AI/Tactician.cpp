#include "Monopoly/Player/AI/Tactician.h"
#include "Monopoly/Player/Player.h"

namespace Monopoly {

    bool Tactician::confirmPurchase(int price) {
        if (player->getMoney() >= price) {
            purchasenum++;
            return (purchasenum % 2 == 1);
        } else {
            return false;
        }
    }

}
