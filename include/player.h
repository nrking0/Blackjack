#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include <string>
#include <vector>
#include "card.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"

namespace blackjack {

/**
 * Class representing a player in the blackjack game.
 */
class Player {

public:
    /**
     * Basic player constructor that gets name to set for player.
     *
     * @param name the set name for the player
     */
    explicit Player(std::string name);

    /**
     * Calculates the current score of the player based off the rules of blackjack.
     *
     * @return the player's current score
     */
    int CalculateScore() const;

    /**
     * Adds a given card to the player's hand.
     *
     * @param card the card to be added
     */
    void DealCard(Card card);

    /**
     * Clears the player's given hand.
     */
    void ClearHand();

    /**
     * Resets the win count of a player to zero.
     */
    void ClearWins();

    /**
     * Adds a win to the player's win count.
     */
    void AddWin();

    /**
     * Draws player in visual app.
     */
    void Draw(int player_index, int num_players) const;

    /**
     * Draws the dealer in the visual app.
     */
    void DrawDealer(int turn) const;

    const std::vector<Card>& GetHand() const;
    std::string GetName() const;
    void SetHasPlayed(bool has_played);
    bool GetHasPlayed() const;
    int GetWinCount() const;

private:
    const double kWindowSize = 750;
    const double kMargin = 100;
    const double kCardMargin = 25;
    std::string name_;
    std::vector<Card> hand_;
    bool has_played_;
    int win_count_;

};

} // namespace blackjack

#endif //BLACKJACK_PLAYER_H
