#include <iostream>
#include <chrono>
#include <memory>
#include <vector>
#include <forward_list>
#include <map>
#include <string>

struct Order
{
	Volume volume;
	Price price;
	std::string s;
};

int main()
{
	std::unordered_map<InstrumentId, Book> books;
	// books[id] = newBook;

	std::map<int, Order> m;
	m[5].s = "foo";

	Order& order = ...;

	// 1. INSERT
	const bool inserted = m.emplace(5, Order{1, 2.0, "bar"}).second;
	//THROW_IF(!inserted, "..");

	// 2. UPDATE
	auto it = m.find(5);
	//THROW_IF(it == m.cend(), "...");
	it->second.s = "bar";

	// 3. UPSERT
	m[5] = Order{1, 2., "foo"};



	return 0;
}

/*
int main()
{
	std::forward_list<int> l;

	static const int IterationsCount = 10000;

	auto startTs = std::chrono::steady_clock::now();
	for (int i = 0; i < IterationsCount; ++i)
		l.push_front(5);
	auto endTs = std::chrono::steady_clock::now();

	std::cout << "heap: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTs - startTs).count () / (double)IterationsCount << "ns/iter" << std::endl;

	std::vector<int> v;
	v.reserve(IterationsCount);

	startTs = std::chrono::steady_clock::now();
	for (int i = 0; i < IterationsCount; ++i)
		v.push_back(5);
	endTs = std::chrono::steady_clock::now();

	std::cout << "stack: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTs - startTs).count () / (double)IterationsCount  << "ns/iter" << std::endl;

	return 0;
}
*/
