#ifndef BLACKJACK_GAME_ENGINE_H
#define BLACKJACK_GAME_ENGINE_H

#include "player.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "deck.h"


namespace blackjack {

/**
 * Enum representing the current state of the game.
 */
enum class Turn {
    HOME_SCREEN = 0,
    NUM_PLAYERS = 1,
    PLAYERS_TURN = 2,
    DEALERS_TURN = 3,
    GAME_FINISHED = 4
};

/**
 * Game engine class the runs the game and its rules.
 */
class GameEngine {

public:
    /**
     * Basic set up constructor that sets up game, deck, dealer, and state.
     */
    GameEngine();

    /**
     * Updates the game based on events that have happened.
     *
     * @param event a key that the player has pressed
     */
    void Update();

    /**
     * Draws the game board when it is in a state of active play.
     *
     * @param turn the current turn the game is in
     */
    void Draw(Turn turn);

    /**
     * Resets the game to the very beginning state.
     */
    void Reset();

    /**
    * Resets deck and hands so the current players can play another game while maintaining win count.
    */
    void NewGame();

    /**
     * Makes current player hit.
     */
    void Hit();

    /**
     * Makes current player stay.
     */
    void Stay();

    Turn GetCurrentState() const;
    void SetPlayerNumber(int num_players);
    const std::vector<Player>& GetPlayers() const;

private:
    const double kWindowSize = 750;
    const double kMargin = 100;
    const double kCardMargin = 25;
    int num_players_;
    Deck deck;
    Turn current_turn_;
    std::vector<Player> players_;
    Player dealer_ = Player("Dealer");
    std::string current_winner_;

    /**
     * Adds players to the game based on how many people are playing.
     *
     * @param num_players the number of players in the game
     */
    void AddPlayers(int num_players);

    /**
     * Calculates the winner of the hand based on the current scores of the players.
     *
     * @return the player who won in string form
     */
    std::string CalculateWinner();
};

} // namespace blackjack

#endif //BLACKJACK_GAME_ENGINE_H
