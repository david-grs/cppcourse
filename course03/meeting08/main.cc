#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include <unordered_map>

using namespace std::string_literals;

struct A
{
	explicit A(std::string s) : mName(s) {}

	bool operator<(const A& rhs) const
	{
		return mName < rhs.mName;
	}

	std::string mName;
};

int main()
{
	std::map<A, B> m;


	// INSERT ONLY
	const bool inserted = m.emplace("foo", 3).second;


	// UPSERT
	auto& r = m[A{"foo"}];
	r.foo = 12;
	m.emplace("foo", 3);

	// UPDATE ONLY
	auto it = m.find(A{"foo"});
	if (it != m.cend())
	{
		it->second.foo = 12;
	}

	std::cout << m[A{"foo"}] << std::endl;

	//std::unordered_map<A, int> m;





	//const std::vector<std::string> args{argv, argv + argc};
	/*
	 * const int foo = std::count_if(argv, argv + argc,
			[](const char* str) { return !std::strcmp(str, "foo"); });

	std::cout << "found " << foo << " foo" << std::endl;
	*/




	return 0;
}
