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
}

