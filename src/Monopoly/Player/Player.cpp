#include "Monopoly/Player/Player.h"
#include "Monopoly/Fields/Property.h"

namespace Monopoly {

    Player::Player(std::string nm, int start_money) : name(nm), money(start_money) {
    }

    Player::~Player() {
        delete brain;
    }

    std::string Player::getName() {
        return name;
    }

    std::string Player::getShortName() {
        return name.substr(0, 5);
    }

    int Player::getMoney() {
        return money;
    }

    void Player::setBrain(AI* aiptr) {
        brain = aiptr;
        brain->init(this);
        brain->clearSpendings(money);
    }

    void Player::setCurrentPosition(unsigned int pos) {
        position = pos;
    }

    unsigned int Player::getCurrentPosition() const {
        return position;
    }

    bool Player::isStillPlaying() const {
        return money > 0;
    }

    void Player::finishedRound() {
        if (brain != nullptr) {
            brain->clearSpendings(money);
        }
    }

    void Player::changeMoney(int add) {
        money += add;
    }

    AI* Player::getBrain() const {
        return brain;
    }

}
