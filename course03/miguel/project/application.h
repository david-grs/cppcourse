#pragma once

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

#include "spaceimpact.h"
#include "types.h"

class Application : public ci::app::App
{
public:
	Application();

	void keyDown(KeyEvent) override;
	void keyUp(KeyEvent) override;
	void setup() override;
	void draw() override;
	void update() override;

	static void prepareSettings(Settings*);
private:

	SpaceImpactGame::SpaceImpact mSpaceImpact;
	Status mStatus {Status::STARTUP};
};
