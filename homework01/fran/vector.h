#include <iostream>

class Vector
{
public:
	Vector();
	Vector(int x, int y);
	
	bool operator==(const Vector& rhs) const
	{
		return mX == rhs.mX && mY == rhs.mY;
	}

	Vector operator+(const Vector& rhs) const
	{
		return Vector(mX + rhs.mX, mY + rhs.mY);
	}

	Vector& operator+=(const Vector& rhs)
	{
		mX += rhs.mX;
		mY += rhs.mY;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Vector& rhs)
	{
		stream << "x:" << rhs.mX << " y:" << rhs.mY;
		return stream;
	}

	const int GetX();
	const int GetY();
	void Add(const Vector&);
	
private:
	int mX;
	int mY;
};