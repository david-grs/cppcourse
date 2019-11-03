#pragma once
#include "singly_linked_list.h"
#include <vector>

namespace TestHelper
{
    std::vector<size_t> ConvertToVector(SinglyLinkedList* list)
    {
        std::vector<size_t> vector;
        SinglyLinkedListNode* curr = list->front();
        while (curr != nullptr)
        {
            vector.push_back(curr->get_value());
            curr = curr->next.get();
        }

        return vector;
    }

    void PushElementsToFront(SinglyLinkedList* list, std::vector<size_t> elements)
    {
        for (auto elem : elements)
        {
            list->push_front(elem);
        }
    }
}