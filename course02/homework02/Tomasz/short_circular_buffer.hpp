#pragma once

#include <array>
#include <cassert>

template<typename _Ty, std::size_t _Size>
class short_circular_buffer
{
public:
	short_circular_buffer() :
		mBegin(0),
		mSize(0)
	{ }

	void push(const _Ty& value)
	{
		assert(!full());

		mBuffer[crop_index(mBegin + mSize)] = value;
		mSize++;
	}

	void pop()
	{
		assert(!empty());

		mBegin = crop_index(mBegin + 1);
		mSize--;
	}

	_Ty& front()
	{
		assert(!empty());

		return mBuffer[mBegin];
	}

	bool empty() const
	{
		return mSize == 0;
	}

	bool full() const
	{
		return mSize == _Size;
	}

private:
	size_t crop_index(std::size_t index) const
	{
		return index % _Size;
	}

	std::array<_Ty, _Size> mBuffer;

	std::size_t mBegin;
	std::size_t mSize;
};