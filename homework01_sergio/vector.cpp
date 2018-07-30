#include "vector.h"

void Vector::Add(const Vector& v)
{
    mX=mX + v.mX;
    mY=mY + v.mY;
}

bool Vector::operator == (const Vector& v)
{
    return (mX == v.mX)
        && (mY == v.mY);
}

Vector Vector::operator + (const Vector& v)
{
    return Vector(mX+v.mX, mY+v.mY);
}

Vector Vector::operator += (const Vector& v)
{
    this->Add(v);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    os<<"Vector("<<v.mX<<","<<v.mY<<")";
    return os;
}
