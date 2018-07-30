#include <iostream>

class Vector
{
public:
    Vector(int x, int y)
        : mX(x)
        , mY(y)
    {}
    Vector(){}

    int GetX() const {return mX;}

    int GetY() const {return mY;}

    void Add (const Vector&);

    bool operator == (const Vector&);

    Vector operator + (const Vector&);

    Vector operator += (const Vector&);

    friend std::ostream& operator << (std::ostream&, const Vector&);

private:
    int mX{0};
    int mY{0};
};
