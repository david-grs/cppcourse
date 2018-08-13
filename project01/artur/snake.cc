#include "snake.h"
#include <algorithm>

#include <iostream>

void Snake::ChangeDirection(Point dir)
{
  if(!((dir == Dir()) || (-dir == Dir())))
    {
      Snake::Move(dir);
    }
}

bool Snake::IsAlive()
{
  return !(CheckWallsCollision() || CheckSelfCollision());
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

void Snake::Move(Point dir)
{
  mBody.push_back(mBody.back() + Point(dir));
  mBody.erase(mBody.begin());
}

bool Snake::CheckWallsCollision()
{
  int x = mBody.back().GetX();
  int y = mBody.back().GetY();
  if(x<0 || x>15 || y<0 || y>15)
    {
      return true;
    }
  return false;
}

bool Snake::CheckSelfCollision()
{
  return std::find(mBody.begin(), mBody.end()-1, mBody.back()) != mBody.end()-1;
}
