#pragma once

#include "segment.h"
#include <cinder/app/RendererGl.h>
#include "cinder/gl/gl.h"
#include <vector>
#include <random>

class Snake
{
public:
    Snake();

    void Update(const cinder::vec2& offset);
    void Draw();
    void SetDirection();
    void SetInitialPosition(float width, float height);

private:
    int mLength = 1;
    float mRadius = 2.0f;
    std::vector<Segment> mSegments;

    std::mt19937 mEng;
};

