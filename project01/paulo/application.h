#pragma once

#include "game_canvas.h"
#include "snake.h"

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

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
	bool mGameOver{false};
	ci::ivec2 mFruit;
	std::unique_ptr<GameCanvas> mCanvas;
	std::unique_ptr<Snake> mSnake;
};
