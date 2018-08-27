#include "snake.h"
#include "cinder/Rand.h"

Snake::Snake(int length, float radius):
		mLength(length),
		mRadius(radius)
{}

void Snake::Update()
{
    for(int index = mLength -1 ; index > 0 ; index--)
    {
        mSegments[index].Update(mSegments[index - 1].GetPosition());
    }

    mSegments[0].Update(mSegments[0].GetPosition() + mCurrentDirection);
}

void Snake::Draw()
{
    for(auto& segment : mSegments)
    {
        segment.Draw();
    }
}

void Snake::SetDirection(const cinder::vec2& directionOffset)
{
    mCurrentDirection = cinder::vec2(directionOffset.x * mRadius * 2, directionOffset.y * mRadius * 2);
}

void Snake::SetInitialPosition(float width, float height)
{
    Segment head = Segment(cinder::vec2(cinder::Rand::randFloat( mRadius, width - mRadius * 2),
            cinder::Rand::randFloat( mRadius, height - mRadius * 2)),
                    mRadius);
    mSegments.push_back(head);

    cinder::vec2 offset(0.0f, mRadius * 2);
    Segment currentSegment = head;
    for(int bodyCount = 0 ; bodyCount < mLength - 1 ; bodyCount++)
    {
        mSegments.push_back(Segment(currentSegment.GetPosition() + offset, mRadius));
        currentSegment = mSegments.back();
    }

}

bool Snake::IsCollidingWith(const cinder::vec2& position)
{
	cinder::vec2 distanceBetweenCenters = mSegments[0].GetPosition() - position;
	return distanceBetweenCenters.x <= mRadius && distanceBetweenCenters.y <= mRadius;
}

bool Snake::IsCollidingWithWindow(float width, float height)
{
    return mSegments[0].IsCollidingWithWindow(width, height);
}