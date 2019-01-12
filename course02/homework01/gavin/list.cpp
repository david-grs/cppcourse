#include <memory>

#include <memory>

#include "list.h"

void List::clear() {
    std::unique_ptr<Element> newList;
    mFirst = std::move(newList);
    mSize = 0;
}

void List::insert(std::size_t pos, int data)
{
    if(pos == 0)
    {
        push_front(data);
        return;
    }
    if(pos == size())
    {
        push_back(data);
        return;
    }
    auto new_element = std::make_shared<Element>(data);
    auto next = at(pos);
    auto prev = next->mPrevious;
    prev.lock()->mNext = new_element;
    next->mPrevious = new_element;
    new_element->mNext = next;
    new_element->mPrevious = prev;

    mSize++;
}

std::shared_ptr<Element> List::at(std::size_t pos) const
{
    if(pos >= size())
        throw std::out_of_range("Index out of range");

    auto iter = mFirst;
    for(std::size_t j=0; j < pos; j++)
    {
        iter = iter->mNext;
    }
    return iter;
}

void List::erase(std::size_t pos)
{
    if(pos == 0)
    {
        pop_front();
        return;
    }
    if(pos == size()-1)
    {
        pop_back();
        return;
    }
    auto item = at(pos);
    auto prev = item->mPrevious;
    auto next = item->mNext;
    prev.lock()->mNext = next;
    next->mPrevious = prev;
    mSize--;
}

void List::push_back(int data)
{
    auto new_element = std::make_shared<Element>(data);
    if(!mHead)
    {
        mHead = new_element;
        mSize++;
    }
    mHead->mNext = new_element;
    new_element->mPrevious = mHead;
    mHead = new_element;
    mSize++;
}

void List::pop_back()
{
    if(!mHead)
        throw std::runtime_error("Cannot pop from empty list");
    auto prev = mHead->mPrevious;
    mHead = prev.lock();
    mSize--;
}

std::size_t List::size() const
{
    return mSize;
}

void List::push_front(int data)
{
    std::shared_ptr<Element> new_element = std::make_shared<Element>(data);
    if(mFirst)
    {
        new_element->mNext = mFirst;
        mFirst->mPrevious = new_element;
        mFirst = new_element;
    }else
    {
        mFirst = new_element;
        mHead = mFirst;
    }
    mSize++;
}

void List::pop_front()
{
    if(size() == 0)
        throw std::out_of_range("cannot pop from an empty list");
    auto new_front = mFirst->mNext;
    new_front->mPrevious.reset();
    mFirst = new_front;
    mSize--;
}

int& List::get(std::size_t pos)
{
    return at(pos)->mData;
}

int List::get(std::size_t pos) const
{
    return at(pos)->mData;
}

List::List(std::initializer_list<int> elements)
{
    for(const auto &e : elements)
        push_back(e);
}

List::List(const List &other)
{
    for(std::size_t i = 0; i < other.size(); i++)
        push_back(other.get(i));
}
