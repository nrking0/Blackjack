#include "deck.h"
#include "card.h"
#include <algorithm>
#include <random>

namespace blackjack {

Deck::Deck() {
    for (int suit = 0; suit < 4; suit++) {

        for (int rank = 1; rank < 14; rank++) {
            Card card = Card((Suit)suit, (Rank)rank);
            this->deck_.push_back(card);
        }
    }
}

Card Deck::RemoveCard() {
   Card card = deck_.back();
   deck_.pop_back();
   return card;
}

void Deck::Shuffle() {
    // Code below assisted by: https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::shuffle(std::begin(deck_), std::end(deck_), e);
}

int Deck::Size() const {
    return this->deck_.size();
}

std::ostream& operator<<(std::ostream& os, Deck& deck) {
    for (Card card : deck.deck_) {
        os << card;
    }
    return os;
}

bool operator!=(Deck& deck, Deck& other_deck) {
    // Checking to make sure the deck is not the exact same as the other_deck
    for (int i = 0; i < deck.Size(); i++) {
        Card card = deck.RemoveCard();
        Card other_card = other_deck.RemoveCard();
        if (!(card == other_card)) {
            return true;
        }
    }
    return false;
}

const std::vector<Card> &Deck::GetCards() const {
    return deck_;
}

} // namespace blackjack

