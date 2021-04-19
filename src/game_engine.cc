#include "game_engine.h"


namespace blackjack {

GameEngine::GameEngine() {
    dealer_ = Player("Dealer");
    current_turn_ = Turn::HOME_SCREEN;

    ci::app::setWindowSize((int) kWindowSize, (int)kWindowSize);
}

void GameEngine::draw() {
    ci::Color8u background_color(30, 135, 70); // dark green
    ci::gl::clear(background_color);

    switch (current_turn_) {
        case Turn::HOME_SCREEN:
            ci::gl::drawStringCentered(
                    "Welcome to Blackjack",
                    glm::vec2(kWindowSize / 2, kWindowSize / 2),
                    ci::Color("black"),
                    cinder::Font("times", (float) kWindowSize / 10));
            ci::gl::drawStringCentered(
                    "Press Enter to Play",
                    glm::vec2(kWindowSize / 2, (kWindowSize / 2) + kMargin),
                    ci::Color("black"), cinder::Font("times", (float)kMargin / 8));
            break;
        case Turn::NUM_PLAYERS:
            break;
        case Turn::PLAYERS_NAMES:
            break;
        case Turn::PLAYERS_TURN:
            break;
        case Turn::DEALERS_TURN:
            break;
        case Turn::GAME_FINISHED:
            break;
    }
}

void GameEngine::PlayGame() {
    switch (current_turn_) {
        case Turn::HOME_SCREEN:
            break;
        case Turn::NUM_PLAYERS:
            break;
        case Turn::PLAYERS_NAMES:
            break;
        case Turn::PLAYERS_TURN:
            for (Player player : players_) {
                if (player.GetHasPlayed()) {
                    continue;
                } else {
                    if (player.GetScore() > 21) {
                        player.SetHasPlayed(true);
                    }
                    break;
                }
            }
            break;
        case Turn::DEALERS_TURN:
            break;
        case Turn::GAME_FINISHED:
            break;
    }
}

void GameEngine::keyDown(ci::app::KeyEvent event) {
    switch (current_turn_) {
        case Turn::HOME_SCREEN:
            if (event.getCode() == ci::app::KeyEvent::KEY_RETURN) {
                current_turn_ = Turn::NUM_PLAYERS;
            }
            break;
        case Turn::NUM_PLAYERS:
            switch (event.getCode()) {
                case ci::app::KeyEvent::KEY_1:
                    break;
                case ci::app::KeyEvent::KEY_2:
                    break;
                case ci::app::KeyEvent::KEY_3:
                    break;
                case ci::app::KeyEvent::KEY_4:
                    break;
            }
            break;
        case Turn::PLAYERS_NAMES:
            break;
        case Turn::PLAYERS_TURN:
            break;
        case Turn::DEALERS_TURN:
            break;
        case Turn::GAME_FINISHED:
            break;
    }
}

} // namespace blackjack