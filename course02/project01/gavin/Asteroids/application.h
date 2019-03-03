#pragma once
#include "controller.h"
#include "game_world.h"
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

using namespace ci::app;

class Application : public App {
public:
    Application();
    void draw() override;
    void keyDown(KeyEvent event) override;
    void keyUp(KeyEvent event) override;
private:
    GameWorld mGameWorld;
    float mLastFrameTime;
    float mThisFrameTime;
    Controller mController;
};


CINDER_APP( Application, RendererGl )