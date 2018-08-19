#include "snake.h"

Snake::Snake() : Snake(std::experimental::nullopt) {}
Snake::Snake(std::experimental::optional<ci::ivec2> bounds) :
	mBounds(bounds)
{
	if (mBounds)
	{
		mBodyParts.emplace_back((*mBounds).x/2, (*mBounds).y/2);
	}
	else
	{
		mBodyParts.emplace_back(0, 0);
	}
}

void Snake::Draw(std::function<void(const ci::ivec2&)> drawPoint)
{
	for (const auto& part : mBodyParts)
	{
		drawPoint(part);
	}
}

void Snake::SetDirection(Direction dir)
{
	if (mBodyParts.size() > 1 && mDirection == GetOpposite(dir))
		return;
	mDirection = dir;
}

std::experimental::optional<ci::ivec2> Snake::Move()
{
	if (mDirection == Direction::None)
		return std::experimental::nullopt;

	ci::ivec2 newHead = mBodyParts.front();
	switch(mDirection)
	{
		case Direction::Up: newHead += ci::ivec2{0, -1}; break;
		case Direction::Down: newHead += ci::ivec2{0, 1}; break;
		case Direction::Left: newHead += ci::ivec2{-1, 0}; break;
		case Direction::Right: newHead += ci::ivec2{1, 0}; break;
		default: throw std::runtime_error("unexpected direction on Move");
	}
	if (mBounds)
	{
		newHead.x = (newHead.x + (*mBounds).x) % (*mBounds).x;
		newHead.y = (newHead.y + (*mBounds).y) % (*mBounds).y;
	}
	mBodyParts.front() = newHead;

	return newHead;
}
