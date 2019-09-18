#include "asteroidmanager.h"
#include "utils.h"

namespace SpaceImpactGame {

AsteroidManager::AsteroidManager(const vec2& bounds, int numAsteroids)
: mBounds(bounds)
{
	// Distribute asteroids randomly within the bounds
	for (int i = 0; i < numAsteroids; ++i)
	{
		mAsteroids.emplace_back(RandInBounds(bounds), mVelocity);
	}
}

Status AsteroidManager::Update()
{
	bool continuePlaying {false};
	for(auto& asteroid : mAsteroids)
	{
		asteroid.Update();
		if (asteroid.IsAlive())
		{
			continuePlaying = true;
		}
	}

	return continuePlaying ?  Status::PLAYING : Status::LOST;
}

void AsteroidManager::Draw() const
{
	for (auto& asteroid : mAsteroids)
	{
		asteroid.Draw();
	}

}

void AsteroidManager::TakeHit(double height)
{
	for (auto& asteroid : mAsteroids)
	{
		if (asteroid.IsAffectedByShotAtHeight(height))
		{
			asteroid.Destroy();

			// Another one will follow, but faster
			asteroid.Reset(vec2{mBounds.x, cinder::Rand::randFloat() * mBounds.y});
			asteroid.Faster();
		}
	}
}

}
