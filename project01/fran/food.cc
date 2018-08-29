#include "food.h"
#include "cinder/Rand.h"

Food::Food(float radius):
		mRadius(radius)
{}

void Food::Update(double elapsedSeconds)
{
	mAnimateOffset = cinder::vec2(cos(elapsedSeconds) * mRadius, sin(elapsedSeconds) * mRadius);
}

void Food::Draw()
{
	// A Tasty Flower for a very hungry caterpillar
	cinder::gl::color(cinder::Color(0.0f, 1.0f, 0.0f));
	cinder::gl::drawLine(mPosition + mAnimateOffset, mPosition + cinder::vec2(0, 20));

	cinder::gl::color(cinder::Color(0.0f, 0.0f, 1.0f));
	cinder::gl::drawSolidCircle(mPosition + mAnimateOffset + cinder::vec2(10 - mRadius / 2, 0.0f - mRadius / 2), mRadius / PETAL_SIZE);
	cinder::gl::drawSolidCircle(mPosition + mAnimateOffset + cinder::vec2(0  - mRadius / 2, 10 - (mRadius / 2)), mRadius / PETAL_SIZE);
	cinder::gl::drawSolidCircle(mPosition + mAnimateOffset + cinder::vec2(10 - mRadius / 2, 10 - (mRadius / 2)), mRadius / PETAL_SIZE);
	cinder::gl::drawSolidCircle(mPosition + mAnimateOffset + cinder::vec2(0 - mRadius / 2, 0 - (mRadius / 2)), mRadius / PETAL_SIZE);

	cinder::gl::color(cinder::Color(0.9f, 1.0f, 1.0f));
	cinder::gl::drawStrokedCircle(mPosition + mAnimateOffset + cinder::vec2(10 - mRadius / 2, 0.0f - mRadius / 2), mRadius / PETAL_SIZE);
	cinder::gl::drawStrokedCircle(mPosition + mAnimateOffset + cinder::vec2(0  - mRadius / 2, 10 - (mRadius / 2)), mRadius / PETAL_SIZE);
	cinder::gl::drawStrokedCircle(mPosition + mAnimateOffset + cinder::vec2(10 - mRadius / 2, 10 - (mRadius / 2)), mRadius / PETAL_SIZE);
	cinder::gl::drawStrokedCircle(mPosition + mAnimateOffset + cinder::vec2(0 - mRadius / 2, 0 - (mRadius / 2)), mRadius / PETAL_SIZE);
	cinder::gl::drawSolidCircle(mPosition + mAnimateOffset, mRadius / 2);


}

cinder::vec2 Food::GetPosition()
{
	return mPosition + mAnimateOffset;
}

void Food::Respawn(float width, float height)
{
	mPosition = cinder::vec2(cinder::Rand::randFloat( mRadius, width - mRadius * 2 ),
			cinder::Rand::randFloat( mRadius, height - mRadius * 2 ));
}
