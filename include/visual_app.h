#ifndef BLACKJACK_VISUAL_APP_H
#define BLACKJACK_VISUAL_APP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_engine.h"

namespace blackjack {

class VisualApp : public ci::app::App  {

public:
    VisualApp();
    void draw() override;
    void keyDown(ci::app::KeyEvent event) override;


private:
    const double kWindowSize = 750;
    GameEngine game_engine = GameEngine();

};

} // namespace blackjack

#endif //BLACKJACK_VISUAL_APP_H
