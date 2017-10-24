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

    void Player::stepTo(int pos, Field* field) {
        position = pos;
        money += field->moneyChange();

        if (money < 0) {
            isPlaying = false;
        }
    }

    int Player::getCurrentPosition() {
        return position;
    }

    bool Player::isStillPlaying() {
        return isPlaying;
    }

    void Player::finishedRound() {

    }

}
