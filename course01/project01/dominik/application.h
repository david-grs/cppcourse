#pragma once

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>

#include "game.h"
#include "view.h"

class Application : public ci::app::App
{
public:
	Application();

	void keyDown(ci::app::KeyEvent) override;
	void setup() override;
	void draw() override;
	void update() override;

	static void prepareSettings(Settings*);
private:

    Game mGame;
    GameView mView;
};
