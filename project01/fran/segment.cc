#include "segment.h"

Segment::Segment(const cinder::vec2& startingPosition, float radius):
        mPosition(startingPosition),
        mRadius(radius)
{}

void Segment::Update(const cinder::vec2& newPosition)
{
    mPosition = newPosition;
}

void Segment::Draw()
{
    cinder::gl::drawSolidCircle(mPosition, mRadius);
}

const cinder::vec2& Segment::GetPosition()
{
    return mPosition;
}
