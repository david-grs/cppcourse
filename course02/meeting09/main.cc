#include <map>
#include <string>
#include <iostream>

void* operator new(std::size_t n)
{
	std::cout << "malloc " << n << std::endl;
	return malloc(n);
}

struct Order
{
	Order() { std::cout << "Order()" << std::endl; }
	Order(const std::string& id, double price, int volume)
	 : mID(id), mPrice(price), mVolume(volume)
	{
		std::cout << "Order(...)" << std::endl;
	}
	Order(std::string&& id, double price, int volume)
	 : mID(std::move(id)), mPrice(price), mVolume(volume)
	{
		std::cout << "Order(... temp)" << std::endl;
	}
	Order(const Order& order) : mID(order.mID), mPrice(order.mPrice), mVolume(order.mVolume)
	{
		std::cout << "Order(const Order&)" << std::endl;
	}
	Order& operator=(const Order& order)
	{
		mID = order.mID;
		mPrice = order.mPrice;
		mVolume = order.mVolume;
		std::cout << "Order operator=(const Order&)" << std::endl;
		return *this;
	}
	Order(Order&& order) : mID(std::move(order.mID)), mPrice(order.mPrice), mVolume(order.mVolume)
	{
		std::cout << "Order(Order&&)" << std::endl;
	}
	Order& operator=(Order&& order)
	{
		mID = std::move(order.mID);
		mPrice = order.mPrice;
		mVolume = order.mVolume;
		std::cout << "Order operator=(Order&&)" << std::endl;
		return *this;
	}

	std::string mID;
	double mPrice;
	int mVolume;
};

class OrderStore
{
public:
	void Add(const Order& order)
	{
		mOrders[order.mID] = order;
	}

	void Add(const std::string& id, double price, int volume)
	{
		const bool inserted = mOrders.emplace(id, Order{id, price, volume}).second;
		if (!inserted) throw 42;
	}

	void Add(std::string&& id, double price, int volume)
	{
		std::cout << "&&" << std::endl;
		const bool inserted = mOrders.emplace(id, Order{id, price, volume}).second;
		if (!inserted) throw 42;
	}

	std::map<std::string, Order> mOrders;
};


/*
int main()
{
	OrderStore store;

	//const Order order{"foofoofoofoofoofoofoofoofoofoofoofoofoo", 10.5, 100};
	//store.Add(order);

	store.Add("foofoofoofoofoofoofoofoofoofoofoofoofoo", 10.5, 100);

	return 0;
}
*/

void Print(int i)
{
	std::cout << i << std::endl;
}
void Print(std::string&& s) { std::cout << "string&&" << std::endl; }
void Print(const std::string& s) { std::cout << "const string&" << std::endl; }

void Print(std::string& s, int i) { std::cout << s << std::endl; }
void Print(std::string& s, int& i) { std::cout << s << std::endl; }

template <class T>
void Proxy(T&& t)
{
	Print(std::forward<T>(t));
}

int main()
{
	std::string s = "foo";
	Proxy(s);
}

