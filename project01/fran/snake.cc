#include "snake.h"

Snake::Snake()
{
    std::random_device rd;
    std::mt19937 mEng(rd());
}

void Snake::Update(const cinder::vec2& offset)
{
    mSegments[0].Update(mSegments[0].GetPosition() + offset);
}

void Snake::Draw()
{
    for(auto& segment : mSegments)
    {
        segment.Draw();
    }
}

void Snake::SetDirection()
{}

void Snake::SetInitialPosition(float width, float height)
{
    std::uniform_int_distribution<> randX(mRadius, width - mRadius);
    std::uniform_int_distribution<> randY(mRadius, height - mRadius);

    mSegments.push_back(Segment(cinder::vec2(randX(mEng), randY(mEng)), mRadius));
}