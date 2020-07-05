#include <string>

#include "linked_list.h"

LinkedList::LinkedList(const LinkedList& from)
{
	std::unique_ptr<Link>* outputLink = &mFront;

	for(const auto& item : from)
	{
		outputLink->reset(new Link { item, {} });
		outputLink = &(outputLink->get()->mNext);
	}
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
	std::unique_ptr<Link> newLink{new Link { str, {} }};

	newLink->mNext = std::move(mFront);
	mFront = std::move(newLink);
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

std::unique_ptr<LinkedList::Link>* LinkedList::find_link(LinkedList::size_type index)
{
	std::unique_ptr<Link>* link = &mFront;

	for(; index>0; index--)
	{
		link = &(*link)->mNext;
	}

	return link;
}

void LinkedList::insert_at(LinkedList::size_type index, const std::string& str)
{
	auto link = find_link(index);
	(*link).reset(new Link { str, std::move(*link) });
}
