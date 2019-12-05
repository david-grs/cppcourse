#include "min.h"

namespace Internal
{

// Generic programming
// T should be comparable "named requirement" -> Concept TS C++20
template <class T>
T Min(T x, T y)
{
	return y < x ? y : x;
}

}

int Min(int x, int y)
{
	return Internal::Min(x, y);
}

double Min(double x, double y)
{
	return Internal::Min(x, y);
}

template <typename LessThanComparable>
LessThanComparable Max(LessThanComparable x, LessThanComparable y)
{
	return y < x ? x : y;
}

template int Max(int, int);
