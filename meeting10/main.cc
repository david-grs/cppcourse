#include <iostream>
#include <cstdint>

bool boom = false;

struct A
{
	A() =default;
	A& operator=(const A&)
	{
		if (boom)
		{
			throw std::runtime_error("boom");
		}
		return *this;
	}
};

template <class T>
class Vector
{
public:
	using value_type = T;

	Vector(std::size_t count, const T& value = T{}) :
		mCapacity(count),
		mSize(count)
	{
		try
		{
			mData = new T[count];

			for (std::size_t i = 0; i < mSize; ++i)
			{
				mData[i] = value;
			}
		}
		catch(const std::exception&)
		{
			delete[] mData;
			//mData = nullptr;
		}
	}

	~Vector()
	{
		delete[] mData;
	}

	Vector& operator=(const Vector& v)
	{
		delete[] mData;

		mCapacity = v.mCapacity;
		mData = new T[mCapacity];

		for (std::size_t i = 0; i < v.mSize; ++i)
		{
			mData[i] = v.mData[i];
		}

		return *this;
	}

private:
	std::size_t mCapacity;
	std::size_t mSize;
	T* mData;
};


int main()
{
	boom = true;

	try
	{
		Vector<A> v(10);
	}
	catch(...) {}
}


