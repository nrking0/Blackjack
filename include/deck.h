#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>
#include "card.h"

namespace blackjack {

class Deck {

public:
    Deck();
    int Size() const;

private:
    std::vector<Card> deck;

};

} // namespace blackjack

#endif //BLACKJACK_DECK_H
