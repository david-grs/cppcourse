#include "linked_list.h"

LinkedList::~LinkedList()
{
    Node* nodeptr = this->mFirstNode;
    while (nodeptr != nullptr)
    {
        this->Remove(nodeptr->mData);
        nodeptr = this->mFirstNode;
    }
}

void LinkedList::Append(int data)
{
    Node* nodeptr = new Node(data);

    if (this->IsEmpty())
    {
        this->mFirstNode = nodeptr;
        this->mLastNode = nodeptr;
    }
    else
    {
        this->mLastNode->mNextNode = nodeptr;
        this->mLastNode = nodeptr;
    }
}

void LinkedList::Remove(int data)
{
    if (this->IsEmpty())
        return;

    Node* nodeptr1 = this->mFirstNode;

    if (data == nodeptr1->mData)
    {
        this->mFirstNode = nodeptr1->mNextNode;

        if (this->mFirstNode == nullptr)
            this->mLastNode = nullptr;

        delete nodeptr1;
        return;
    }

    Node* nodeptr2 = nodeptr1->mNextNode;
    while (nodeptr2 != nullptr)
    {
        if (nodeptr2->mData == data)
        {
            nodeptr1->mNextNode = nodeptr2->mNextNode;

            if (nodeptr2 == this->mLastNode)
                this->mLastNode = nodeptr1;

            delete nodeptr2;
            break;
        }

        nodeptr1 = nodeptr2;
        nodeptr2 = nodeptr2->mNextNode;
    }
}
