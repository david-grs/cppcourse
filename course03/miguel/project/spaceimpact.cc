#include "spaceimpact.h"

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>

namespace SpaceImpactGame {

SpaceImpact::SpaceImpact(const ivec2& windowSize)
: mWindowSize(windowSize),
  mAsteroids(windowSize, NUM_ASTEROIDS),
  mSpaceship(windowSize)
 {
 } 

void SpaceImpact::Setup()
{
	mSpaceship.Setup([this](ShotHeight height) mutable
	{
		mAsteroids.TakeHit(height);
		++mScore;
	});
;
}

void SpaceImpact::Draw() const
{
	gl::clear();
	mSpaceship.Draw();
	mAsteroids.Draw();

	DrawTextInPosition("Score     " + std::to_string(mScore), vec2(0,0));
	DrawTextInPosition("Use  'j/k' to move and 'f' to fire. "
			"Asteroids will keep coming while you keep shooting them. Hold on for as long as you can.",
			vec2{0, mWindowSize.y-15});
}
Status SpaceImpact::Update()
{
	mSpaceship.Update();
	return mAsteroids.Update();
}

void SpaceImpact::KeyDown(KeyEvent event)
{
	mSpaceship.KeyDown(event);
}

void SpaceImpact::KeyUp(KeyEvent event)
{
	mSpaceship.KeyUp(event);
}
}
