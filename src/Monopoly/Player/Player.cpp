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

    int Player::getMoney() {
        return money;
    }

    void Player::setBrain(AI* aiptr) {
        brain = aiptr;
        brain->clearSpendings(money);
    }

    void Player::stepTo(int pos, Field* field) {
        position = pos;
        money += field->moneyChange();

        if(Property* v = dynamic_cast<Property*>(field)) {
            int upgradePrice = v->getUpgradePrice();
            if (upgradePrice > 0) {
                // upgradable
                if (brain != nullptr) {
                    if (brain->confirmPurchase(upgradePrice)) {
                        v->buy();
                        money -= upgradePrice;
                    }
                }
            }
        }

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
        if (brain != nullptr) {
            brain->clearSpendings(money);
        }
    }

}
