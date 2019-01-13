//
// Created by gavin on 19/12/2018.
//

#include <memory>
struct Node
{
    explicit Node(int data) : mData(data)
    {}
    int mData{};
    std::shared_ptr<Node> mNext;
    std::shared_ptr<Node> mPrevious;
};

class List {
public:
    List() = default;
    List(std::initializer_list<int> elements);
    List(const List &other);
    List& operator=(List other);

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
    std::shared_ptr<Node> mFirst;
    std::shared_ptr<Node> mHead = mFirst;
    std::shared_ptr<Node> at(std::size_t pos) const;
    std::size_t mSize = 0;

};
