#pragma once

#include "asteroidmanager.h"
#include "spaceship.h"
#include "utils.h"
#include "types.h"

#include <cinder/app/App.h>

using namespace ci;
using namespace ci::app;

namespace SpaceImpactGame {

class SpaceImpact
{
public:
	SpaceImpact(const ivec2& windowSize);

	void Setup();
	void Draw() const;
	Status Update();
	void KeyDown(KeyEvent event);
	void KeyUp(KeyEvent event);

private:
	const ivec2& mWindowSize;
	AsteroidManager mAsteroids;
	Spaceship mSpaceship;
	int mScore {0};

	static constexpr int NUM_ASTEROIDS {10};
};

}
