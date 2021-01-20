#include "uniqueptr.h"

UniquePtrInt make_unique_int(std::size_t n) { return UniquePtrInt(new int[n]); };

int* UniquePtrInt::release()
{
	int* tmp = mData;
	mData = nullptr;
	return tmp;
}

void UniquePtrInt::reset(int* newData)
{
	int* oldData = mData;
	mData = newData;
	if (oldData) delete oldData;
}

void UniquePtrInt::swap(UniquePtrInt& other)
{
	int* currentData = mData;
	mData = other.release();
	other.reset(currentData);
}
