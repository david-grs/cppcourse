#pragma once

#include <array>
#include <cassert>

template<typename _Ty, std::size_t _Size>
class short_circular_buffer
{
public:
	short_circular_buffer() :
		mBegin(0),
		mEnd(1)
	{ }

	void push(const _Ty& value)
	{
		assert(!full());

		mBuffer[mEnd] = value;
		mEnd = next_index(mEnd);
	}

	void pop()
	{
		assert(!empty());

		mBegin = next_index(mBegin);
	}

	_Ty& front()
	{
		assert(!empty());

		return mBuffer[mBegin];
	}

	bool empty() const
	{
		return mEnd == next_index(mBegin);
	}

	bool full() const
	{
		return mEnd == mBegin;
	}


private:
	size_t next_index(std::size_t index) const
	{
		return (mBegin + 1) % _Size;
	}

	std::array<_Ty, _Size> mBuffer;

	std::size_t mBegin;
	std::size_t mEnd;
};