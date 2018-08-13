#include "vector.h"

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    return os << "Vector(x = " << v.GetX() << ", y = " << v.GetY() << ")";
}

void Vector::Add(const Vector& other)
{
    mX += other.GetX();
    mY += other.GetY();
}
