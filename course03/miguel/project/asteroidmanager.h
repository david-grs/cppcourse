#pragma once

#include "asteroid.h"
#include "types.h"

namespace SpaceImpactGame {

class AsteroidManager
{
public:
	AsteroidManager(const vec2& bounds, int numAsteroids);
	Status Update();
	void Draw() const;
	void TakeHit(double height);

private:
	std::vector<Asteroid> mAsteroids;
	const vec2& mBounds;
	float mVelocity {3.2f};
};
}
