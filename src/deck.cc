#include "deck.h"
#include "card.h"

namespace blackjack {

    Deck::Deck() {
        for (int suit = 0; suit < 4; suit++) {

            for (int rank = 0; rank < 14; rank++) {
                Card card = Card((Suit)suit, (Rank)rank);
                this->deck.push_back(card);
            }
        }
    }

    int Deck::Size() const {
        return this->deck.size();
    }

} // namespace blackjack

