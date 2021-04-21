#include <catch2/catch.hpp>
#include "card.h"

using blackjack::Card;
using blackjack::Rank;
using blackjack::Suit;

TEST_CASE("Card Test") {
    Card card = Card(Suit::HEARTS, Rank::FIVE);

    SECTION("Check Getters") {
        REQUIRE(card.GetRank() == Rank::FIVE);
        REQUIRE(card.GetSuit() == Suit::HEARTS);
    }

    SECTION("Check related int values to enum") {
        REQUIRE((int) card.GetRank() == 5);
        REQUIRE((int) card.GetSuit() == 1);
    }
}
