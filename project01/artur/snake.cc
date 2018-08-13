#include "snake.h"
#include <algorithm>

#include <iostream>

void Snake::ChangeDirection(const Point& dir)
{
  if(!(-dir == Dir()))
    {
      Snake::Move(dir);
    }
}

bool Snake::IsAlive(const Point& corner)
{
  return !(CheckWallsCollision(corner) || CheckSelfCollision());
}

Point Snake::Dir()
{
  return mBody.end()[-1] - mBody.end()[-2];
}

int Snake::Length()
{
  return mBody.size();
}

std::vector<Point> Snake::Body()
{
  return mBody;
}

void Snake::Move(const Point& dir)
{
  mBody.push_back(mBody.back() + Point(dir));
  mBody.erase(mBody.begin());
}

void Snake::Grow()
{
  mBody.insert(mBody.begin(),mBody.front());
}

bool Snake::CheckWallsCollision(const Point& corner)
{
  int x = mBody.back().GetX();
  int y = mBody.back().GetY();
  if(x<=0 || x>=corner.GetX() || y<=0 || y>=corner.GetY())
    {
      return true;
    }
  return false;
}

bool Snake::CheckSelfCollision()
{
  return std::find(mBody.begin(), mBody.end()-1, mBody.back()) != mBody.end()-1;
}
