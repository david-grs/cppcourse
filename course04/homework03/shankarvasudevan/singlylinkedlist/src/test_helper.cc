#include "singly_linked_list.h"
#include <vector>
#include <iostream>

namespace TestHelper
{
    template<class T>
    std::vector<T> ConvertToVector(SinglyLinkedList<T>* list)
    {
        std::vector<T> vector;
        SinglyLinkedListNode<T>* curr = list->front();
        while (curr != nullptr)
        {
            vector.push_back(curr->get_value());
            curr = curr->next.get();
        }

        return vector;
    }

    template<class T>
    void PushElementsToFront(SinglyLinkedList<T>* list, std::vector<T> elements)
    {
        for (auto elem : elements)
        {
            list->push_front(elem);
        }
    }
}
