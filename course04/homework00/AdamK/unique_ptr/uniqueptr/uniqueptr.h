#pragma once

#include <iostream>

class UniquePtrInt
{
public:
	UniquePtrInt() = default;
	explicit UniquePtrInt(int* data) { mData = data; }
	~UniquePtrInt() { if (this) delete mData; }

	UniquePtrInt& operator=(UniquePtrInt&& r) { reset(r.release()); return *this; }
	int* release();
	void reset(int*);
	void swap(UniquePtrInt& other);

	int* get() const { return mData; }
	operator bool() const { return mData != nullptr; }
	int operator [](std::size_t i) const { return mData[i]; }
	int& operator [](std::size_t i) { return mData[i]; }

private:
	int* mData = nullptr;	
};

UniquePtrInt make_unique_int(std::size_t n);
