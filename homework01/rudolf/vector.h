#pragma once

#include <iostream>

class Vector
{
public:
	Vector();

	Vector(double x, double y);

	double GetX() const{return mX;};
	double GetY() const{return mY;};

      	void Add(const Vector& v);

      	bool operator==(const Vector& v)const{return mX == v.mX && mY == v.mY;};

	Vector operator+(const Vector& v){return Vector(mX+v.mX,mY+ v.mY);};

	Vector& operator+=(const Vector& v){this->Add(v);return *this;};

	friend std::ostream& operator<<(std::ostream& os,const Vector& v);
private:
	double mX;
	double mY;
};

