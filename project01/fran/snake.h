#pragma once

#include "segment.h"
#include <cinder/app/RendererGl.h>
#include "cinder/gl/gl.h"
#include <vector>
#include <random>

class Snake
{
public:
	Snake(int length, float radius);

	Snake& operator++()
	{
		auto offset = (mCurrentDirection * cinder::vec2(-1.0f, -1.0f));
		mSegments.push_back(Segment(mSegments.back().GetPosition() + offset, mRadius));
		++mLength;
		return *this;
	}

	Snake operator++(int)
	{
		Snake old = *this;
		++*this;
		return old;
	}

	void Update();
	void Draw();
	int GetLength();
	const cinder::vec2& GetHeadPosition();
	void SetDirection(const cinder::vec2& directionOffset);
	void SetInitialPosition(float width, float height);
	bool HeadIsCollidingWith(const cinder::vec2 &startingPosition);
	bool HeadIsCollidingWithSelf();
	bool IsCollidingWithWindow(float width, float height);

private:
	int mLength;
	float mRadius;
	cinder::vec2 mCurrentDirection;
	std::vector<Segment> mSegments;
};

