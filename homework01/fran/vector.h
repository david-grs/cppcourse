class Vector
{
public:
	Vector();
	Vector(int x, int y);
	
	bool operator==(const Vector& rhs) const
	{
		return mX == rhs.mX && mY == rhs.mY;
	}
	
	const int GetX();
	const int GetY();
	void Add(const Vector&);
	
private:
	int mX;
	int mY;
};