#pragma once

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
};
