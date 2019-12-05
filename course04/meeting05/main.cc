#include <iostream>
#include <memory>

class Vector
{
public:
	Vector() =default;

	void push_back(int);

	int operator[](std::size_t i) const { return mData[i]; }
	std::size_t size() const { return mSize; }

private:
	void grow();

	std::size_t mSize = 0;
	std::size_t mCapacity = 0;
	std::unique_ptr<int[]> mData;
};

void Vector::grow()
{
	const std::size_t newCapacity = mCapacity * 2 + 1;
	auto newData = std::make_unique<int[]>(newCapacity);

	std::copy(mData.get(), mData.get() + mSize, newData.get());

	mCapacity = newCapacity;
	mData = newData;
}

void Vector::push_back(int value)
{
	if (mSize == mCapacity)
	{
		grow();
	}

	mData[mSize] = value;
	mSize += 1;
}

/*
class A
{
public:
	A(int) {}
	int mI;
};


int main()
{
	// RAII!
	std::unique_ptr<A> pa = std::make_unique<A>(6);
	foo(pa);

	std::cout << pa->mI << std::endl;

	return 0;
}
*/
