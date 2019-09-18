#include "spaceship.h"

namespace SpaceImpactGame {

void Spaceship::Setup(std::function<void(ShotHeight)> onShotCallback)
{
	mShotCallback = std::move(onShotCallback);
}

void Spaceship::Draw() const
{
	// Draw ship
	gl::color(Color{0.5,0,1});
	gl::drawSolidCircle( mPosition, 10.0f, 6 );

	// Draw the shot
	if (!mShot)
		return;
	
	gl::color(Color{1,0,0});
	gl::drawLine({0, mShot->first}, {mWindowSize.x, mShot->first});
}

void Spaceship::Update()
{
	// Shot should only be seen for this amount of time
	if(!!mShot && timestamp_ms() - mShot->second > SHOT_LIFE_SPAN_MS)
	{
		mShot = boost::none;
	}

	mPosition.y += mVelocity * mMovingSign;
}

void Spaceship::KeyDown(ci::app::KeyEvent event)
{

	switch(event.getCode())
	{
	case KeyEvent::KEY_k: mMovingSign -= 1; break;
	case KeyEvent::KEY_j: mMovingSign += 1; break;
	case KeyEvent::KEY_f: Shoot(); break;
	}
}

void Spaceship::KeyUp(ci::app::KeyEvent event)
{
	switch(event.getCode())
	{
	case KeyEvent::KEY_k: mMovingSign +=1; break;
	case KeyEvent::KEY_j: mMovingSign -=1; break;
	}
}

void Spaceship::Shoot()
{
	mShot = std::make_pair(mPosition.y, timestamp_ms());
	mShotCallback(mPosition.y);
}

}
