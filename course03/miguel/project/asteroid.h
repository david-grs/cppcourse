#pragma once

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/gl.h>
#include <cinder/Rand.h>

using namespace ci;

namespace SpaceImpactGame {

class Asteroid
{
public:
	Asteroid(const vec2& position, float velocity)
	: mPosition(position),
	  mVelocity(velocity)
	{}

	bool IsAlive() const { return mAlive; }
	bool IsAffectedByShotAtHeight(double height) const;
	void Update();
	void Draw() const;
	void Reset(vec2&& position);
	void Destroy() { mAlive = false; }
	void Faster() { mVelocity *= 1.1; }

private:
	static constexpr float ASTEROID_RADIUS {14.f};

	vec2 mPosition;
	bool mAlive {true};
	float mVelocity;
	float mAngle {ci::Rand::randFloat()};
};

}
