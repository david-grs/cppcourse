#pragma once

#include <string>
#include <boost/optional.hpp>
#include <iostream>

namespace CppCourse { namespace Homework2 {

template <typename T>
struct Node
{
    explicit Node(T value) : mValue(value) {}

    T mValue;
    std::unique_ptr<Node<T>> mNextNode;
};

template <typename T>
class LinkedList
{
public:
    LinkedList() = default;

    void push(T value)
    {
        std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);

        if (size() == 0)
        {
            mRootNode = std::move(newNode);
        }
        else
        {
            Node<T>& lastNode = traverseUntil(*mRootNode, size() - 1);
            lastNode.mNextNode = std::move(newNode);
        }
    }

    T pop()
    {
        if (size() == 0)
        {
            throw std::runtime_error("Nothing to pop, list is empty");
        }

        if (size() == 1)
        {
            T value = mRootNode->mValue;
            mRootNode.release();
            return value;
        }

        Node<T>& secondTolastNode = traverseUntil(*mRootNode, size() - 2);
        T value = secondTolastNode.mNextNode->mValue;
        secondTolastNode.mNextNode.release();

        return value;
    }

    T get(int index)
    {
        const Node<T>& node = traverseUntil(*mRootNode, index);
        return node.mValue;
    }

    int size()
    {
        if (!mRootNode)
            return 0;

        return sizeHelper(*mRootNode);
    }

    bool isEmpty()
    {
        return size() == 0;
    }

private:
    int sizeHelper(Node<T>& node)
    {
        if (!node.mNextNode)
            return 1;

        return 1 + sizeHelper(*node.mNextNode);
    }

    Node<T>& traverseUntil(Node<T>& node, int index)
    {
        if (index == 0)
            return node;

        if (!node.mNextNode)
            throw std::runtime_error("index out of bounds");

        return traverseUntil(*node.mNextNode, --index);
    }

private:
    std::unique_ptr<Node<T>> mRootNode;
};

}};

