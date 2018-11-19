#include "vector.h"
  
Vector::Vector(): 
	Vector(0, 0)
{}

Vector::Vector(int x, int y):
	mX(x),
	mY(y)
{}

Vector& Vector::operator+=(const Vector& rhs)
	{
		mX += rhs.mX;
		mY += rhs.mY;
		return *this;
	}

int Vector::GetX() const
{
	return mX;
}

int Vector::GetY() const
{
	return mY;
}

void Vector::Add(const Vector& vector)
{
	mX += vector.mX;
	mY += vector.mY;
}