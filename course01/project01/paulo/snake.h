#pragma once

#include "direction.h"

#include <cinder/gl/gl.h>

#include <deque>
#include <experimental/optional>

class GameCanvas;

class Snake
{
public:
	explicit Snake(GameCanvas&);
	~Snake();

	void Draw();
	void SetDirection(Direction);
	std::experimental::optional<ci::ivec2> Move();
	const ci::ivec2& Head() const;
	void GrowTail(const ci::ivec2& tail);

private:
	GameCanvas& mCanvas;
	Direction mDirection{Direction::None};
	std::deque<ci::ivec2> mBodyParts;
};
