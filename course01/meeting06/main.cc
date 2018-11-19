#include <iostream>
#include <utility>

template <class T, class Comparator = std::less<T>>
class Range
{
public:
	using value_type = T;

	Range(T min, T max) :
		mMin(min),
		mMax(max)
	{}

	bool Contains(const T&) const;

	const T& Min() const { return mMin; }
	const T& Max() const { return mMax; }

private:
	T mMin;
	T mMax;
};

template <typename T>
using InclRange = Range<T, std::less_equal<T>>;

template <typename T>
using ExclRange = Range<T, std::less<T>>;

template <class T, class Comparator>
bool Range<T, Comparator>::Contains(const T& t) const
{
	return Comparator()(mMin, t) && Comparator()(t, mMax);
}

template <class R>
typename R::value_type GetMean(const R& r)
{
	return (r.Min() + r.Max()) / 2.0;
}

template <class T>
Range<T> MakeRange(T min, T max)
{
	return Range<T>(min, max);
}


template <class T>
struct GetType {};

template <>
struct GetType<int>
{
	static std::string Name() { return "int"; }
};

template <class T>
struct GetType<T*>
{
	static std::string Name() { return "pointer to " + GetType<T>::Name(); }
};

int main()
{
	std::cout << GetType<int>::Name() << std::endl;
	std::cout << GetType<int*>::Name() << std::endl;


	using DRange = Range<double>;

	//std::cout << GetMean(r) << std::endl;

	InclRange<double> ir(2.0, 4.0);
	std::cout << std::boolalpha << ir.Contains(2.0) << std::endl;
	std::cout << std::boolalpha << ir.Contains(2.5) << std::endl;

	ExclRange<double> er(2.0, 4.0);
	std::cout << std::boolalpha << er.Contains(2.0) << std::endl;
	std::cout << std::boolalpha << er.Contains(2.5) << std::endl;
	//auto r2 = MakeRange(2.0, 4.0);
	//auto p = std::make_pair(5, "foo");

	return 0;
}

