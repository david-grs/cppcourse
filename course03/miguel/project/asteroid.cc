#include "asteroid.h"

namespace SpaceImpactGame {

bool Asteroid::IsAffectedByShotAtHeight(double height) const
{
	return IsAlive()
	   and (mPosition.y - ASTEROID_RADIUS < height)
	   and (mPosition.y + ASTEROID_RADIUS > height);
}

void Asteroid::Update()
{
	mPosition.x -= mVelocity;
	mAngle += 0.1;

	if (mPosition.x < 0)
	{
		Destroy();
	}
}

void Asteroid::Draw() const
{
	if (not IsAlive())
		return;

	gl::color(Color::white());

	// Make the asteroids rotate around their own center.
	// Interesting maths here. We need to translate 
	// the object around its own axis, so we translate
	// it back to the origin, then rotate, then translate it 
	// back to its original position. The matrices are applied
	// in the opposite order because that's the natural order
	// of matrix multiplication
	gl::pushModelMatrix();
	gl::translate(mPosition);
	gl::rotate(mAngle);
	gl::translate(-mPosition);
	gl::drawSolidCircle(mPosition, ASTEROID_RADIUS, 4);
	gl::popModelMatrix();
} 

void Asteroid::Reset(vec2&& position)
{
	mAlive = true;
	mPosition = std::move(position);
}

}
