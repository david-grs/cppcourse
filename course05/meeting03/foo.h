
#include <boost/optional.hpp>

class Order
{
public:
	Order(double price, double volume);

	double GetOrderValue();

//private:
	double VeryExpensiveCalculation() const;

	double mPrice;
	double mVolume;
	boost::optional<double> mOrderValue;
};

