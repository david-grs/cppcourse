class Vector
{
public:
    Vector()
    {
        x = 0;
        y = 0;
    }

    Vector(int xx, int yy)
    {
        x = xx;
        y = yy;
    }

    int GetX() const
    {
        return x;
    }

    int GetY() const
    {
        return y;
    }

    bool operator==(const Vector& other) const
    {
        return other.x == x && other.y == y;
    }

    Vector Add(const Vector& other)
    {
        return Vector(other.GetX() + x, other.GetY() + y);
    }

private:
    int x;
    int y;
};
