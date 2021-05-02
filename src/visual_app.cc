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
                    "Please select the number of players (1 through 4)",
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
    game_engine.Update(event);
}

} // namespace blackjack