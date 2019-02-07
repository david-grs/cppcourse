#pragma once

#include <array>
#include <cassert>

template<typename _Ty, std::size_t _Size>
class short_circular_buffer
{
public:
	short_circular_buffer();

	void push(const _Ty& value);
	void pop();

	_Ty& front();

	bool empty() const;
	bool full() const;

private:
	size_t next_index(std::size_t index) const;

	std::array<_Ty, _Size> mBuffer;

	std::size_t mBegin;
	std::size_t mEnd;
};

template<typename _Ty, std::size_t _Size>
short_circular_buffer<_Ty, _Size>::short_circular_buffer() :
	mBegin(0),
	mEnd(1)
{ }

template<typename _Ty, std::size_t _Size>
void short_circular_buffer<_Ty, _Size>::push(const _Ty& value)
{
	assert(!full());

	mBuffer[mEnd] = value;

	mEnd = next_index(mEnd);
}

template<typename _Ty, std::size_t _Size>
void short_circular_buffer<_Ty, _Size>::pop()
{
	assert(!empty());

	mBegin = next_index(mBegin);
}

template<typename _Ty, std::size_t _Size>
_Ty& short_circular_buffer<_Ty, _Size>::front()
{
	assert(!empty());

	return mBuffer[mBegin];
}

template<typename _Ty, std::size_t _Size>
bool short_circular_buffer<_Ty, _Size>::empty() const
{
	return mEnd == next_index(mBegin);
}

template<typename _Ty, std::size_t _Size>
bool short_circular_buffer<_Ty, _Size>::full() const
{
	return mEnd == mBegin;
}

template<typename _Ty, std::size_t _Size>
size_t short_circular_buffer<_Ty, _Size>::next_index(std::size_t index) const
{
	return (mBegin + 1) % _Size;
}