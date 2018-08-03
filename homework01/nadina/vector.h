#include <iostream>

class Vector
{
public:
    Vector() : Vector(0, 0)
    {}

    Vector(int x, int y) :
        mX(x),
        mY(y)
    {}

    int GetX() const
    {
        return mX;
    }

    int GetY() const
    {
        return mY;
    }

    bool operator==(const Vector& other) const
    {
        return other.GetX() == mX && other.GetY() == mY;
    }

    Vector operator+(const Vector& other) const
    {
        return Vector(other.GetX() + mX, other.GetY() + mY);
    }

    Vector operator+=(const Vector& other) const
    {
        return Vector(other.GetX() + mX, other.GetY() + mY);
    }

    void Add(const Vector&);

private:
    int mX;
    int mY;
};

std::ostream& operator<<(std::ostream&, const Vector&);
