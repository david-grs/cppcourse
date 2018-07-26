class Vector {
public:

    Vector(int x, int y)
        : mX(x)
        , mY(y)
    {}

    int GetX() const {
        return mX;
    }

    int GetY() const {
        return mY;
    }

    void Add(const Vector& newVector) {
        mX += newVector.mX;
        mY += newVector.mY;
    }

    bool operator==(Vector newVector) {
        return (mX == newVector.mX)
               && (mY == newVector.mY);
    }

private:
    int mX{0};
    int mY{0};
};
