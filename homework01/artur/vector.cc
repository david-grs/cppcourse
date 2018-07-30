#include "vector.h"

Vector::Vector()
{
}

Vector::Vector(const int x, const int y)
{
  mX = x;
  mY = y;
}

Vector::Vector(const Vector& other)
{
  mX = other.GetX();
  mY = other.GetY();
}

const int Vector::GetX() const
{
  return mX;
}

const int Vector::GetY() const
{
  return mY;
}

const bool Vector::operator==(const Vector& other)
{
  return (mX == other.GetX()) && (mY == other.GetY());
}

const Vector Vector::operator+(const Vector& other)
{
  return Vector(mX + other.GetX(), mY + other.GetY());
}

Vector& Vector::operator+=(const Vector& other)
{
  Add(other);
  return *this;
}

void Vector::Add(const Vector& other)
{
  mX += other.GetX();
  mY += other.GetY();
}

std::ostream& operator<<(std::ostream& os, const Vector& vector)
{
  os << '(' << vector.GetX() << ',' << vector.GetY() << ')';
  return os;
}
