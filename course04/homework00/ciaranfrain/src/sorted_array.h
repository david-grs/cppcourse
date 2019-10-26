#pragma once

#include <vector>

class SortedArray
{
public:
	explicit SortedArray(std::size_t maximumSize);
	
	void clear() { mStorage.clear(); }
	int operator[](int n) const { return mStorage[n]; }

	bool empty() const { return mStorage.empty(); }
	std::size_t size() const { return mStorage.size(); }

	void Insert(int n);

private:
	std::size_t mMaxSize = 0;
	std::vector<int> mStorage;
};
