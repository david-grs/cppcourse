#include <iostream>

class Vector3
{
public:
	Vector3(double x, double y, double z)
		: mX(x), mY(y), mZ(z)
	{ }

	double dotProduct(const Vector3& vec) const
	{
		return mX * vec.mX + mY * vec.mY + mZ * vec.mZ;
	}
private:
	double mX;
	double mY;
	double mZ;
};

double foo(const Vector3& vec)
{
	Vector3 ref{1.0, 2.0, 0.5};
	return vec.dotProduct(ref);
}

int main(int argc, char** argv)
{
	int i = 0;
	std::cout << "hello, ";

	i = argc;
	std::cout << i << std::endl;
	return 0;
}
