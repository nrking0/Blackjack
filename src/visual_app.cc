#include "visual_app.h"

namespace blackjack {

VisualApp::VisualApp() {
    ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void VisualApp::draw() {
    ci::Color8u background_color(30, 135, 70); // dark green
    ci::gl::clear(background_color);

    switch (game_engine.GetCurrentState()) {
        case Turn::HOME_SCREEN:
            ci::gl::drawStringCentered(
                    "Welcome to Blackjack",
                    glm::vec2(kWindowSize / 2, kWindowSize / 2),
                    ci::Color("black"),
                    cinder::Font("times", (float) kWindowSize / 10));
            ci::gl::drawStringCentered(
                    "Press Enter to Play",
                    glm::vec2(kWindowSize / 2, (kWindowSize / 2) + kMargin),
                    ci::Color("black"), cinder::Font("times", (float) kMargin / 8));
            break;
        case Turn::NUM_PLAYERS:
            ci::gl::drawStringCentered(
                    "Please select the number of players (1 through 3)",
                    glm::vec2(kWindowSize / 2, (kWindowSize / 2)),
                    ci::Color("black"), cinder::Font("times", (float) kMargin / 5));
            break;
        case Turn::PLAYERS_TURN: {
            game_engine.Draw(Turn::PLAYERS_TURN);
            break;
        }
        case Turn::DEALERS_TURN:
            game_engine.Draw(Turn::DEALERS_TURN);
            break;
        case Turn::GAME_FINISHED:
            game_engine.Draw(Turn::GAME_FINISHED);
            break;
    }
}

void VisualApp::keyDown(ci::app::KeyEvent event) {
    switch (game_engine.GetCurrentState()) {
        case Turn::HOME_SCREEN:
            if (event.getCode() == ci::app::KeyEvent::KEY_RETURN) {
                game_engine.Update();
            }
            break;
        case Turn::NUM_PLAYERS:
            // Checking to see if user input 1, 2, or 3 and setting player number if so
            if ((int) event.getCode() >= (int)'1' && (int) event.getCode() <= (int)'3') {
                game_engine.SetPlayerNumber((int)event.getCode() - (int)'0');
                game_engine.Update();
            } else if (event.getCode() == ci::app::KeyEvent::KEY_q) {
                    game_engine.Reset();
            }
            break;
        case Turn::PLAYERS_TURN:
            switch (event.getCode()) {
                case ci::app::KeyEvent::KEY_h:
                    game_engine.Hit();
                    game_engine.Update();
                    break;
                case ci::app::KeyEvent::KEY_s:
                    game_engine.Stay();
                    game_engine.Update();
                    break;
                case ci::app::KeyEvent::KEY_n:
                    game_engine.NewGame();
                    game_engine.Update();
                    break;
                case ci::app::KeyEvent::KEY_q:
                    game_engine.Reset();
                    break;
            }
            break;
        case Turn::DEALERS_TURN:
            switch (event.getCode()) {
                case ci::app::KeyEvent::KEY_q:
                    game_engine.Reset();
            }
            break;
        case Turn::GAME_FINISHED:
            switch (event.getCode()) {
                case ci::app::KeyEvent::KEY_q:
                    game_engine.Reset();
                    break;
                case ci::app::KeyEvent::KEY_n:
                    game_engine.NewGame();
                    break;
            }
            break;
    }
}

} // namespace blackjack