#include <iostream>
#include "../include/card.h"
#include "../include/deck.h"

using namespace blackjack;

int main() {
    Deck deck = Deck();
    deck.Shuffle();
    std::cout << deck;
    return 0;
}
