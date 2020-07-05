#include "linkedlist.hpp"

template <typename T>
Node<T>& Node<T>::Append(T val)
{
    auto &cur_node = this->At(mSize).get();
    Node<T>* new_node = new Node<T>{val};
    cur_node.mNxt = new_node;
    mSize++;
    return *new_node;
}

template <typename T>
Node<T>& Node<T>::Append(T val, const int index)
{
    // Appends AFTER index
    auto &cur_node = this->At(index).get();

    Node<T>* new_node = new Node<T>{val};
    Node<T> *old_next = cur_node.mNxt;
    cur_node.mNxt = new_node;
    new_node->mNxt = old_next;

    mSize++;
    return *new_node;
}

template <typename T>
boost::optional<Node<T>&> Node<T>::At(int index){
    boost::optional<Node<T>&> cur_node = *this;
    int count = 0;
    while (cur_node.get().Next() && count < index)
    {
        // Find the last node in the chain, or index, whichever is first
        cur_node = cur_node.get().Next();
        count++;
    }
    if (count != index)
        // ran to the end of the chain without seeing index (index > mSize)
        return boost::none;
    return cur_node;

}

template <typename T>
Node<T>& Node<T>::Pop() {
    auto &cur_node = this->At(mSize - 1).get();
    auto &node = cur_node.get().Next();
    cur_node.mNxt = nullptr;
    return node;
}
