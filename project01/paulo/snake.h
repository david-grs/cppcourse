#pragma once

#include <cinder/gl/gl.h>

#include <deque>
#include <functional>
#include <experimental/optional>

enum class Direction
{
	None,
	Up,
	Down,
	Left,
	Right
};

inline Direction GetOpposite(Direction dir)
{
	switch(dir)
	{
		case Direction::Up: return Direction::Down;
		case Direction::Down: return Direction::Up;
		case Direction::Left: return Direction::Right;
		case Direction::Right: return Direction::Left;
		case Direction::None: return Direction::None;
	}
}

class Snake
{
public:
	Snake();
	Snake(std::experimental::optional<ci::ivec2> /*movingBounds*/);

	void Draw(std::function<void(const ci::ivec2&)>);
	void SetDirection(Direction);
	std::experimental::optional<ci::ivec2> Move();
	ci::ivec2 Head() const;
	void Grow(const ci::ivec2& tail);

private:
	std::experimental::optional<ci::ivec2> mBounds;
	Direction mDirection{Direction::None};
	std::deque<ci::ivec2> mBodyParts;
};
