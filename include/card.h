#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <ostream>

namespace blackjack {

/**
 * Enum Representing the Suit of each card.
 */
enum class Suit {
    CLUBS = 0,
    HEARTS = 1,
    SPADES = 2,
    DIAMONDS = 3
};

/**
 * Enum Representing the Rank of each card.
 */
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

/**
 * Class representing a card that can be played in blackjack.
 */
class Card {

public:
    /**
     * Simple constructor that creates a card based on a given suit and rank.
     *
     * @param suit the suit of the card
     * @param rank the rank of the card
     */
    Card(Suit suit, Rank rank);
    Rank GetRank() const;
    Suit GetSuit() const;
    std::string GetImageURL() const;

    /**
     * Overload of the output operator so the Card can be printed in the console.
     *
     * @param os the output stream
     * @param card the card to be printed
     * @return the output stream after the card has been outputted
     */
    friend std::ostream& operator<<(std::ostream& os, Card& card);

    /**
     * Overload of the equality operator to help check if cards have the same rank and suit.
     *
     * @param card first card to be compared
     * @param other_card second card to be compared with first
     * @return true if card has same rank and suit, else false.
     */
    friend bool operator==(Card& card, Card& other_card);

private:
    Suit suit_;
    Rank rank_;

};

} // namespace blackjack

#endif //BLACKJACK_CARD_H
