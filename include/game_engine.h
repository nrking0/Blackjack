#ifndef BLACKJACK_GAME_ENGINE_H
#define BLACKJACK_GAME_ENGINE_H

#include "player.h"
//#include "../../../include/cinder/app/RendererGl.h"
//#include "../../../include/cinder/gl/gl.h"
//#include "../../../include/cinder/app/App.h"

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"


namespace blackjack {

enum class Turn {
    HOME_SCREEN,
    NUM_PLAYERS,
    PLAYERS_NAMES,
    PLAYERS_TURN,
    DEALERS_TURN,
    GAME_FINISHED
};

class GameEngine : public ci::app::App {

public:
    GameEngine();

    void PlayGame();
    void draw() override;
    void keyDown(ci::app::KeyEvent event) override;

private:
    Turn current_turn_;
    std::vector<Player> players_;
    Player dealer_ = Player("Dealer");

};

} // namespace blackjack

#endif //BLACKJACK_GAME_ENGINE_H
