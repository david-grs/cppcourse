#include "snake.h"
#include <cinder/app/App.h>

static const int INITIAL_SNAKE_LENGTH = 20;
static const int SNAKE_GROW_INCREMENTS = 10;


Snake::Snake(const cinder::ivec2& screenSize, const int bodyPartSize)
    : mFieldSize(screenSize),
      mMovingDirection(1, 0),
      mSnakeBody(INITIAL_SNAKE_LENGTH),
      mSnakeBodyPartSize(bodyPartSize),
      mMovingSpeed(1)
{
    cinder::ivec2 position = {mFieldSize.x / 2, mFieldSize.y / 2};
    for(cinder::ivec2& bodyPart : mSnakeBody)
    {
        bodyPart = position;
        position.x -= 1;
    }
}

void Snake::Move()
{
    cinder::ivec2 previous = mSnakeBody.at(0);
    mSnakeBody.at(0) = mSnakeBody.at(0) + (mMovingDirection * mMovingSpeed);

    for (std::size_t i = 1; i < mSnakeBody.size(); ++i)
    {
        std::swap(mSnakeBody.at(i), previous);
    }
}

void Snake::Grow()
{
    for (int i = 0; i < SNAKE_GROW_INCREMENTS; ++i)
    {
        mSnakeBody.push_back(mSnakeBody.back() - mMovingDirection);
    }
}

bool Snake::HeadClashedWithBody() const
{
    for (std::size_t i = 1; i < mSnakeBody.size(); ++i)
    {
        if ( mSnakeBody.at(i) == mSnakeBody.at(0))
            return true;
    }
    return false;
}

bool Snake::ObjectClashedWithBody(const cinder::ivec2& object) const
{
    for (std::size_t i = 0; i < mSnakeBody.size(); ++i)
    {
        if ( mSnakeBody.at(i) == object)
            return true;
    }
    return false;
}

bool Snake::HeadOutsideField() const
{
    return mSnakeBody.at(0).x == 0 || mSnakeBody.at(0).y == 0 || mSnakeBody.at(0).x == mFieldSize.x || mSnakeBody.at(0).y == mFieldSize.y;
}

int Snake::DistanceHeadToVector(const cinder::ivec2& point) const
{
    return glm::distance2(cinder::vec2(mSnakeBody.at(0)), cinder::vec2(point.x, point.y));
}

void Snake::ChangeMovingDirection(const SnakeMovingDirection& direction)
{
    switch(direction)
    {
    case SnakeMovingDirection::left:
        mMovingDirection = {-1, 0};
        break;
    case SnakeMovingDirection::right:
        mMovingDirection = {1, 0};
        break;
    case SnakeMovingDirection::up:
        mMovingDirection = {0, -1};
        break;
    case SnakeMovingDirection::down:
        mMovingDirection = {0, 1};
        break;
    };
}
