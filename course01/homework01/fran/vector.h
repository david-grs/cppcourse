
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

	Vector& operator+=(const Vector& rhs);

	int GetX() const;
	int GetY() const;
	void Add(const Vector&);
	
private:
	int mX;
	int mY;
};

