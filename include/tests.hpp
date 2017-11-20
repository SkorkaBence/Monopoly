#include "Monopoly/Game.h"
#include "Monopoly/Player/Player.h"
#include "Monopoly/Player/AI/AI.h"
#include "Monopoly/Player/AI/Careful.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace Monopoly;

Player* test_player = new Player("Test Player", 1500);

TEST_CASE("Greedy", "[ai]") {
    AI* greedy = new Careful{};
    greedy->init(test_player);

    for (int i = 0; i < 10; i++) {
        REQUIRE( greedy->confirmPurchase(1000) );
    }

    delete greedy;
}
