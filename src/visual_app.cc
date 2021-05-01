#include "visual_app.h"

namespace blackjack {

VisualApp::VisualApp() {
    ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
}

void VisualApp::draw() {
    ci::Color8u background_color(30, 135, 70); // dark green
    ci::gl::clear(background_color);

    game_engine.draw();
}

void VisualApp::keyDown(ci::app::KeyEvent event) {
    game_engine.Update(event);
}

} // namespace blackjack