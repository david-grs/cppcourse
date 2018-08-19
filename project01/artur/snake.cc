#include "snake.h"
#include <algorithm>

void Snake::ChangeDirection(const Point& dir)
{
  if(!(-dir == Dir()))
    {
      Snake::Move(dir);
    }
}

bool Snake::IsAlive(const Point& corner, const Walls& walls) const
{
  return !(CheckSelfCollision() ||
	   CheckOutsideWallsCollision(corner) ||
	   CheckWallsCollision(walls));
}

Point Snake::Dir() const
{
  return mBody.end()[-1] - mBody.end()[-2];
}

int Snake::Length() const
{
  return mBody.size();
}

std::vector<Point> Snake::Body() const
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

bool Snake::CheckOutsideWallsCollision(const Point& corner) const
{
  int x = mBody.back().GetX();
  int y = mBody.back().GetY();
  if(x<=0 || x>=corner.GetX() || y<=0 || y>=corner.GetY())
    {
      return true;
    }
  return false;
}

bool Snake::CheckSelfCollision() const
{
  return std::find(mBody.begin(), mBody.end()-1, mBody.back()) != mBody.end()-1;
}

bool Snake::CheckWallsCollision(const Walls& walls) const
{
  for(size_t i = 0; i < walls.Body().size(); ++i)
    {
      if(std::find(mBody.begin(), mBody.end(), walls.Body().at(i)) != mBody.end())
	{
	  return true;
	}
    }
  return false;
}
