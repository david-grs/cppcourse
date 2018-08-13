#include "bait.h"

Bait::Bait(const cinder::ivec2& screenSize)
    : mRadius(10),
      mRndEngine(std::random_device()()),
      mUniformDistX(0, screenSize.x),
      mUniformDistY(0, screenSize.y)
{
    PositionRandomly();
}

