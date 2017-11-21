#include "Monopoly/Game.h"
#include "Monopoly/Player/Player.h"
#include "Monopoly/Player/AI/AI.h"
#include "Monopoly/Player/AI/Careful.h"
#include "Monopoly/Player/AI/Greedy.h"
#include "Monopoly/Player/AI/Tactician.h"
#include "Monopoly/Randomizer/OneDice.h"

#include <memory>
#include <utility>
#include <vector>
#include <cmath>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace Monopoly;

TEST_CASE("Greedy", "[ai]") {
    std::unique_ptr<Player> test_player = std::make_unique<Player>("Test Player", 15000);
    std::unique_ptr<AI> greedy = std::make_unique<Greedy>();
    greedy->init(test_player.get());

    for (int i = 0; i < 10; i++) {
        CAPTURE(i);
        REQUIRE( greedy->confirmPurchase(1000) );
    }
}

TEST_CASE("Careful", "[ai]") {
    std::unique_ptr<Player> test_player = std::make_unique<Player>("Test Player", 15000);
    std::unique_ptr<AI> careful = std::make_unique<Careful>();
    careful->init(test_player.get());
    careful->clearSpendings(test_player->getMoney());

    for (int i = 0; i < 10; i++) {
        CAPTURE(i);
        REQUIRE( careful->confirmPurchase(1000) );
    }
}

TEST_CASE("Tactician", "[ai]") {
    std::unique_ptr<Player> test_player = std::make_unique<Player>("Test Player", 15000);
    std::unique_ptr<AI> tactician = std::make_unique<Tactician>();
    tactician->init(test_player.get());

    for (int i = 0; i < 10; i++) {
        CAPTURE(i);
        if (i % 2 == 0) {
            REQUIRE( tactician->confirmPurchase(1000) );
        } else {
            REQUIRE_FALSE( tactician->confirmPurchase(1000) );
        }
    }
}

TEST_CASE("Loading an empty game", "[gameload]") {
    REQUIRE_THROWS(Game("empty"));
}

TEST_CASE("Loading a game with 0 fields", "[gameload]") {
    REQUIRE_THROWS(Game("0fields"));
}

TEST_CASE("Loading a game with 0 players", "[gameload]") {
    REQUIRE_THROWS(Game("0players"));
}

TEST_CASE("Loading a correct game", "[gameload]") {
    REQUIRE_NOTHROW(Game("real"));
}

TEST_CASE("Random dice distribution", "[dice]") {
    OneDice dice;
    std::vector<unsigned int> res(6, 0);

    const unsigned int roll_num = 100000;
    const unsigned int perfect_distribution = roll_num / res.size();
    const unsigned int error_limit = roll_num * 0.01;

    for (unsigned int i = 0; i < roll_num; i++) {
        unsigned int n = dice.DiceRoll();
        res[n-1]++;
    }

    for (unsigned int i = 0; i < res.size(); i++) {
        int diff = abs(res[i] - perfect_distribution);
        CAPTURE( diff );
        REQUIRE( diff < error_limit );
    }
}
