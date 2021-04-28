#include <catch2/catch.hpp>
#include <iostream>
#include "deck.h"

using blackjack::Deck;
using blackjack::Card;

TEST_CASE("Deck Creation") {
    Deck deck = Deck();

    SECTION("Deck Size") {
        REQUIRE(deck.Size() == 52);
    }

    SECTION("Deck has correct Cards") {
        std::vector<Card> cards_temp;
        for (Card card : deck.GetCards()) {
            for (Card other_card : cards_temp) {
                REQUIRE(!(card == other_card));
            }
            cards_temp.push_back(card);
        }
    }
}

TEST_CASE("Remove Card") {
    Deck deck = Deck();
    deck.RemoveCard();

    SECTION("Deck Size") {
        REQUIRE(deck.Size() == 51);
    }
}

// TODO: check deck equality
TEST_CASE("Test Shuffle") {
    Deck deck = Deck();
    deck.Shuffle();
    std::cout << deck;
}
