#include <map>
#include <unordered_map>
#include <iostream>
#include <string>

struct A
{
	bool operator<(const A& other)
	{
		return std::tie(i, j, k) < std::tie(other.i, other.j, other.k);
	}

	int i;
	int j;
	int k;
};

int main()
{

	std::deque<A> instruments;
	instruments.push_back(...);

	A& newInstrument = instruments.back();

	Common::vector_map;

	std::map<std::string, int> m;
	m.emplace("foo", 5);

	const bool inserted = m.emplace("foo", 6).second;
	std::cout << std::boolalpha << inserted  << std::endl;

	std::cout << m.size() << std::endl;

	auto it = m.find("foo");
	if (it != m.cend())
	{
		it->second = 6;
	}
	else
	{
		throw;
	}

	m["foo"] = 6;
	m["bar"] = 7;

	return 0;
}
