#pragma once

struct Node
{
    Node(int data) : mData{data} {}
    int mData;
    Node* mNextNode = nullptr;
};

struct LinkedList
{
    ~LinkedList();
    bool IsEmpty() { return mFirstNode == nullptr && mLastNode == nullptr; }
    void Append(int data);
    void Remove(int data);
    Node* mFirstNode = nullptr;
    Node* mLastNode = nullptr;
};
