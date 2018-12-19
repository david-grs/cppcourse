#include <memory>
#include <iostream>

template<typename T>
struct Node
{
    Node(const T& t)
    : mData(t)
    {};

    T mData;
    std::shared_ptr<Node<T>> mNext;
};

template<typename T>
class LinkedList
{
public:

    using PtrNode = std::shared_ptr<Node<T>>;

    LinkedList() {};
    
    LinkedList(const LinkedList& other)
    {
        std::cout << "copy constructor" << std::endl;
        
        if (other.mSize == 0)
            return;
        
        PtrNode ptrNode = other.mFirst;
        while(ptrNode != nullptr)
            {
                Append(ptrNode->mData);
                ptrNode = ptrNode->mNext;
            }
    };

    LinkedList& operator=(const LinkedList& other)
    {
        std::cout << "assignment operator" << std::endl;

        mFirst.reset();
        mSize = 0;

        if (other.mSize == 0)
            return *this;
        
        PtrNode ptrNode = other.mFirst;
        while(ptrNode != nullptr)
            {
                Append(ptrNode->mData);
                ptrNode = ptrNode->mNext;
            }
        return *this;
    }

    void Append(const T& data)
    {
        if(mSize == 0)
        {
            mFirst = std::make_shared<Node<T>>(data);
        }
        else
        {
            PtrNode ptrNode = mFirst;
            while(ptrNode->mNext != nullptr)
            {
                ptrNode = ptrNode->mNext;
            }
            ptrNode->mNext =  std::make_shared<Node<T>>(data);
        }

        mSize++;
    }

    friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
    {
        PtrNode ptrNode = list.mFirst;
        
        while(ptrNode != nullptr)
        {
            stream << ptrNode->mData << ", ";
            ptrNode = ptrNode->mNext;
        }

        return stream;
    }

private:
    PtrNode mFirst;
    int mSize {};
};
