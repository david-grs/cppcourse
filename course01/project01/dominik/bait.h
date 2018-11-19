#ifndef BAIT_H
#define BAIT_H

#include <cinder/app/RendererGl.h>
#include <random>

class Bait
{
public:
    Bait(const cinder::ivec2&);

    void PositionRandomly() { mPosition = {mUniformDistX(mRndEngine), mUniformDistY(mRndEngine)}; }
    void IncreaseSize() { mRadius += 2; }

    cinder::ivec2 GetPosition() const { return mPosition; }
    int GetRadius() const { return mRadius; }
private:
    cinder::ivec2 mPosition;
    int mRadius;

    std::default_random_engine mRndEngine;
    std::uniform_int_distribution<int> mUniformDistX;
    std::uniform_int_distribution<int> mUniformDistY;
};

#endif // BAIT_H
