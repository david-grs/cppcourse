#include "list.h"

#include <memory>

void List::clear() {
    mFirst.reset();
    mSize = 0;
}

void List::insert(std::size_t pos, int data)
{
    auto newElement = std::make_shared<Node>(data);
    auto next = pos == size() ? nullptr : at(pos);
    auto prev = pos == 0 ? nullptr : at(pos-1);

    if(next)
    {
        newElement->mNext = next;
        next->mPrevious = newElement;
    }
    if(prev)
    {
        newElement->mPrevious = prev;
        prev->mNext = newElement;
    }
    if(pos == 0)
        mFirst = newElement;
    if(pos == size())
        mHead = newElement;
    mSize++;
}

std::shared_ptr<Node> List::at(std::size_t pos) const
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
    auto item = at(pos);
    auto prev = item->mPrevious;
    auto next = item->mNext;
    if(next)
    {
        next->mPrevious = prev;
    }
    if(prev)
    {
        prev->mNext = next;
    }
    if(pos == 0)
        mFirst = next;
    if(pos == size() - 1)
        mHead = prev;
    mSize--;
}

void List::push_back(int data)
{
    insert(size(), data);
}

void List::pop_back()
{
    erase(size()-1);
}

std::size_t List::size() const
{
    return mSize;
}

void List::push_front(int data)
{
    insert(0, data);
}

void List::pop_front()
{
    erase(0);
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
    for( std::size_t i = 0; i < other.size(); i++ )
        push_back(other.get(i));
}

List &List::operator=(List other) {
    std::swap(mSize, other.mSize);
    std::swap(mHead, other.mHead);
    std::swap(mFirst, other.mFirst);
    return *this;
}

iterator List::begin() {
    return iterator(mFirst.get());
}

iterator List::end() {
    return iterator(nullptr);
}

iterator& iterator::operator++() {
    mItr = mItr->mNext.get();
    return *this;
}

bool iterator::operator!=(const iterator &other) {
    return mItr != other.mItr;
}

bool iterator::operator==(const iterator &other) {
    return mItr == other.mItr;
}

iterator::iterator(const iterator &other) {
    mItr = other.mItr;
}

iterator &iterator::operator=(iterator other) {
    std::swap(mItr, other.mItr);
    return *this;
}

const iterator iterator::operator++(int a) {
    for(int i=0; i < a; i++)
        mItr = mItr->mNext.get();
    return iterator(mItr);
}
