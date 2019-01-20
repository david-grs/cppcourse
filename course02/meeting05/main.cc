#include <iostream>
#include <cassert>
#include <limits>
#include <type_traits>
#include <string>


template <class T>
struct is_integral
{
	static const bool value = false;
};

template <>
struct is_integral<int>
{
	static const bool value = true;
};

template <class T, class Comparator = std::less<T>>
class Range
{
public:
	static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value,
				  "T must be an integer type");

	using value_type = T;
	using range_compare = Comparator;

	Range() =default;
	Range(T min, T max);

	T GetMin() const { return mMin; }
	T GetMax() const { return mMax; }

	template <class F>
	bool Contains(T) const;

private:
	T mMin = std::numeric_limits<T>::lowest();
	T mMax = std::numeric_limits<T>::max();
};

template <class T, class Comparator>
Range<T, Comparator>::Range(T min, T max) :
	mMin(min),
	mMax(max)
{}

template <class T, class Comparator>
template <class F>
bool Range<T, Comparator>::Contains(T value) const
{
	Comparator comp;
	return comp(mMin, value) && !comp(mMax, value);
}

template <class T>
using ExclusiveRange = Range<T>;

template <class T, class Comparator>
std::ostream& operator<<(std::ostream& stream, const Range<T, Comparator>& range)
{
	return stream << range.GetMin() << "-" << range.GetMax();
}


template <class T>
struct GetType
{
	static std::string GetName() { return "???"; }
};

template <>
struct GetType<int>
{
	static std::string GetName() { return "int"; }
};

template <class T>
struct GetType<T*>
{
	static std::string GetName() { return "pointer to " + GetType<T>::GetName(); }
};


int main()
{
	Range<int> r{1,4};
	std::cout << r << std::endl;

	std::cout << GetType<double*>::GetName() << std::endl;
	return 0;
}


#if 0


template <class Container>
const typename Container::value_type& at(const Container& container,
										 std::size_t position)
{
	assert(position < container.size());

	auto it = container.cbegin();
	for (std::size_t i = 0; i < position; ++i)
		++it;

	return *it;
}

template <class T>
const T& at(const std::vector<T>& container, std::size_t position)
{
	assert(position < container.size());
	return container[position];
}

#endif
