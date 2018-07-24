#include "vector.h"

Vector::Vector()
{
    mX = 0;
    mY = 0;
}

Vector::Vector(int x, int y)
{
    mX = x;
    mY = y;
}

int Vector::GetX()
{
    return mX;
}
    
int Vector::GetY()
{
    return mY;
}

void Vector::Add(Vector& vector)
{
    mX += vector.mX;
    mY += vector.mY;
}