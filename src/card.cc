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

std::string Card::GetImageURL() const {
    std::string url;

    switch(this->GetRank()) {
        case Rank::ACE:
            url += "A";
            break;
        case Rank::TWO:
            url += "2";
            break;
        case Rank::THREE:
            url += "3";
            break;
        case Rank::FOUR:
            url += "4";
            break;
        case Rank::FIVE:
            url += "5";
            break;
        case Rank::SIX:
            url += "6";
            break;
        case Rank::SEVEN:
            url += "7";
            break;
        case Rank::EIGHT:
            url += "8";
            break;
        case Rank::NINE:
            url += "9";
            break;
        case Rank::TEN:
            url += "10";
            break;
        case Rank::JACK:
            url += "J";
            break;
        case Rank::QUEEN:
            url += "Q";
            break;
        case Rank::KING:
            url += "K";
            break;
    }

    switch(this->GetSuit()) {
        case Suit::CLUBS:
            url += "C";
            break;
        case Suit::HEARTS:
            url += "H";
            break;
        case Suit::SPADES:
            url += "S";
            break;
        case Suit::DIAMONDS:
            url += "D";
            break;
    }

    url += ".png";
    return url;
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

