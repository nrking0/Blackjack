#include "card.h"

namespace blackjack {

Card::Card(Suit suit, Rank rank) {
    this->rank_ = rank;
    this->suit_ = suit;
}

Rank Card::GetRank() const {
    return this->rank_;
}

Suit Card::GetSuit() const {
    return this->suit_;
}

std::ostream& operator<<(std::ostream& os, Card& card) {
    std::string suit;
    std::string rank;
    switch (card.GetSuit()) {
        case Suit::CLUBS:
            suit = "Clubs";
            break;
        case Suit::HEARTS:
            suit = "Hearts";
            break;
        case Suit::SPADES:
            suit = "Spades";
            break;
        case Suit::DIAMONDS:
            suit = "Diamonds";
            break;
    }

    switch (card.GetRank()) {
        case Rank::ACE:
            rank = "Ace";
            break;
        case Rank::TWO:
            rank = "Two";
            break;
        case Rank::THREE:
            rank = "Three";
            break;
        case Rank::FOUR:
            rank = "Four";
            break;
        case Rank::FIVE:
            rank = "Five";
            break;
        case Rank::SIX:
            rank = "Six";
            break;
        case Rank::SEVEN:
            rank = "Seven";
            break;
        case Rank::EIGHT:
            rank = "Eight";
            break;
        case Rank::NINE:
            rank = "Nine";
            break;
        case Rank::TEN:
            rank = "Ten";
            break;
        case Rank::JACK:
            rank = "Jack";
            break;
        case Rank::QUEEN:
            rank = "Queen";
            break;
        case Rank::KING:
            rank = "King";
            break;
    }
    os << rank + " of " + suit << std::endl;
    return os;
}

    bool operator==(Card& card, Card& other_card) {
        return (card.GetSuit() == other_card.GetSuit() && card.GetRank() == other_card.GetRank());
    }

} // namespace blackjack

