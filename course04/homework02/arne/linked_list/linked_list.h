#pragma once
#include <memory>

struct Node
{
    Node(int data) : mData{data} {}
    int mData;
    std::unique_ptr<Node> mNextNode = nullptr;
};

struct LinkedList
{
    LinkedList() = default;
    bool IsEmpty() { return mNode == nullptr; }
    void Append(int data);
    void Remove(int data);
    std::unique_ptr<Node> mNode = nullptr;
};
