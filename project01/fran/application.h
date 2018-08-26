#pragma once

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include "cinder/gl/gl.h"
#include "cinder/gl/TextureFont.h"

class Application : public ci::app::App
{
public:
    const std::string FULL_SCREEN_MESSAGE = "Full screen mode, Esc to exit full screen, or use F11 to toggle on/off.";
	Application();

	void keyDown(ci::app::KeyEvent) override;
	void setup() override;
	void draw() override;
	void update() override;

	static void prepareSettings(Settings*);

private:
    cinder::gl::TextureFontRef mTextureFontRef;
    std::string mDisplayString = "SNAKE";

    void ChangeDirectionUp();
    void ChangeDirectionDown();
    void ChangeDirectionLeft();
    void ChangeDirectionRight();
};
