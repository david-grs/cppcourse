#include <stdexcept>
#include <limits>
#include <type_traits>
#include <iomanip>
#include <iostream>

template <class T, class ComparatorLower, class ComparatorUpper>
class Range
{
public:
	static_assert(std::is_arithmetic_v<T>, "T is not an arithmetic");

	using value_type = T;
	using difference_type = T;

	Range() =default;

	Range(T min, T max) :
		mMin(min),
		mMax(max)
	{
		if (mMin > mMax)
		{
			throw std::runtime_error("range");
		}
	}

	bool Contains(T value) const;

	T Min() const { return mMin; }
	T Max() const { return mMax; }

private:
	T mMin = std::numeric_limits<T>::min();
	T mMax = std::numeric_limits<T>::max();
};

template <class T>
using InclRange = Range<T, std::greater_equal<T>, std::less<T>>;

template <class T, class ComparatorLower, class ComparatorUpper>
bool Range<T, ComparatorLower, ComparatorUpper>::Contains(T value) const
{
	return ComparatorLower{}(value, mMin) && ComparatorUpper{}(value, mMax);//value >= mMin && value < mMax;
}


template <class RangeT>
typename RangeT::difference_type distance(RangeT r)
{
	return r.Max() - r.Min();
}

int main()
{
	Range<int> r{1,5};
	std::cout << std::boolalpha << r.Contains(1) << std::endl;
	std::cout << std::boolalpha << r.Contains(2) << std::endl;
	std::cout << std::boolalpha << r.Contains(5) << std::endl;
	return 0;
}
