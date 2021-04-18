#include <game_engine.h>

using blackjack::GameEngine;

void prepareSettings(GameEngine::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(GameEngine, ci::app::RendererGl, prepareSettings);