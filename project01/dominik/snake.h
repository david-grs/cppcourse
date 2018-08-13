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

    cinder::ivec2 GetHead() const { return mSnakeBody[0]; }
    int GetSize() const { return mSnakeBodyPartSize; }
    std::vector<cinder::ivec2> GetBody() const { return mSnakeBody; }

    bool HeadClashedWithBody() const;
    bool HeadOutsideField() const;
    bool ObjectClashedWithBody(const cinder::ivec2&) const;
    int DistanceHeadToVector(const cinder::ivec2&) const;

private:
    cinder::ivec2 mFieldSize;
    cinder::ivec2 mMovingDirection;
    std::vector<cinder::ivec2> mSnakeBody;
    int mSnakeBodyPartSize;
};

#endif // SNAKE_H
