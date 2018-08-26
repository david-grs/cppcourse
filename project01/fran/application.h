#pragma once
#include "snake.h"
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include "cinder/gl/gl.h"
#include "cinder/gl/TextureFont.h"

class Application : public ci::app::App
{
public:
    const std::string FULL_SCREEN_MESSAGE = "Full screen mode, Esc to exit full screen, or use F11 to toggle on/off.";
    const cinder::vec2 UP_OFFSET = cinder::vec2(0.0f, -4.0f);
    const cinder::vec2 DOWN_OFFSET = cinder::vec2(0.0f, 4.0f);
    const cinder::vec2 LEFT_OFFSET = cinder::vec2(-4.0f, 0.0f);
    const cinder::vec2 RIGHT_OFFSET = cinder::vec2(4.0f, 0.0f);
	Application();

	void keyDown(ci::app::KeyEvent) override;
	void setup() override;
	void draw() override;
	void update() override;

	static void prepareSettings(Settings*);

private:
    cinder::gl::TextureFontRef mTextureFontRef;
    std::string mDisplayString = "SNAKE";
    Snake mSnake;
    int mSnakeLength = 1;
    cinder::vec2 mDirectionOffset = UP_OFFSET;

    void ChangeDirectionUp();
    void ChangeDirectionDown();
    void ChangeDirectionLeft();
    void ChangeDirectionRight();
};
