#include "vector.h"

Vector::Vector():
	Vector(0,0)
{}

Vector::Vector(double x, double y): 
	mX(x), 
	mY(y)
{}

void Vector::Add(const Vector& v) 
{
	mX=mX + v.GetX();
	mY=mY + v.GetY();		
}
std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    os<< " Vector(" << v.GetX() <<"," << v.GetY()  <<")";
    return os;
};

