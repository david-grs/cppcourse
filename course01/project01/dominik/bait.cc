#include "bait.h"

Bait::Bait(const cinder::ivec2& screenSize)
    : mRadius(10),
      mRndEngine(std::random_device()()),
      mUniformDistX(mRadius, screenSize.x - mRadius),
      mUniformDistY(mRadius, screenSize.y - mRadius)
{
    PositionRandomly();
}

