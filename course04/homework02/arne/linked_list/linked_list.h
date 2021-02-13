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

    struct Iterator : std::iterator<std::forward_iterator_tag, T>
    {
        Iterator(Node<T>* node) : mNode(node) {}

        Iterator operator++() { mNode = mNode->mNextNode.get(); return *this; }
        T& operator*() { return mNode->mData; }
        bool operator!=(Iterator other) const { return mNode != other.mNode; }
        bool operator==(Iterator other) const { return mNode == other.mNode; }

        Node<T>* mNode;
    };

    Iterator begin() { return Iterator{mNode.get()}; }
    Iterator end() { return Iterator{nullptr}; }

    template <class... Args>
    Iterator Emplace(Iterator targetIt, Args&&... args)
    {
        Node<T>* searchTargetNodePtr = this->mNode.get();
        std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(std::forward<Args...>(args...));

        if (Iterator(searchTargetNodePtr) == targetIt)
        {
            newNode->mNextNode = move(this->mNode);
            this->mNode = move(newNode);
            return Iterator(this->mNode.get());
        }

        while (Iterator(searchTargetNodePtr->mNextNode.get()) != targetIt)
        {
            searchTargetNodePtr = searchTargetNodePtr->mNextNode.get();
        }

        newNode->mNextNode = move(searchTargetNodePtr->mNextNode);
        searchTargetNodePtr->mNextNode = move(newNode);
        return Iterator(searchTargetNodePtr->mNextNode.get());
    }

    std::unique_ptr<Node<T>> mNode = nullptr;
};
