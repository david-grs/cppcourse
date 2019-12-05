#include <iostream>
#include <optional>
#include <type_traits>

template <class T>
class Less
{
public:
	bool operator()(const T& t, const T& u) const
	{
		return t < u;
	}
};

// traits
template <class T> struct IsArithmetic { static constexpr bool value = false; };
template <> struct IsArithmetic<int> { static constexpr bool value = true; };

template <class T, class Comparator> // policy
class Range
{
public:
	static_assert(IsArithmetic<T>::value, "T needs to be an arithmetic type");

	Range() =default;
	Range(const T& min, const T& max);

	bool Contains(const T&) const;

private:
	T mMin = {};
	T mMax = {};
};

template <class T, class Comparator>
Range<T, Comparator>::Range(const T& min, const T& max) :
	mMin{min}, mMax{max}
{}

template <class T, class Comparator>
bool Range<T, Comparator>::Contains(const T& value) const
{
	return Comparator{}(mMin, value) && Comparator{}(value, mMax);
}

template <class T>
using ExclusiveRange = Range<T, Less<T>>;

template <class T>
using InclusiveRange = Range<T, std::less_equal<T>>;

int main()
{
	InclusiveRange<int> r(2, 5);
	std::cout << std::boolalpha << r.Contains(2) << std::endl;
	std::cout << std::boolalpha << r.Contains(3) << std::endl;
	std::cout << std::boolalpha << r.Contains(5) << std::endl;
	return 0;
}
