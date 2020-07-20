// Some copyright 2020
#pragma once

#include <memory>

namespace cppcourse {

template<class T>
class list
{

public:

	class node
	{
	public:

		explicit node(const T& value) :
			mValue(value)
		{}

		~node() = default;

		T mValue;
		std::unique_ptr<node> mNextNode;
	};

	struct iter
	{
		node* mPositionPtr;

		iter(node* position) :
			mPositionPtr(position)
		{}

		bool operator!=(const list<T>::iter& rhs) const
		{
			return !(*this == rhs);
		}

		bool operator==(const list<T>::iter& rhs) const
		{
			return mPositionPtr == rhs.mPositionPtr;
		}

		iter& operator++()
		{
			mPositionPtr = mPositionPtr->mNextNode.get();
			return *this;
		}

		iter operator++(int)
		{
			iter it = mPositionPtr;
			mPositionPtr = mPositionPtr->mNextNode.get();
			return it;
		}

		T& operator*() const
		{
			return mPositionPtr->mValue;
		}
	};

	struct const_iter
	{
		node* mPositionPtr;

		const_iter(node* position) :
			mPositionPtr(position)
		{}

		bool operator!=(const list<T>::const_iter& rhs) const
		{
			return !(*this == rhs);
		}

		bool operator==(const list<T>::const_iter& rhs) const
		{
			return mPositionPtr == rhs.mPositionPtr;
		}

		const_iter& operator++()
		{
			mPositionPtr = mPositionPtr->mNextNode.get();
			return *this;
		}

		const_iter operator++(int)
		{
			const_iter it = mPositionPtr;
			mPositionPtr = mPositionPtr->mNextNode.get();
			return it;
		}

		const T& operator*() const
		{
			return mPositionPtr->mValue;
		}
	};


	list() = default;

	list(const list& list_)
	{
		for (auto c: list_)
			push_back(c);
	}

	list(list&& list_)
	{
		mFirstNode = std::move(list_.mFirstNode);
		mSize = list_.mSize;
		list_.mSize = 0;
	}

	~list() = default;


	std::size_t size() const { return mSize; }

	void push_back(const T& value)
	{
		if (mFirstNode == nullptr)
		{
			mFirstNode = std::make_unique<node>(value);
			mLastNode = mFirstNode.get();
		}
		else
		{
			mLastNode->mNextNode = std::make_unique<node>(value);
			mLastNode = mLastNode->mNextNode.get();
		}
		++mSize;
	}

	iter erase(const iter& pos)
	{
		if (pos.mPositionPtr == mFirstNode.get())
		{
			if (mFirstNode->mNextNode)
			mFirstNode = std::move(mFirstNode->mNextNode);
			--mSize;
			return mFirstNode.get();
		}

		auto currentNodeIt = begin();
		auto previousNodeIt = currentNodeIt++;
		while (currentNodeIt != end())
		{
			if (currentNodeIt.mPositionPtr == pos.mPositionPtr)
			{
				--mSize;

				if (currentNodeIt.mPositionPtr->mNextNode)
				{
					previousNodeIt.mPositionPtr->mNextNode = std::move(currentNodeIt.mPositionPtr->mNextNode);
					return iter(previousNodeIt.mPositionPtr->mNextNode.get());
				}
				else
				{
					delete previousNodeIt.mPositionPtr->mNextNode.release();
					return iter(nullptr);
				}
			}
			previousNodeIt = currentNodeIt++;
		}

		return end();
	}

	iter begin()
	{
		return iter(mFirstNode.get());
	}

	iter end()
	{
		return iter(nullptr);
	}

	const_iter begin() const
	{
		return const_iter(mFirstNode.get());
	}

	const_iter end() const
	{
		return const_iter(nullptr);
	}

private:

	std::size_t mSize = 0;
	std::unique_ptr<node> mFirstNode;
	node* mLastNode = nullptr;

};

}

