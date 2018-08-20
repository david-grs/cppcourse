#pragma once

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

class GameCanvas;
class Snake;
class Apple;

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
	std::unique_ptr<GameCanvas> mCanvas;
	std::unique_ptr<Snake> mSnake;
	std::unique_ptr<Apple> mApple;
};
