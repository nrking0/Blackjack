#ifndef BLACKJACK_GAME_ENGINE_H
#define BLACKJACK_GAME_ENGINE_H

#include "player.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "deck.h"


namespace blackjack {

enum class Turn {
    HOME_SCREEN,
    NUM_PLAYERS,
    PLAYERS_TURN,
    DEALERS_TURN,
    GAME_FINISHED
};

class GameEngine {

public:
    GameEngine();

    void Update(ci::app::KeyEvent event);
    void draw();
//    void keyDown(ci::app::KeyEvent event) override;

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
    void AddPlayers(int num_players);
    void Reset();
    void DrawGameBoard(Turn turn);
    std::string CalculateWinner();
    void NewGame();



};

} // namespace blackjack

#endif //BLACKJACK_GAME_ENGINE_H
