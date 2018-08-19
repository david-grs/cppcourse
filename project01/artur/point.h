#pragma once
#include "direction.h"

class Point
{
 public:
  Point();
  Point(Direction);
  Point(int, int);
  Point(const Point&);
  int GetX() const;
  int GetY() const;
  Point operator+() const;
  Point operator-() const;
  Point operator+(const Point&) const;
  Point operator-(const Point&) const;
  bool operator==(const Point&) const;
  bool operator!=(const Point&) const;
 private:
  int mX;
  int mY;
};
