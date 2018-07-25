#include "vector.h"

Vector::Vector()
{
	mX=0;
	mY=0;
}

Vector::Vector(double x, double y): mX(x), mY(y){}

double Vector::dotProduct(const Vector& vec) const
{
	return mX * vec.mX + mY * vec.mY ;
}

double Vector::GetX() const
{
	return mX;
}

double Vector::GetY() const
{
	return mY;
}

void Vector::Add(const Vector& v) 
{
	mX=mX + v.GetX();
	mY=mY + v.GetY();		
}

// Overload = operator.
void Vector::operator=(const Vector& v) 
{
	this->mX =v.GetX();
	this->mY =v.GetY();
}
// Overload == operator.
bool Vector::operator==(const Vector& v) 
{
	if (mX ==v.GetX() && mY == v.GetY());
	{
		return true;
	}
	return false;
}
