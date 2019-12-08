#pragma once
#include <memory>

template <class T>
struct Node
{
    Node(T data) : mData{data} {}
    T mData;
    std::unique_ptr<Node> mNextNode = nullptr;
};

template <class T>
struct LinkedList
{
    LinkedList() = default;
    bool IsEmpty() { return mNode == nullptr; }
    void Append(T data)
    {
        Node<T>* searchEmptyNodePtr = this->mNode.get();

        if (searchEmptyNodePtr == nullptr)
        {
            this->mNode = std::make_unique<Node<T>>(data);
            return;
        }

        while (searchEmptyNodePtr->mNextNode != nullptr)
        {
            searchEmptyNodePtr = searchEmptyNodePtr->mNextNode.get();
        }

        searchEmptyNodePtr->mNextNode = std::make_unique<Node<T>>(data);
    }
    void Remove(T data)
    {
        if (this->IsEmpty())
            return;

        Node<T>* nodeptr1 = this->mNode.get();

        if (data == nodeptr1->mData)
        {
            this->mNode = move(nodeptr1->mNextNode);
            return;
        }

        Node<T>* nodeptr2 = nodeptr1->mNextNode.get();
        while (nodeptr2 != nullptr)
        {
            if (data == nodeptr2->mData)
            {
                nodeptr1->mNextNode = move(nodeptr2->mNextNode);
                return;
            }

            nodeptr1 = nodeptr2;
            nodeptr2 = nodeptr2->mNextNode.get();
        }
    }
    std::unique_ptr<Node<T>> mNode = nullptr;
};
