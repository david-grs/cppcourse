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
	cinder::gl::color(cinder::Color(0.0f, 0.4f, 0.0f));
	cinder::gl::drawSolidCircle(mPosition, mRadius);
	cinder::gl::color(cinder::Color(0.0f, 1.0f, 0.0f));
	cinder::gl::drawStrokedCircle(mPosition, mRadius);
	cinder::gl::color(cinder::Color(0.0f, 1.0f, 0.0f));
	cinder::gl::drawStrokedCircle(mPosition, mRadius / 2);
	cinder::gl::color(cinder::Color(0.0f, 1.0f, 0.0f));
	cinder::gl::drawStrokedCircle(mPosition, mRadius / 4);
}

const cinder::vec2& Segment::GetPosition()
{
	return mPosition;
}

bool Segment::IsCollidingWithWindow(float width, float height)
{
	if( mPosition.x < ( 0.0f + mRadius ) || mPosition.x > ( width - mRadius ) )
	{
		return true;
	}

	if( mPosition.y < ( 0.0f + mRadius ) || mPosition.y > ( height - mRadius ) )
	{
		return true;
	}

	return false;
}
