#include "point.h"

Point::Point(Direction dir)
{
  switch(dir)
  {
  case -2:
    mX = -1;
    mY = 0;
    break;
  case -1:
    mX = 0;
    mY = -1;
    break;
  case 1:
    mX = 0;
    mY = 1;
    break;
  case 2:
    mX = 1;
    mY = 0;
    break;    
  }
}

Point::Point()
{
}

Point::Point(int x, int y)
  : mX(x)
  , mY(y)
{
}

Point::Point(const Point& other)
  : mX(other.GetX())
  , mY(other.GetY())
{
}

int Point::GetX() const
{
  return mX;
}

int Point::GetY() const
{
  return mY;
}

Point Point::operator+() const
{
  return Point(mX, mY);
}

Point Point::operator-() const
{
  return Point(-mX, -mY);
}

Point Point::operator+(const Point& other) const
{
  return Point(mX + other.GetX(), mY + other.GetY());
}

Point Point::operator-(const Point& other) const
{
  return Point(mX - other.GetX(), mY - other.GetY());
}

bool Point::operator==(const Point& other) const
{
  return mX == other.GetX() && mY == other.GetY();
}
