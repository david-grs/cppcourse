#pragma once

class Vector
{
public:
	Vector();

	Vector(double x, double y);

	double GetX() const{return mX;};
	double GetY() const{return mY;};

      	void Add(const Vector& v);

      	bool operator==(const Vector& v)const{return mX == v.mX && mY == v.mY;};

private:
	double mX;
	double mY;
};

