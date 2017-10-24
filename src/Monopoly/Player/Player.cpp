#include "Monopoly/Player/Player.h"

namespace Monopoly {

    Player::Player(std::string nm, int start_money) : name(nm), money(start_money) {

    }

    Player::~Player() {
        delete brain;
    }

    std::string Player::getName() {
        return name;
    }

    int Player::getMoney() {
        return money;
    }

    void Player::setBrain(AI* aiptr) {
        brain = aiptr;
    }

}
