#pragma once
#include "snake.h"
#include "food.h"
#include "constants.h"
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include "cinder/gl/gl.h"
#include "cinder/gl/TextureFont.h"

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
	cinder::gl::TextureFontRef mTextureFontRef;
	std::string mDisplayString = "(hit enter to begin)";
	std::string mFinalScoreString = GAME_TITLE;
	Snake mSnake;
	Food mFood;
	cinder::vec2 mDirectionOffset = UP_OFFSET;
	bool mShowStartingScreen = true;
	bool mGameOver = false;

	void ChangeDirectionUp();
	void ChangeDirectionDown();
	void ChangeDirectionLeft();
	void ChangeDirectionRight();
	void StartNewGame();
};
