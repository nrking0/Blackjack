#include <catch2/catch.hpp>
#include "player.h"
#include "deck.h"

using blackjack::Player;
using blackjack::Deck;
using blackjack::Card;
using blackjack::Suit;
using blackjack::Rank;

TEST_CASE("Player") {
    Player player = Player("Test");

    SECTION("Name") {
        REQUIRE(player.GetName() == "Test");
    }

    SECTION("Check has played") {
        REQUIRE(!player.GetHasPlayed());
    }

    SECTION("Changed has played") {
        player.SetHasPlayed(true);
        REQUIRE(player.GetHasPlayed());
    }
}

TEST_CASE("Hand") {
    Player player = Player("Test");
    Deck deck = Deck();
    deck.Shuffle();
    player.DealCard(deck.RemoveCard());
    player.DealCard(deck.RemoveCard());

    SECTION("Add cards to hand") {
        REQUIRE(player.GetHand().size() == 2);
    }

    player.ClearHand();

    SECTION("Clear hand") {
        REQUIRE(player.GetHand().empty());
    }

    Card card = Card(Suit::HEARTS, Rank::FIVE);
    player.DealCard(card);
    SECTION("Test get card value") {
        Card other_card = Card(Suit::HEARTS, Rank::FIVE);
        Card get_card = player.GetHand().at(0);
        REQUIRE(get_card.GetRank() == other_card.GetRank());
        REQUIRE(get_card.GetSuit() == other_card.GetSuit());
    }
}

TEST_CASE("Get score") {
    Player player = Player("Test");
    Card card = Card(Suit::HEARTS, Rank::FIVE);
    player.DealCard(card);

    SECTION("Check Score") {
        REQUIRE(player.CalculateScore() == 5);
    }

    player.ClearHand();
    Card ace = Card(Suit::HEARTS, Rank::KING);
    Card face_card = Card(Suit::SPADES, Rank::ACE);
    player.DealCard(ace);
    player.DealCard(face_card);

    SECTION("Special ace case") {
        REQUIRE(player.CalculateScore() == 21);
    }

    player.DealCard(card);

    SECTION("Other special ace case") {
        REQUIRE(player.CalculateScore() == 16);
    }
}