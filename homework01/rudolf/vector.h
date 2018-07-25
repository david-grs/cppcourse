#ifndef __VECTOR_H_INCLUDED__   // if x.h hasn't been included yet...
#define __VECTOR_H_INCLUDED__   //   #define this so the compiler knows it has been included

#include <iostream>

class Vector
{
public:
	Vector();

	Vector(double x, double y);

	double dotProduct(const Vector& vec) const;

	double GetX() const;
	double GetY() const;

      	void Add(const Vector& v);

      	// Overload = operator.
      	void operator=(const Vector& v);
	// Overload == operator.
      	bool operator==(const Vector& v);

private:
	double mX;
	double mY;
};

#endif  

