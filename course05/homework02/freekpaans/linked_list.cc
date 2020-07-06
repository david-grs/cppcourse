#include <string>
#include <numeric>

#include "linked_list.h"

static void push_at(LinkedList::LinkPtr& link, const std::string& str)
{
	LinkedList::LinkPtr newLink{new LinkedList::Link { str, {} }};

	newLink->mNext = std::move(link);
	link = std::move(newLink);
}

LinkedList::LinkedList(const LinkedList& from)
{
	std::accumulate(
		from.begin(), from.end(),
		std::ref(mFront),
		[](LinkPtr& output, const std::string& item) -> LinkPtr&
		{
			push_at(output, item);

			return output->mNext;
		});
}

LinkedList& LinkedList::operator=(const LinkedList& from)
{
	LinkedList copy{from};
	mFront = std::move(copy.mFront);
	return *this;
}

LinkedList::size_type LinkedList::size() const
{
	return std::distance(begin(), end());
}

void LinkedList::push_front(const std::string& str)
{
	push_at(mFront, str);
}

void LinkedList::pop_front()
{
	mFront = std::move(mFront->mNext);
}

const std::string& LinkedList::front() const
{
	return mFront->mValue;
}

const std::string& LinkedList::at(size_type index) const
{
	return *std::next(begin(), index);
}

static LinkedList::LinkPtr& find_link(LinkedList::LinkPtr& from, LinkedList::size_type index)
{
	LinkedList::LinkPtr* link = &from;

	while(index-- > 0)
	{
		link = &link->get()->mNext;
	}

	return *link;
}

void LinkedList::insert_at(LinkedList::size_type index, const std::string& str)
{
	push_at(find_link(mFront, index), str);
}
