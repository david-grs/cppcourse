//
// Created by gavin on 19/12/2018.
//

#include <cstdio>
#include <memory>
#include <iostream>
struct Element
{
    Element(int data) : mData(data)
    {}
    int mData{};
    std::shared_ptr<Element> mNext;
    std::weak_ptr<Element> mPrevious;
};

class List {
public:
    List(){};
    List(std::initializer_list<int> elements);
    List(const List &other);

    void clear();

    void insert(std::size_t pos, int data);

    void erase(std::size_t pos);

    void push_back(int data);

    void pop_back();

    void push_front(int data);

    void pop_front();

    std::size_t size() const;

    int get(std::size_t pos) const;
    int& get(std::size_t pos);
private:
    std::shared_ptr<Element> mFirst;
    std::shared_ptr<Element> mHead = mFirst;
    std::size_t mSize = 0;
    std::shared_ptr<Element> at(std::size_t pos) const;

};
