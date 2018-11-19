#include "snake.h"

#include "game_canvas.h"

static const ci::Color SnakeColor{ci::Color::hex(0x0B7B10)};

Snake::Snake(GameCanvas& canvas) :
	mCanvas(canvas)
{
	GrowTail(mCanvas.GetRandomUnusedPoint());
}

Snake::~Snake()
{
	for (const auto& part : mBodyParts)
		mCanvas.Release(part);
}

void Snake::Draw()
{
	for (const auto& part : mBodyParts)
	{
		mCanvas.Add(part, SnakeColor);
	}
}

void Snake::SetDirection(Direction dir)
{
	if (mBodyParts.size() > 1 && mDirection == GetOpposite(dir))
		return;
	mDirection = dir;
}

const ci::ivec2& Snake::Head() const
{
	return mBodyParts.front();
}

void Snake::GrowTail(const ci::ivec2& tail)
{
	mCanvas.Use(tail);
	mBodyParts.push_back(tail);
}

std::experimental::optional<ci::ivec2> Snake::Move()
{
	if (mDirection == Direction::None)
	{
		return std::experimental::nullopt;
	}

	ci::ivec2 newHead = mBodyParts.front() + ToVector(mDirection);
	newHead.x = (newHead.x + mCanvas.GetWidth()) % mCanvas.GetWidth();
	newHead.y = (newHead.y + mCanvas.GetHeight()) % mCanvas.GetHeight();

	auto tail = mBodyParts.back();
	mBodyParts.pop_back();

	for (const auto& part : mBodyParts)
	{
		if (part == newHead)
		{
			mBodyParts.push_back(tail);
			return std::experimental::nullopt;
		}
	}

	mCanvas.Release(tail);

	mCanvas.Use(newHead);
	mBodyParts.push_front(newHead);
	return tail;
}
