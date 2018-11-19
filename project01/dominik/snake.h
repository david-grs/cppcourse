#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <cinder/app/RendererGl.h>

enum class SnakeMovingDirection
{
    left, right, up, down
};

class Snake
{
public:
    Snake(const cinder::ivec2 &, const int);
    void Move();
    void Grow();
    void ChangeMovingDirection(const SnakeMovingDirection& direction);
    void IncreaseSpeed() { ++mMovingSpeed; }

    void GetHead(cinder::ivec2& head) const { head = mSnakeBody[0]; }
    int GetSize() const { return mSnakeBodyPartSize; }
    void GetBody(std::vector<cinder::ivec2>& body) const { body = mSnakeBody; }

    bool HeadClashedWithBody() const;
    bool HeadOutsideField() const;
    bool ObjectClashedWithBody(const cinder::ivec2&) const;
    float MinDistanceHeadToVectorNowAndBefore(const cinder::ivec2&) const;

private:
    cinder::ivec2 mFieldSize;
    cinder::ivec2 mMovingDirection;
    std::vector<cinder::ivec2> mSnakeBody;
    int mSnakeBodyPartSize;
    int mMovingSpeed;
};

#endif // SNAKE_H
