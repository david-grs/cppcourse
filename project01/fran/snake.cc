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

int Snake::GetLength()
{
	return mLength;
}

const cinder::vec2& Snake::GetHeadPosition()
{
	return mSegments[0].GetPosition();
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

bool Snake::HeadIsCollidingWith(const cinder::vec2 &position)
{
	float xDistance = abs(position.x - mSegments[0].GetPosition().x);
	float yDistance = abs(position.y - mSegments[0].GetPosition().y);
	return xDistance < mRadius * 2 - 0.1f && yDistance < mRadius * 2 - 0.1f;
}

bool Snake::HeadIsCollidingWithSelf()
{
	for(int index = mLength -1 ; index > 0 ; index--)
	{
		if (HeadIsCollidingWith(mSegments[index].GetPosition()))
		{
			return true;
		}
	}

	return false;
}

bool Snake::IsCollidingWithWindow(float width, float height)
{
	return mSegments[0].IsCollidingWithWindow(width, height);
}