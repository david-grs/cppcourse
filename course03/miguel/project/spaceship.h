#pragma once

#include <boost/circular_buffer.hpp>
#include "utils.h"
#include "shot.h"

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <boost/optional/optional.hpp>

using namespace ci;
using namespace ci::app;

namespace SpaceImpactGame {

class Spaceship
{
public:
	explicit Spaceship(const vec2& windowSize)
	: mWindowSize(windowSize),
	  mPosition(0, windowSize.y/2)
	  {}

	void Setup(std::function<void(ShotHeight)> onShotCallback);
	void Draw() const;
	void Update();
	void KeyDown(KeyEvent event);
	void KeyUp(KeyEvent event);

private:

	void Shoot();

	vec2 mPosition;
	int mMovingSign = 0;
	const int mVelocity {5};

	const vec2 mWindowSize;

	// Game logic and graphics
	int mNumLives { 3 };
	static const Color mShipColor;
	static const Color mLaserColor;

	static constexpr double  SHOT_LIFE_SPAN_MS = 200;

	boost::optional<Shot> mShot;
	std::function<void(ShotHeight)> mShotCallback;
};
}

