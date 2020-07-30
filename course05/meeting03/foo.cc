#include "foo.h"


Order::Order(double price, double volume) :
	mPrice{price},
	mVolume{volume}
{}

double Order::GetOrderValue()
{
	if (!mOrderValue)
	{
		mOrderValue = VeryExpensiveCalculation();
	}
	return mOrderValue.get();
}

inline double Order::VeryExpensiveCalculation() const
{
	return mPrice * mVolume * 0.1234;
}

