#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>
#include "card.h"

namespace blackjack {

/**
 * Class representing a deck of cards in a card game.
 */
class Deck {

public:
    /**
     * Basic constructor that builds a basic deck of the 52 possible cards in a regular deck of cards.
     */
    Deck();

    /**
     * Finds the size of the deck.
     *
     * @return the size of the current deck
     */
    int Size() const;

    /**
     * Used a random seed to randomize the order of cards simulating a real-life shuffle.
     */
    void Shuffle();

    /**
     * Removes card from deck, simulating a card being dealt from the deck.
     *
     * @return the card that was removed
     */
    Card RemoveCard();

    const std::vector<Card>& GetCards() const;

    /**
     * Overload of the output operator for display of deck in console.
     *
     * @param os the output stream given
     * @param deck the deck to be printed
     * @return the output stream after the deck has been outputted
     */
    friend std::ostream& operator<<(std::ostream& os, Deck& deck);

    /**
     * Overload of not equals operator for use in testing.
     *
     * @param deck deck to be compared
     * @param other_deck other deck to be compared with first
     * @return true, if the decks are not equal, else false
     */
    friend bool operator!=(Deck& deck, Deck& other_deck);

private:
    std::vector<Card> deck_;

};

} // namespace blackjack

#endif //BLACKJACK_DECK_H
