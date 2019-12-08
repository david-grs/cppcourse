#include "linked_list.h"

void LinkedList::Append(int data)
{
    Node* searchEmptyNodePtr = this->mNode.get();

    if (searchEmptyNodePtr == nullptr)
    {
        this->mNode = std::make_unique<Node>(data);
        return;
    }

    while (searchEmptyNodePtr->mNextNode != nullptr)
    {
        searchEmptyNodePtr = searchEmptyNodePtr->mNextNode.get();
    }

    searchEmptyNodePtr->mNextNode = std::make_unique<Node>(data);
}

void LinkedList::Remove(int data)
{
    if (this->IsEmpty())
        return;

    Node* nodeptr1 = this->mNode.get();

    if (data == nodeptr1->mData)
    {
        this->mNode = move(nodeptr1->mNextNode);
        return;
    }

    Node* nodeptr2 = nodeptr1->mNextNode.get();
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
