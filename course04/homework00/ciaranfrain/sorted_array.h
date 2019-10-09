#pragma once

#include <deque>

class SortedArray
{
public:
	SortedArray(std::size_t maximumSize);
	
	void clear() { mStorage.clear(); }
	const int& operator[](int n) const { return Get(n); }

	bool empty() const { return mStorage.empty(); }
	std::size_t size() const { return mStorage.size(); }

	void Insert(int n);
	const int& Get(int index) const;

private:
	std::size_t mMaxSize = 0;
	std::deque<int> mStorage;
};
