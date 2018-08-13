#include "vector.h"

Vector::Vector(): Vector(0, 0){}

Vector::Vector(int x, int y):
	mX(x),
	mY(y)
{}

const int Vector::GetX()
{
	return mX;
}

const int Vector::GetY()
{
	return mY;
}

void Vector::Add(const Vector& vector)
{
	mX += vector.mX;
	mY += vector.mY;
}