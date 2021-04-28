#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <ostream>

namespace blackjack {

enum class Suit {
    CLUBS = 0,
    HEARTS = 1,
    SPADES = 2,
    DIAMONDS = 3
};

enum class Rank {
    ACE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13
};

class Card {

public:
    Card(Suit suit, Rank rank);
    Rank GetRank() const;
    Suit GetSuit() const;
    std::string GetImageURL() const;
    friend std::ostream& operator<<(std::ostream& os, Card& card);
    friend bool operator==(Card& card, Card& other_card);

private:
    Suit suit_;
    Rank rank_;

};

} // namespace blackjack

#endif //BLACKJACK_CARD_H
