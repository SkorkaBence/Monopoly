#include "Monopoly/Player/AI/Greedy.h"
#include "Monopoly/Player/Player.h"

namespace Monopoly {

    bool Greedy::confirmPurchase(int price) {
        return (player->getMoney() >= price);
    }

}
