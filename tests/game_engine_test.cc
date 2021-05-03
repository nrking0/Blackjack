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

TEST_CASE("Adding Players") {
    GameEngine game_engine = GameEngine();

    game_engine.Update();
    game_engine.SetPlayerNumber(2);
    game_engine.Update();

    SECTION("Players size") {
        REQUIRE(game_engine.GetPlayers().size() == 2);
    }

    SECTION("Correct state after update") {
        REQUIRE((int)game_engine.GetCurrentState() == 2);
    }

    SECTION("Ensure has-played is false at start") {
        REQUIRE(!game_engine.GetPlayers()[0].GetHasPlayed());
        REQUIRE(!game_engine.GetPlayers()[1].GetHasPlayed());
    }
}

TEST_CASE("Player Actions") {
    GameEngine game_engine = GameEngine();

    game_engine.Update();
    game_engine.SetPlayerNumber(1);
    game_engine.Update();

    SECTION("Hit") {
        int prior_score = game_engine.GetPlayers()[0].CalculateScore();
        game_engine.Hit();
        game_engine.Hit();
        game_engine.Hit();
        game_engine.Hit();
        REQUIRE(prior_score < game_engine.GetPlayers()[0].CalculateScore());
    }

    SECTION("Stay") {
        game_engine.Stay();
        REQUIRE(game_engine.GetPlayers()[0].GetHasPlayed());
    }

    SECTION("Update goes to game finished turn after stay") {
        game_engine.Stay();
        game_engine.Update();
        REQUIRE((int)game_engine.GetCurrentState() == 4);
    }
}