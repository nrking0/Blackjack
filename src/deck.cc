#include "deck.h"
#include "card.h"
#include <algorithm>
#include <random>

namespace blackjack {

    Deck::Deck() {
        for (int suit = 0; suit < 4; suit++) {

            for (int rank = 1; rank < 14; rank++) {
                Card card = Card((Suit)suit, (Rank)rank);
                this->deck.push_back(card);
            }
        }
    }

    Card Deck::RemoveCard() {
       Card card = deck.back();
       deck.pop_back();
       return card;
    }

    void Deck::Shuffle() {
        // Code below assisted by: https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine e(seed);
        std::shuffle(std::begin(deck), std::end(deck), e);
    }

    int Deck::Size() const {
        return this->deck.size();
    }

    std::ostream& operator<<(std::ostream& os, Deck& deck) {
        for (Card card : deck.deck) {
            os << card;
        }
        return os;
    }

} // namespace blackjack

