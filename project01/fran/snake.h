#pragma once

#include "segment.h"
#include <cinder/app/RendererGl.h>
#include "cinder/gl/gl.h"
#include <vector>
#include <random>

class Snake
{
public:
    Snake(int length);

    void Update();
    void Draw();
    void SetDirection(const cinder::vec2& directionOffset);
    void SetInitialPosition(float width, float height);
    bool IsCollidingWithWindow(float width, float height);

private:
    int mLength;
    float mRadius = 10.0f;
    cinder::vec2 mCurrentDirection;
    std::vector<Segment> mSegments;
};
