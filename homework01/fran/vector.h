class Vector
{
    public:
	Vector();
	Vector(int x, int y);
	
	bool operator==(const Vector& rhs) const
    {
        return mX == rhs.mX && mY == rhs.mY;
    }
	
	int GetX();
	int GetY();
	void Add(Vector&);
	
	private:
	int mX;
	int mY;
};
