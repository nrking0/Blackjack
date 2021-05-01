#include <visual_app.h>

using blackjack::VisualApp;

void prepareSettings(VisualApp::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(VisualApp, ci::app::RendererGl, prepareSettings);