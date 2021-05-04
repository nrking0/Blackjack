#ifndef BLACKJACK_VISUAL_APP_H
#define BLACKJACK_VISUAL_APP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_engine.h"

namespace blackjack {

/**
 * Cinder visual app class.
 */
class VisualApp : public ci::app::App  {

public:
    /**
     * Basic setup constructor for GUI.
     */
    VisualApp();

    /**
     * Override of cinder's draw method.
     */
    void draw() override;

    /**
     * Key listener that updates game based on input.
     *
     * @param event the key that has been pressed
     */
    void keyDown(ci::app::KeyEvent event) override;


private:
    const double kWindowSize = 750;
    const double kMargin = 100;
    GameEngine game_engine_ = GameEngine();

};

} // namespace blackjack

#endif //BLACKJACK_VISUAL_APP_H
