#include <catch2/catch.hpp>
#include "game_engine.h"

using blackjack::GameEngine;

TEST_CASE("Basic Set-up") {
    GameEngine game_engine = GameEngine();

    SECTION("Players at start") {
        REQUIRE(game_engine.GetPlayers().empty());
    }

    SECTION("State at start") {
        REQUIRE((int)game_engine.GetCurrentState() == 0);
    }

    SECTION("Update from Home-Screen") {
        game_engine.Update();
        REQUIRE((int)game_engine.GetCurrentState() == 1);
    }
}